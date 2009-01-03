# New ports collection makefile for:	xpi-gbrain
# Date created:		18 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gbrain
PORTVERSION=	0.5.4
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Keeps your browser history at Google bookmarks

XPI_NUM=	2515
XPI_ID=		gbrain@andreas.gohr
XPI_FILES=	chrome/gbrain.jar chrome.manifest defaults/preferences/gbrain.js install.rdf
XPI_DIRS=	chrome defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
