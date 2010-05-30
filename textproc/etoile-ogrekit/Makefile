# New ports collection makefile for:    etoile-ogrekit
# Date created:         14 Dec 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	ogrekit
PORTVERSION=	0.4.1
CATEGORIES=	textproc gnustep
MASTER_SITES=	http://download.gna.org/etoile/
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project OgreKit framework

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}

OPTIONS=	ONIGURUMA4 "build with oniguruma4 instead of oniguruma5" OFF

DEFAULT_LIBVERSION=	1.2.1
WRKSRC=	${WRKDIR}/Etoile-${PORTVERSION}
USE_GNUSTEP_MAKE_DIRS+=	Frameworks/OgreKit

UNITKIT_PORT?=	devel/etoile-unitkit
ONIGURUMA4_PORT?=	devel/oniguruma4
ONIGURUMA5_PORT?=	devel/oniguruma5

.include <bsd.port.pre.mk>

.if defined(WITH_ONIGURUMA4)
ADDITIONAL_OBJCFLAGS+=	-DONIGURUMA_4
LIB_DEPENDS+=	onig:${PORTSDIR}/${ONIGURUMA4_PORT}
.else
LIB_DEPENDS+=	onig:${PORTSDIR}/${ONIGURUMA5_PORT}
.endif

.include <bsd.port.post.mk>
