# New ports collection makefile for:	opal3
# Date created:		Thu Feb 17 15:00:48 GMT 2000
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	opal3
PORTVERSION=	3.6.6
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	SF/opalvoip/v3.6%20Lalande/Stable%205
DISTNAME=	opal-${PORTVERSION}

MAINTAINER=	melifaro@ipfw.ru
COMMENT=	VoIP abstraction library

LIB_DEPENDS=	pt-2.6.[4-9]:${PORTSDIR}/devel/ptlib26

CONFLICTS=	opal-2.*

WRKSRC=		${WRKDIR}/opal-${PORTVERSION}

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_SLD=	yes
USE_LDCONFIG=	yes
#MAKE_JOBS_SAFE=	yes

CXXFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	ZRTP	"Enable ZRTP protocol support" off \
		JAVA	"Enable Java JNI support" off \
		CELT	"Use celt codec from ports" on \
		ILBC	"USE iLBC codec from ports" off \
		GSM	"Use GSM codec from ports" on \
		SPEEX	"Use SPEEX codec from ports" on \
		THEORA	"Enable theora  codec support" off \
		FFMPEG	"Enable ffmpeg codec support" on \
		X264	"Enable x.264 codec support" on \
		SIP	"Enable SIP protocol support" on \
		H323	"Enable H.323 protocol support" off \
		IAX	"Enable IAX2 protocol support" off \
		H224	"Enable H.224 control protocol" on \
		H281	"Enable H.281 (Far End Camera Control)" on \
		FAX	"Enable Fax T.38 support" on \
		MSRP	"Enable MSRP protocol" on \
		SIPIM	"Enable SIP-IM protocol" on \
		RTPTEXT	"Enable RFC4103 Text RTP payload" on \
		H450	"Enable H.450 H.323 subset" off \
		H460	"Enable H.460 H.323 extension for NAT traversal" off \
		H501	"Enable H.501 H323 mobility extensions" off \
		LID	"Enable LID (Light-Weight Identity) support" on \
		UVIDEO	"Enable RFC4175 uncompressed video RTP payload" off \
		AEC	"Enable accoustic echo cancellation" on

.include <bsd.port.pre.mk>

.ifdef OPALDIR
.error	OPALDIR is defined as an environment variable, or in the arguments \
		to "make".  Please unset it and restart the build.
.endif

PLIST_SUB+=	PORTVERSION=${PORTVERSION} \
		PVERSION_MAJOR=${PORTVERSION:C/.[0-9]+$//g}  \
		PVERSION_MINOR=${PORTVERSION:C/^[0-9]+.[0-9]+.//}

.if defined(WITH_ZRTP)
.if !defined(SAFE_ZRTP)
IGNORE=	please build devel/libzrtpcpp WITHOUT ports SSL and re-run build with SAFE_ZRTP set
.endif
LIB_DEPENDS+=	zrtpcpp.0:${PORTSDIR}/devel/libzrtpcpp
CONFIGURE_ARGS+=	--enable-zrtp
.else
CONFIGURE_ARGS+=	--disable-zrtp
.endif

.if defined(WITH_GSM)
LIB_DEPENDS+=	gsm.1:${PORTSDIR}/audio/gsm
.else
CONFIGURE_ARGS+=	--enable-localgsm
.endif

.if defined(WITH_SPEEX)
LIB_DEPENDS+=	speex.1:${PORTSDIR}/audio/speex
.else
CONFIGURE_ARGS+=	--enable-localspeex
.endif

.if defined(WITH_JAVA)
CONFIGURE_ARGS+=	--enable-java
.else
CONFIGURE_ARGS+=	--disable-java
.endif

.if defined(WITH_CELT)
LIB_DEPENDS+=	celt.0:${PORTSDIR}/audio/celt
CONFIGURE_ARGS+=	--enable-celt
PLIST_SUB+=	CELT=""
.else
CONFIGURE_ARGS+=	--disable-celt
PLIST_SUB+=	CELT="@comment "
.endif

.if defined(WITH_ILBC)
LIB_DEPENDS+=	ilbc.0:${PORTSDIR}/net/ilbc
.else
CONFIGURE_ARGS+=	--enable-localilbc
.endif

.if defined(WITH_THEORA)
LIB_DEPENDS+=	theora.0:${PORTSDIR}/multimedia/libtheora \
		ogg.6:${PORTSDIR}/audio/libogg
CONFIGURE_ARGS+=	--enable-theora
PLIST_SUB+=	THEORA=""
WITH_VIDEO=	yes
.else
CONFIGURE_ARGS+=	--disable-theora
PLIST_SUB+=	THEORA="@comment "
.endif

.if defined(WITH_X264)
LIB_DEPENDS+=	x264.85:${PORTSDIR}/multimedia/x264
CONFIGURE_ARGS+=	--enable-h264
PLIST_SUB+=	X264=""
WITH_VIDEO=	yes
.else
CONFIGURE_ARGS+=	--disable-h264
PLIST_SUB+=	X264="@comment "
.endif

.if defined(WITH_FFMPEG)
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+=	--enable-ffmpeg --enable-ffmpeg-h263
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

.if defined(WITH_SIP)
CONFIGURE_ARGS+=	--enable-sip
.else
CONFIGURE_ARGS+=	--disable-sip
.endif

.if defined(WITH_H323)
CONFIGURE_ARGS+=	--enable-h323
.else
CONFIGURE_ARGS+=	--disable-h323
.endif

.if defined(WITH_IAX)
CONFIGURE_ARGS+=	--enable-iax
.else
CONFIGURE_ARGS+=	--disable-iax
.endif

.if defined(WITH_H224)
CONFIGURE_ARGS+=	--enable-h224
.else
CONFIGURE_ARGS+=	--disable-h224
.endif

.if defined(WITH_H281)
CONFIGURE_ARGS+=	--enable-h281
.else
CONFIGURE_ARGS+=	--disable-h281
.endif

.if defined(WITH_FAX)
LIB_DEPENDS+=	spandsp.2:${PORTSDIR}/comms/spandsp-devel
CONFIGURE_ARGS+=	--enable-fax --enable-t38
PLIST_SUB+=	FAX=""
.else
CONFIGURE_ARGS+=	--disable-fax --disable-t38 --disable-spandsp
PLIST_SUB+=	FAX="@comment "
.endif

.if defined(WITH_MSRP)
CONFIGURE_ARGS+=	--enable-msrp
##BROKEN=			Does not compile
.else
CONFIGURE_ARGS+=	--disable-msrp
.endif

.if defined(WITH_SIPIM)
CONFIGURE_ARGS+=	--enable-sipim
.else
CONFIGURE_ARGS+=	--disable-sipim
.endif

.if defined(WITH_RTPTEXT)
CONFIGURE_ARGS+=	--enable-rfc4103
.else
CONFIGURE_ARGS+=	--disable-rfc4103
.endif

.if defined(WITH_H450)
CONFIGURE_ARGS+=	--enable-h450
.else
CONFIGURE_ARGS+=	--disable-h450
.endif

.if defined(WITH_H460)
CONFIGURE_ARGS+=	--enable-h460
.else
CONFIGURE_ARGS+=	--disable-h460
.endif

.if defined(WITH_H501)
CONFIGURE_ARGS+=	--enable-h501
.else
CONFIGURE_ARGS+=	--disable-h501
.endif

.if defined(WITH_LID)
CONFIGURE_ARGS+=	--enable-lid --enable-ixj --enable-vpb
PLIST_SUB+=	LID=""
.else
CONFIGURE_ARGS+=	--disable-lid --disable-ixj --disable-vpb
PLIST_SUB+=	LID="@comment "
.endif

.if defined(WITH_UVIDEO)
CONFIGURE_ARGS+=	--enable-rfc4175
.else
CONFIGURE_ARGS+=	--disable-rfc4175
.endif

.if defined(WITH_AEC)
CONFIGURE_ARGS+=	--enable-aec
.else
CONFIGURE_ARGS+=	--disable-aec
.endif

.if defined(WITH_DEBUG)
BROKEN=DEBUG: Not implemented
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

post-patch:
	@${REINPLACE_CMD} -e 's?-lopal?-lopal-${PORTVERSION:C/.[0-9]+$//g}?' ${WRKSRC}/opal.pc.in
	@${REINPLACE_CMD} -e 's?^LIBS="-lilbc?LIBS="-lilbc -lm?' ${WRKSRC}/plugins/configure
	@${REINPLACE_CMD} -e 's/^\(EXTRACCFLAGS.*\)/\1 -I\/usr\/local\/include/' ${WRKSRC}/plugins/*/*/Makefile.in
	@${REINPLACE_CMD} -e 's?^EXTRALIBS = $(GSM_LIBS)?EXTRALIBS = $(GSM_LIBS) -L/usr/local/lib?' ${WRKSRC}/plugins/audio/GSM0610/Makefile.in
	@${REINPLACE_CMD} -e 's?^EXTRALIBS = $(ILBC_LIBS)?EXTRALIBS = $(ILBC_LIBS) -L/usr/local/lib?' ${WRKSRC}/plugins/audio/iLBC/Makefile.in
	@${REINPLACE_CMD} -e 's?ILBC_CFLAGS=""?ILBC_CFLAGS="-L/usr/local/lib"?' ${WRKSRC}/plugins/configure
	@${REINPLACE_CMD} -e 's?^\(EXTRALIBS\)\(.*\)?\1\2 -L/usr/local/lib?' ${WRKSRC}/plugins/fax/fax_spandsp/Makefile.in
	@${REINPLACE_CMD} -e 's?/pkgconfig?data/pkgconfig?g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's?@@SO_VER@@?'${PORTVERSION:C/.[0-9]+$//g}'.so.'${PORTVERSION:C/^[0-9]+.[0-9]+.//}'?g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's?@@SO_MAJ@@?'${PORTVERSION:C/.[0-9]+$//g}'.so?g' ${WRKSRC}/Makefile.in
.if !defined(WITH_DEBUG)
	@${REINPLACE_CMD} -e 's/^\(all:\).*/\1 optdepend opt/' ${WRKSRC}/Makefile.in
.endif

post-configure:
	@${REINPLACE_CMD} -e 's?\$$(LIB_FILENAME_SHARED_PAT)?libopal-${PORTVERSION:C/.[0-9]+$//g}'.so.'${PORTVERSION:C/^[0-9]+.[0-9]+.//}?' ${WRKSRC}/opal_defs.mak

.include <bsd.port.post.mk>
