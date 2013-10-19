# Created by: ijliao
# $FreeBSD$

PORTNAME=	libquicktime
PORTVERSION=	1.2.4
PORTREVISION?=	5
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	library for reading and writing quicktime files

.if !defined(_BUILDING_LIBQUICKTIME_PLUGINS)
LIB_DEPENDS=	libvorbis.so:${PORTSDIR}/audio/libvorbis
.endif

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USE_LDCONFIG=	yes
USES=		gmake pathfix pkgconfig gettext
USE_AUTOTOOLS=	autoconf

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} -lintl

CFLAGS+=	-fPIC
.if !defined(_BUILDING_LIBQUICKTIME_PLUGINS)
USE_XORG=	xaw xv
CONFIGURE_ARGS=	--with-x --enable-gpl --without-doxygen --without-lame
MAN1=		lqtplay.1

OPTIONS_DEFINE=	ALSA DV FAAC FAAD FFMPEG GTK2 JPEG OPENGL OPTIMIZED_CFLAGS PNG \
		SCHROEDINGER X264 DOCS
OPTIONS_DEFAULT=	FFMPEG JPEG OPENGL PNG SCHROEDINGER X264
OPTIONS_SUB=	yes

PORTDOCS=	api_usage.html codecs.html qt4l_building.html \
		qt4l_codecs.html qt4l_index.html \
		qt4l_license.html qt4l_opening.html qt4l_positioning.html \
		qt4l_reading.html qt4l_util.html qt4l_writing.html

.else
CONFIGURE_ARGS+=	--without-x --enable-gpl --without-doxygen
OPTIONS_DEFINE=	OPTIMIZED_CFLAGS
.endif

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CONFIGURE_ARGS+=	--without-cpuflags
.endif

.if !defined(_BUILDING_LIBQUICKTIME_PLUGINS)
.if ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=	--with-gtk
.else
CONFIGURE_ARGS+=	--without-gtk
.endif

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
.else
CONFIGURE_ARGS+=	--without-alsa
.endif

.if ${PORT_OPTIONS:MOPENGL}
USE_GL=		yes
CONFIGURE_ARGS+=	--with-opengl
.else
CONFIGURE_ARGS+=	--without-opengl
.endif

.if ${PORT_OPTIONS:MDV}
LIB_DEPENDS+=	libdv.so:${PORTSDIR}/multimedia/libdv
CONFIGURE_ARGS+=	--with-libdv
.else
CONFIGURE_ARGS+=	--without-libdv
.endif

.if ${PORT_OPTIONS:MJPEG}
LIB_DEPENDS+=	libjpeg.so:${PORTSDIR}/graphics/jpeg
CONFIGURE_ARGS+=	--with-libjpeg
.else
CONFIGURE_ARGS+=	--without-libjpeg
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	libpng15.so:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=	--with-libpng
.else
CONFIGURE_ARGS+=	--without-libpng
.endif

.if ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg
CONFIGURE_ARGS+=	--with-ffmpeg
.else
CONFIGURE_ARGS+=	--without-ffmpeg
.endif

.if ${PORT_OPTIONS:MFAAC}
LIB_DEPENDS+=	libfaac.so:${PORTSDIR}/audio/faac
CONFIGURE_ARGS+=	--with-faac
.else
CONFIGURE_ARGS+=	--without-faac
.endif

.if ${PORT_OPTIONS:MFAAD}
LIB_DEPENDS+=	libfaad.so:${PORTSDIR}/audio/faad
CONFIGURE_ARGS+=	--with-faad2
.else
CONFIGURE_ARGS+=	--without-faad2
.endif

.if ${PORT_OPTIONS:MX264}
LIB_DEPENDS+=	libx264.so:${PORTSDIR}/multimedia/x264
CONFIGURE_ARGS+=	--with-x264
.else
CONFIGURE_ARGS+=	--without-x264
.endif

.if ${PORT_OPTIONS:MSCHROEDINGER}
LIB_DEPENDS+=	libschroedinger-1.0.so:${PORTSDIR}/multimedia/schroedinger
.else
CONFIGURE_ARGS+=	--without-schroedinger
.endif

.endif

AUTOTOOLSFILES=	aclocal.m4

post-patch:
	@${REINPLACE_CMD} -e 's|2.64|%%AUTOCONF_VERSION%%|g' ${WRKSRC}/aclocal.m4
	@${REINPLACE_CMD} -e 's|stdint.h|inttypes.h|' \
		${WRKSRC}/plugins/audiocodec/* \
		${WRKSRC}/plugins/videocodec/*
	@${REINPLACE_CMD} -E -e 's|objformat=aout|objformat=elf|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-DG.*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure*

pre-configure:
	@${CHMOD} +x ${WRKSRC}/configure

.if ${PORT_OPTIONS:MDOCS} && !defined(_BUILDING_LIBQUICKTIME_PLUGINS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
