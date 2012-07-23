# New ports collection makefile for:	gmerlin-avdecoder
# Date created:		07 Nov 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gmerlin-avdecoder
PORTVERSION=	1.2.0
CATEGORIES=	multimedia
MASTER_SITES=	SF/gmerlin/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose media decoding library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/linux/dvb/frontend.h:${PORTSDIR}/multimedia/v4l_compat \
		pkg-config>0:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS=	gavl.1:${PORTSDIR}/multimedia/gavl

OPTIONS_DEFINE=	A52 CDIO DCA DVDREAD FAAD FFMPEG FLAC GMERLIN MAD \
		MJPEGTOOLS MPEG2 MUSEPACK OPENJPEG OPTIMIZED_CFLAGS PNG \
		SAMBA SCHROEDINGER SPEEX THEORA TIFF VDPAU VORBIS
OPTIONS_DEFAULT=	A52 CDIO DCA DVDREAD FAAD FFMPEG FLAC GMERLIN MAD \
		MJPEGTOOLS MPEG2 MUSEPACK OPENJPEG OPTIMIZED_CFLAGS PNG \
		SAMBA SCHROEDINGER SPEEX THEORA TIFF VDPAU VORBIS
DVDREAD_DESC=	libdvdread support
GMERLIN_DESC=	gmerlin support
SAMBA_DESC=	Samba support using libsmbclient

USE_GNOME=	gnomehack
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cpuflags=none --without-doxygen
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MGMERLIN}
LIB_DEPENDS+=	gmerlin.0:${PORTSDIR}/multimedia/gmerlin
PLIST_SUB+=	GMERLIN=""
.else
CONFIGURE_ARGS+=--disable-gmerlin
PLIST_SUB+=	GMERLIN="@comment "
.endif

.if ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg
.else
CONFIGURE_ARGS+=--disable-libavcodec --disable-libpostproc --disable-libswscale --disable-libavformat
.endif

.if ${PORT_OPTIONS:MTHEORA}
LIB_DEPENDS+=	theora.0:${PORTSDIR}/multimedia/libtheora
.else
CONFIGURE_ARGS+=--disable-theoradec
.endif

.if ${PORT_OPTIONS:MSPEEX}
LIB_DEPENDS+=	speex.1:${PORTSDIR}/audio/speex
.else
CONFIGURE_ARGS+=--disable-speex
.endif

.if ${PORT_OPTIONS:MJPEGTOOLS}
LIB_DEPENDS+=	lavjpeg-2.0.0:${PORTSDIR}/multimedia/mjpegtools
.else
CONFIGURE_ARGS+=--disable-mjpegtools
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=--with-vorbis=${LOCALBASE}
.else
CONFIGURE_ARGS+=--disable-vorbis
.endif

.if ${PORT_OPTIONS:MMPEG2}
LIB_DEPENDS+=	mpeg2.0:${PORTSDIR}/multimedia/libmpeg2
.else
CONFIGURE_ARGS+=--disable-libmpeg2
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
.else
CONFIGURE_ARGS+=--disable-libtiff
.endif

.if ${PORT_OPTIONS:MSAMBA}
LIB_DEPENDS+=	smbclient.0:${PORTSDIR}/net/samba-libsmbclient
.else
CONFIGURE_ARGS+=--disable-samba
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
.else
CONFIGURE_ARGS+=--disable-libpng
.endif

.if ${PORT_OPTIONS:MFAAD}
LIB_DEPENDS+=	faad.2:${PORTSDIR}/audio/faad
.else
CONFIGURE_ARGS+=--disable-faad2
.endif

.if ${PORT_OPTIONS:MDVDREAD}
LIB_DEPENDS+=	dvdread.4:${PORTSDIR}/multimedia/libdvdread
PLIST_SUB+=	DVDREAD=""
.else
CONFIGURE_ARGS+=--disable-dvdread
PLIST_SUB+=	DVDREAD="@comment "
.endif

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac
.else
CONFIGURE_ARGS+=--disable-flac
.endif

.if ${PORT_OPTIONS:MMUSEPACK}
LIB_DEPENDS+=	mpcdec.7:${PORTSDIR}/audio/musepack
.else
CONFIGURE_ARGS+=--disable-musepack
.endif

.if ${PORT_OPTIONS:MMAD}
LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad
.else
CONFIGURE_ARGS+=--disable-mad
.endif

.if ${PORT_OPTIONS:MA52}
LIB_DEPENDS+=	a52.0:${PORTSDIR}/audio/liba52
.else
CONFIGURE_ARGS+=--disable-liba52
.endif

.if ${PORT_OPTIONS:MDCA}
LIB_DEPENDS+=	dca.0:${PORTSDIR}/multimedia/libdca
.else
# error in configure
CONFIGURE_ARGS+=--disable-libcda --disable-libdca
.endif

.if ${PORT_OPTIONS:MCDIO}
LIB_DEPENDS+=	cdio.13:${PORTSDIR}/sysutils/libcdio
PLIST_SUB+=	CDIO=""
.else
CONFIGURE_ARGS+=--disable-libcdio
PLIST_SUB+=	CDIO="@comment "
.endif

.if ${PORT_OPTIONS:MOPENJPEG}
LIB_DEPENDS+=	openjpeg.2:${PORTSDIR}/graphics/openjpeg
.else
CONFIGURE_ARGS+=--disable-openjpeg
.endif

.if ${PORT_OPTIONS:MSCHROEDINGER}
LIB_DEPENDS+=	schroedinger-1.0.11:${PORTSDIR}/multimedia/schroedinger
.else
CONFIGURE_ARGS+=--disable-schroedinger
.endif

.if ${PORT_OPTIONS:MVDPAU}
LIB_DEPENDS+=	vdpau.1:${PORTSDIR}/multimedia/libvdpau
.else
CONFIGURE_ARGS+=	--disable-vdpau
.endif

# vendor ocflags from configure
.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -funroll-all-loops -ffast-math
CXXFLAGS+=	-O3 -funroll-all-loops -ffast-math
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-O3 -funroll-all-loops -ffast-math||g; \
		 /LIBS/ s|-ldl||g; \
		 s|^LDFLAGS="|&$${LDFLAGS} |' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|#if DVDREAD_VERSION < 905|#if DVDREAD_VERSION < 904|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/^LIBS = / s|$$| @LIBINTL@ -lz|' ${WRKSRC}/tests/Makefile.in
	@${REINPLACE_CMD} -e \
		's|malloc.h|stdlib.h|' ${WRKSRC}/lib/in_smb.c

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
