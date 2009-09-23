# New ports collection makefile for:    etoile-mediakit
# Date created:         23 Nov 2008
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	mediakit
PORTVERSION=	0.4.1
CATEGORIES=	multimedia gnustep
MASTER_SITES=	http://download.gna.org/etoile/
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project MediaKit framework

LIB_DEPENDS=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}
USE_GNUSTEP_LOCAL_LIBS+=	EtoileFoundation:${FOUNDATION_PORT}
USE_GNUSTEP_LOCAL_LIBS+=	SystemConfig:${SYSTEMCONFIG_PORT}

DEFAULT_LIBVERSION=	0.1
WRKSRC=	${WRKDIR}/Etoile-${PORTVERSION}
USE_GNUSTEP_MAKE_DIRS+=	Frameworks/MediaKit

FOUNDATION_PORT?=	devel/etoile-foundation
SYSTEMCONFIG_PORT?=	deskutils/etoile-systemconfig

ADDITIONAL_INCLUDE_DIRS+=	-I${LOCALBASE}/include/ffmpeg

.include <bsd.port.mk>
