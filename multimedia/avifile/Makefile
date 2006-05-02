# New ports collection makefile for:   avifile
# Date created: 	16 September 2000
# Whom: 		Holger Lamm
#
# $FreeBSD$
#

PORTNAME=	avifile
PORTVERSION=	0.7.43
PORTEPOCH=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-0.7-${PORTVERSION}

MAINTAINER=	holger@e-gitt.net
COMMENT=	AVI player/converter with numerous codecs, including MPEG-4(DivX ;-))

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

USE_SUBMAKE=	yes
USE_BZIP2=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_ICONV=	yes
INSTALLS_SHLIB=	yes

LIBTOOLFILES=	acinclude.m4
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib" \
		CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-gnu-ld --enable-iconv \
		--disable-v4l \
		--disable-divx4
CONFIGURE_TARGET=

PLIST_SUB=	LIB_VERSION="${LIB_VERSION}" VERSION="${VERSION}"

MAN1=	avibench.1 avicap.1 avicat.1 avifile-config.1 avimake.1 \
	aviplay.1 avirec.1 avirecompress.1 avitype.1

#CODEC_PORT=	${PORTSDIR}/multimedia/win32-codecs
CODEC_PORT=	${.CURDIR}/../win32-codecs
CODEC_DETECTION_FILE!=	${MAKE} -f ${CODEC_PORT}/Makefile -V CODEC_DETECTION_FILE

LIB_VERSION=	3
VERSION=	0.7

# qt -- USE_QT_VER has to happen befor bsd.port.pre.mk
.if !defined(WITHOUT_QT)
. if exists(${X11BASE}/include/qt2/qapp.h)
USE_QT_VER=	2
. else
USE_QT_VER=	3
. endif
PLIST_SUB+=	QT=""
.else
CONFIGURE_ARGS+=	--without-qt

PLIST_SUB+=	QT="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 600000
WITH_OPTIMIZED_CFLAGS=	yes
.endif

.if (${ARCH} != "i386") && (${ARCH} != "amd64")
WITHOUT_A52=yes
BROKEN=		Does not compile on !i386
.endif

# compilation optimizations
.if defined(WITH_OPTIMIZED_CFLAGS)
CONFIGURE_ARGS+=	--enable-release
. if ${ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-x86opt
. endif
.else
CONFIGURE_ARGS+=	--disable-release
.endif

# soundblaster can be passed ac3 instead of letting avifile decode
# it
.if defined(WITH_AC3_PASSTHROUGH)
CONFIGURE_ARGS+=	--enable-ac3passthrough
PLIST_SUB+=	AC3_PASS=""
.else
CONFIGURE_ARGS+=	--disable-ac3passthrough
PLIST_SUB+=	AC3_PASS="@comment "
.endif

# liba52
.if !defined(WITHOUT_A52)
LIB_DEPENDS+=	a52.0:${PORTSDIR}/audio/liba52

# --enable-ffmpeg-a52bin breaks build
CONFIGURE_ARGS+=	--enable-a52 \
			--enable-ffmpeg-a52 \
			--with-a52-prefix=${LOCALBASE}
PLIST_SUB+=	A52=""
.else
CONFIGURE_ARGS+=	--disable-a52

PLIST_SUB+=	A52="@comment "
.endif

# faad
.if !defined(WITHOUT_FAAD)
LIB_DEPENDS+=	faad.0:${PORTSDIR}/audio/faad

CONFIGURE_ARGS+=	--with-faad-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--disable-faad
.endif

# libmad
.if !defined(WITHOUT_MAD)
LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad

CONFIGURE_ARGS+=	--enable-libmad
PLIST_SUB+=	MAD=""
.else
CONFIGURE_ARGS+=	--disable-mad
PLIST_SUB+=	MAD="@comment "
.endif

# sdl
.if !defined(WITHOUT_SDL)
USE_SDL=		sdl
CONFIGURE_ARGS+=	--with-sdl-prefix=${LOCALBASE} \
			--with-sdl-exec-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-sdl
.endif

# vidix support: requires root privileges
.if defined(WITH_VIDIX)
CONFIGURE_ARGS+=	--enable-vidix
PLIST_SUB+=	VIDIX=""
.else
CONFIGURE_ARGS+=	--disable-vidix
PLIST_SUB+=	VIDIX="@comment "
.endif

# libvorbis; thus, libogg
.if !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis

CONFIGURE_ARGS+=	--with-vorbis-prefix=${LOCALBASE} \
			--with-ogg-prefix=${LOCALBASE}
PLIST_SUB+=	VORBIS=""
.else
CONFIGURE_ARGS+=	--disable-vorbis
PLIST_SUB+=	VORBIS="@comment "
.endif

# xvid
.if !defined(WITHOUT_XVID)
LIB_DEPENDS+=	xvidcore.4:${PORTSDIR}/multimedia/xvid
CONFIGURE_ARGS+=	--with-xvid-prefix=${LOCALBASE}
PLIST_SUB+=	XVID=""
.else
CONFIGURE_ARGS+=	--disable-xvid
PLIST_SUB+=	XVID="@comment "
.endif

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "You can enable compilation optimizations by defining"
	@${ECHO_MSG} "	WITH_OPTIMIZED_CFLAGS."
.endif
.if !defined(WITH_AC3_PASSTHROUGH)
	@${ECHO_MSG} "You can enable soundblaster ac3 passthrough support by"
	@${ECHO_MSG} "	defining WITH_AC3_PASSTHROUGH."
.endif
.if !defined(WITHOUT_A52)
	@${ECHO_MSG} "You can disable ac3 (liba52) support by defining WITHOUT_A52."
.endif
.if !defined(WITHOUT_FAAD)
	@${ECHO_MSG} "You can disable faad support by defining WITHOUT_FAAD."
.endif
.if !defined(WITHOUT_MAD)
	@${ECHO_MSG} "You can disable mad support by defining WITHOUT_MAD."
.endif
.if !defined(WITHOUT_QT)
	@${ECHO_MSG} "You can disable QT supported tools by defining WITHOUT_QT."
.endif
.if !defined(WITHOUT_SDL)
	@${ECHO_MSG} "You can disable SDL supported tools by defining WITHOUT_SDL."
.endif
.if !defined(WITH_VIDIX)
	@${ECHO_MSG} "You can enable VIDIX support by defining WITH_VIDIX."
.endif
.if !defined(WITHOUT_VORBIS)
	@${ECHO_MSG} "You can disable vorbis support by defining WITHOUT_VORBIS."
.endif
.if !defined(WITHOUT_XVID)
	@${ECHO_MSG} "You can disable xvid support by defining WITHOUT_XVID."
.endif

pre-extract:
	@if [ -f ${LOCALBASE}/lib/libpth.so ]; then \
	  ${ECHO_MSG} "Error: This packet does not compile when the \
packet 'pth' is installed.";\
	  ${FALSE};\
	fi

post-extract:
# grab does not work outside Linux for now
	@${RM} -f ${WRKSRC}/ffmpeg/libavformat/grab.c
	@${TOUCH} ${WRKSRC}/ffmpeg/libavformat/grab.c

post-patch:
# linux/ioctl.h -> sys/ioctl.h
	@${REINPLACE_CMD} -e 's|linux/ioctl.h|sys/ioctl.h|' \
		${WRKSRC}/drivers/libdha/kernelhelper/dhahelper.h
# FreeBSD does not support Video4Linux or equivalent
# therefore, do not build qtvidcap
	@${REINPLACE_CMD} -E -e 's|^(SUBDIRS.+)qtvidcap|\1|' \
		${WRKSRC}/samples/Makefile.in
.if !defined(WITHOUT_MAD)
	@${REINPLACE_CMD} -e 's|"mad.h"|<mad.h>|' \
		${WRKSRC}/plugins/libmad/libmad.cpp
	@${REINPLACE_CMD} -e 's|@AMM_USE_LIBMAD_FALSE@CUSTOMFLAGS = -I$(SUBDIRS)||' \
		${WRKSRC}/plugins/libmad/Makefile.in
.endif
.if !defined(WITHOUT_QT)
. if exists(${X11BASE}/include/qt2/qapp.h)
	@${REINPLACE_CMD} -e 's|qt-mt|qt2-mt|' ${WRKSRC}/configure
. endif
	@${REINPLACE_CMD} -e 's|QT_CFLAGS = \@QT_CFLAGS\@|QT_CFLAGS = -I${X11BASE}/include \@QT_CFLAGS\@|; \
		s|QT_LIBS = \@QT_LIBS\@|QT_LIBS = -L${X11BASE}/lib \@QT_LIBS\@|' \
		${WRKSRC}/libavqt/Makefile.in
.endif
.if !defined(WITHOUT_XVID)
	@${REINPLACE_CMD} -e 's|XVID_LIBS = \@XVID_LIBS\@|XVID_LIBS = -L${LOCALBASE}/lib \@XVID_LIBS\@|' \
		${WRKSRC}/plugins/libxvid/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's|__THROW||' \
		${WRKSRC}/plugins/libwin32/loader/dshow/DS_Filter.h
	@${REINPLACE_CMD} -e 's|-ljpeg|-L${LOCALBASE}/lib -ljpeg|' \
		${WRKSRC}/samples/mjpeg_plugin/Makefile.in
# if we have LAME
	@${REINPLACE_CMD} -e 's|-lmp3lame|-L${LOCALBASE}/lib -lmp3lame|' \
		${WRKSRC}/configure
# use portname without version to build dir names
	@${REINPLACE_CMD} -E -e 's|(PACKAGE[:space:]*=[:space:]*avifile).*|\1|' \
		${WRKSRC}/configure
# fix build in -CURRENT
	@${FIND} ${WRKSRC} -type f | ${XARGS} -n 10 ${REINPLACE_CMD} -e \
		's|#include <malloc.h>|#include <stdlib.h>|g'
# use correct signal type
	@${REINPLACE_CMD} -e 's|sighandler_t|sig_t|' \
		${WRKSRC}/samples/misc/benchmark.cpp
# fix breakage if either auto{conf,make} are installed
# CFLAGS safeness
# do not version library names
# fix incorrect behavior of configure script
# make doc follow our hier
	@${FIND} ${WRKSRC} \( -name Makefile.in -o -name configure \) | \
		${XARGS} -n 10 ${REINPLACE_CMD} -E -e \
		's|INSTALL = \@INSTALL\@|INSTALL = ${INSTALL}|; \
		s!-O4!${CFLAGS}!; \
		s!-release[[:space:]]+\$$\([^\)]+\)!!; \
		s!ACLOCAL =!ACLOCAL = ${TRUE} || !; \
		s!AUTOCONF =!AUTOCONF = ${TRUE} || !; \
		s!AUTOHEADER =!AUTOHEADER = ${TRUE} || !; \
		s!AUTOMAKE =!AUTOMAKE = ${TRUE} || !; \
		s|[(]datadir[)]/[$$][(]PACKAGE[)]/doc|(prefix)/share/doc/$$(PACKAGE)|'
# fix location of pkgconfig dir
	@${REINPLACE_CMD} -E \
		-e 's|^(pkgconfigdir).*|\1=${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in
# do not install man page for v4l
	@${REINPLACE_CMD} -E \
		-e 's|kv4lsetup.1||' ${WRKSRC}/doc/Makefile.in
# libmad's configure script has problems in this release
# therefore, we avoid it since we do not need it anyway
	@${REINPLACE_CMD} -E \
		-e 's|^subdirs[[:space:]]*=.*libmad.*$$||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
# int_fast16/32_t are not in 4.x
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|int_fast16_t|int16_t|g; \
		s|int_fast32_t|int32_t|g' \
		${WRKSRC}/ffmpeg/libavcodec/jfdctfst.c \
		${WRKSRC}/ffmpeg/libavcodec/jfdctint.c \
		${WRKSRC}/ffmpeg/libavcodec/ffv1.c
.endif

post-configure:
	@${LN} -sf ${LIBTOOL} ${WRKSRC}/libtool

post-install:
	@${FMT} < ${PKGMESSAGE}

.if (${ARCH} == "i386")
RUN_DEPENDS+=	${CODEC_DETECTION_FILE}:${CODEC_PORT}

CONFIGURE_ARGS+=	--enable-win32 \
			--with-win32-path=${LOCALBASE}/lib/win32

PLIST_SUB+=	WIN32=""
.else
CONFIGURE_ARGS+=	--disable-win32

PLIST_SUB+=	WIN32="@comment "
.endif

.if (${ARCH} == "i386") || (${ARCH} == "amd64")
CONFIGURE_ARGS+=	--enable-x86opt

PLIST_SUB+=	FFMPEG=""
.else
CONFIGURE_ARGS+=	--disable-x86opt \
			--disable-ffmpeg

PLIST_SUB+=	FFMPEG="@comment "
.endif

# hack taken from ogle to make it work with liba52 + djbfft
.if exists(${LOCALBASE}/lib/liba52.la)
LIBA52_DEP_LIBS!=	${GREP} dependency_libs ${LOCALBASE}/lib/liba52.la | ${CUT} -d \' -f 2
.else
LIBA52_DEP_LIBS=
.endif

# if we have LAME
.if exists(${LOCALBASE}/lib/libmp3lame.so)
LIB_DEPENDS+=	mp3lame.0:${PORTSDIR}/audio/lame

CONFIGURE_ARGS+=	--enable-lame-bin

PLIST_SUB+=	NOLAME="@comment " LAME=""
.else
PLIST_SUB+=	NOLAME="" LAME="@comment "
.endif

.include <bsd.port.post.mk>
