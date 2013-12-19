# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mjpegtools
PORTVERSION=	2.0.0
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME:S/tools//}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Set of tools to record/playback/edit videos in MPEG format

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg

OPTIONS_DEFINE=	GTK2 SDL PNG DV QUICKTIME SIMD DOCS
OPTIONS_DEFAULT=GTK2 SDL PNG
QUICKTIME_DESC=		Enable libQuickTime support

CONFLICTS=	mplex-[0-9]*

USES=		gmake pkgconfig
USE_AUTOTOOLS=	libtoolize aclocal autoheader automake autoconf
LIBTOOLIZE_ARGS=--force
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKEL_ARGS=	--add-missing --foreign
CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		ac_cv_lib_Xxf86dga_XF86DGAQueryExtension=no
CONFIGURE_ARGS=	--without-x
USE_LDCONFIG=	yes

INFO=		mjpeg-howto

DOC_FILES=	AUTHORS BUGS CHANGES ChangeLog HINTS NEWS PLANS README \
		README.DV README.avilib README.glav README.AltiVec \
		README.lavpipe README.transist TODO

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

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
LIB_DEPENDS+=	libpng15.so:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=--with-libpng
PLIST_SUB+=	PNG:=""
.else
CONFIGURE_ARGS+=--without-libpng
PLIST_SUB+=	PNG:="@comment "
.endif # PNG

.if ${PORT_OPTIONS:MDV}
LIB_DEPENDS+=	libdv.so:${PORTSDIR}/multimedia/libdv
CONFIGURE_ARGS+=--with-libdv
.else
CONFIGURE_ARGS+=--without-libdv
.endif # DV

.if ${PORT_OPTIONS:MQUICKTIME}
PLIST_SUB+=	QUICKTIME=""
LIB_DEPENDS+=	libquicktime.so:${PORTSDIR}/multimedia/libquicktime
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
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
