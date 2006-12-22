# New ports collection makefile for:    etoile-lucenekit
# Date created:         14 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	lucenekit
PORTVERSION=	0.1.${SNAPSHOT}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNUSTEP_CH}
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile_0+${SNAPSHOT}+dfsg.orig

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project OgreKit framework

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LOCAL_LIBS+=	OgreKit:${OGREKIT_PORT}
USE_GNUSTEP_LDCONFIG=	${SYSLIBDIR}

SNAPSHOT=	20060917
WRKSRC=	${WRKDIR}/etoile-0+${SNAPSHOT}+dfsg/Etoile/
USE_GNUSTEP_MAKE_DIRS+=	Frameworks/LuceneKit

OGREKIT_PORT?=	textproc/etoile-ogrekit

.include <bsd.port.mk>
