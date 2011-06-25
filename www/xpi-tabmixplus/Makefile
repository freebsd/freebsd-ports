# New ports collection makefile for:	xpi-tabmixplus
# Date created:		29 March 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tabmixplus
DISTVERSION=	0.3.8.6
DISTVERSIONSUFFIX=	-fx
CATEGORIES=	www

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Enhances tab browsing capabilities

XPI_DISTNAME=	tab_mix_plus
XPI_NUM=	1122
XPI_ID=		{dc572301-7619-498c-a57d-39143191b318}
XPI_FILES=	chrome/tabmixplus.jar chrome.manifest \
		defaults/preferences/tabmix.js icon.png \
		install.rdf license.txt modules/AutoReload.jsm \
		modules/MergeWindows.jsm modules/Services.jsm \
		modules/Slideshow.jsm modules/XPCOMUtils.jsm \
		modules/extensions/CompatibilityCheck.jsm \
		modules/extensions/TabGroupsManager.jsm modules/log.jsm

XPI_DIRS=	chrome defaults/preferences defaults \
		modules/extensions modules

.include "../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
