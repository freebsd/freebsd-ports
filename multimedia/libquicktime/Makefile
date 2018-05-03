# Created by: ijliao
# $FreeBSD$

PORTNAME=	libquicktime
PORTVERSION=	1.2.4
PORTREVISION?=	20
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	library for reading and writing quicktime files

.if !defined(_BUILDING_LIBQUICKTIME_PLUGINS)
LIB_DEPENDS=	libvorbis.so:audio/libvorbis
.endif

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USE_LDCONFIG=	yes
USES=		gettext gmake libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lintl
INSTALL_TARGET=	install-strip

.if !defined(_BUILDING_LIBQUICKTIME_PLUGINS)
USE_XORG=	xaw xv
CONFIGURE_ARGS=	--with-x --enable-gpl --without-doxygen --without-lame

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
LIB_DEPENDS=	libasound.so:audio/alsa-lib
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
LIB_DEPENDS+=	libdv.so:multimedia/libdv
CONFIGURE_ARGS+=	--with-libdv
.else
CONFIGURE_ARGS+=	--without-libdv
.endif

.if ${PORT_OPTIONS:MJPEG}
USES+=		jpeg
CONFIGURE_ARGS+=	--with-libjpeg
.else
CONFIGURE_ARGS+=	--without-libjpeg
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	libpng.so:graphics/png
CONFIGURE_ARGS+=	--with-libpng
.else
CONFIGURE_ARGS+=	--without-libpng
.endif

.if ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	libavcodec.so:multimedia/ffmpeg
CONFIGURE_ARGS+=	--with-ffmpeg
.else
CONFIGURE_ARGS+=	--without-ffmpeg
.endif

.if ${PORT_OPTIONS:MFAAC}
LIB_DEPENDS+=	libfaac.so:audio/faac
CONFIGURE_ARGS+=	--with-faac
.else
CONFIGURE_ARGS+=	--without-faac
.endif

.if ${PORT_OPTIONS:MFAAD}
LIB_DEPENDS+=	libfaad.so:audio/faad
CONFIGURE_ARGS+=	--with-faad2
.else
CONFIGURE_ARGS+=	--without-faad2
.endif

.if ${PORT_OPTIONS:MX264}
LIB_DEPENDS+=	libx264.so:multimedia/libx264
CONFIGURE_ARGS+=	--with-x264
.else
CONFIGURE_ARGS+=	--without-x264
.endif

.if ${PORT_OPTIONS:MSCHROEDINGER}
LIB_DEPENDS+=	libschroedinger-1.0.so:multimedia/schroedinger
.else
CONFIGURE_ARGS+=	--without-schroedinger
.endif

.endif

post-patch:
	@${REINPLACE_CMD} 's/-DGTK_DISABLE_DEPRECATED//' ${WRKSRC}/configure

.if ${PORT_OPTIONS:MDOCS} && !defined(_BUILDING_LIBQUICKTIME_PLUGINS)
post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
