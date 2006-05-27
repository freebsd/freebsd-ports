# New ports collection makefile for:	xpi-urllink
# Date created:		20 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	urllink
PORTVERSION=	1.06.9
DISTVERSIONSUFFIX=	-fx+tb
CATEGORIES=	www

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Select a non-URL and open it in a browser window

XPI_DISTNAME=	url_link
XPI_ID=		{139a120b-c2ea-41d2-bf70-542d9f063dfd}
XPI_FILES=	chrome/urllink.jar install.rdf chrome.manifest
XPI_DIRS=	chrome

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
