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
DISTNAME=	Grr-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rss reader for GNUstep

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_LIBS+=	RSSKit:${RSSKIT_PORT}

RSSKIT_PORT?=	www/etoile-rsskit

.include <bsd.port.mk>
