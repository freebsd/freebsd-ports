# $FreeBSD$

PORTNAME=	poe
PORTVERSION=	0.5.1
PORTREVISION=	6
CATEGORIES=	multimedia gnustep
MASTER_SITES=	http://www.eskimo.com/~pburns/Poe/files/
DISTNAME=	Poe-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A vorbis comment editor for GNUstep

LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis

LICENSE=	GPLv2

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

PORTSCOUT=	skipv:0.5.2

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's|-lvorbisfile$$|-lvorbisfile -logg|' \
		${WRKSRC}/GNUmakefile

.include <bsd.port.mk>
