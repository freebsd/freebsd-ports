# New ports collection makefile for:    etoile-ogrekit
# Date created:         14 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	ogrekit
PORTVERSION=	0.2
CATEGORIES=	textproc gnustep
MASTER_SITES=	http://download.gna.org/etoile/
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project OgreKit framework

LIB_DEPENDS=	onig:${PORTSDIR}/${ONIGURUMA4_PORT}

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

WRKSRC=	${WRKDIR}/Etoile-${PORTVERSION}
USE_GNUSTEP_MAKE_DIRS+=	Frameworks/OgreKit
ADDITIONAL_OBJCFLAGS+=	-DONIGURUMA_4

UNITKIT_PORT?=	devel/etoile-unitkit
ONIGURUMA4_PORT?=	devel/oniguruma4

.include <bsd.port.mk>
