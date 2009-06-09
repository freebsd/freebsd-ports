# New ports collection makefile for:	fxtv
# Date created:		Thu Nov  4 19:54:04 EST 1999
# Whom:			Randall Hopper <aa8vb@nc.rr.com>
#
# $FreeBSD$
#

PORTNAME=	fxtv
PORTVERSION=	1.03
PORTREVISION=	9
CATEGORIES=	multimedia
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	rhh
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X-based TV Display and Capture Application (for use with bt848 driver)

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		Xaw3d:${PORTSDIR}/x11-toolkits/Xaw3d

USE_XORG=	ice sm x11 xaw xext xmu xt xpm xxf86vm xxf86dga
USE_GMAKE=	yes
MAKE_FLAGS=	-e
MAN1=		fxtv.1

ONLY_FOR_ARCHS=	alpha i386 ia64 amd64

OPTIONS=	EXTRA "Extra programs required to record/playback/save" off

.include <bsd.port.pre.mk>

# This program does not actually require the programs below unless you
#   use audio/video recording and/or playback and save to a non-raw format.
.if defined(WITH_EXTRA)
RUN_DEPENDS+=	sox:${PORTSDIR}/audio/sox \
		mpg123:${PORTSDIR}/audio/mpg123 \
		mpeg_musicin:${PORTSDIR}/audio/mpegaudio \
		mpeg_encode:${PORTSDIR}/multimedia/mpeg_encode \
		mplex:${PORTSDIR}/multimedia/mplex
.endif

pre-install:
	${CP} ${WRKSRC}/fxtv.1 ${WRKSRC}/fxtv.man

.include <bsd.port.post.mk>
