# New ports collection makefile for:	liveMedia
# Date created:				2002/09/25
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	liveMedia
PORTVERSION=	2004.07.22
PORTEPOCH=	1
CATEGORIES=	net devel
MASTER_SITES=	http://www.LIVE.COM/liveMedia/public/
#MASTER_SITES+=	${MASTER_SITE_LOCAL}
#MASTER_SITE_SUBDIR=	nork
DISTNAME=	live.${PORTVERSION}

MAINTAINER=	nork@FreeBSD.org
COMMENT=	LIVE.COM Streaming Media

NO_CDROM=	'dated material'

WRKSRC=		${WRKDIR}/live
PLIST=		${WRKDIR}/pkg-plist

HAS_CONFIGURE=	YES
USE_REINPLACE=	YES

CONFIGURE_SCRIPT=	genMakefiles
CONFIGURE_ARGS=		fixed-${OPSYS:L}

INSTALL_DATADIR=	${INSTALL} -d ${_SHROWNGRP} -m 755

BasicUsageEnvironment=	\
		BasicUsageEnvironment/include/BasicHashTable.hh \
		BasicUsageEnvironment/include/BasicUsageEnvironment.hh \
		BasicUsageEnvironment/include/BasicUsageEnvironment0.hh \
		BasicUsageEnvironment/include/BasicUsageEnvironment_version.hh \
		BasicUsageEnvironment/include/DelayQueue.hh \
		BasicUsageEnvironment/include/HandlerSet.hh

UsageEnvironment=	\
		UsageEnvironment/include/Boolean.hh \
		UsageEnvironment/include/HashTable.hh \
		UsageEnvironment/include/UsageEnvironment.hh \
		UsageEnvironment/include/UsageEnvironment_version.hh \
		UsageEnvironment/include/strDup.hh

groupsock=		\
		groupsock/include/GroupEId.hh \
		groupsock/include/Groupsock.hh \
		groupsock/include/GroupsockHelper.hh \
		groupsock/include/IOHandlers.hh \
		groupsock/include/NetAddress.hh \
		groupsock/include/NetCommon.h \
		groupsock/include/NetInterface.hh \
		groupsock/include/TunnelEncaps.hh \
		groupsock/include/groupsock_version.hh

liveMedia=		\
		liveMedia/include/AC3AudioRTPSink.hh \
		liveMedia/include/AC3AudioRTPSource.hh \
		liveMedia/include/AC3AudioStreamFramer.hh \
		liveMedia/include/AMRAudioFileServerMediaSubsession.hh \
		liveMedia/include/AMRAudioFileSink.hh \
		liveMedia/include/AMRAudioFileSource.hh \
		liveMedia/include/AMRAudioRTPSink.hh \
		liveMedia/include/AMRAudioRTPSource.hh \
		liveMedia/include/AMRAudioSource.hh \
		liveMedia/include/AudioInputDevice.hh \
		liveMedia/include/AudioRTPSink.hh \
		liveMedia/include/BasicUDPSink.hh \
		liveMedia/include/BasicUDPSource.hh \
		liveMedia/include/ByteStreamFileSource.hh \
		liveMedia/include/ByteStreamMultiFileSource.hh \
		liveMedia/include/DarwinInjector.hh \
		liveMedia/include/DeviceSource.hh \
		liveMedia/include/FileSink.hh \
		liveMedia/include/FileServerMediaSubsession.hh \
		liveMedia/include/FramedFileSource.hh \
		liveMedia/include/FramedFilter.hh \
		liveMedia/include/FramedSource.hh \
		liveMedia/include/GSMAudioRTPSink.hh \
		liveMedia/include/H261VideoRTPSource.hh \
		liveMedia/include/H263plusVideoRTPSink.hh \
		liveMedia/include/H263plusVideoRTPSource.hh \
		liveMedia/include/HTTPSink.hh \
		liveMedia/include/JPEGVideoRTPSink.hh \
		liveMedia/include/JPEGVideoRTPSource.hh \
		liveMedia/include/JPEGVideoSource.hh \
		liveMedia/include/MP3AudioFileServerMediaSubsession.hh \
		liveMedia/include/MP3ADU.hh \
		liveMedia/include/MP3ADURTPSink.hh \
		liveMedia/include/MP3ADURTPSource.hh \
		liveMedia/include/MP3ADUTranscoder.hh \
		liveMedia/include/MP3ADUinterleaving.hh \
		liveMedia/include/MP3FileSource.hh \
		liveMedia/include/MP3HTTPSource.hh \
		liveMedia/include/MP3Transcoder.hh \
		liveMedia/include/MPEG1or2AudioRTPSink.hh \
		liveMedia/include/MPEG1or2AudioRTPSource.hh \
		liveMedia/include/MPEG1or2AudioStreamFramer.hh \
		liveMedia/include/MPEG1or2Demux.hh \
		liveMedia/include/MPEG1or2DemuxedElementaryStream.hh \
		liveMedia/include/MPEG1or2DemuxedServerMediaSubsession.hh \
		liveMedia/include/MPEG1or2FileServerDemux.hh \
		liveMedia/include/MPEG1or2VideoFileServerMediaSubsession.hh \
		liveMedia/include/MPEG1or2VideoHTTPSink.hh \
		liveMedia/include/MPEG1or2VideoRTPSink.hh \
		liveMedia/include/MPEG1or2VideoRTPSource.hh \
		liveMedia/include/MPEG1or2VideoStreamFramer.hh \
		liveMedia/include/MPEG2TransportFileServerMediaSubsession.hh \
		liveMedia/include/MPEG2TransportStreamFramer.hh \
		liveMedia/include/MPEG2TransportStreamFromPESSource.hh \
		liveMedia/include/MPEG4ESVideoRTPSink.hh \
		liveMedia/include/MPEG4ESVideoRTPSource.hh \
		liveMedia/include/MPEG4GenericRTPSink.hh \
		liveMedia/include/MPEG4GenericRTPSource.hh \
		liveMedia/include/MPEG4LATMAudioRTPSource.hh \
		liveMedia/include/MPEG4VideoFileServerMediaSubsession.hh \
		liveMedia/include/MPEG4VideoStreamFramer.hh \
		liveMedia/include/MPEGVideoStreamFramer.hh \
		liveMedia/include/Media.hh \
		liveMedia/include/MediaSession.hh \
		liveMedia/include/MediaSink.hh \
		liveMedia/include/MediaSource.hh \
		liveMedia/include/MultiFramedRTPSink.hh \
		liveMedia/include/MultiFramedRTPSource.hh \
		liveMedia/include/OnDemandServerMediaSubsession.hh \
		liveMedia/include/PassiveServerMediaSubsession.hh \
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
		liveMedia/include/SIPClient.hh \
		liveMedia/include/ServerMediaSession.hh \
		liveMedia/include/SimpleRTPSink.hh \
		liveMedia/include/SimpleRTPSource.hh \
		liveMedia/include/VideoRTPSink.hh \
		liveMedia/include/WAVAudioFileServerMediaSubsession.hh \
		liveMedia/include/WAVAudioFileSource.hh \
		liveMedia/include/liveMedia.hh \
		liveMedia/include/liveMedia_version.hh \
		liveMedia/include/uLawAudioFilter.hh

.include <bsd.port.pre.mk>

post-extract:
	@${CP} ${FILESDIR}/config.fixed-${OPSYS:L} ${WRKSRC}/

post-build:
	@${RM} -f ${PLIST}
	@${TOUCH} ${PLIST}
	@${ECHO_CMD} bin/playSIP  >> ${PLIST}
	@${ECHO_CMD} bin/openRTSP >> ${PLIST}
	@${ECHO_CMD} bin/sapWatch >> ${PLIST}
	@${ECHO_CMD} live/BasicUsageEnvironment/libBasicUsageEnvironment.a >> ${PLIST}
	@${ECHO_CMD} live/UsageEnvironment/libUsageEnvironment.a           >> ${PLIST}
	@${ECHO_CMD} live/groupsock/libgroupsock.a                         >> ${PLIST}
	@${ECHO_CMD} live/liveMedia/libliveMedia.a                         >> ${PLIST}
.for file in ${BasicUsageEnvironment}
	@${ECHO_CMD} live/BasicUsageEnvironment/include/${file:T} >> ${PLIST}
.endfor
.for file in ${UsageEnvironment}
	@${ECHO_CMD} live/UsageEnvironment/include/${file:T}      >> ${PLIST}
.endfor
.for file in ${groupsock}
	@${ECHO_CMD} live/groupsock/include/${file:T}             >> ${PLIST}
.endfor
.for file in ${liveMedia}
	@${ECHO_CMD} live/liveMedia/include/${file:T}             >> ${PLIST}
.endfor
	@${CAT} ${.CURDIR}/pkg-plist >> ${PLIST}

pre-install:
	@${INSTALL_DATADIR} ${PREFIX}/live
	@${INSTALL_DATADIR} ${PREFIX}/live/groupsock
	@${INSTALL_DATADIR} ${PREFIX}/live/liveMedia
	@${INSTALL_DATADIR} ${PREFIX}/live/UsageEnvironment
	@${INSTALL_DATADIR} ${PREFIX}/live/BasicUsageEnvironment
	@${INSTALL_DATADIR} ${PREFIX}/live/groupsock/include
	@${INSTALL_DATADIR} ${PREFIX}/live/liveMedia/include
	@${INSTALL_DATADIR} ${PREFIX}/live/UsageEnvironment/include
	@${INSTALL_DATADIR} ${PREFIX}/live/BasicUsageEnvironment/include

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/testProgs/playSIP  ${PREFIX}/bin/
	@${INSTALL_PROGRAM} ${WRKSRC}/testProgs/openRTSP ${PREFIX}/bin/
	@${INSTALL_PROGRAM} ${WRKSRC}/testProgs/sapWatch ${PREFIX}/bin/
	@${INSTALL_DATA} ${WRKSRC}/BasicUsageEnvironment/libBasicUsageEnvironment.a ${PREFIX}/live/BasicUsageEnvironment/
	@${INSTALL_DATA} ${WRKSRC}/UsageEnvironment/libUsageEnvironment.a           ${PREFIX}/live/UsageEnvironment/
	@${INSTALL_DATA} ${WRKSRC}/groupsock/libgroupsock.a                         ${PREFIX}/live/groupsock/
	@${INSTALL_DATA} ${WRKSRC}/liveMedia/libliveMedia.a                         ${PREFIX}/live/liveMedia/
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

.include <bsd.port.post.mk>
