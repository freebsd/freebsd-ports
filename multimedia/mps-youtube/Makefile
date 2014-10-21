# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mps-youtube
PORTVERSION=	0.01.46
#PORTREVISION=	0
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	CHEESESHOP

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Terminal based YouTube jukebox with playlist management

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pafy>=0.3.41:${PORTSDIR}/www/py-pafy

OPTIONS_DEFAULT=	MPLAYER
OPTIONS_RADIO=	PLAYER
OPTIONS_RADIO_PLAYER=	MPLAYER MPV

MPV_DESC=	Mpv media player support

# This port installs the following files in shared dirs
# PLIST_FILES=	bin/mpsyt
USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMPLAYER}
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
.elif ${PORT_OPTIONS:MMPV}
RUN_DEPENDS+=	mpv:${PORTSDIR}/multimedia/mpv
.endif

.include <bsd.port.mk>
