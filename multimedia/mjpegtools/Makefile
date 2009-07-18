# New ports collection makefile for:	mjpegtools
# Date created:		Wed May 29 21:12:38 UTC 2002
# Whom:	          Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mjpegtools
DISTVERSION=	1.9.0rc3
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	SF/mjpeg

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Set of tools to record/playback/edit videos in MPEG format

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

CONFLICTS=	mplex-[0-9]*

WANT_SDL=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget
WANT_GNOME=	yes
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

INFO=		mjpeg-howto
MAN1=		jpeg2yuv.1 lav2mpeg.1 lav2wav.1 lav2yuv.1 lavpipe.1 lavplay.1 \
		lavrec.1 lavtrans.1 mjpegtools.1 mp2enc.1 mpeg2enc.1 mplex.1 \
		pgmtoy4m.1 png2yuv.1 pnmtoy4m.1 ppmtoy4m.1 y4mcolorbars.1 \
		y4mdenoise.1 y4munsharp.1 y4mtopnm.1 y4mtoppm.1 yuv2lav.1 \
		yuvdenoise.1 yuvfps.1 yuvinactive.1 yuvkineco.1 \
		yuvmedianfilter.1 yuvplay.1 yuvscaler.1 yuvycsnoise.1
MAN5=		yuv4mpeg.5
DOC_FILES=	AUTHORS BUGS CHANGES COPYING ChangeLog HINTS NEWS PLANS README \
		README.DV README.avilib README.glav README.AltiVec \
		README.lavpipe README.transist TODO

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PNG)
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=--with-libpng
PLIST_SUB+=	PNG:=""
.else
CONFIGURE_ARGS+=--without-libpng
PLIST_SUB+=	PNG:="@comment "
.endif

.if !defined(WITHOUT_X11)
USE_XORG=	x11
CONFIGURE_ARGS+=--with-x
.else
CONFIGURE_ARGS+=--without-x
WITHOUT_DV=	yes
WITHOUT_GTK2=	yes
WITHOUT_SDL=	yes
WITHOUT_QUICKTIME=yes
.endif

.if exists(${LOCALBASE}/lib/libdv.so)
WITH_DV=	yes
.endif

.if exists(${LOCALBASE}/lib/libquicktime.so.0)
WITH_QUICKTIME=	yes
.endif

.if (${HAVE_GNOME:Mgtk20}!="" || defined(WITH_GTK2)) && !defined(WITHOUT_GTK2)
USE_GNOME+=	gtk20
PLIST_SUB+=	GTK2:=""
ENABLE_GTK2=	yes
.else
PLIST_SUB+=	GTK2:="@comment "
DISABLE_GTK2=	yes
.endif

# The GTK player required SDL support, so add ENABLE_GTK2 in here.
.if (${HAVE_SDL:Msdl}!="" || defined(WITH_SDL)) && (!defined(WITHOUT_SDL) || defined(ENABLE_GTK2))
USE_SDL+=	sdl
PLIST_SUB+=	SDL:=""
.else
PLIST_SUB+=	SDL:="@comment "
DISABLE_SDL=	yes
.endif

.if defined(WITH_DV) && !defined(WITHOUT_DV)
LIB_DEPENDS+=	dv.4:${PORTSDIR}/multimedia/libdv
CONFIGURE_ARGS+=--with-libdv
.else
CONFIGURE_ARGS+=--without-libdv
.endif

.if defined(WITH_QUICKTIME) && !defined(WITHOUT_QUICKTIME)
LIB_DEPENDS+=	quicktime.0:${PORTSDIR}/multimedia/libquicktime
CONFIGURE_ARGS+=--with-libquicktime
.else
#CONFIGURE_ARGS+=--without-libquicktime # Does not work, patch it instead...
DISABLE_QUICKTIME=yes
.endif

pre-everything::
	@${ECHO_MSG} "You may specify the following on the command line:"
	@${ECHO_MSG} " "
.if !defined(WITH_DV)
	@${ECHO_MSG} "WITH_DV=yes to enable DV support."
.endif
.if !defined(WITH_GTK2)
	@${ECHO_MSG} "WITH_GTK2=yes to enable GTK+2 support (required SDL)."
.endif
.if !defined(WITH_QUICKTIME)
	@${ECHO_MSG} "WITH_QUICKTIME=yes to enable quicktime support."
.endif
.if !defined(WITH_SDL)
	@${ECHO_MSG} "WITH_SDL=yes to enable SDL support."
.endif
.if !defined(WITHOUT_PNG)
	@${ECHO_MSG} "WITHOUT_PNG=yes to disable png support."
.endif
.if !defined(WITHOUT_X11)
	@${ECHO_MSG} "WITHOUT_X11=yes to disable X11 (included DV, GTK2, QUICKTIME and SDL) support."
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-l$$flag|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure
.if defined(DISABLE_GTK2)
	@${REINPLACE_CMD} -e 's|have_gtk="true"|have_gtk="false"|g' \
		${WRKSRC}/configure
.endif
.if defined(DISABLE_QUICKTIME)
	@${REINPLACE_CMD} -e 's|have_libquicktime=true|have_libquicktime=false|g' \
		${WRKSRC}/configure
.endif
.if defined(DISABLE_SDL)
	@${REINPLACE_CMD} -e 's|have_sdl=true|have_sdl=false|g' \
		${WRKSRC}/configure
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/mpeg2enc/mpeg2syntaxcodes.h ${PREFIX}/include/mjpegtools/mpeg2enc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
