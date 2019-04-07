/*
 * hunspellchecker.cpp
 *
 * Copyright (C) 2009 Alexander Tsvyashchenko
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * You can also redistribute and/or modify this program under the
 * terms of the Psi License, specified in the accompanied COPYING
 * file, as published by the Psi Project; either dated January 1st,
 * 2005, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 */

#include <QDir>
#include <QCoreApplication>
#include <QtDebug>
#include <QTextCodec>

#include <hunspell/hunspell.hxx>
#include "hunspellchecker.h"

HunSpellChecker::HunSpellChecker()
{
	QStringList dict_paths(getDictSearchPaths());

	for (QStringList::const_iterator dict_path_it = dict_paths.begin(); dict_path_it != dict_paths.end(); ++dict_path_it) {
		// Get all affixes present in given path.
		QStringList affixes = QDir(*dict_path_it).entryList(QStringList("*.aff"), QDir::Files);

		for (QStringList::const_iterator affix_it = affixes.begin(); affix_it != affixes.end(); ++affix_it) {
			QString base_name(QFileInfo(*affix_it).baseName());
			int sep_pos = base_name.indexOf("_");
			QString lang = sep_pos != -1 ? base_name.left(sep_pos) : base_name;

			if (!all_langs_.contains(lang))
				all_langs_.append(lang);
		}
	}
}

void HunSpellChecker::clearSpellers()
{
	for (HunSpellers::const_iterator it = spellers_.begin(); it != spellers_.end(); ++it)
		delete it.value().speller;

	spellers_.clear();
}

HunSpellChecker::~HunSpellChecker()
{
	clearSpellers();
}

bool HunSpellChecker::isCorrect(const QString& word)
{
	if (!spellers_.empty()) {
		for (HunSpellers::const_iterator it = spellers_.begin(); it != spellers_.end(); ++it) {
			QByteArray word_enc = it.value().codec -> fromUnicode(word);
			if (it.value().speller -> spell(word_enc.constData()) != 0)
				return true;
		}
		return false;
	}
	return true;
}

QList<QString> HunSpellChecker::suggestions(const QString& word, const QString& lang, unsigned max_sugs)
{
	QList<QString> words;

	HunSpellers::const_iterator it = spellers_.find(lang);

	if (it != spellers_.end()) {
		char** suggestions;
		QByteArray word_enc = it.value().codec -> fromUnicode(word);

		if (int sugs_num = it.value().speller -> suggest(&suggestions, word_enc.constData())) {
			int sugs_out = max_sugs ? std::min((int)max_sugs, sugs_num) : sugs_num;
			for (int i = 0; i < sugs_out; ++i) {
				words << it.value().codec -> toUnicode(suggestions[i]);
			}
			it.value().speller -> free_list(&suggestions, sugs_num);
		}
	}

	return words;
}

// FIXME: hunspell keeps added words in memory only!
// To survive program exit they have to be saved/restored manually,
// which is not done here.
bool HunSpellChecker::add(const QString& word, const QString& lang)
{
	QString trimmed_word = word.trimmed();
	HunSpellers::const_iterator it = spellers_.find(lang);

	if(!trimmed_word.isEmpty() && it != spellers_.end()) {
		QByteArray word_enc = it.value().codec -> fromUnicode(trimmed_word);
		it.value().speller -> add(word_enc.constData());
		return true;
	}

	return false;
}

bool HunSpellChecker::available() const
{
	return true;
}

bool HunSpellChecker::writable() const
{
	return true;
}

QList<QString> HunSpellChecker::getAllLanguages() const
{
	return all_langs_;
}

QList<QString> HunSpellChecker::getDictSearchPaths() const
{
	QStringList dict_paths(QString("%1/hunspell").arg(QCoreApplication::applicationDirPath()));

	// Paths taken from hunspell-1.2.8/src/tools/hunspell.cxx
#ifdef Q_OS_WIN32
	dict_paths << "C:/Hunspell";
#else
	dict_paths <<
		"/usr/local/share/hunspell" <<
		"/usr/share/myspell" <<
		"/usr/share/myspell/dicts";
#endif

	return dict_paths;
}

void HunSpellChecker::setActiveLanguages(const QList<QString>& langs)
{
	// Free all spellers not needed anymore.
	for (HunSpellers::iterator it = spellers_.begin(); it != spellers_.end(); )
	{
		if (!langs.contains(it.key()))
		{
			delete it.value().speller;
			it = spellers_.erase(it);
		}
		else
			++it;
	}

	QStringList dict_paths(getDictSearchPaths());

	for (QStringList::const_iterator dict_path_it = dict_paths.begin(); dict_path_it != dict_paths.end(); ++dict_path_it)
	{
		for (QStringList::const_iterator lang_it = langs.begin(); lang_it != langs.end(); ++lang_it)
		{
			// Load dictionaries only for those languages that are not present already.
			if (spellers_.contains(*lang_it))
				continue;

			// Get all affixes with names beginning with the specified language.
			QStringList affixes = QDir(*dict_path_it).entryList(QStringList(QString("%1*.aff").arg(*lang_it)), QDir::Files);

			for (QStringList::const_iterator affix_it = affixes.begin(); affix_it != affixes.end(); ++affix_it)
			{
				QString base_name(QFileInfo(*affix_it).completeBaseName());

				// Get all dictionaries with names beginning with the affix name.
				QStringList dicts_all = QDir(*dict_path_it).entryList(QStringList(QString("%1*.dic").arg(base_name)), QDir::Files),
					dicts_to_add;

				// Add all dictionaries except those that have corresponding more specific affix name: those should be
				// handled separately, together with its affix file.
				//
				// So, for example, having en.aff, en.dic, en_XX.dic, en_YY.aff, en_YY.dic we should get in the result two
				// hunspell objects, one with affix en.aff and dictionaries en.dic and en_XX.dic and the other one with
				// affix en_YY.aff and dictionary en_YY.dic
				for (QStringList::const_iterator dict_it = dicts_all.begin(); dict_it != dicts_all.end(); ++dict_it)
				{
					QString matching_affix(QString("%1.aff").arg(QFileInfo(*dict_it).completeBaseName()));

					if (matching_affix == *affix_it || !affixes.contains(matching_affix))
						dicts_to_add << *dict_it;
				}

				if (dicts_to_add.size())
				{
					Hunspell* speller = new Hunspell(
						QString("%1/%2").arg(*dict_path_it, *affix_it).toLocal8Bit().constData(),
						QString("%1/%2").arg(*dict_path_it, dicts_to_add[0]).toLocal8Bit().constData()
					);

					for (int i = 1; i < dicts_to_add.size(); ++i)
						speller -> add_dic(QString("%1/%2").arg(*dict_path_it, dicts_to_add[i]).toLocal8Bit().constData());

					spellers_.insert(*lang_it, HunSpellInfo(speller, QTextCodec::codecForName(speller -> get_dic_encoding())));
				}
			}
		}
	}
}
