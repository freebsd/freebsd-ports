# $FreeBSD$

PORTNAME=	obs-studio
PORTVERSION=	0.16.0
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source streaming/recording software

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	v4l_compat>=0:multimedia/v4l_compat
LIB_DEPENDS=	libsysinfo.so:devel/libsysinfo \
		libx264.so:multimedia/libx264 \
		libv4l2.so:multimedia/libv4l \
		libpulse.so:audio/pulseaudio \
		libjack.so:audio/jack \
		libjansson.so:devel/jansson \
		libcurl.so:ftp/curl \
		libavcodec.so:multimedia/ffmpeg \
		libfdk-aac.so:audio/fdk-aac \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libdbus-1.so:devel/dbus

USES=		cmake:outsource compiler:c++11-lib pkgconfig
USE_GITHUB=	yes
USE_GL=		gl
USE_LDCONFIG=	yes
USE_QT5=	gui core widgets x11extras buildtools_build qmake_build imageformats_run
USE_XORG=	sm ice xcb xcomposite xext xfixes xinerama xrandr x11

CMAKE_ARGS=	-DUNIX_STRUCTURE:BOOL=ON \
		-DOBS_VERSION_OVERRIDE:STRING="${PORTVERSION}"

GH_ACCOUNT=	jp9000

INSTALLS_ICONS=	yes

BROKEN_aarch64=		Fails to compile: invalid conversion between vector type and integer type

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
CXXFLAGS+=	-D_GLIBCXX_USE_C99
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||' \
		${WRKSRC}/deps/glad/CMakeLists.txt

.include <bsd.port.post.mk>
