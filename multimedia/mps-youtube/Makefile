# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mps-youtube
PORTVERSION=	0.2.5
PORTREVISION=	0
CATEGORIES=	multimedia
MASTER_SITES=	CHEESESHOP
DISTFILES=	${PORTNAME}-${PORTVERSION}-2.tar.gz

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Terminal based YouTube jukebox with playlist management

LICENSE=	GPLv3

RUN_DEPENDS=	ca_root_nss>=3.17.3:${PORTSDIR}/security/ca_root_nss \
		${PYTHON_PKGNAMEPREFIX}pafy>=0.3.74:${PORTSDIR}/www/py-pafy

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
PLIST_FILES=	bin/${PORTNAME}

SUB_FILES=	${PORTNAME}

USES=		python:3.2+
USE_PYTHON=	autoplist distutils

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
