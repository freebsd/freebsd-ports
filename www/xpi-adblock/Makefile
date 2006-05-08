# New ports collection makefile for:	xpi-adblock
# Date created:		28 March 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	adblock
PORTVERSION=	0.5.3.042
DISTVERSIONSUFFIX=	-fx+fl+mz+ns
CATEGORIES=	www

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	A content filtering extension

XPI_ID=		{34274bf4-1d97-a289-e984-17e546307e4f}
XPI_FILES=	chrome/adblock.jar chrome.manifest components/.autoreg \
		components/nsAdblock.js defaults/preferences/adblock.js \
		install.js install.rdf license.txt
XPI_DIRS=	chrome components defaults/preferences defaults

.include "../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
