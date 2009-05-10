# New ports collection makefile for:	xpi-resurrectpages
# Date created:		20 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	resurrectpages
PORTVERSION=	2.0.4
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Resurrects pages from big page caches/mirrors

XPI_DISTNAME=	resurrect_pages
XPI_ID=		{0c8fbd76-bdeb-4c52-9b24-d587ce7b9dc3}
XPI_NUM=	2570
XPI_FILES=	chrome/resurrect.jar chrome.manifest defaults/preferences/resurrect.js\
		install.rdf
XPI_DIRS=	chrome defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
