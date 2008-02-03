# New ports collection makefile for:	clive
# Date created:		2007-02-11
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clive
PORTVERSION=	0.4.4
#PORTREVISION=	0
#PORTEPOCH=	0
CATEGORIES=	multimedia
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Video extraction utility for YouTube and Google Video

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/urlgrabber/__init__.py:${PORTSDIR}/www/py-urlgrabber

# deskutils/ljclive (same executable/manpage/distfile name)
CONFLICTS=	clive-[0-9]*

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.if !defined(NO_INSTALL_MANPAGES)
MAN1=	${PORTNAME}.1
MANCOMPRESSED=	yes
.else
MAKE_ENV=	NO_INSTALL_MANPAGES=${NO_INSTALL_MANPAGES}
.endif

OPTIONS=	FFMPEG	"Install ffmpeg for re-encoding" off \
		MPLAYER	"Install mplayer as video player" off \
		VLC	"Install vlc as video player" off \
		XCLIP	"Install xclip (read URLs from clipboard)" on
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

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

.if defined(WITH_XCLIP)
RUN_DEPENDS+=	xclip:${PORTSDIR}/x11/xclip
.endif

.include <bsd.port.post.mk>
