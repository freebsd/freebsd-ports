# New ports collection makefile for: handbrake
# Date created:        19 November 2004
# Whom:                Andrew Thompson <andy@fud.org.nz>
#
# $FreeBSD$
#

PORTNAME=	handbrake
PORTVERSION=	0.6.2
CATEGORIES=	multimedia
MASTER_SITES=	http://people.via.ecp.fr/~titer/handbrake/ \
		http://download.videolan.org/pub/videolan/vlc/0.8.1/contrib/:ffmpeg
DISTFILES=	HandBrake-${PORTVERSION}-src${EXTRACT_SUFX} \
		${FFMPEG_DIST}:ffmpeg
EXTRACT_ONLY=	HandBrake-${PORTVERSION}-src${EXTRACT_SUFX}

MAINTAINER=	andy@fud.org.nz
COMMENT=	A DVD to MPEG-4 ripper and encoder

BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam \
		nasm:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	a52.0:${PORTSDIR}/audio/liba52 \
		dvdcss.2:${PORTSDIR}/multimedia/libdvdcss \
		dvdread.3:${PORTSDIR}/multimedia/libdvdread \
		faac.0:${PORTSDIR}/audio/faac \
		mp3lame.0:${PORTSDIR}/audio/lame \
		mp4.0:${PORTSDIR}/multimedia/mpeg4ip \
		mpeg2.0:${PORTSDIR}/multimedia/libmpeg2 \
		ogg.5:${PORTSDIR}/audio/libogg \
		samplerate.1:${PORTSDIR}/audio/libsamplerate \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		xvidcore.4:${PORTSDIR}/multimedia/xvid

FFMPEG_SNAP=	20041113
FFMPEG_DIST=	ffmpeg-${FFMPEG_SNAP}.tar.bz2
FFMPEG_SRC_DIR=	${WRKDIR}/ffmpeg-${FFMPEG_SNAP}
PLIST_FILES=	bin/handbrake
WRKSRC=		${WRKDIR}/HandBrake-${PORTVERSION}

USE_GNOME=	gtk20
USE_REINPLACE=	yes
USE_X_PREFIX=	yes

SYSCTL_CMD?=	/sbin/sysctl

FFMPEG_CONFIGURE_ARGS+=	--enable-gpl --disable-ffserver \
			--enable-memalign-hack \
			--cc="${CC}" \
			--make="${GMAKE}" \
			--extra-ldflags="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
			--extra-cflags="${CFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include" \
			--extra-libs"-lm" \
			--disable-debug \
			--enable-pp \
			--enable-pthreads \
			--enable-faac \
			--enable-mp3lame \
			--enable-faad \
			--enable-a52 \
			--enable-xvid

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
WITH_DVD_DEVICE?=	acd0c
.else
WITH_DVD_DEVICE?=	acd0
.endif

post-extract:
	cd ${WRKDIR}; ${BZIP2_CMD} ${EXTRACT_BEFORE_ARGS} \
		${_DISTDIR}/${FFMPEG_DIST} ${EXTRACT_AFTER_ARGS}

do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} jam)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gtk2HB ${PREFIX}/bin/handbrake

post-patch:
	@${REINPLACE_CMD} -e 's:%%PREFIX%%:${LOCALBASE}:g' \
		-e 's:%%LIBAVCODEC%%:${FFMPEG_SRC_DIR}/libavcodec:g' \
		-e 's:%%PTHREAD_LIBS%%:${PTHREAD_LIBS}:g' \
		-e 's:%%CC%%:${CC}:g' -e 's:%%CXX%%:${CXX}:g' \
		-e 's:%%CFLAGS%%:${CFLAGS}:g' \
		${BUILD_WRKSRC}/Jamfile ${BUILD_WRKSRC}/core/Jamfile \
		${BUILD_WRKSRC}/Jamrules
	@${REINPLACE_CMD} -e 's:%%DVD_DEVICE%%:${WITH_DVD_DEVICE}:g' \
		${BUILD_WRKSRC}/gtk2/main.c
# sysctl
	@${REINPLACE_CMD} -e 's|/usr/sbin/sysctl|${SYSCTL_CMD}|' \
		${BUILD_WRKSRC}/core/HandBrake.c
# ffmpeg
.if ${OSVERSION} < 502119
	@${REINPLACE_CMD} -e 's|roundf|rintf|' \
		${FFMPEG_SRC_DIR}/libavcodec/xvidff.c
.endif
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' \
		${FFMPEG_SRC_DIR}/configure
	cd ${FFMPEG_SRC_DIR} && \
		${PATCH} -p0 < ${PATCHDIR}/ffmpeg-patch

pre-configure:
	cd ${FFMPEG_SRC_DIR} \
	&& ${SETENV} ${SCRIPTS_ENV} ${CONFIGURE_ENV} \
		${SH} ./configure ${CONFIGURE_ARGS} ${FFMPEG_CONFIGURE_ARGS}
	cd ${FFMPEG_SRC_DIR}/libavcodec \
		&& ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} Makefile \
		${MAKE_ARGS} all

.include <bsd.port.post.mk>
