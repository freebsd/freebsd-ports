# New ports collection makefile for:	gmerlin
# Date created:		07 Nov 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gmerlin
PORTVERSION=	1.2.0
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multimedia framework

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		gavl.1:${PORTSDIR}/multimedia/gavl

OPTIONS_DEFINE= ALSA CDDB CDIO ESOUND JACK JPEG LIBVISUAL \
		OPTIMIZED_CFLAGS PNG PULSEAUDIO QUICKTIME \
		TIFF
OPTIONS_DEFAULT=	CDDB CDIO JACK JPEG LIBVISUAL \
		OPTIMIZED_CFLAGS PNG PULSEAUDIO QUICKTIME \
		TIFF

USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-v4l --disable-v4l2 --disable-v4lconvert \
		--without-doxygen --with-cpuflags=none --disable-musicbrainz
USE_GNOME=	gnomehack gtk20 libxml2
USE_XORG=	x11 xext xfixes xinerama xv
USE_GL=		gl
USE_LDCONFIG=	yes
INSTALL_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		gmerlin
MAN1=		gmerlin.1 \
		gmerlin_play.1 \
		gmerlin_remote.1 \
		gmerlin_transcoder.1 \
		gmerlin_transcoder_remote.1 \
		gmerlin-record.1

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
PLIST_SUB+=	ALSA=""
.else
CONFIGURE_ARGS+=--disable-alsa
PLIST_SUB+=	ALSA="@comment "
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
PLIST_SUB+=	PULSEAUDIO=""
.else
CONFIGURE_ARGS+=--disable-pulseaudio
PLIST_SUB+=	PULSEAUDIO="@comment "
.endif

.if ${PORT_OPTIONS:MQUICKTIME}
LIB_DEPENDS+=	quicktime.0:${PORTSDIR}/multimedia/libquicktime
PLIST_SUB+=	QUICKTIME=""
.else
CONFIGURE_ARGS+=--disable-lqt
PLIST_SUB+=	QUICKTIME="@comment "
.endif

.if ${PORT_OPTIONS:MLIBVISUAL}
LIB_DEPENDS+=	visual-0.4:${PORTSDIR}/graphics/libvisual04
.else
CONFIGURE_ARGS+=--disable-libvisual
.endif

.if ${PORT_OPTIONS:MCDIO}
LIB_DEPENDS+=	cdio.13:${PORTSDIR}/sysutils/libcdio
PLIST_SUB+=	CDIO=""
.else
CONFIGURE_ARGS+=--disable-libcdio
PLIST_SUB+=	CDIO="@comment "
.endif

.if ${PORT_OPTIONS:MCDDB}
LIB_DEPENDS+=	cddb.4:${PORTSDIR}/audio/libcddb
.else
CONFIGURE_ARGS+=--disable-cddb
.endif

.if ${PORT_OPTIONS:MESOUND}
LIB_DEPENDS+=	esd.2:${PORTSDIR}/audio/esound
PLIST_SUB+=	ESOUND=""
.else
CONFIGURE_ARGS+=--disable-esd
PLIST_SUB+=	ESOUND="@comment "
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
PLIST_SUB+=	JACK=""
.else
CONFIGURE_ARGS+=--disable-jack
PLIST_SUB+=	JACK="@comment "
.endif

.if ${PORT_OPTIONS:MJPEG}
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
PLIST_SUB+=	JPEG=""
.else
CONFIGURE_ARGS+=--disable-libjpeg
PLIST_SUB+=	JPEG="@comment "
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
PLIST_SUB+=	PNG=""
.else
CONFIGURE_ARGS+=--disable-libpng
PLIST_SUB+=	PNG="@comment "
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
PLIST_SUB+=	TIFF=""
.else
CONFIGURE_ARGS+=--disable-libtiff
PLIST_SUB+=	TIFF="@comment "
.endif

# applications
.if ${PORT_OPTIONS:MALSA}
PLIST_SUB+=	ALSAMIXER=""
.else
CONFIGURE_ARGS+=--disable-alsamixer
PLIST_SUB+=	ALSAMIXER="@comment "
.endif

# vendor ocflags from configure
.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -funroll-all-loops -fomit-frame-pointer -ffast-math
CXXFLAGS+=	-O3 -funroll-all-loops -fomit-frame-pointer -ffast-math
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-O3.*-ffast-math||g ; \
		 s|-DGTK_DISABLE_DEPRECATED||g ; \
		 /LIBS/ s|-ldl||g ; \
		 s|^LDFLAGS="|&$${LDFLAGS} |g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|-ldl||g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g ; \
		 /^LIBS = / s|$$| @LIBINTL@ ${PTHREAD_LIBS}|g' \
		${WRKSRC}/lib/Makefile.am ${WRKSRC}/lib/Makefile.in \
		${WRKSRC}/tests/Makefile.am ${WRKSRC}/tests/Makefile.in \
		${WRKSRC}/apps/*/Makefile.am ${WRKSRC}/apps/*/Makefile.in
	@${REINPLACE_CMD} -e \
		 's|^texinfo_|#texinfo_|g' ${WRKSRC}/doc/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
