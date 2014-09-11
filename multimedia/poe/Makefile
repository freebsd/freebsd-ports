# $FreeBSD$

PORTNAME=	poe
PORTVERSION=	0.5.1
PORTREVISION=	8
CATEGORIES=	multimedia gnustep
MASTER_SITES=	http://www.eskimo.com/~pburns/Poe/files/
DISTNAME=	Poe-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	vorbis comment editor for GNUstep

LICENSE=	GPLv2

LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

PORTSCOUT=	skipv:0.5.2

post-patch:
	${REINPLACE_CMD} -e 's|-lvorbisfile$$|-lvorbisfile -logg|' \
		${WRKSRC}/GNUmakefile

.include <bsd.port.mk>
