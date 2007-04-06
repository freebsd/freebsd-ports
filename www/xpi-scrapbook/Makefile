# New ports collection makefile for:	xpi-scrapbook
# Date created:		6 April 2007
# Whom:			Hannes Frederic Sowa <hannes@stressinduktion.org>
#
# $FreeBSD$

PORTNAME=	scrapbook
PORTVERSION=	1.2.0.8
DISTVERSIONSUFFIX=	-fx+fl
CATEGORIES=	www

MAINTAINER=	hannes@stressinduktion.org
COMMENT=	Webcontent capturing and managing extension

XPI_ID=		{53A03D43-5363-4669-8190-99061B2DEBA5}
XPI_NUM=	427
XPI_FILES=	LICENSE.txt chrome/scrapbook.jar chrome.manifest defaults/preferences/scrapbook-prefs.js install.rdf
XPI_DIRS=	chrome defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
