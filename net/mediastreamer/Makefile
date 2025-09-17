PORTNAME=	mediastreamer
DISTVERSION=	5.4.26
CATEGORIES=	net

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Real-time audio and video streaming and processing
WWW=		https://www.linphone.org/technical-corner/mediastreamer2

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox \
		libbzrtp.so:security/bzrtp \
		libortp.so:net/ortp \
		libsrtp2.so:net/libsrtp2

USES=		cmake compiler gnome python:build sqlite
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
GL_PROJECT=	${PORTNAME}2
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DENABLE_ALSA=NO \
		-DENABLE_BV16=NO \
		-DENABLE_DOC=NO \
		-DENABLE_JPEG=NO \
		-DENABLE_OSS=YES \
		-DENABLE_PULSEAUDIO=NO \
		-DENABLE_STATIC=NO \
		-DENABLE_STRICT=NO \
		-DENABLE_TOOLS=NO
CMAKE_ON=		BUILD_SHARED_LIBS
CMAKE_OFF=		ENABLE_UNIT_TESTS

LDFLAGS+=	-pthread

OPTIONS_DEFINE=		MATROSKA VIDEO
OPTIONS_DEFAULT=	FFMPEG G729 GLX GSM MATROSKA OPUS QTGL SPEEX THEORA \
			V4L VIDEO VPX XVIDEO
OPTIONS_GROUP=		AUDIOOPT VIDEOOPT
OPTIONS_GROUP_AUDIOOPT=	G726 G729 GSM OPUS SPEEX
OPTIONS_GROUP_VIDEOOPT=	FFMPEG GLX QTGL THEORA V4L VPX XVIDEO
OPTIONS_SUB=		yes

AUDIOOPT_DESC=	Audio options
G726_DESC=		G.726 codec support
G729_DESC=		G.729 codec support
QTGL_DESC=		Qt OpenGL rendering support
VIDEOOPT_DESC=	Video options

FFMPEG_IMPLIES=		VIDEO
FFMPEG_LIB_DEPENDS=	libavcodec.so.58:multimedia/ffmpeg4
FFMPEG_CMAKE_BOOL=	ENABLE_FFMPEG
G726_LIB_DEPENDS=	libspandsp.so:comms/spandsp
G726_CMAKE_BOOL=	ENABLE_G726
G729_LIB_DEPENDS=	libbcg729.so:audio/bcg729
G729_CMAKE_BOOL=	ENABLE_G729
GLX_IMPLIES=	VIDEO
GLX_USES=	gl
GLX_USE=	GL=gl,glew
GLX_CMAKE_BOOL=	ENABLE_GL ENABLE_GLX
GSM_LIB_DEPENDS=	libgsm.so:audio/gsm
GSM_CMAKE_BOOL=		ENABLE_GSM
MATROSKA_LIB_DEPENDS=	libbcmatroska2.so:multimedia/bcmatroska2
MATROSKA_CMAKE_BOOL=	ENABLE_MKV
OPUS_LIB_DEPENDS=	libopus.so:audio/opus
OPUS_CMAKE_BOOL=	ENABLE_OPUS
QTGL_IMPLIES=	VIDEO
QTGL_USES=	qt:5
QTGL_USE=	QT=core,declarative,gui,network,buildtools:build,qmake:build
QTGL_CMAKE_BOOL=	ENABLE_QT_GL
SPEEX_LIB_DEPENDS=	libspeex.so:audio/speex \
			libspeexdsp.so:audio/speexdsp
SPEEX_CMAKE_BOOL=	ENABLE_SPEEX_CODEC
THEORA_IMPLIES=		VIDEO
THEORA_LIB_DEPENDS=	libtheora.so:multimedia/libtheora
THEORA_CMAKE_BOOL=	ENABLE_THEORA
V4L_IMPLIES=		VIDEO
V4L_BUILD_DEPENDS=	v4l_compat>=1.0.20120501:multimedia/v4l_compat
V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l
V4L_CMAKE_BOOL=		ENABLE_V4L
VIDEO_CMAKE_BOOL=	ENABLE_VIDEO
VPX_IMPLIES=		VIDEO
VPX_LIB_DEPENDS=	libvpx.so:multimedia/libvpx
VPX_CMAKE_BOOL=		ENABLE_VPX
XVIDEO_IMPLIES=		VIDEO
XVIDEO_USES=		xorg
XVIDEO_USE=		XORG=x11,xext,xfixes,xorgproto,xv
XVIDEO_CMAKE_BOOL=	ENABLE_X11 ENABLE_XV
XVIDEO_LDFLAGS=		-L${LOCALBASE}/lib -lX11

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} 's,gsm/gsm\.h,gsm.h,' \
		${WRKSRC}/cmake/FindGSM.cmake ${WRKSRC}/src/audiofilters/gsm.c
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${PATCH_WRKSRC}/CMakeLists.txt
.if ${CHOSEN_COMPILER_TYPE} == gcc
	@${REINPLACE_CMD} '/-Wno-format-truncation/d' ${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.post.mk>
