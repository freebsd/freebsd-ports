# $FreeBSD$

PORTNAME=	obs-studio
DISTVERSION=	25.0.8
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open source streaming/recording software

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=	Fails to compile: invalid conversion between vector type and integer type

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
		libmbedtls.so:security/mbedtls \
		libpulse.so:audio/pulseaudio \
		libspeexdsp.so:audio/speexdsp \
		libsysinfo.so:devel/libsysinfo \
		libudev.so:devel/libudev-devd \
		libv4l2.so:multimedia/libv4l \
		libvlc.so:multimedia/vlc \
		libx264.so:multimedia/libx264 \
		${LIB_DEPENDS_${ARCH}}
LIB_DEPENDS_amd64=	libluajit-5.1.so:lang/luajit
LIB_DEPENDS_armv7=	libluajit-5.1.so:lang/luajit
LIB_DEPENDS_i386=	libluajit-5.1.so:lang/luajit
LIB_DEPENDS_powerpc=	libluajit-5.1.so:lang/luajit

USES=		cmake gl lua pkgconfig python:3.4+ qt:5 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	obsproject
USE_QT=		core gui svg widgets x11extras xml buildtools_build imageformats_run qmake_build
USE_GL=		gl
USE_XORG=	ice sm x11 xcb xcomposite xext xfixes xinerama xrandr
USE_LDCONFIG=	yes

CMAKE_ON=	UNIX_STRUCTURE
CMAKE_ARGS=	-DOBS_VERSION_OVERRIDE:STRING="${PORTVERSION}"
CFLAGS+=	-D_WITH_GETLINE

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64
USES+=		compiler:gcc-c++11-lib
.else
USES+=		compiler:c++11-lib
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} != amd64 && ${ARCH} != armv7 && ${ARCH} != i386 && ${ARCH} != powerpc
PLIST_SUB+=	LUAJIT="@comment "
.else
PLIST_SUB+=	LUAJIT=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| 3.4)| ${PYTHON_VER})|' \
		${WRKSRC}/cmake/Modules/FindPythonDeps.cmake

post-install:
	# https://github.com/obsproject/obs-studio/issues/2625
	${INSTALL_DATA} ${WRKSRC}/UI/obs-frontend-api/obs-frontend-api.h ${STAGEDIR}${PREFIX}/include/obs
	# https://github.com/obsproject/obs-studio/issues/2647 (only for multimedia/obs-audio-spectralizer, should be removed later)
	${INSTALL_DATA} ${WRKSRC}/cmake/Modules/ObsHelpers.cmake ${STAGEDIR}${PREFIX}/lib/cmake
	${INSTALL_DATA} ${WRKSRC}/cmake/external/ObsPluginHelpers.cmake ${STAGEDIR}${PREFIX}/lib/cmake

.include <bsd.port.post.mk>
