PORTNAME=	pjsip
DISTVERSION=	2.14.1
CATEGORIES=	net

MAINTAINER=	oliver.epper@gmail.com
COMMENT=	Multimedia communication library written in C language
WWW=		https://www.pjsip.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gmake localbase ssl pkgconfig
CPE_VENDOR=	teluu
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_PROJECT=	pjproject

GNU_CONFIGURE=	yes

PLIST_SUB=	CONFIGURE_TARGET="${CONFIGURE_TARGET}"

OPTIONS_DEFINE=	APPS DEBUG FFMPEG KQUEUE PA PJSUA2 RESAMPLEDLL SHARED SOUND \
		SRTP UPNP VIDEO WEBRTC YUV
OPTIONS_DEFAULT=G711 G722 KQUEUE OPUS PA PJSUA2 RESAMPLE SHARED SOUND SPEEX \
		SRTP VIDEO WEBRTC YUV
OPTIONS_GROUP=	CODECS
OPTIONS_GROUP_CODECS=	AMR BCG729 G711 G722 G7221 GSM ILBC L16 OPUS SILK \
			SPEEX SPEEXAEC
OPTIONS_SINGLE=	RESAMPLEIMP
OPTIONS_SINGLE_RESAMPLEIMP=	RESAMPLE SAMPLERATE SPEEXRESAMPLE NONE
OPTIONS_SUB=	yes

BCG729_DESC=		bcg729 codec support
CODECS_DESC=		Codecs & Echo Cancellation
G711_DESC=		G.711 codec support
G7221_DESC=		G.722.1 codec support
G722_DESC=		G.722 codec support
ILBC_DESC=		iLBC codec support
KQUEUE_DESC=		Use kqueue ioqueue on macos/BSD (experimental)
L16_DESC=		Linear/L16 codec support
PA_DESC=		Use external PortAudio development files
PJSUA2_DESC=		Enable pjsua2 library
PJSUA_DESC=		Command line SIP agent
RESAMPLEDLL_DESC=	Build libresample as a shared library
RESAMPLE_DESC=		Enable resampling implementations
APPS_DESC=		Install apps & samples from the pjsip-apps directory
SHARED_DESC=		Build shared libraries (other ports may depend on this)
SILK_DESC=		Enable SILK support
SOUND_DESC=		Include sound in the build
SPEEXAEC_DESC=		Speex Acoustic Echo Canceller/AEC
SPEEXRESAMPLE_DESC=	Enable Speex resample
SRTP_DESC=		Secure Real-Time Transport Protocol – SRTP support
WEBRTC_DESC=		Include libwebrtc in the build
YUV_DESC=		Include libyuv in the build
RESAMPLEIMP_DESC=	Resample Implementations
NONE_DESC=		Disable resampling implementations

# general options

DEBUG_CFLAGS=		-DNDEBUG=0
DEBUG_CFLAGS_OFF=	-DNDEBUG=1

FFMPEG_LIB_DEPENDS=	libswresample.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_OFF=	--disable-ffmpeg

# This can become KQUEUE_CONFIGURE_ENABLE once
# https://github.com/pjsip/pjproject/commit/c36802585ddefb3ca477d1f6d773d179510c5412
# is included in the next release (> 2.14.1).
KQUEUE_CONFIGURE_ON=	--enable-kqueue

PA_LIB_DEPENDS=		libportaudio.so:audio/portaudio
PA_CONFIGURE_ON=	--with-external-pa

PJSUA2_CONFIGURE_OFF=	--disable-pjsua2

RESAMPLE_CONFIGURE_ENABLE=	resample

RESAMPLEDLL_CONFIGURE_ENABLE=	resample-dll
RESAMPLEDLL_IMPLIES=		RESAMPLE

SAMPLERATE_LIB_DEPENDS=		libsamplerate.so:audio/libsamplerate
SAMPLERATE_CONFIGURE_ENABLE=	libsamplerate
SAMPLERATE_PREVENTS=		RESAMPLE RESAMPLEDLL
SAMPLERATE_PREVENTS_MSG=	SAMPLERATE will prevent RESAMPLE that is\
				implied by RESAMPLEDLL

SHARED_CONFIGURE_ENABLE=	shared
SHARED_PREVENTS=		RESAMPLEDLL
SHARED_PREVENTS_MSG=		When building shared libraries RESAMPLEDLL\
				has no effect.

SOUND_CONFIGURE_ENABLE=	sound

SRTP_LIB_DEPENDS=	libsrtp2.so:net/libsrtp2
SRTP_CONFIGURE_ENABLE=	libsrtp
SRTP_CONFIGURE_ON=	--with-external-srtp

UPNP_LIB_DEPENDS=	libupnp.so:devel/upnp
UPNP_CONFIGURE_OFF=	--disable-upnp

VIDEO_CONFIGURE_ENABLE=	video

WEBRTC_CONFIGURE_OFF=	--disable-libwebrtc

YUV_CONFIGURE_ENABLE=	libyuv
YUV_IMPLIES=		VIDEO

# Codecs
AMR_LIB_DEPENDS=	libopencore-amrwb.so:audio/opencore-amr \
			libvo-amrwbenc.so:audio/vo-amrwbenc
AMR_CONFIGURE_WITH=	opencore-amr

BCG729_CONFIGURE_ENABLE=bcg729

G711_CONFIGURE_ENABLE=	g711-codec

G7221_CONFIGURE_ENABLE=	g7221-codec

G722_CONFIGURE_ENABLE=	g722-codec

GSM_LIB_DEPENDS=	libgsm.so:audio/gsm
GSM_CONFIGURE_ENABLE=	gsm-codec
GSM_CONFIGURE_ON=	--with-external-gsm

ILBC_CONFIGURE_ENABLE=	ilbc-codec

L16_CONFIGURE_ENABLE=	l16-codec

OPUS_LIB_DEPENDS=	libopus.so:audio/opus
OPUS_CONFIGURE_OFF=	--disable-opus

SILK_CONFIGURE_ENABLE=	silk

SPEEX_LIB_DEPENDS=	libspeex.so:audio/speex \
			libspeexdsp.so:audio/speexdsp
SPEEX_CONFIGURE_ENABLE=	speex-codec
SPEEX_CONFIGURE_ON=	--with-external-speex

# Speex Echo Cancellation & Resampling
SPEEXAEC_CONFIGURE_ENABLE=	speex-aec
SPEEXAEC_IMPLIES=		SPEEX

SPEEXRESAMPLE_CONFIGURE_ENABLE=	speex-resample
SPEEXRESAMPLE_IMPLIES=		SPEEX
SPEEXRESAMPLE_PREVENTS=		RESAMPLE RESAMPLEDLL
SPEEXRESAMPLE_PREVENTS_MSG=	SPEEXRESAMPLE will prevent RESAMPLE that is\
				implied by RESAMPLEDLL

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/pkgconfig.py
	@${CP} ${FILESDIR}/config_site.h \
		${WRKSRC}/pjlib/include/pj/config_site.h

pre-build:
	@${MAKE_CMD} -C ${WRKSRC} dep
	@${MAKE_CMD} -C ${WRKSRC} clean

post-install-SHARED-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

post-install-APPS-on:
	${INSTALL_PROGRAM} \
		${WRKSRC}/pjsip-apps/bin/pjsua-${ARCH}-portbld-${OPSYS:tl}${OSREL} \
		${STAGEDIR}${PREFIX}/bin/pjsua
	${INSTALL_PROGRAM} \
		${WRKSRC}/pjsip-apps/bin/pjsystest-${ARCH}-portbld-${OPSYS:tl}${OSREL} \
		${STAGEDIR}${PREFIX}/bin/pjsystest
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/pjsip-apps/samples
	${INSTALL_PROGRAM} \
		${WRKSRC}/pjsip-apps/bin/samples/${ARCH}-portbld-${OPSYS:tl}${OSREL}/* \
		${STAGEDIR}${PREFIX}/libexec/pjsip-apps/samples/

.include <bsd.port.pre.mk>

# resample dso needs to be installed when either the dso is
# explicitely requested via RESAMPLEDLL which implies RESAMPLE,
# or when RESAMPLE is selected together with SHARED
RESAMPLE_DLL_OR_SHARED="@comment "

.if ${PORT_OPTIONS:MRESAMPLEDLL}
RESAMPLE_DLL_OR_SHARED=""
.endif

.if ${PORT_OPTIONS:MRESAMPLE} && ${PORT_OPTIONS:MSHARED}
RESAMPLE_DLL_OR_SHARED=""
.endif

PLIST_SUB+= RESAMPLE_DLL_OR_SHARED=${RESAMPLE_DLL_OR_SHARED}

.include <bsd.port.post.mk>
