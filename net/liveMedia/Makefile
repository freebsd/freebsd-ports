# New ports collection makefile for:	liveMedia
# Date created:				2002/09/25
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	liveMedia
PORTVERSION=	2002.11.04
PORTCOMMENT=	LIVE.COM Streaming Media
CATEGORIES=	net devel
MASTER_SITES=	http://www.LIVE.COM/liveMedia/public/
MASTER_SITES+=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	nork
DISTNAME=	live.${PORTVERSION}

MAINTAINER=	nork@FreeBSD.org

WRKSRC=		${WRKDIR}/live

USE_REINPLACE=	YES

BasicUsageEnvironment= \
		BasicUsageEnvironment/include/BasicHashTable.hh \
		BasicUsageEnvironment/include/BasicUsageEnvironment.hh \
		BasicUsageEnvironment/include/BasicUsageEnvironment_version.hh \
		BasicUsageEnvironment/include/DelayQueue.hh \
		BasicUsageEnvironment/include/Lock.hh

UsageEnvironment= \
		UsageEnvironment/include/Boolean.hh \
		UsageEnvironment/include/HashTable.hh \
		UsageEnvironment/include/UsageEnvironment.hh \
		UsageEnvironment/include/UsageEnvironment_version.hh

groupsock= \
		groupsock/include/GroupEId.hh \
		groupsock/include/Groupsock.hh \
		groupsock/include/GroupsockHelper.hh \
		groupsock/include/IOHandlers.hh \
		groupsock/include/NetAddress.hh \
		groupsock/include/NetInterface.hh \
		groupsock/include/TunnelEncaps.hh \
		groupsock/include/groupsock_version.hh

liveMedia= \
		liveMedia/include/BasicUDPSource.hh \
		liveMedia/include/ByteStreamFileSource.hh \
		liveMedia/include/ByteStreamMultiFileSource.hh \
		liveMedia/include/DeviceSource.hh \
		liveMedia/include/FileSink.hh \
		liveMedia/include/FramedFileSource.hh \
		liveMedia/include/FramedFilter.hh \
		liveMedia/include/FramedSource.hh \
		liveMedia/include/GSMAudioRTPSink.hh \
		liveMedia/include/H263plusVideoRTPSink.hh \
		liveMedia/include/H263plusVideoRTPSource.hh \
		liveMedia/include/HTTPSink.hh \
		liveMedia/include/MP3ADU.hh \
		liveMedia/include/MP3ADURTPSink.hh \
		liveMedia/include/MP3ADURTPSource.hh \
		liveMedia/include/MP3ADUTranscoder.hh \
		liveMedia/include/MP3ADUinterleaving.hh \
		liveMedia/include/MP3FileSource.hh \
		liveMedia/include/MP3HTTPSource.hh \
		liveMedia/include/MP3Transcoder.hh \
		liveMedia/include/MPEGAudioRTPSink.hh \
		liveMedia/include/MPEGAudioRTPSource.hh \
		liveMedia/include/MPEGAudioStreamFramer.hh \
		liveMedia/include/MPEGDemux.hh \
		liveMedia/include/MPEGDemuxedElementaryStream.hh \
		liveMedia/include/MPEGVideoHTTPSink.hh \
		liveMedia/include/MPEGVideoRTPSink.hh \
		liveMedia/include/MPEGVideoRTPSource.hh \
		liveMedia/include/MPEGVideoStreamFramer.hh \
		liveMedia/include/Media.hh \
		liveMedia/include/MediaSession.hh \
		liveMedia/include/MediaSink.hh \
		liveMedia/include/MediaSource.hh \
		liveMedia/include/MultiFramedRTPSink.hh \
		liveMedia/include/MultiFramedRTPSource.hh \
		liveMedia/include/PassiveServerMediaSession.hh \
		liveMedia/include/PrioritizedRTPStreamSelector.hh \
		liveMedia/include/QCELPAudioRTPSource.hh \
		liveMedia/include/QuickTimeFileSink.hh \
		liveMedia/include/QuickTimeGenericRTPSource.hh \
		liveMedia/include/RTCP.hh \
		liveMedia/include/RTPInterface.hh \
		liveMedia/include/RTPSink.hh \
		liveMedia/include/RTPSource.hh \
		liveMedia/include/RTSPClient.hh \
		liveMedia/include/RTSPServer.hh \
		liveMedia/include/ServerMediaSession.hh \
		liveMedia/include/SimpleRTPSink.hh \
		liveMedia/include/SimpleRTPSource.hh \
		liveMedia/include/liveMedia.hh \
		liveMedia/include/liveMedia_version.hh

post-extract:
	@${CP} ${FILESDIR}/config.fixed-${OPSYS:L} ${WRKSRC}/

do-configure:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./genMakefiles fixed-${OPSYS:L})

do-install::
	@${INSTALL_PROGRAM} ${WRKSRC}/testProgs/openRTSP ${PREFIX}/bin/
	@${INSTALL_PROGRAM} ${WRKSRC}/testProgs/sapWatch ${PREFIX}/bin/

do-install::
	@${MKDIR} ${PREFIX}/live
	@${MKDIR} ${PREFIX}/live/BasicUsageEnvironment
	@${MKDIR} ${PREFIX}/live/UsageEnvironment
	@${MKDIR} ${PREFIX}/live/groupsock
	@${MKDIR} ${PREFIX}/live/liveMedia
	@${INSTALL_DATA} ${WRKSRC}/BasicUsageEnvironment/libBasicUsageEnvironment.a ${PREFIX}/live/BasicUsageEnvironment/
	@${INSTALL_DATA} ${WRKSRC}/UsageEnvironment/libUsageEnvironment.a           ${PREFIX}/live/UsageEnvironment/
	@${INSTALL_DATA} ${WRKSRC}/groupsock/libgroupsock.a                         ${PREFIX}/live/groupsock/
	@${INSTALL_DATA} ${WRKSRC}/liveMedia/libliveMedia.a                         ${PREFIX}/live/liveMedia/

do-install::
	@${MKDIR} ${PREFIX}/live/BasicUsageEnvironment/include
	@${MKDIR} ${PREFIX}/live/UsageEnvironment/include
	@${MKDIR} ${PREFIX}/live/groupsock/include
	@${MKDIR} ${PREFIX}/live/liveMedia/include
.for file in ${BasicUsageEnvironment}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/live/BasicUsageEnvironment/include/
.endfor
.for file in ${UsageEnvironment}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/live/UsageEnvironment/include/
.endfor
.for file in ${groupsock}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/live/groupsock/include/
.endfor
.for file in ${liveMedia}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/live/liveMedia/include/
.endfor

.include <bsd.port.mk>
