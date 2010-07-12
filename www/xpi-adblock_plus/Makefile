# New ports collection makefile for:	xpi-adblock_plus
# Date created:			2 May 2006
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	adblock_plus
PORTVERSION=	1.2.1
DISTVERSIONSUFFIX=	-fx+sm+tb+fn
CATEGORIES=	www

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A content filtering extension

XPI_NUM=	1865
XPI_ID=		{d10d0bf8-f5b5-c8b4-a8b2-2b9879e08c5d}
XPI_FILES=	META-INF/manifest.mf META-INF/zigbert.rsa META-INF/zigbert.sf \
		chrome/adblockplus.jar chrome.manifest components/AdblockPlus.js \
		defaults/preferences/adblockplus.js \
		icon.png install.rdf
XPI_DIRS=	META-INF chrome components defaults/preferences defaults

.include "../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
