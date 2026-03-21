PORTNAME=	msopenh264
DISTVERSION=	5.4.58
CATEGORIES=	multimedia net

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Mediastreamer plugin with H.264 codec
WWW=		https://www.linphone.org/technical-corner/mediastreamer2.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	v4l_compat>=1.0.20120501:multimedia/v4l_compat
LIB_DEPENDS=	\
		libbctoolbox.so:net/bctoolbox \
		libmediastreamer2.so:net/mediastreamer \
		libopenh264.so:multimedia/openh264 \
		libortp.so:net/ortp

USES=		cmake
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public

CMAKE_ARGS=	-DMEDIASTREAMER2_PLUGINS_LOCATION=${CMAKE_INSTALL_PREFIX}/lib/mediastreamer/plugins
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	ENABLE_STATIC

PLIST_FILES=	lib/mediastreamer/plugins/libmsopenh264.so

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
