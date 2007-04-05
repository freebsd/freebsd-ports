# New ports collection makefile for: handbrake
# Date created:        19 November 2004
# Whom:                Andrew Thompson <andy@fud.org.nz>
#
# $FreeBSD$
#

PORTNAME=	handbrake
PORTVERSION=	0.7.1
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://download.m0k.org/${PORTNAME}/ \
		http://www.mirrors.ausmac.net/ftp/AudioVisual-SW/HandBrake/ \
		http://apple.doit.wisc.edu/mirrors/ausmac/Audio-SW/HandBrake/
DISTNAME=	HandBrake-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	A DVD to MPEG-4 ripper and encoder

BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam
LIB_DEPENDS=	a52.0:${PORTSDIR}/audio/liba52 \
		dvdcss.2:${PORTSDIR}/multimedia/libdvdcss \
		dvdread.5:${PORTSDIR}/multimedia/libdvdread \
		faac.0:${PORTSDIR}/audio/faac \
		mp3lame.0:${PORTSDIR}/audio/lame \
		mp4v2.0:${PORTSDIR}/multimedia/mpeg4ip-libmp4v2 \
		mpeg2.0:${PORTSDIR}/multimedia/libmpeg2 \
		ogg.5:${PORTSDIR}/audio/libogg \
		samplerate.1:${PORTSDIR}/audio/libsamplerate \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		xvidcore.4:${PORTSDIR}/multimedia/xvid \
		x264.50:${PORTSDIR}/multimedia/x264

WRKSRC=		${WRKDIR}/HandBrake-${PORTVERSION}
HAS_CONFIGURE=	yes
PLIST_FILES=	bin/handbrake

JAM?=		${LOCALBASE}/bin/jam
SYSCTL_CMD?=	/sbin/sysctl

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude beos \
			--exclude contrib \
			--exclude gtk2 \
			--exclude macosx \
			--exclude wx

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libavformat.a) && !exists(${LOCALBASE}/libdata/pkgconfig/libavcodec.pc)
BROKEN=	ffmpeg exists, handbrake needs ffmpeg-devel so uninstall ffmpeg if you still want handbrake
.else
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg-devel
.endif

.if ${OSVERSION} < 500000
USE_GETOPT_LONG=	yes
MAKE_ENV=		EXTRA_LIBS="-lcipher -lgnugetopt"
WITH_DVD_DEVICE?=	acd0c
.else
WITH_DVD_DEVICE?=	acd0
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g ; s|HBTest|${PORTNAME}|g' \
			${WRKSRC}/configure ${WRKSRC}/Jamfile \
			${WRKSRC}/libhb/Jamfile ${WRKSRC}/test/test.c
	@${REINPLACE_CMD} -e 's|/usr/sbin/sysctl|${SYSCTL_CMD}|g' \
		${WRKSRC}/libhb/ports.c
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|g' \
		${WRKSRC}/libhb/fifo.c

# jam -dx, it will giving a verbose of build.
do-build:
	@(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${JAM} -dx)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.post.mk>
