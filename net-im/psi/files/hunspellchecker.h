/*
 * hunspellchecker.h
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

#ifndef HUNSPELLCHECKER_H
#define HUNSPELLCHECKER_H

#include <QList>
#include <QString>
#include <QMap>

#include "spellchecker.h"

class Hunspell;

class HunSpellChecker : public SpellChecker
{
public:
	HunSpellChecker();
	~HunSpellChecker();
	virtual QList<QString> suggestions(const QString&, const QString& lang, unsigned max_sugs);
	virtual bool isCorrect(const QString&);
	virtual bool add(const QString& word, const QString& lang);
	virtual bool available() const;
	virtual bool writable() const;
	virtual QList<QString> getAllLanguages() const;
	virtual void setActiveLanguages(const QList<QString>&);

private:
	struct HunSpellInfo
	{
		QTextCodec* codec;
		Hunspell* speller;

		HunSpellInfo(Hunspell* speller, QTextCodec* codec):
			speller(speller), codec(codec) {}
	};

	typedef QMap<QString, HunSpellInfo> HunSpellers;

	HunSpellers spellers_;
	QList<QString> all_langs_;

private:
	void clearSpellers();
	QList<QString> getDictSearchPaths() const;
};

#endif
