# New ports collection makefile for:	xpi-modify_headers
# Date created:			24 January 2009
# Whom:				Dominic Fandrey <kamikaze@bsdforen.de>
#
# $FreeBSD$
#

PORTNAME=	modify_headers
PORTVERSION=	0.6.6
DISTVERSIONSUFFIX=	-fx+sm+mz
PORTREVISION=	2
CATEGORIES=	www

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	A firefox extension to manipulate HTTP headers

XPI_NUM=	967
XPI_ID=		{b749fc7c-e949-447f-926c-3f4eed6accfe}

XPI_FILES=	chrome.manifest \
		chrome/modifyheaders.jar \
		components/mhIHeader.xpt \
		components/modifyheaders-service.js \
		components/nsIModifyheaders.xpt \
		install.js \
		install.rdf

XPI_DIRS=	chrome \
		components

post-patch:
	${RM} ${WRKSRC}/install.rdf.orig

.include "../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
