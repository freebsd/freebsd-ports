PORTNAME=	msopenh264
DISTVERSION=	5.2.0
PORTREVISION=	1
CATEGORIES=	multimedia net

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Mediastreamer plugin with H.264 codec
WWW=		https://www.linphone.org/technical-corner/mediastreamer2.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox \
		libmediastreamer.so:net/mediastreamer \
		libopenh264.so:multimedia/openh264 \
		libortp.so:net/ortp

USES=		cmake
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
GL_COMMIT=	5c7a9522478f5eedc9a3e1600fdd705da1e00d23

CMAKE_ARGS=	-DENABLE_STATIC=NO
PLIST_FILES=	lib/mediastreamer/plugins/libmsopenh264.so

.include <bsd.port.mk>
