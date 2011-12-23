# New ports collection makefile for:	xpi-adblock_plus
# Date created:			2 May 2006
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	adblock_plus
PORTVERSION=	2.0.1
DISTVERSIONSUFFIX=	-fx+tb+fn+sm
CATEGORIES=	www

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A content filtering extension

XPI_NUM=	1865
XPI_ID=		{d10d0bf8-f5b5-c8b4-a8b2-2b9879e08c5d}
XPI_FILES=	chrome/adblockplus.jar chrome.manifest components/Initializer.js \
		defaults/patterns.ini defaults/preferences/adblockplus.js \
		icon.png icon64.png install.rdf \
		modules/AppIntegration.jsm modules/AppIntegrationFennec.jsm \
		modules/Bootstrap.jsm modules/ContentPolicy.jsm \
		modules/ContentPolicyRemote.jsm modules/ElemHide.jsm \
		modules/ElemHideRemote.jsm modules/FilterClasses.jsm \
		modules/FilterListener.jsm modules/FilterNotifier.jsm \
		modules/FilterStorage.jsm \
		modules/Matcher.jsm modules/ObjectTabs.jsm \
		modules/Prefs.jsm modules/Public.jsm \
		modules/RequestNotifier.jsm modules/SubscriptionClasses.jsm \
		modules/Sync.jsm modules/Synchronizer.jsm modules/Utils.jsm

XPI_DIRS=	chrome components defaults/preferences defaults modules

.include "../xpi-adblock/Makefile.xpi"
.include <bsd.port.mk>
