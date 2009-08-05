# New ports collection makefile for:	xpi-tabmixplus
# Date created:		29 March 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tabmixplus
DISTVERSION=	0.3.8.1
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Enhances tab browsing capabilities

XPI_DISTNAME=	tab_mix_plus
XPI_NUM=	1122
XPI_ID=		{dc572301-7619-498c-a57d-39143191b318}
XPI_FILES=	chrome/tabmixplus.jar chrome.manifest \
		defaults/preferences/tabmix.js install.rdf \
		license.txt
XPI_DIRS=	chrome defaults/preferences defaults

.include "../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
