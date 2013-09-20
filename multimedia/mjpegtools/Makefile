# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mjpegtools
PORTVERSION=	2.0.0
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME:S/tools//}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Set of tools to record/playback/edit videos in MPEG format

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg

OPTIONS_DEFINE=	GTK2 SDL PNG DV QUICKTIME SIMD DOCS
OPTIONS_DEFAULT=GTK2 SDL PNG
QUICKTIME_DESC=		Enable libQuickTime support

CONFLICTS=	mplex-[0-9]*

USES=		pkgconfig
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtoolize aclocal autoheader automake autoconf
LIBTOOLIZE_ARGS=--force
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKEL_ARGS=	--add-missing --foreign
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		ac_cv_lib_Xxf86dga_XF86DGAQueryExtension=no
CONFIGURE_ARGS=	--without-x
USE_LDCONFIG=	yes

MAN1=		jpeg2yuv.1 lav2mpeg.1 lav2wav.1 lav2yuv.1 lavpipe.1 lavplay.1 \
		lavrec.1 lavtrans.1 mjpegtools.1 mp2enc.1 mpeg2enc.1 mplex.1 \
		pgmtoy4m.1 png2yuv.1 pnmtoy4m.1 ppmtoy4m.1 y4mcolorbars.1 \
		y4mdenoise.1 y4munsharp.1 y4mtopnm.1 y4mtoppm.1 yuv2lav.1 \
		yuvdenoise.1 yuvfps.1 yuvinactive.1 yuvkineco.1 \
		yuvmedianfilter.1 yuvplay.1 yuvscaler.1 yuvycsnoise.1
MAN5=		yuv4mpeg.5
INFO=		mjpeg-howto

DOC_FILES=	AUTHORS BUGS CHANGES ChangeLog HINTS NEWS PLANS README \
		README.DV README.avilib README.glav README.AltiVec \
		README.lavpipe README.transist TODO

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}

.if empty(PORT_OPTIONS:MSDL)
IGNORE=		GTK+2 player needs SDL
.endif # GTK2/SDL

USE_GNOME+=	gtk20
PLIST_SUB+=	GTK2:=""
.else
PLIST_SUB+=	GTK2:="@comment "
CONFIGURE_ARGS+=--without-gtk
.endif # GTK2

.if ${PORT_OPTIONS:MSDL}
USE_SDL+=	gfx sdl
PLIST_SUB+=	SDL:=""
.else
CONFIGURE_ENV+=	ac_cv_path_SDL_CONFIG=no
PLIST_SUB+=	SDL:="@comment "
CONFIGURE_ARGS+=--without-libsdl
.endif # SDL

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=--with-libpng
PLIST_SUB+=	PNG:=""
.else
CONFIGURE_ARGS+=--without-libpng
PLIST_SUB+=	PNG:="@comment "
.endif # PNG

.if ${PORT_OPTIONS:MDV}
LIB_DEPENDS+=	dv:${PORTSDIR}/multimedia/libdv
CONFIGURE_ARGS+=--with-libdv
.else
CONFIGURE_ARGS+=--without-libdv
.endif # DV

.if ${PORT_OPTIONS:MQUICKTIME}
PLIST_SUB+=	QUICKTIME=""
LIB_DEPENDS+=	quicktime:${PORTSDIR}/multimedia/libquicktime
CONFIGURE_ARGS+=--with-libquicktime
.else
PLIST_SUB+=	QUICKTIME="@comment "
CONFIGURE_ARGS+=--without-libquicktime
.endif # QUICKTIME

.if ${PORT_OPTIONS:MSIMD}
CONFIGURE_ARGS+=--enable-simd-accel
.else
CONFIGURE_ARGS+=--disable-simd-accel
.endif # SIMD

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CFLAGS:=	${CFLAGS:N-O*:N-fno-strict*}
.endif

.if ${ARCH} == "powerpc" && ${OSVERSION} > 900000
BROKEN=		Does not build on powerpc-9
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/ARCHFLAGS=/s|^|#|g' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e \
		'/^pkgconfigdir/s|$$(libdir)|$$(prefix)/libdata|g' ${WRKSRC}/Makefile.am

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif # NOPORTDOCS

.include <bsd.port.post.mk>
