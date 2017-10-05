# $FreeBSD$

PORTNAME=	pjsip
PORTVERSION=	2.7
CATEGORIES=	net
MASTER_SITES=	http://www.pjsip.org/release/${PORTVERSION}/
DISTNAME=	pjproject-${DISTVERSION}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Multimedia communication library written in C language

LICENSE=	GPLv2+

LIB_DEPENDS=	libportaudio.so:audio/portaudio

CONFLICTS=	pjsip-extsrtp-[0-9]* \
		libsrtp-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-external-pa \
		--disable-silk
USES=		gmake localbase pathfix ssl tar:bz2
PATHFIX_MAKEFILEIN=	Makefile
USE_LDCONFIG=	yes
PLIST_SUB=	CONFIGURE_TARGET="${CONFIGURE_TARGET}"
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DEBUG FFMPEG G711 G722 G7221 GSM ILBC IPV6 L16 \
		OPENH264 PJSUA RESAMPLE RESAMPLEDLL SAMPLERATE SDL \
		SHARED SPEEX SPEEXAEC V4L SOUND VIDEO AMR EXTSRTP WEBRTC
OPTIONS_DEFAULT=G711 G722 G7221 GSM ILBC L16 SHARED SPEEX SPEEXAEC

G711_DESC=	G.711 codec support
G722_DESC=	G.722 codec support
G7221_DESC=	G.722.1 codec support
ILBC_DESC=	iLBC codec support
L16_DESC=	Linear/L16 codec support
OPENH264_DESC=	OpenH264 support
PJSUA_DESC=	Command line SIP agent
RESAMPLE_DESC=	Enable resampling implementations
RESAMPLEDLL_DESC=	Build libresample as shared library
SHARED_DESC=	Build shared libraries (other ports may depend on this)
SPEEXAEC_DESC=	Speex Acoustic Echo Canceller/AEC
V4L_DESC=	Video4Linux2 support
YUV_DESC=	Libyuv support
EXTSRTP_DESC=	Use libsrtp port (needed to get SRTP support in asterisk13 pjsip backend)
WEBRTC_DESC=	Build linwebrtc

OPTIONS_SUB=	yes

DEBUG_CFLAGS=			-DNDEBUG=0
DEBUG_CFLAGS_OFF=		-DNDEBUG=1
FFMPEG_CONFIGURE_ENABLE=	ffmpeg
FFMPEG_LIB_DEPENDS=		libswresample.so:multimedia/ffmpeg
G711_CONFIGURE_ENABLE=		g711-codec
G722_CONFIGURE_ENABLE=		g722-codec
G7221_CONFIGURE_ENABLE=		g7221-codec
GSM_CONFIGURE_ENABLE=		gsm-codec
GSM_LIB_DEPENDS=		libgsm.so:audio/gsm
GSM_CONFIGURE_ON=		--with-external-gsm
ILBC_CONFIGURE_ENABLE=		ilbc-codec
IPV6_CFLAGS=			-DPJ_HAS_IPV6=1
IPV6_CFLAGS_OFF=		-DPJ_HAS_IPV6=1
L16_CONFIGURE_ENABLE=		l16-codec
OPENH264_CONFIGURE_ENABLE=	openh264
OPENH264_LIB_DEPENDS=		libopenh264.so:multimedia/openh264
RESAMPLE_CONFIGURE_ENABLE=	resample
RESAMPLEDLL_CONFIGURE_ENABLE=	resample-dll
SAMPLERATE_CONFIGURE_ENABLE=	libsamplerate
SAMPLERATE_LIB_DEPENDS=		libsamplerate.so:audio/libsamplerate
SDL_CONFIGURE_ENABLE=		sdl
SDL_USE=			SDL=sdl
SHARED_CONFIGURE_ENABLE=	shared
SPEEX_CONFIGURE_ENABLE=		speex-codec
SPEEX_CONFIGURE_ON=		--with-external-speex
SPEEX_LIB_DEPENDS=		libspeex.so:audio/speex \
				libspeexdsp.so:audio/speexdsp
SPEEXAEC_CONFIGURE_ENABLE=	speex-aec
V4L_CONFIGURE_ENABLE=		v4l2
V4L_BUILD_DEPENDS=		v4l_compat>=0:multimedia/v4l_compat
V4L_LIB_DEPENDS=		libv4l2.so:multimedia/libv4l
IPV6_CFLAGS=			"-DPJ_HAS_IPV6=1"
SOUND_CONFIGURE_ENABLE=		sound
VIDEO_CONFIGURE_ENABLE=		video
AMR_CONFIGURE_WITH=		opencore-amr
AMR_LIB_DEPENDS=		libopencore-amrwb.so:audio/opencore-amr \
				libvo-amrwbenc.so:audio/vo-amrwbenc
EXTSRTP_CONFIGURE_WITH=		external-srtp
EXTSRTP_LIB_DEPENDS=		libsrtp.so:net/libsrtp
WEBRTC_CONFIGURE_OFF=		--disable-libwebrtc

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/pkgconfig.py
	@${REINPLACE_CMD} -e 's/$$(APP_LDFLAGS) \{0,1\}//' \
		-e 's/$$(OS_LDFLAGS)/$$(APP_LDFLAGS) &/' \
		${WRKSRC}/*/build/Makefile
	@${ECHO} "#include <sys/select.h>" > ${WRKSRC}/pjlib/include/pj/config_site.h
	@${ECHO} "#define PJ_IOQUEUE_MAX_HANDLES (FD_SETSIZE)" >> ${WRKSRC}/pjlib/include/pj/config_site.h

post-install-SHARED-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

post-install-PJSUA-on:
	${INSTALL_PROGRAM} \
	${WRKSRC}/pjsip-apps/bin/pjsua-${ARCH}-portbld-${OPSYS:tl}${OSREL} \
	${STAGEDIR}${PREFIX}/bin/pjsua
	${INSTALL_PROGRAM} \
	${WRKSRC}/pjsip-apps/bin/pjsystest-${ARCH}-portbld-${OPSYS:tl}${OSREL} \
	${STAGEDIR}${PREFIX}/bin/pjsystest

.include <bsd.port.mk>
