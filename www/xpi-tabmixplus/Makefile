# New ports collection makefile for:	xpi-tabmixplus
# Date created:		29 March 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tabmixplus
DISTVERSION=	0.3.8.3
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Enhances tab browsing capabilities

XPI_DISTNAME=	tab_mix_plus
XPI_NUM=	1122
XPI_ID=		{ec8030f7-c20a-464f-9b0e-13a3a9e97384}
XPI_FILES=	chrome/tabmixplus.jar chrome.manifest \
		defaults/preferences/tabmix.js install.rdf \
		icon.png
XPI_DIRS=	chrome defaults/preferences defaults

.include "../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
