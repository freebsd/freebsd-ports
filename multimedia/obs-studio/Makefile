# $FreeBSD$

PORTNAME=	obs-studio
DISTVERSION=	24.0.4
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open source streaming/recording software

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=		Fails to compile: invalid conversion between vector type and integer type

BUILD_DEPENDS=	v4l_compat>=0:multimedia/v4l_compat \
		swig3.0:devel/swig30
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libcurl.so:ftp/curl \
		libdbus-1.so:devel/dbus \
		libfdk-aac.so:audio/fdk-aac \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libjack.so:audio/jack \
		libjansson.so:devel/jansson \
		libluajit-5.1.so:lang/luajit \
		libmbedtls.so:security/mbedtls \
		libpulse.so:audio/pulseaudio \
		libspeexdsp.so:audio/speexdsp \
		libsysinfo.so:devel/libsysinfo \
		libudev.so:devel/libudev-devd \
		libv4l2.so:multimedia/libv4l \
		libx264.so:multimedia/libx264

USES=		cmake compiler:c++11-lib gl lua pkgconfig python:3.4+ qt:5 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	obsproject
USE_QT=		core gui svg widgets x11extras buildtools_build imageformats_run qmake_build
USE_GL=		gl
USE_XORG=	ice sm x11 xcb xcomposite xext xfixes xinerama xrandr
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DUNIX_STRUCTURE:BOOL=ON \
		-DOBS_VERSION_OVERRIDE:STRING="${PORTVERSION}"
CFLAGS+=	-D_WITH_GETLINE

post-patch:
	@${REINPLACE_CMD} -e 's| 3.4)| ${PYTHON_VER})|' \
		${WRKSRC}/cmake/Modules/FindPythonDeps.cmake

.include <bsd.port.mk>
