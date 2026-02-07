PORTNAME=	msopenh264
DISTVERSION=	5.2.0
PORTREVISION=	5
CATEGORIES=	multimedia net

PATCH_SITES=	https://gitlab.linphone.org/BC/public/msopenh264/-/commit/
PATCHFILES=	a7c4a130a1fd0a2d1f18df748d370430cfbe936a.diff:-p1

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Mediastreamer plugin with H.264 codec
WWW=		https://www.linphone.org/technical-corner/mediastreamer2.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	v4l_compat>=1.0.20120501:multimedia/v4l_compat
LIB_DEPENDS=	\
		libmediastreamer2.so:net/mediastreamer \
		libopenh264.so:multimedia/openh264

USES=		cmake
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public

CMAKE_ARGS=	-DMEDIASTREAMER2_PLUGINS_LOCATION=${CMAKE_INSTALL_PREFIX}/lib/mediastreamer/plugins
CMAKE_OFF=	ENABLE_STATIC

PLIST_FILES=	lib/mediastreamer/plugins/libmsopenh264.so

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
