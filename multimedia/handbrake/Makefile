# New ports collection makefile for: handbrake
# Date created:        19 November 2004
# Whom:                Andrew Thompson <andy@fud.org.nz>
#
# $FreeBSD$
#

PORTNAME=	handbrake
PORTVERSION=	0.6.2
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://people.via.ecp.fr/~titer/handbrake/
DISTNAME=	HandBrake-${PORTVERSION}-src

MAINTAINER=	thompsa@FreeBSD.org
COMMENT=	A DVD to MPEG-4 ripper and encoder

BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam \
		nasm:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	a52.0:${PORTSDIR}/audio/liba52 \
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		dvdcss.2:${PORTSDIR}/multimedia/libdvdcss \
		dvdread.3:${PORTSDIR}/multimedia/libdvdread \
		faac.0:${PORTSDIR}/audio/faac \
		mp3lame.0:${PORTSDIR}/audio/lame \
		mp4v2.0:${PORTSDIR}/multimedia/mpeg4ip-libmp4v2 \
		mpeg2.0:${PORTSDIR}/multimedia/libmpeg2 \
		ogg.5:${PORTSDIR}/audio/libogg \
		samplerate.1:${PORTSDIR}/audio/libsamplerate \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		xvidcore.4:${PORTSDIR}/multimedia/xvid

PLIST_FILES=	bin/handbrake
WRKSRC=		${WRKDIR}/HandBrake-${PORTVERSION}

USE_GNOME=	gtk20
USE_REINPLACE=	yes
USE_X_PREFIX=	yes

SYSCTL_CMD?=	/sbin/sysctl

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_GETOPT_LONG=	yes
MAKE_ENV=		EXTRA_LIBS="-lcipher -lgnugetopt"
WITH_DVD_DEVICE?=	acd0c
.else
WITH_DVD_DEVICE?=	acd0
.endif

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

.include <bsd.port.post.mk>
