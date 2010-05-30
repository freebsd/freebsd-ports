# New ports collection makefile for:    etoile-bookmarkkit
# Date created:         18 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	bookmarkkit
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	www gnustep
MASTER_SITES=	http://download.gna.org/etoile/
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile-${PORTVERSION}

PORTSCOUT=	limit:^0\.2

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project BookmarkKit framework

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_LIBS+=	CollectionKit:${COLLECTIONKIT_PORT}
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

WRKSRC=	${WRKDIR}/Etoile-${PORTVERSION}
USE_GNUSTEP_MAKE_DIRS+=	Frameworks/BookmarkKit

COLLECTIONKIT_PORT?=	devel/etoile-collectionkit

.include <bsd.port.mk>
