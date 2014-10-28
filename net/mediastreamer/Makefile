# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mediastreamer
PORTVERSION=	2.10.0
PORTREVISION=	7
CATEGORIES=	net
MASTER_SITES=	SAVANNAH/linphone/mediastreamer

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Real-time audio and video streaming and processing

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libortp.so:${PORTSDIR}/net/ortp

CONFLICTS_INSTALL=	linphone-base-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-alsa --disable-pulseaudio \
		--disable-silent-rules --disable-strict \
		--with-gsm=${LOCALBASE} xxd_found=yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
USES=		gmake libtool pathfix pkgconfig
USE_GNOME=	intlhack
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		IPV6 NLS UPNP VIDEO
OPTIONS_GROUP=		AUDIOOPT VIDEOOPT
OPTIONS_GROUP_AUDIOOPT=	GSM OPUS SPANDSP SPEEX
OPTIONS_GROUP_VIDEOOPT=	FFMPEG GLX THEORA V4L VPX XVIDEO
OPTIONS_DEFAULT=	UPNP VIDEO \
			GSM OPUS SPANDSP SPEEX \
			FFMPEG GLX THEORA V4L VPX XVIDEO
OPTIONS_SUB=		yes

AUDIOOPT_DESC=		Audio options

FFMPEG_CONFIGURE_ENABLE=ffmpeg
FFMPEG_LIB_DEPENDS=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg

GLX_CONFIGURE_ENABLE=	glx
GLX_USE=		GL=glew

GSM_CONFIGURE_ENABLE=	gsm
GSM_LIB_DEPENDS=	libgsm.so:${PORTSDIR}/audio/gsm

IPV6_CONFIGURE_ENABLE=	ipv6

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

OPUS_CONFIGURE_ENABLE=	opus
OPUS_LIB_DEPENDS=	libopus.so:${PORTSDIR}/audio/opus

SPANDSP_CONFIGURE_ENABLE=	spandsp
SPANDSP_LIB_DEPENDS=	libspandsp.so.2:${PORTSDIR}/comms/spandsp-devel

SPEEX_CONFIGURE_ENABLE=	speex
SPEEX_LIB_DEPENDS=	libspeex.so:${PORTSDIR}/audio/speex

THEORA_CONFIGURE_ENABLE=theora
THEORA_LIB_DEPENDS=	libtheora.so:${PORTSDIR}/multimedia/libtheora

UPNP_CONFIGURE_ENABLE=	upnp
UPNP_LIB_DEPENDS=	libupnp.so:${PORTSDIR}/devel/upnp

V4L_CONFIGURE_ENABLE=	libv4l1 libv4l2
V4L_BUILD_DEPENDS=	v4l_compat>=1.0.20120501:${PORTSDIR}/multimedia/v4l_compat
V4L_LIB_DEPENDS=	libv4l2.so:${PORTSDIR}/multimedia/libv4l

VIDEOOPT_DESC=		Video options

VIDEO_CONFIGURE_ENABLE=	video

VPX_CONFIGURE_ENABLE=	vp8
VPX_LIB_DEPENDS=	libvpx.so:${PORTSDIR}/multimedia/libvpx

XVIDEO_CONFIGURE_ENABLE=x11 xv
XVIDEO_USE=		XORG=videoproto,x11,xv

.if defined(WITH_DEBUG) && !defined(WITHOUT_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif

post-patch:
	@${REINPLACE_CMD} 's,gsm/gsm\.h,gsm.h,' \
		${WRKSRC}/configure ${WRKSRC}/src/audiofilters/gsm.c

pre-build:
# Transform file to C array (similar to xxd -i from editors/vim)
.for i in yuv2rgb.fs yuv2rgb.vs
	(cd ${WRKSRC}/src && { \
		${ECHO_CMD} 'unsigned char ${i:S/./_/}[] = {' && \
		/usr/bin/hexdump -v -e '" " 12/1 " 0x%02x," "\n" \
		"  0x00 };\nunsigned int ${i:S/./_/}_len = %_Ad;"' ${i} | \
		${SED} 's/ 0x  ,//g' ; } > ${i}.h)
.endfor

.include <bsd.port.mk>
