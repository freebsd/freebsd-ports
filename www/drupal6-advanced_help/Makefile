# Created by: Eygene Ryabinkin <rea-fbsd@codelabs.ru>
# $FreeBSD$

PORTNAME=	advanced_help
DISTVERSION=	6.x-1.2
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://ftp.drupal.org/files/projects/

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Allows to store module help pages outside the module system

USES=		drupal:6,module
MODULE_DIRS=	help \
		help_example/help help_example/translations help_example \
		translations/help/de translations/help translations
MODULE_FILES=	help/advanced_help.help.ini help/ini-file.html \
		help/translation.html help/using-advanced-help.html \
		help/why-advanced-help.html \
		advanced-help-popup.tpl.php advanced_help.info \
		advanced_help.install advanced_help.module \
		help-icon.css help-popup.css help.css help.png \
		help_example/help/180px-Andi_Gutmans_1.jpg \
		help_example/help/180px-Lerdorf.jpg \
		help_example/help/180px-PHP_Hello_World_screenshot.png \
		help_example/help/about-php.html \
		help_example/help/help_example.help.ini \
		help_example/help/history.html \
		help_example/help/security.html \
		help_example/help/syntax.html \
		help_example/help/usage.html \
		help_example/help_example.info \
		help_example/help_example.module \
		help_example/translations/help_example.de.po \
		help_example/translations/help_example.pot \
		translations/help/de/advanced_help.help.ini \
		translations/help/de/ini-file.html \
		translations/help/de/translation.html \
		translations/help/de/using-advanced-help.html \
		translations/help/de/why-advanced-help.html \
		translations/advanced_help.de.po \
		translations/advanced_help.hu.po \
		translations/advanced_help.pot \
		translations/fr.po
DOC_FILES=	LICENSE.txt
OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
