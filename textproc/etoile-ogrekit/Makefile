# New ports collection makefile for:    etoile-ogrekit
# Date created:         14 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	ogrekit
PORTVERSION=	0.1.${SNAPSHOT}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNUSTEP_CH}
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile_0+${SNAPSHOT}+dfsg.orig

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project OgreKit framework

LIB_DEPENDS=	onig:${PORTSDIR}/${ONIGURUMA4_PORT}

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${LOCALLIBDIR}

SNAPSHOT=	20060917
WRKSRC=	${WRKDIR}/etoile-0+${SNAPSHOT}+dfsg/Etoile/
USE_GNUSTEP_MAKE_DIRS+=	Frameworks/OgreKit

UNITKIT_PORT?=	devel/etoile-unitkit
ONIGURUMA4_PORT?=	devel/oniguruma4

.include <bsd.port.mk>
