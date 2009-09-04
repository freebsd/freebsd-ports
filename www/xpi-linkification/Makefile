# New ports collection makefile for:	xpi-linkification
# Date created:		20 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	linkification
PORTVERSION=	1.3.6
CATEGORIES=	www
MASTER_SITES=	http://yellow5.us/firefox/
DISTNAME=	${PORTNAME}_${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Converts text links into genuine, clickable links

XPI_ID=		{35106bca-6c78-48c7-ac28-56df30b51d2a}
XPI_FILES=	chrome/linkification.jar chrome.manifest defaults/preferences/linkification.js \
		install.js install.rdf
XPI_DIRS=	chrome defaults/preferences defaults

.include "${.CURDIR}/../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
