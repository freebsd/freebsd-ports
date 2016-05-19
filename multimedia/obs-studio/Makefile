# $FreeBSD$

PORTNAME=	obs-studio
PORTVERSION=	0.14.1
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source streaming/recording software

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsysinfo.so:devel/libsysinfo \
		libx264.so:multimedia/libx264 \
		libv4l2.so:multimedia/libv4l \
		libpulse.so:audio/pulseaudio \
		libjack.so:audio/jack \
		libjansson.so:devel/jansson \
		libcurl.so:ftp/curl \
		libavcodec.so:multimedia/ffmpeg \
		libfdk-aac.so:audio/fdk-aac
BUILD_DEPENDS=	v4l_compat>=0:multimedia/v4l_compat

USE_XORG=	xcb xcomposite xfixes xinerama xrandr
USE_LDCONFIG=	yes
USE_GL=		gl
USE_QT5=	widgets x11extras buildtools_build qmake_build imageformats_run
USES=		cmake:outsource compiler:c++11-lib pkgconfig
CMAKE_ARGS=	-DUNIX_STRUCTURE:BOOL=ON \
		-DOBS_VERSION_OVERRIDE:STRING="${PORTVERSION}" \

USE_GITHUB=	yes
GH_ACCOUNT=	jp9000

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
CXXFLAGS+=	-D_GLIBCXX_USE_C99
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||' \
		${WRKSRC}/deps/glad/CMakeLists.txt

.include <bsd.port.post.mk>
