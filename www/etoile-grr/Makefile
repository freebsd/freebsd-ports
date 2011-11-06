# New ports collection makefile for:    grr
# Date created:         05 Nov 2011
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	grr
PORTVERSION=	0.9.0
CATEGORIES=	www gnustep
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	gap
PKGNAMEPREFIX=	etoile-
DISTNAME=	Grr-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Rss reader for GNUstep

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_LIBS+=	RSSKit:${RSSKIT_PORT}
#USE_GNUSTEP_LOCAL_LIBS+=	BookmarkKit:${BOOKMARKKIT_PORT}
#USE_GNUSTEP_LOCAL_LIBS+=	CollectionKit:${COLLECTIONKIT_PORT}
#USE_GNUSTEP_LOCAL_LIBS+=	PaneKit:${PANEKIT_PORT}

RSSKIT_PORT?=	www/etoile-rsskit

.include <bsd.port.mk>
