# $FreeBSD$

PORTNAME=	poe
PORTVERSION=	0.5.1
PORTREVISION=	11
CATEGORIES=	multimedia gnustep
MASTER_SITES=	http://www.eskimo.com/~pburns/Poe/files/
DISTNAME=	Poe-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vorbis comment editor for GNUstep

LICENSE=	GPLv2+

LIB_DEPENDS=	libvorbis.so:audio/libvorbis

USES=		gnustep
USE_GNUSTEP=	back build

PORTSCOUT=	skipv:0.5.2

post-patch:
	${REINPLACE_CMD} -e 's|-lvorbisfile$$|-lvorbisfile -logg|' \
		${WRKSRC}/GNUmakefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Poe.app/Poe

.include <bsd.port.mk>
