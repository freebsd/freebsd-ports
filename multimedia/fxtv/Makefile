# New ports collection makefile for:	fxtv
# Date created:		Thu Nov  4 19:54:04 EST 1999
# Whom:			Randall Hopper <aa8vb@nc.rr.com>
#
# $FreeBSD$
#

PORTNAME=	fxtv
PORTVERSION=	1.03
CATEGORIES=	graphics
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	rhh
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d

# This program does not actually require the programs below unless you
#   use audio/video recording and/or playback and save to a non-raw format.
#RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox \
#		mpg123:${PORTSDIR}/audio/mpg123 \
#		mpeg_musicin:${PORTSDIR}/audio/mpegaudio \
#		mpeg_encode:${PORTSDIR}/graphics/mpeg_encode \
#		mplex:${PORTSDIR}/graphics/mplex

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes
MAKE_FLAGS=	-e
MAN1=		fxtv.1

pre-install:
	${CP} ${WRKSRC}/fxtv.1 ${WRKSRC}/fxtv.man

.include <bsd.port.mk>
