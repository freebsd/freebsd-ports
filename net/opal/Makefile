# Created by: Roger Hardiman <roger@FreeBSD.org>
# $FreeBSD$

PORTNAME=	opal
PORTVERSION=	3.10.10
PORTREVISION=	18
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VoIP abstraction library

LICENSE=	MPL10

LIB_DEPENDS=	libpt.so:devel/ptlib

USES=		gmake pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CXXFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	JAVA CELT ILBC GSM SPEEX THEORA FFMPEG X264 SIP H323 IAX \
		H224 H281 FAX MSRP SIPIM RTPTEXT H450 H460 H501 LID UVIDEO \
		AEC DEBUG RUBY
# ZRTP
# MSRP = plist extra line vpd?
# RTPTEXT disable == build fail, so make it default?
OPTIONS_DEFAULT=CELT GSM SPEEX FFMPEG X264 SIP H224 H281 FAX MSRP SIPIM \
		RTPTEXT LID AEC
DEBUG_DESC=	Install debug library
ZRTP_DESC=	ZRTP protocol support
JAVA_DESC=	Java JNI support
RUBY_DESC=	Ruby support
CELT_DESC=	Celt codec from ports
ILBC_DESC=	iLBC codec from ports
GSM_DESC=	GSM 06.10 codec from ports
SPEEX_DESC=	SPEEX codec from ports
THEORA_DESC=	Theora codec support
FFMPEG_DESC=	Ffmpeg codec support
X264_DESC=	x.264 codec support
SIP_DESC=	SIP protocol support
H323_DESC=	H.323 protocol support
IAX_DESC=	IAX2 protocol support
H224_DESC=	H.224 control protocol
H281_DESC=	H.281 (Far End Camera Control) protocol support
FAX_DESC=	Fax T.38 support
MSRP_DESC=	MSRP protocol
SIPIM_DESC=	SIP-IM protocol
RTPTEXT_DESC=	RFC4103 Text RTP payload support
H450_DESC=	H.450 H.323 subset
H460_DESC=	H.460 H.323 extension for NAT traversal
H501_DESC=	H.501 H323 mobility extensions
LID_DESC=	Light-Weight Identity (incl. xJack cards and voicetronix vpb) support
UVIDEO_DESC=	RFC4175 uncompressed video RTP payload
AEC_DESC=	Accoustic echo cancellation

.include <bsd.port.options.mk>

.ifdef OPALDIR
.error	OPALDIR is defined as an environment variable, or in the arguments \
		to "make".  Please unset it and restart the build.
.endif

PLIST_SUB+=	VERSION=${PORTVERSION} \
		PVERSION_MAJOR=${PVERSION_MAJOR} \
		PVERSION_MINOR=${PVERSION_MINOR}

PVERSION_MAJOR=	${PORTVERSION:C/.[0-9]+.[0-9]+$//g}
PVERSION_MINOR=	${PORTVERSION:C/.[0-9]+$//g}

.if ${PORT_OPTIONS:MDEBUG}
ALL_TARGET=	debug opt
PLIST_SUB+=	DEBUG=""
.else
ALL_TARGET=	opt
PLIST_SUB+=	DEBUG="@comment "
.endif

# libzrtpcpp uses port ssl, which will conflict with this port since we use
# base ssl.
#.if ${PORT_OPTIONS:MZRTP}
.if 0
.if !defined(SAFE_ZRTP)
IGNORE=	please build devel/libzrtpcpp WITHOUT ports SSL and re-run build with SAFE_ZRTP set
.endif
LIB_DEPENDS+=	libzrtpcpp.so:devel/libzrtpcpp
CONFIGURE_ARGS+=	--enable-zrtp
.else
CONFIGURE_ARGS+=	--disable-zrtp
.endif

.if ${PORT_OPTIONS:MGSM}
LIB_DEPENDS+=	libgsm.so:audio/gsm
.else
CONFIGURE_ARGS+=	--enable-localgsm
.endif

.if ${PORT_OPTIONS:MSPEEX}
LIB_DEPENDS+=	libspeex.so:audio/speex
.else
CONFIGURE_ARGS+=	--enable-localspeex
.endif

.if ${PORT_OPTIONS:MJAVA}
CONFIGURE_ARGS+=	--enable-java
.else
CONFIGURE_ARGS+=	--disable-java
.endif

.if ${PORT_OPTIONS:MRUBY}
CONFIGURE_ARGS+=	--enable-ruby
.else
CONFIGURE_ARGS+=	--disable-ruby
.endif

.if ${PORT_OPTIONS:MCELT}
LIB_DEPENDS+=	libcelt0.so:audio/celt
CONFIGURE_ARGS+=	--enable-celt
PLIST_SUB+=	CELT=""
.else
CONFIGURE_ARGS+=	--disable-celt
PLIST_SUB+=	CELT="@comment "
.endif

.if ${PORT_OPTIONS:MILBC}
LIB_DEPENDS+=	libilbc.so:net/ilbc
.else
CONFIGURE_ARGS+=	--enable-localilbc
.endif

.if ${PORT_OPTIONS:MTHEORA}
LIB_DEPENDS+=	libtheora.so:multimedia/libtheora
CONFIGURE_ARGS+=	--enable-theora
PLIST_SUB+=	THEORA=""
WITH_VIDEO=	yes
.else
CONFIGURE_ARGS+=	--disable-theora
PLIST_SUB+=	THEORA="@comment "
.endif

.if ${PORT_OPTIONS:MX264} && ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	libx264.so:multimedia/libx264
CONFIGURE_ARGS+=	--enable-x264
PLIST_SUB+=	X264=""
WITH_VIDEO=	yes
# work around some weirdness in plugins/configure where it looses the
# cflags/libs of x264
CONFIGURE_ENV+=	X264_CFLAGS="`pkg-config --cflags x264`" \
		X264_LIBS="`pkg-config --libs x264`"
.else
CONFIGURE_ARGS+=	--disable-x264
PLIST_SUB+=	X264="@comment "
.endif

.if ${PORT_OPTIONS:MFFMPEG}
BUILD_DEPENDS+=		ffmpeg>=2:multimedia/ffmpeg
RUN_DEPENDS+=		ffmpeg>=2:multimedia/ffmpeg
CONFIGURE_ARGS+=	--enable-libavcodec
PLIST_SUB+=	FFMPEG=""
WITH_VIDEO=	yes
.else
CONFIGURE_ARGS+=	--disable-libavcodec
PLIST_SUB+=	FFMPEG="@comment "
.endif

WITH_VIDEO=yes
.if defined(WITH_VIDEO)
CONFIGURE_ARGS+=	--enable-video
PLIST_SUB+=	VIDEO=""
.else
CONFIGURE_ARGS+=	--disable-video
PLIST_SUB+=	VIDEO="@comment "
.endif

.if ${PORT_OPTIONS:MSIP}
CONFIGURE_ARGS+=	--enable-sip
.else
CONFIGURE_ARGS+=	--disable-sip
.endif

.if ${PORT_OPTIONS:MH323}
CONFIGURE_ARGS+=	--enable-h323
.else
CONFIGURE_ARGS+=	--disable-h323
.endif

.if ${PORT_OPTIONS:MIAX}
CONFIGURE_ARGS+=	--enable-iax2
.else
CONFIGURE_ARGS+=	--disable-iax2
.endif

.if ${PORT_OPTIONS:MH224}
CONFIGURE_ARGS+=	--enable-h224
.else
CONFIGURE_ARGS+=	--disable-h224
.endif

.if ${PORT_OPTIONS:MH281}
CONFIGURE_ARGS+=	--enable-h281
.else
CONFIGURE_ARGS+=	--disable-h281
.endif

.if ${PORT_OPTIONS:MFAX}
LIB_DEPENDS+=		libspandsp.so:comms/spandsp
CONFIGURE_ARGS+=	--enable-spandsp --enable-fax --enable-t38
PLIST_SUB+=	FAX=""
.else
CONFIGURE_ARGS+=	--disable-fax --disable-t38 --disable-spandsp
PLIST_SUB+=	FAX="@comment "
.endif

.if ${PORT_OPTIONS:MMSRP}
CONFIGURE_ARGS+=	--enable-msrp
##BROKEN=			Does not compile
.else
CONFIGURE_ARGS+=	--disable-msrp
.endif

.if ${PORT_OPTIONS:MSIPIM}
CONFIGURE_ARGS+=	--enable-sipim
.else
CONFIGURE_ARGS+=	--disable-sipim
.endif

.if ${PORT_OPTIONS:MRTPTEXT}
CONFIGURE_ARGS+=	--enable-rfc4103
.else
CONFIGURE_ARGS+=	--disable-rfc4103
.endif

.if ${PORT_OPTIONS:MH450}
CONFIGURE_ARGS+=	--enable-h450
.else
CONFIGURE_ARGS+=	--disable-h450
.endif

.if ${PORT_OPTIONS:MH460}
CONFIGURE_ARGS+=	--enable-h460
.else
CONFIGURE_ARGS+=	--disable-h460
.endif

.if ${PORT_OPTIONS:MH501}
CONFIGURE_ARGS+=	--enable-h501
.else
CONFIGURE_ARGS+=	--disable-h501
.endif

.if ${PORT_OPTIONS:MLID}
CONFIGURE_ARGS+=	--enable-lid --enable-ixj --enable-vpb
PLIST_SUB+=	LID=""
.else
CONFIGURE_ARGS+=	--disable-lid --disable-ixj --disable-vpb
PLIST_SUB+=	LID="@comment "
.endif

.if ${PORT_OPTIONS:MUVIDEO}
CONFIGURE_ARGS+=	--enable-rfc4175
.else
CONFIGURE_ARGS+=	--disable-rfc4175
.endif

# xxxx
.if ${PORT_OPTIONS:MXXXX}
CONFIGURE_ARGS+=	--enable-rfc2435
.else
CONFIGURE_ARGS+=	--disable-rfc2435
.endif

.if ${PORT_OPTIONS:MAEC}
CONFIGURE_ARGS+=	--enable-aec
.else
CONFIGURE_ARGS+=	--disable-aec
.endif

# ??
CONFIGURE_ARGS+=	--disable-debug

# configure flags not used
CONFIGURE_ARGS+=	--disable-gsmamr \
			--disable-ruby

post-install:
	${LN} -sf libopal.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libopal.so.${PVERSION_MAJOR}
	${LN} -sf libopal.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libopal.so.${PVERSION_MINOR}
.if ${PORT_OPTIONS:MDEBUG}
	${LN} -sf libopal_d.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libopal_d.so.${PVERSION_MAJOR}
	${LN} -sf libopal_d.so.${PORTVERSION} ${STAGEDIR}${PREFIX}/lib/libopal_d.so.${PVERSION_MINOR}
.endif
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libopal.so.${PORTVERSION}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/opal-${PORTVERSION}/codecs/video/h264_video_pwplugin_helper
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/opal-${PORTVERSION}/*/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/opal-${PORTVERSION}/*/*/*.so

.include <bsd.port.mk>
