# $FreeBSD$

PORTNAME=	msopenh264
PORTVERSION=	1.2.1
CATEGORIES=	multimedia net
MASTER_SITES=	https://www.linphone.org/releases/sources/plugins/msopenh264/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mediastreamer plugin with H.264 codec

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmediastreamer_base.so:net/mediastreamer \
		libopenh264.so:multimedia/openh264 \
		libortp.so:net/ortp

USES=		cmake

CMAKE_ARGS=	-DENABLE_STATIC=NO
PLIST_FILES=	lib/mediastreamer/plugins/libmsopenh264.so

.include <bsd.port.mk>
