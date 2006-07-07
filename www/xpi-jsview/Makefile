# New ports collection makefile for:	xpi-jsview
# Date created:		5 June 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jsview
PORTVERSION=	1.1.4
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_CSME}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Easily view embedded/external JS and CSS

XPI_ID=		{cf15270e-cf08-4def-b4ea-6a5ac23f3bca}
XPI_FILES=	chrome/jsview.jar chrome.manifest install.js install.rdf
XPI_DIRS=	chrome

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
