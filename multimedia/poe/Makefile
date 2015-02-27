# $FreeBSD$

PORTNAME=	poe
PORTVERSION=	0.5.1
PORTREVISION=	8
CATEGORIES=	multimedia gnustep
MASTER_SITES=	http://www.eskimo.com/~pburns/Poe/files/
DISTNAME=	Poe-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vorbis comment editor for GNUstep

LICENSE=	GPLv2 # or later

LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

PORTSCOUT=	skipv:0.5.2

post-patch:
	${REINPLACE_CMD} -e 's|-lvorbisfile$$|-lvorbisfile -logg|' \
		${WRKSRC}/GNUmakefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Applications/Poe.app/Poe

.include <bsd.port.mk>
