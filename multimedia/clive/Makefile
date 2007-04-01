# New ports collection makefile for:	clive
# Date created:		2007-02-11
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clive
PORTVERSION=	0.1.9
#PORTREVISION=	0
#PORTEPOCH=	0
CATEGORIES=	multimedia
MASTER_SITES=	http://download.gna.org/${PORTNAME}/${PORTVERSION:R}/src/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Video extraction utility for YouTube and Google Video

# deskutils/ljclive (same executable/manpage/distfile name)
CONFLICTS=	clive-[0-9]*

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

MAN1=	${PORTNAME}.1
MANCOMPRESSED=	yes

OPTIONS=	FFMPEG	"Install ffmpeg for re-encoding" off \
		MPLAYER	"Install mplayer as video player" off \
		VLC	"Install vlc as video player" off
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if defined(WITH_FFMPEG)
RUN_DEPENDS+=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg
.endif

.if defined(WITH_MPLAYER)
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
.endif

.if defined(WITH_VLC)
RUN_DEPENDS+=	vlc:${PORTSDIR}/multimedia/vlc
.endif

.include <bsd.port.post.mk>
