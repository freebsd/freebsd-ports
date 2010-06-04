# New ports collection makefile for:    poe
# Date created:         17 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	poe
PORTVERSION=	0.5.1
PORTREVISION=	4
CATEGORIES=	multimedia gnustep
MASTER_SITES=	http://www.eskimo.com/~pburns/Poe/files/
DISTNAME=	Poe-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A vorbis comment editor for GNUstep

LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis

LICENSE=	GPLv2

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

PORTSCOUT=	skipv:0.5.2

.include <bsd.port.mk>
