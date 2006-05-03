# New ports collection makefile for:	xpi-adblock_plus
# Date created:			2 May 2006
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	adblock_plus
PORTVERSION=	0.7
DISTVERSIONSUFFIX=	-fx+fl+mz+ns
CATEGORIES=	www

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A content filtering extension

XPI_ID=		{d10d0bf8-f5b5-c8b4-a8b2-2b9879e08c5d}
XPI_FILES=	chrome/adblockplus.jar chrome.manifest components/nsAdblockPlus.js \
		components/nsAdblockPlus.xpt defaults/preferences/adblockplus.js \
		install.js install.rdf
XPI_DIRS=	chrome components defaults/preferences defaults

.include "../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
