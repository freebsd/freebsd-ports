# Ports collection makefile for:	libquicktime
# Date Created:			Jul 17, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libquicktime
PORTVERSION=	1.1.5
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	mm@FreeBSD.org
COMMENT=	A library for reading and writing quicktime files

.if !defined(_BUILDING_LIBQUICKTIME_PLUGINS)
LIB_DEPENDS=	vorbis.4:${PORTSDIR}/audio/libvorbis
.endif

USE_LDCONFIG=	yes
USE_GNOME=	gnometarget gnomehack pkgconfig
USE_GMAKE=	yes
USE_GETTEXT=	yes
MAKE_JOBS_SAFE=	yes
USE_AUTOTOOLS=	autoconf:262

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}"
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS} -lintl"

CFLAGS+=	-fPIC
.if !defined(_BUILDING_LIBQUICKTIME_PLUGINS)
USE_XORG=	xaw xv
CONFIGURE_ARGS=	--with-x --enable-gpl --without-doxygen --without-lame
MAN1=		lqtplay.1

OPTIONS=	OPENGL "Enable OpenGL support" On \
		DV "Enable libdv support for digital cameras" On \
		JPEG "Enable JPEG support" On \
		PNG "Enable PNG support" On \
		FFMPEG "Enable FFmpeg support" On \
		FAAC "Enable FAAC support" Off \
		FAAD "Enable FAAD support" On \
		X264 "Enable X264 codec support" On \
		X264_DEV "Require X264 from multimedia/x264-devel" Off \
		SCHROEDINGER "Enable dirac support" On \
		GTK2 "Enable Gtk+2 Frontend" Off \
		OPTIMIZED_CFLAGS "Enable Optimized CFLAGS" Off

PORTDOCS=	api_usage.html codecs.html qt4l_building.html \
		qt4l_codecs.html qt4l_index.html \
		qt4l_license.html qt4l_opening.html qt4l_positioning.html \
		qt4l_reading.html qt4l_util.html qt4l_writing.html

.else
CONFIGURE_ARGS+=	--without-x --enable-gpl --without-doxygen
OPTIONS=	OPTIMIZED_CFLAGS "Enable Optimized CFLAGS" Off
.endif

.include <bsd.port.pre.mk>

.if !defined(WITH_OPTIMIZED_CFLAGS)
CONFIGURE_ARGS+=	--without-cpuflags
.endif

.if !defined(_BUILDING_LIBQUICKTIME_PLUGINS)
.if ${HAVE_GNOME:Mgtk20}!="" && defined(WITH_GTK2)
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=	--with-gtk
PLIST_SUB+=	GTK=""
.else
CONFIGURE_ARGS+=	--without-gtk
PLIST_SUB+=	GTK="@comment "
.endif

.if !defined(WITHOUT_OPENGL)
USE_GL=		yes
CONFIGURE_ARGS+=	--with-opengl
.else
CONFIGURE_ARGS+=	--without-opengl
.endif

.if !defined(WITHOUT_DV)
LIB_DEPENDS+=	dv.4:${PORTSDIR}/multimedia/libdv
PLIST_SUB+=	DV=""
CONFIGURE_ARGS+=	--with-libdv
.else
PLIST_SUB+=	DV="@comment "
CONFIGURE_ARGS+=	--without-libdv
.endif

.if !defined(WITHOUT_JPEG)
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
PLIST_SUB+=	JPEG=""
CONFIGURE_ARGS+=	--with-libjpeg
.else
PLIST_SUB+=	JPEG="@comment "
CONFIGURE_ARGS+=	--without-libjpeg
.endif

.if !defined(WITHOUT_PNG)
LIB_DEPENDS+=	png.6:${PORTSDIR}/graphics/png
PLIST_SUB+=	PNG=""
CONFIGURE_ARGS+=	--with-libpng
.else
PLIST_SUB+=	PNG="@comment "
CONFIGURE_ARGS+=	--without-libpng
.endif

.if !defined(WITHOUT_FFMPEG)
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg
PLIST_SUB+=	FFMPEG=""
CONFIGURE_ARGS+=	--with-ffmpeg
.else
PLIST_SUB+=	FFMPEG="@comment "
CONFIGURE_ARGS+=	--without-ffmpeg
.endif

.if defined(WITH_FAAC)
LIB_DEPENDS+=	faac.0:${PORTSDIR}/audio/faac
PLIST_SUB+=	FAAC=""
CONFIGURE_ARGS+=	--with-faac
.else
PLIST_SUB+=	FAAC="@comment "
CONFIGURE_ARGS+=	--without-faac
.endif

.if !defined(WITHOUT_FAAD)
LIB_DEPENDS+=	faad.2:${PORTSDIR}/audio/faad
PLIST_SUB+=	FAAD=""
CONFIGURE_ARGS+=	--with-faad2
.else
PLIST_SUB+=	FAAD="@comment "
CONFIGURE_ARGS+=	--without-faad2
.endif

.if !defined(WITHOUT_X264)
PLIST_SUB+=	X264=""
CONFIGURE_ARGS+=	--with-x264

# Automatically choose the multimedia/x264-devel port if installed
. if !defined(WITH_X264_DEV)
.  if exists(${LOCALBASE}/include/x264.h)
X264_BUILD!=    ${GREP} "define X264_BUILD .." ${LOCALBASE}/include/x264.h | ${AWK} '{ print $$3 }'
.   if ${X264_BUILD} == "93"
_WANT_X264_DEVEL=       yes
.   endif
.  endif
. else
_WANT_X264_DEVEL=yes
. endif
. if defined(_WANT_X264_DEVEL)
LIB_DEPENDS+=	x264.93:${PORTSDIR}/multimedia/x264-devel
. else
LIB_DEPENDS+=	x264.85:${PORTSDIR}/multimedia/x264
. endif
.else
PLIST_SUB+=	X264="@comment "
CONFIGURE_ARGS+=	--without-x264
.endif

.if !defined(WITHOUT_SCHROEDINGER)
LIB_DEPENDS+=	schroedinger-1.0.3:${PORTSDIR}/multimedia/schroedinger
PLIST_SUB+=	SCHROEDINGER=""
.else
PLIST_SUB+=	SCHROEDINGER="@comment "
CONFIGURE_ARGS+=	--without-schroedinger
.endif

.endif

post-patch:
	@${REINPLACE_CMD} -e 's|2.61|2.62|g' ${WRKSRC}/aclocal.m4
	@${REINPLACE_CMD} -e 's|stdint.h|inttypes.h|' \
		${WRKSRC}/plugins/audiocodec/* \
		${WRKSRC}/plugins/videocodec/*
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-DG.*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure*

pre-configure:
	@${CHMOD} +x ${WRKSRC}/configure

.if !defined(NOPORTDOCS) && !defined(_BUILDING_LIBQUICKTIME_PLUGINS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
