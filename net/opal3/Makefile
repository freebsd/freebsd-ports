# Created by: Roger Hardiman <roger@freebsd.org>
# $FreeBSD$

PORTNAME=	opal3
PORTVERSION=	3.6.6
PORTREVISION=	17
CATEGORIES=	net
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S|3||g}/${PORTVERSION:R}
DISTNAME=	opal-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VoIP abstraction library

LICENSE=	MPL

LIB_DEPENDS=	pt-2.6.[4-9]:${PORTSDIR}/devel/ptlib26

CONFLICTS=	opal-2.*

WRKSRC=		${WRKDIR}/opal-${PORTVERSION}

USE_GCC=	any
USE_BZIP2=	yes
USES=		pathfix gmake pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CXXFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	ZRTP JAVA CELT ILBC GSM SPEEX THEORA FFMPEG X264 SIP H323 IAX \
		H224 H281 FAX MSRP SIPIM RTPTEXT H450 H460 H501 LID UVIDEO AEC
OPTIONS_DEFAULT=CELT GSM SPEEX FFMPEG X264 SIP H224 H281 FAX MSRP SIPIM \
		RTPTEXT LID AEC
ZRTP_DESC=	ZRTP protocol support
JAVA_DESC=	Java JNI support
CELT_DESC=	Celt codec from ports
ILBC_DESC=	iLBC codec from ports
GSM_DESC=	GSM codec from ports
SPEEX_DESC=	SPEEX codec from ports
THEORA_DESC=	Theora  codec support
FFMPEG_DESC=	Ffmpeg codec support
X264_DESC=	x.264 codec support
SIP_DESC=	SIP protocol support
H323_DESC=	H.323 protocol support
IAX_DESC=	IAX2 protocol support
H224_DESC=	H.224 control protocol
H281_DESC=	H.281 (Far End Camera Control)
FAX_DESC=	Fax T.38 support
MSRP_DESC=	MSRP protocol
SIPIM_DESC=	SIP-IM protocol
RTPTEXT_DESC=	RFC4103 Text RTP payload
H450_DESC=	H.450 H.323 subset
H460_DESC=	H.460 H.323 extension for NAT traversal
H501_DESC=	H.501 H323 mobility extensions
LID_DESC=	LID (Light-Weight Identity) support
UVIDEO_DESC=	RFC4175 uncompressed video RTP payload
AEC_DESC=	Accoustic echo cancellation

.include <bsd.port.options.mk>

.ifdef OPALDIR
.error	OPALDIR is defined as an environment variable, or in the arguments \
		to "make".  Please unset it and restart the build.
.endif

PLIST_SUB+=	PORTVERSION=${PORTVERSION} \
		PVERSION_MAJOR=${PORTVERSION:C/.[0-9]+$//g}  \
		PVERSION_MINOR=${PORTVERSION:C/^[0-9]+.[0-9]+.//}

.if ${PORT_OPTIONS:MZRTP}
.if !defined(SAFE_ZRTP)
IGNORE=	please build devel/libzrtpcpp WITHOUT ports SSL and re-run build with SAFE_ZRTP set
.endif
LIB_DEPENDS+=	zrtpcpp:${PORTSDIR}/devel/libzrtpcpp
CONFIGURE_ARGS+=	--enable-zrtp
.else
CONFIGURE_ARGS+=	--disable-zrtp
.endif

.if ${PORT_OPTIONS:MGSM}
LIB_DEPENDS+=	gsm:${PORTSDIR}/audio/gsm
.else
CONFIGURE_ARGS+=	--enable-localgsm
.endif

.if ${PORT_OPTIONS:MSPEEX}
LIB_DEPENDS+=	speex:${PORTSDIR}/audio/speex
.else
CONFIGURE_ARGS+=	--enable-localspeex
.endif

.if ${PORT_OPTIONS:MJAVA}
CONFIGURE_ARGS+=	--enable-java
.else
CONFIGURE_ARGS+=	--disable-java
.endif

.if ${PORT_OPTIONS:MCELT}
LIB_DEPENDS+=	celt0:${PORTSDIR}/audio/celt
CONFIGURE_ARGS+=	--enable-celt
PLIST_SUB+=	CELT=""
.else
CONFIGURE_ARGS+=	--disable-celt
PLIST_SUB+=	CELT="@comment "
.endif

.if ${PORT_OPTIONS:MILBC}
LIB_DEPENDS+=	ilbc:${PORTSDIR}/net/ilbc
.else
CONFIGURE_ARGS+=	--enable-localilbc
.endif

.if ${PORT_OPTIONS:MTHEORA}
LIB_DEPENDS+=	theora:${PORTSDIR}/multimedia/libtheora \
		ogg:${PORTSDIR}/audio/libogg
CONFIGURE_ARGS+=	--enable-theora
PLIST_SUB+=	THEORA=""
WITH_VIDEO=	yes
.else
CONFIGURE_ARGS+=	--disable-theora
PLIST_SUB+=	THEORA="@comment "
.endif

.if ${PORT_OPTIONS:MX264}
LIB_DEPENDS+=	x264:${PORTSDIR}/multimedia/x264
CONFIGURE_ARGS+=	--enable-h264
PLIST_SUB+=	X264=""
WITH_VIDEO=	yes
.else
CONFIGURE_ARGS+=	--disable-h264
PLIST_SUB+=	X264="@comment "
.endif

.if ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	avcodec:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+=	--enable-ffmpeg --enable-ffmpeg-h263
CONFIGURE_ENV+=		ac_cv_lib_avcodec_h263p_encoder=yes \
			ac_cv_lib_avcodec_h264_decoder=yes \
			ac_cv_lib_avcodec_mpeg4_encoder=yes
PLIST_SUB+=	FFMPEG=""
WITH_VIDEO=	yes
.else
CONFIGURE_ARGS+=	--disable-ffmpeg --disable-ffmpeg-h263
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
CONFIGURE_ARGS+=	--enable-iax
.else
CONFIGURE_ARGS+=	--disable-iax
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

# keep version in lib_depend, to see the difference between spandsp-devel and normal
.if ${PORT_OPTIONS:MFAX}
LIB_DEPENDS+=	spandsp.2:${PORTSDIR}/comms/spandsp-devel
CONFIGURE_ARGS+=	--enable-fax --enable-t38
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

.if ${PORT_OPTIONS:MAEC}
CONFIGURE_ARGS+=	--enable-aec
.else
CONFIGURE_ARGS+=	--disable-aec
.endif

CONFIGURE_ARGS+=	--disable-debug

post-patch:
	@${REINPLACE_CMD} -e 's?-lopal?-lopal-${PORTVERSION:C/.[0-9]+$//g}?' ${WRKSRC}/opal.pc.in
	@${REINPLACE_CMD} -e 's?^LIBS="-lilbc?LIBS="-lilbc -lm?' ${WRKSRC}/plugins/configure
	@${REINPLACE_CMD} -e 's/^\(EXTRACCFLAGS.*\)/\1 -I\/usr\/local\/include/' ${WRKSRC}/plugins/*/*/Makefile.in
	@${REINPLACE_CMD} -e 's?^EXTRALIBS = $(GSM_LIBS)?EXTRALIBS = $(GSM_LIBS) -L/usr/local/lib?' ${WRKSRC}/plugins/audio/GSM0610/Makefile.in
	@${REINPLACE_CMD} -e 's?^EXTRALIBS = $(ILBC_LIBS)?EXTRALIBS = $(ILBC_LIBS) -L/usr/local/lib?' ${WRKSRC}/plugins/audio/iLBC/Makefile.in
	@${REINPLACE_CMD} -e 's?ILBC_CFLAGS=""?ILBC_CFLAGS="-L/usr/local/lib"?' ${WRKSRC}/plugins/configure
	@${REINPLACE_CMD} -e 's?^\(EXTRALIBS\)\(.*\)?\1\2 -L/usr/local/lib?' ${WRKSRC}/plugins/fax/fax_spandsp/Makefile.in
	@${REINPLACE_CMD} -e 's?@@SO_VER@@?'${PORTVERSION:C/.[0-9]+$//g}'.so.'${PORTVERSION:C/^[0-9]+.[0-9]+.//}'?g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's?@@SO_MAJ@@?'${PORTVERSION:C/.[0-9]+$//g}'.so?g' ${WRKSRC}/Makefile.in
.if ! ${PORT_OPTIONS:MDEBUG}
	@${REINPLACE_CMD} -e 's/^\(all:\).*/\1 optdepend opt/' ${WRKSRC}/Makefile.in
.endif

post-configure:
	@${REINPLACE_CMD} -e 's?\$$(LIB_FILENAME_SHARED_PAT)?libopal-${PORTVERSION:C/.[0-9]+$//g}'.so.'${PORTVERSION:C/^[0-9]+.[0-9]+.//}?' ${WRKSRC}/opal_defs.mak

.include <bsd.port.mk>
