# New ports collection makefile for:	xpi-fasterfox
# Date created:		28 March 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fasterfox
PORTVERSION=	1.0.3
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Performance and network tweaks for Firefox

XPI_ID=		{c36177c0-224a-11da-8cd6-0800200c9a66}
XPI_FILES=	chrome/fasterfox.jar defaults/preferences/fasterfox.js install.rdf \
		readme.txt chrome.manifest
XPI_DIRS=	chrome defaults/preferences defaults

.include "../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
