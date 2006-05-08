# New ports collection makefile for:	xpi-cutemenus-crystalsvg
# Date created:			4 May 2006
# Whom:				Lapo Luchini <lapo@lapo.it>
#
# $FreeBSD$
#

PORTNAME=	cutemenus-crystalsvg
PORTVERSION=	0.9.9.73
DISTVERSIONSUFFIX=	-fx+fl+tb
CATEGORIES=	www
MASTER_SITE_SUBDIR=	extensions/cutemenus_-_crystal_svg
DISTNAME=	cutemenus_-_crystal_svg-${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	lapo@lapo.it
COMMENT=	An extension that adds cute icons to menus

XPI_ID=		{63df8e21-711c-4074-a257-b065cadc28d8}
XPI_FILES=	chrome/cutemenus.jar chrome.manifest install.js install.rdf
XPI_DIRS=	chrome

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
