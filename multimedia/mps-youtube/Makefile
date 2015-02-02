# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mps-youtube
PORTVERSION=	0.2.1
PORTREVISION=	0
CATEGORIES=	multimedia
MASTER_SITES=	CHEESESHOP

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Terminal based YouTube jukebox with playlist management

LICENSE=	GPLv3

RUN_DEPENDS=	ca_root_nss>=3.17.3:${PORTSDIR}/security/ca_root_nss \
		${PYTHON_PKGNAMEPREFIX}pafy>=0.3.66:${PORTSDIR}/www/py-pafy

CONVERTER_DESC=	Converter to MP3 and other formats

FFMPEG_RUN_DEPENDS=	ffmpeg>=2.3.6:${PORTSDIR}/multimedia/ffmpeg

LIBAV_DESC=	Realtime audio/video conversion library
LIBAV_RUN_DEPENDS=	libav>=11.2:${PORTSDIR}/multimedia/libav

MPLAYER_RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

MPV_DESC=	Free and open-source general-purpose video player
MPV_RUN_DEPENDS=	mpv:${PORTSDIR}/multimedia/mpv

OPTIONS_DEFAULT=	MPV
OPTIONS_RADIO=	CONVERTER
OPTIONS_RADIO_CONVERTER=	FFMPEG LIBAV
OPTIONS_SINGLE=	PLAYER
OPTIONS_SINGLE_PLAYER=	MPLAYER MPV

PLAYER_DESC=	Video player

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},1' \
		${WRKSRC}/mps_youtube/main.py

.include <bsd.port.mk>
