# New ports collection makefile for:	xpi-colorfultabs
# Date created:		29 March 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	colorfultabs
PORTVERSION=	4.6.1
DISTVERSIONSUFFIX=	-fx+sm
PORTEPOCH=	1
CATEGORIES=	www

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Colors every tab in a different color

XPI_ID=		{0545b830-f0aa-4d7e-8820-50a4629a56fe}
XPI_NUM=	1368
XPI_FILES=	chrome/clrtabs.jar chrome.manifest \
		defaults/preferences/defaults.js install.rdf
XPI_DIRS=	chrome defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
