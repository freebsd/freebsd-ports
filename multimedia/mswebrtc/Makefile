# $FreeBSD$

PORTNAME=	mswebrtc
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	multimedia net
MASTER_SITES=	https://www.linphone.org/releases/sources/plugins/mswebrtc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mediastreamer plugin with WebRTC codecs

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox \
		libmediastreamer_base.so:net/mediastreamer \
		libortp.so:net/ortp

USES=		cmake:outsource compiler:c++11-lib

CMAKE_ARGS=	-DENABLE_STATIC=NO
PLIST_FILES=	lib/mediastreamer/plugins/libmswebrtc.so

.include <bsd.port.mk>
