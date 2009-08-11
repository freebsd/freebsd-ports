# Ports collection makefile for:	libquicktime
# Date Created:			Jul 17, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libquicktime
PORTVERSION=	1.1.3
CATEGORIES=	multimedia
MASTER_SITES=	SFE

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	A library for reading and writing quicktime files

LIB_DEPENDS=	vorbis.4:${PORTSDIR}/audio/libvorbis

USE_LDCONFIG=	yes
USE_GNOME=	gnometarget gnomehack pkgconfig
USE_XORG=	xaw xv
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS} -lintl"
CONFIGURE_ARGS=	--with-x --enable-gpl --without-doxygen
CFLAGS+=	-fPIC
MAN1=		lqtplay.1

OPTIONS=	LAME "Enable Lame mp3 encoding support" Off \
		OPENGL "Enable OpenGL support" On \
		DV "Enable libdv support for digital cameras" On \
		JPEG "Enable JPEG support" On \
		PNG "Enable PNG support" On \
		FFMPEG "Enable FFmpeg support" On \
		FAAC "Enable FAAC support" Off \
		FAAD "Enable FAAD support" On \
		X264 "Enable X264 codec support" On \
		SCHROEDINGER "Enable dirac support" On \
		GTK2 "Enable Gtk+2 Frontend" Off \
		OPTIMIZED_CFLAGS "Enable Optimized CFLAGS" Off

PORTDOCS=	api_usage.html codecs.html qt4l_building.html \
		qt4l_codecs.html qt4l_index.html \
		qt4l_license.html qt4l_opening.html qt4l_positioning.html \
		qt4l_reading.html qt4l_util.html qt4l_writing.html

.include <bsd.port.pre.mk>

.if !defined(WITH_OPTIMIZED_CFLAGS)
CONFIGURE_ARGS+=	--without-cpuflags
.endif

.if ${HAVE_GNOME:Mgtk20}!="" && defined(WITH_GTK2)
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=	--with-gtk
PLIST_SUB+=	GTK=""
.else
CONFIGURE_ARGS+=	--without-gtk
PLIST_SUB+=	GTK="@comment "
.endif

.if defined(WITH_LAME)
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame
PLIST_SUB+=	LAME=""
CONFIGURE_ARGS+=	--with-lame
.else
PLIST_SUB+=	LAME="@comment "
CONFIGURE_ARGS+=	--without-lame
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
LIB_DEPENDS+=	jpeg.10:${PORTSDIR}/graphics/jpeg
PLIST_SUB+=	JPEG=""
CONFIGURE_ARGS+=	--with-libjpeg
.else
PLIST_SUB+=	JPEG="@comment "
CONFIGURE_ARGS+=	--without-libjpeg
.endif

.if !defined(WITHOUT_PNG)
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
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
LIB_DEPENDS+=	x264.65:${PORTSDIR}/multimedia/x264
PLIST_SUB+=	X264=""
CONFIGURE_ARGS+=	--with-x264
.else
PLIST_SUB+=	X264="@comment "
CONFIGURE_ARGS+=	--without-x264
.endif

.if !defined(WITHOUT_SCHROEDINGER)
LIB_DEPENDS+=	schroedinger-1.0.2:${PORTSDIR}/multimedia/schroedinger
PLIST_SUB+=	SCHROEDINGER=""
.else
PLIST_SUB+=	SCHROEDINGER="@comment "
CONFIGURE_ARGS+=	--without-schroedinger
.endif

.if ${MACHINE_CPU:Mmmx}
CONFIGURE_ARGS+=	--enable-mmx
.else
CONFIGURE_ARGS+=	--disable-mmx
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
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

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
