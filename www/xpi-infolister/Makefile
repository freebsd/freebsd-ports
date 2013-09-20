# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	infolister
DISTVERSION=	0.9f.2
DISTVERSIONSUFFIX=	-fx+tb+sb
CATEGORIES=	www

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Lists installed extensions and themes

XPI_ID=		{3f0da09b-c1ab-40c5-8d7f-53f475ac3fe8}
XPI_NUM=	447
XPI_FILES=	chrome/infolister.jar chrome.manifest \
		components/infolister-service.js components/ss.js \
		defaults/preferences/infolister_prefs.js install.rdf \
		license.txt
XPI_DIRS=	chrome components defaults/preferences defaults

NO_STAGE=	yes
.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
