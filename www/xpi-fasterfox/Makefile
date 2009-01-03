# New ports collection makefile for:	xpi-fasterfox
# Date created:		28 March 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fasterfox
PORTVERSION=	2.0.0
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Performance and network tweaks for Firefox

XPI_NUM=	1269
XPI_ID=		{c36177c0-224a-11da-8cd6-0800200c9a66}
XPI_FILES=	chrome/fasterfox.jar chrome.manifest defaults/preferences/fasterfox.js \
		install.rdf readme.txt 
XPI_DIRS=	chrome defaults/preferences defaults 

.include "../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
