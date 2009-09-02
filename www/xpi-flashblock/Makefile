# New ports collection makefile for:	flashblock
# Date created:		14 May 2006
# Whom:			Simon Olofsson
#
# $FreeBSD$
#

PORTNAME=	flashblock
PORTVERSION=	1.5.11.2
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	simon@olofsson.de
COMMENT=	Replaces Flash objects with a button you can click to view them

XPI_ID=		{3d7eb24f-2740-49df-8937-200b1cc08f8a}
XPI_NUM=	433
XPI_FILES=	chrome/flashblock.jar chrome.manifest defaults/preferences/flashblock.js install.rdf
XPI_DIRS=	chrome defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
