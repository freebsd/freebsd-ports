# New ports collection makefile for:	transkode
# Date created:				6 August 2007
# Whom:					Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	transkode
PORTVERSION=	0.7
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	multimedia audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A KDE/Qt based frontend for various audio transcoding tools

LIB_DEPENDS=	tag.1:${PORTSDIR}/audio/taglib
RUN_DEPENDS=	amarok:${PORTSDIR}/audio/amarok

USE_BZIP2=	yes
USE_KDELIBS_VER=3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool:22
INSTALLS_ICONS=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS+=	FAAD "Enable MPEG-2 and MPEG-4 AAC audio decoder" on
OPTIONS+=	FFMPEG "Enable ffmpeg audio/video encoder" on
OPTIONS+=	FLAC "Enable Free lossless audio codec" on
OPTIONS+=	FLAME "Enable fast MP3 encoder" on
OPTIONS+=	SPEEX "Enable patent-free voice codec" on
OPTIONS+=	FAAC "Enable PEG-2 and MPEG-4 AAC audio encoder" on
OPTIONS+=	MUSEPACK "Enable musepack (mpc) encoder" on
OPTIONS+=	LPAC "Enable Lossless audio codec" on
OPTIONS+=	OGG "Enable Ogg Vorbis encode" on
OPTIONS+=	WAVPACK "Enable both 16 and 24bit wav format" on
OPTIONS+=	TWOLAME "Enable MPEG Audio Layer 2 encoder" on
OPTIONS+=	TTA "Enable lossless (de)compressor" on
OPTIONS+=	SHORTEN "Enable lossless compression for waveform files" off
OPTIONS+=	OPTIMFROG "Enable Lossless audio codec" on
OPTIONS+=	BONK "Enable Lossy/lossless audio compressor" on
OPTIONS+=	MAC "Enable Monkey's Audio lossless codec" on
OPTIONS+=	MPLAYER "Enable mplayer support" off
OPTIONS+=	GSTREAMER "Enable gstreamer support" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_FAAD)
RUN_DEPENDS+=faad:${PORTSDIR}/audio/faad
.endif
.if !defined(WITHOUT_FFMPEG)
RUN_DEPENDS+=ffmpeg:${PORTSDIR}/multimedia/ffmpeg
.endif
.if !defined(WITHOUT_FLAC)
RUN_DEPENDS+=flac:${PORTSDIR}/audio/flac
.endif
.if !defined(WITHOUT_FLAME)
RUN_DEPENDS+=lame:${PORTSDIR}/audio/lame
.endif
.if !defined(WITHOUT_SPEEX)
RUN_DEPENDS+=speexenc:${PORTSDIR}/audio/speex
.endif
.if !defined(WITHOUT_FAAC)
RUN_DEPENDS+=faac:${PORTSDIR}/audio/faac
.endif
.if !defined(WITHOUT_MUSEPACK)
RUN_DEPENDS+=mppenc:${PORTSDIR}/audio/musepack
.endif
.if !defined(WITHOUT_LPAC)
RUN_DEPENDS+=lpac:${PORTSDIR}/audio/lpac
.endif
.if !defined(WITHOUT_OGG)
RUN_DEPENDS+=oggenc:${PORTSDIR}/audio/vorbis-tools
.endif
.if !defined(WITHOUT_WAVPACK)
RUN_DEPENDS+=wavpack:${PORTSDIR}/audio/wavpack
.endif
.if !defined(WITHOUT_TWOLAME)
RUN_DEPENDS+=twolame:${PORTSDIR}/audio/twolame
.endif
.if !defined(WITHOUT_TTA)
RUN_DEPENDS+=ttaenc:${PORTSDIR}/audio/tta
.endif
.if defined(WITH_SHORTEN)
RUN_DEPENDS+=shorten:${PORTSDIR}/audio/shorten
.endif
.if !defined(WITHOUT_OPTIMFROG)
RUN_DEPENDS+=ofr:${PORTSDIR}/audio/optimfrog
.endif
.if !defined(WITHOUT_BONK)
RUN_DEPENDS+=bonk:${PORTSDIR}/audio/bonk
.endif
.if !defined(WITHOUT_MAC)
RUN_DEPENDS+=mac:${PORTSDIR}/audio/mac
.endif
.if defined(WITH_MPLAYER)
RUN_DEPENDS+=mplayer:${PORTSDIR}/multimedia/mplayer
.endif
.if defined(WITH_GSTREAMER)
RUN_DEPENDS+=gst-launch-0.10:${PORTSDIR}/multimedia/gstreamer
.endif

post-patch:
	${REINPLACE_CMD} 's/applnk/applications/g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
