# Created by: Steven Kreuzer <skreuzer@exit2shell.com>
# $FreeBSD$

PORTNAME=	errorzilla
PORTVERSION=	0.42
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Useful error pages

XPI_DISTNAME=	errorzilla_mod
XPI_NUM=	3336
XPI_ID=	ErrorZillaMod@jaybaldwin
XPI_FILES=	chrome/content/about.xul \
		chrome/content/contents.rdf \
		chrome/content/images/firefox_logo1.gif \
		chrome/content/images/firefox_logo2.gif \
		chrome/content/lib.js \
		chrome/content/netError.css \
		chrome/content/netError.dtd \
		chrome/content/netError.js \
		chrome/content/netError.xhtml \
		chrome/content/overlay.xul \
		chrome/content/prefs.js \
		chrome/locale/en-US/about.dtd \
		chrome/locale/en-US/contents.rdf \
		chrome/skin/classic/about.css \
		chrome/skin/classic/contents.rdf \
		chrome/skin/classic/errorzillamod.png \
		chrome.manifest \
		defaults/preferences/prefs.js \
		install.rdf
XPI_DIRS=	chrome/content/images \
		chrome/content \
		chrome/locale/en-US \
		chrome/locale \
		chrome/skin/classic \
		chrome/skin \
		chrome \
		defaults/preferences \
		defaults

NO_STAGE=	yes
.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
