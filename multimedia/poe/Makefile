# New ports collection makefile for:    poe
# Date created:         17 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	poe
PORTVERSION=	0.5.1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.eskimo.com/~pburns/Poe/files/
DISTNAME=	Poe-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A vorbis comment editor for GNUstep

LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis

USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=
ALL_TARGET=

.include <bsd.port.mk>
