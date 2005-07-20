# New ports collection makefile for:	mjpegtools
# Date created:		Wed May 29 21:12:38 UTC 2002
# Whom:	          Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mjpegtools
DISTVERSION=	1.6.3-rc1
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mjpeg

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Set of tools to record/playback/edit videos in MPEG format

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

CONFLICTS=	mplex-*
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
USE_GNOME=	gnomehack gnometarget
WANT_GNOME=	yes
WANT_SDL=	yes
INSTALLS_SHLIB=	yes

INFO=	mjpeg-howto
MAN1=	jpeg2yuv.1 lav2mpeg.1 lav2wav.1 lav2yuv.1 \
	lavpipe.1 lavplay.1 lavrec.1 lavtrans.1 mjpegtools.1 mp2enc.1 \
	mpeg2enc.1 mplex.1 pgmtoy4m.1 png2yuv.1 pnmtoy4m.1 ppmtoy4m.1 \
	y4mcolorbars.1 y4mdenoise.1 y4munsharp.1 y4mtopnm.1 y4mtoppm.1 \
	yuv2lav.1 yuvdenoise.1 yuvfps.1 yuvinactive.1 yuvkineco.1 \
	yuvmedianfilter.1 yuvplay.1 yuvscaler.1 yuvycsnoise.1
MAN5=	yuv4mpeg.5

DOC_FILES=	AUTHORS BUGS CHANGES COPYING ChangeLog HINTS NEWS \
		PLANS README README.DV README.avilib README.glav \
		README.AltiVec \
		README.lavpipe README.transist TODO

PORTDOCS=	${DOC_FILES}

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" || ${ARCH} == "amd64"
.if !defined(WITHOUT_AVIFILE) && !defined(PACKAGE_BUILDING)
LIB_DEPENDS+=	aviplay.0:${PORTSDIR}/multimedia/avifile
.endif
.endif

.if ${ARCH} == "i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
.endif

# pre-detection
# JPEGMMX
.if exists(${LOCALBASE}/lib/libjpeg-mmx.a)
WITH_JPEGMMX=	yes
.endif
# LIBDV
.if exists(${LOCALBASE}/lib/libdv.a)
WITH_LIBDV=	yes
.endif
# LIBGNUGETOPT
# -CURRENT after 500041 has getopt_long
.if ${OSVERSION} < 500041
WITH_LIBGNUGETOPT=	yes
.endif
# LIBMOVTAR
.if exists(${LOCALBASE}/lib/libmovtar.a)
WITH_LIBMOVTAR=	yes
.endif
# QUICKTIME
.if exists(${LOCALBASE}/lib/libquicktime.so.0)
WITH_QUICKTIME=	yes
.endif
# SDL
.if ${HAVE_SDL}:Msdl}!=""
WITH_SDL=	yes
.endif

# option activation
.if ${HAVE_GNOME:Mgtk12}!=""
USE_GNOME+=	gtk12
PLIST_SUB+=	GTK=""
.else
PLIST_SUB+=	GTK="@comment "
.endif
#
.ifdef(WITH_JPEGMMX)
LIB_DEPENDS+=	jpeg-mmx.62:${PORTSDIR}/graphics/jpeg-mmx
.else
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg
.endif
#
.ifdef(WITH_LIBDV)
LIB_DEPENDS+=	dv.4:${PORTSDIR}/multimedia/libdv

CONFIGURE_ARGS+=	--with-dv=${LOCALBASE}
.endif
#
.ifdef(WITH_LIBDV_PAL)
CONFIGURE_ARGS+=	--with-dv-yv12

WITH_LIBDV=	yes
.endif
#
.ifdef(WITH_LIBGNUGETOPT)
USE_GETOPT_LONG=	yes
.endif
#
.ifdef(WITH_LIBMOVTAR)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmovtar.a:${PORTSDIR}/multimedia/libmovtar

CONFIGURE_ARGS+=	--with-movtar-prefix=${LOCALBASE}
.endif
#
.ifdef(WITH_SDL)
USE_SDL=	sdl
CONFIGURE_ARGS+=	--with-sdl
.endif
#
.ifdef(WITH_QUICKTIME)
LIB_DEPENDS+=	quicktime.0:${PORTSDIR}/multimedia/libquicktime

CONFIGURE_ARGS+=	--with-quicktime
.endif

pre-everything::
.if ${HAVE_GNOME:Mgtk12}==""
	@${ECHO_MSG} "====> You can enable GTK support by defining WITH_GNOME"
.endif
.ifndef(WITH_JPEGMMX)
	@${ECHO_MSG} "====> You can enable Jpeg-MMX support by defining WITH_JPEGMMX"
.endif
.ifndef(WITH_LIBDV)
	@${ECHO_MSG} "====> You can enable DV support by defining WITH_LIBDV"
.endif
.ifndef(WITH_LIBDV_PAL)
	@${ECHO_MSG} "====> You can enable DV PAL support by defining WITH_LIBDV_PAL"
.endif
.ifndef(WITH_LIBMOVTAR)
	@${ECHO_MSG} "====> You can enable movtar support by defining WITH_LIBMOVTAR"
.endif
.ifndef(WITH_QUICKTIME)
	@${ECHO_MSG} "====> You can enable quicktime support by defining WITH_QUICKTIME"
.endif
.ifndef(WITH_SDL)
	@${ECHO_MSG} "====> You can enable SDL support by defining WITH_SDL"
.endif
.if ${ARCH} == "i386" || ${ARCH} == "amd64"
.ifndef(WITHOUT_AVIFILE)
	@${ECHO_MSG} "====> You can disable AVIFILE support by defining WITHOUT_AVIFILE"
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|SDL/|SDL11/|' \
		${WRKSRC}/lavtools/liblavplay.c \
		${WRKSRC}/lavtools/yuvplay.c \
		${WRKSRC}/lavtools/lavplay.c
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|' \
		${WRKSRC}/scripts/lav2avi.sh \
		${WRKSRC}/scripts/lav2mpeg ${WRKSRC}/scripts/mpegtranscode
# a bug that is happening with configure. It's not detecting that
# FreeBSD has pthreads. It might happen in other OSes but I'm not
# risking such a general patch
.if ${OPSYS:L} == "freebsd"
	@${REINPLACE_CMD} -E -e 's|^(have_pthread=).+$$|\1true|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.endif
.ifdef(WITH_LIBGNUGETOPT)
	@${REINPLACE_CMD} -E -e 's|(AVIPLAY_LIBS \=.*)|\1 -lgnugetopt|' \
		${WRKSRC}/lavtools/Makefile.in
.endif
# link to pthreads
	@${REINPLACE_CMD} -E -e 's|(AVIPLAY_LIBS \=.*)|\1 ${PTHREAD_LIBS}|' \
		${WRKSRC}/lavtools/Makefile.in

.include <bsd.port.post.mk>
