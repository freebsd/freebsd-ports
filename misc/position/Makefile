# New ports collection makefile for:    position
# Date created:         21 Oct 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	position
PORTVERSION=	0.3
CATEGORIES=	misc
MASTER_SITES=	http://www.gnustep.it/enrico/position/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GPS and Moving-Map Applikation

BUILD_DEPENDS=	${LOCALBASE}/lib/libproj.a:${PORTSDIR}/${PROJ4_PORT}

WRKSRC=		${WRKDIR}/Position
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile
USE_GNUSTEP_MAKE_DIRS+=	Position

PROJ4_PORT?=	misc/proj4

ADDITIONAL_OBJCFLAGS+=	-I${LOCALBASE}/include
ADDITIONAL_LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	ADDITIONAL_OBJCFLAGS="${ADDITIONAL_OBJCFLAGS}"
MAKE_ENV+=	ADDITIONAL_LDFLAGS="${ADDITIONAL_LDFLAGS}"

.include <bsd.port.mk>
