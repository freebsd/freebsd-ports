# New ports collection makefile for:	xpi-searchstatus
# Date created:			15 May 2006
# Whom:				Lapo Luchini <lapo@lapo.it>
#
# $FreeBSD$
#

PORTNAME=	searchstatus
PORTVERSION=	1.30
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	lapo@lapo.it
COMMENT=	Displays Google PageRank, Alexa popularity and other stats

XPI_NUM=	321
XPI_ID=		{d57c9ff1-6389-48fc-b770-f78bd89b6e8a}
XPI_FILES=	chrome/searchstatus.jar install.js install.rdf \
		installjs.old2 readme.txt chrome.manifest
XPI_DIRS=	chrome

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
