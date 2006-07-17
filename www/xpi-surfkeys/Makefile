# New ports collection makefile for:	xpi-surfkeys
# Date created:		2006-07-15
# Whom:			Simon Olofsson <simon@olofsson.de>
#
# $FreeBSD$
#

PORTNAME=	surfkeys
PORTVERSION=	0.4.1
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	simon@olofsson.de
COMMENT=	Comfortable surfing with keyboard

XPI_ID=		{a44ef047-cd8d-406e-a354-b7101bd24735}
XPI_FILES=	chrome/chrome.jar chrome.manifest defaults/preferences/prefs.js install.rdf
XPI_DIRS=	chrome defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
