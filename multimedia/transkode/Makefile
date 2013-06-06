# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	transkode
PORTVERSION=	0.7
PORTREVISION=	15
PORTEPOCH=	1
CATEGORIES=	multimedia audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A KDE/Qt based frontend for various audio transcoding tools

LIB_DEPENDS=	tag.1:${PORTSDIR}/audio/taglib
RUN_DEPENDS=	amarok:${PORTSDIR}/audio/amarok

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_BZIP2=	yes
USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USES=		gettext
USE_AUTOTOOLS=	libtool
INSTALLS_ICONS=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	FAAD FFMPEG FLAC FLAME SPEEX FAAC MUSEPACK LPAC OGG \
		WAVPACK TWOLAME TTA SHORTEN OPTIMFROG BONK MAC \
		MPLAYER GSTREAMER
OPTIONS_DEFAULT=	FAAD FFMPEG FAAC FLAME SPEEX FAAC MUSEPACK \
			LPAC OGG WAVPACK TWOLAME TTA OPTIMFROG BONK \
			MAC
FLAME_DESC=	Fast MP3 encoder
LPAC_DESC=	Lossless audio codec
TTA_DESC=	Lossless (de)compressor
SHORTEN_DESC=	Lossless compression for waveform files
OPTIMFROG_DESC=	Lossless audio codec
BONK_DESC=	Lossy/lossless audio compressor
MAC_DESC=	Monkey's Audio lossless codec

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFAAD}
RUN_DEPENDS+=faad:${PORTSDIR}/audio/faad
.endif
.if ${PORT_OPTIONS:MFFMPEG}
RUN_DEPENDS+=ffmpeg:${PORTSDIR}/multimedia/ffmpeg
.endif
.if ${PORT_OPTIONS:MFLAC}
RUN_DEPENDS+=flac:${PORTSDIR}/audio/flac
.endif
.if ${PORT_OPTIONS:MFLAME}
RUN_DEPENDS+=lame:${PORTSDIR}/audio/lame
.endif
.if ${PORT_OPTIONS:MSPEEX}
RUN_DEPENDS+=speexenc:${PORTSDIR}/audio/speex
.endif
.if ${PORT_OPTIONS:MFAAC}
RUN_DEPENDS+=faac:${PORTSDIR}/audio/faac
.endif
.if ${PORT_OPTIONS:MMUSEPACK}
RUN_DEPENDS+=mpcenc:${PORTSDIR}/audio/musepack
.endif
.if ${PORT_OPTIONS:MLPAC}
RUN_DEPENDS+=lpac:${PORTSDIR}/audio/lpac
.endif
.if ${PORT_OPTIONS:MOGG}
RUN_DEPENDS+=oggenc:${PORTSDIR}/audio/vorbis-tools
.endif
.if ${PORT_OPTIONS:MWAVPACK}
RUN_DEPENDS+=wavpack:${PORTSDIR}/audio/wavpack
.endif
.if ${PORT_OPTIONS:MTWOLAME}
RUN_DEPENDS+=twolame:${PORTSDIR}/audio/twolame
.endif
.if ${PORT_OPTIONS:MTTA}
RUN_DEPENDS+=ttaenc:${PORTSDIR}/audio/tta
.endif
.if ${PORT_OPTIONS:MSHORTEN}
RUN_DEPENDS+=shorten:${PORTSDIR}/audio/shorten
.endif
.if ${PORT_OPTIONS:MOPTIMFROG}
RUN_DEPENDS+=ofr:${PORTSDIR}/audio/optimfrog
.endif
.if ${PORT_OPTIONS:MBONK}
RUN_DEPENDS+=bonk:${PORTSDIR}/audio/bonk
.endif
.if ${PORT_OPTIONS:MMAC}
RUN_DEPENDS+=mac:${PORTSDIR}/audio/mac
.endif
.if ${PORT_OPTIONS:MMPLAYER}
RUN_DEPENDS+=mplayer:${PORTSDIR}/multimedia/mplayer
.endif
.if ${PORT_OPTIONS:MGSTREAMER}
RUN_DEPENDS+=gst-launch-0.10:${PORTSDIR}/multimedia/gstreamer
.endif

post-patch:
	${REINPLACE_CMD} 's/applnk/applications/g' ${WRKSRC}/configure

.include <bsd.port.mk>
