# New ports collection makefile for:	mpeg4ip
# Date created:		Wed Jun  5 21:49:46 UTC 2002
# Whom:	          Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mpeg4ip
PORTVERSION=	1.6.1
PORTREVISION=	19
CATEGORIES=	multimedia audio ipv6 net
MASTER_SITES=	LOCAL/ahze
# http://sourceforge.net/forum/forum.php?thread_id=1839453&forum_id=59136
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
#MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	${PKG_NAME_SUFFIX}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Standards-based system to encode, stream and play MPEG-4 audio/video

BUILD_DEPENDS=	mp4v2>=1.9.1:${PORTSDIR}/multimedia/mp4v2 \
		${LOCALBASE}/include/linux/videodev.h:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	faac.0:${PORTSDIR}/audio/faac \
		faad.2:${PORTSDIR}/audio/faad \
		mp3lame.0:${PORTSDIR}/audio/lame \
		id3tag.0:${PORTSDIR}/audio/libid3tag \
		a52.0:${PORTSDIR}/audio/liba52 \
		mpeg2.0:${PORTSDIR}/multimedia/libmpeg2	\
		avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		x264.116:${PORTSDIR}/multimedia/x264
RUN_DEPENDS=	mp4v2>=1.9.1:${PORTSDIR}/multimedia/mp4v2

USE_GNOME=	gtk20
USE_SDL=	sdl
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include/SDL -I${LOCALBASE}/include/ffmpeg -I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ARGS=	--enable-ffmpeg=${LOCALBASE} \
		--enable-mp4live \
		--disable-static

OPTIONS=	ARTS "Enable Arts Support" Off \
		ESOUND "Enable Esound Support" Off \
		IPV6 "Enable IPV6 Support" On \
		NAS "Enable Nas Support" Off \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" Off \
		XVID "Enable XVID Support" On

DOC_FILES=	${PORTDOCS}
PORTDOCS=	MAINREADME.html MP4LIVE_INTERNALS.html MPEG4IP_Guide.pdf \
		MP4LIVE_README.html PLAYER_INTERNALS.html PLAYER_README.html \
		ReadingList.txt encoding.htm m4rm.html \
		mp4player.jpg mrm.html pi.html prm.html

MAN1=	gmp4player.1 mp4creator.1 mp4encode.1 mp4live.1
MAN3=	MP4.3 MP4AddAudioTrack.3 MP4AddHintTrack.3 MP4AddODTrack.3 \
	MP4AddRtpESConfigurationPacket.3 MP4AddRtpHint.3 MP4AddRtpImmediateData.3 \
	MP4AddRtpPacket.3 MP4AddRtpSampleData.3 MP4AddRtpVideoHint.3 MP4AddSceneTrack.3 \
	MP4AddSystemsTrack.3 MP4AddTrack.3 MP4AddTrackEdit.3 MP4AddVideoTrack.3 \
	MP4AppendHintTrackSdp.3 MP4AppendSessionSdp.3 MP4BinaryToBase16.3 MP4BinaryToBase64.3 \
	MP4CloneTrack.3 MP4Close.3 MP4ConvertFromMovieDuration.3 MP4ConvertFromTrackDuration.3 \
	MP4ConvertFromTrackTimestamp.3 MP4ConvertToTrackDuration.3 MP4ConvertToTrackTimestamp.3  \
	MP4CopySample.3 MP4CopyTrack.3 MP4Create.3 MP4DeleteTrack.3 MP4DeleteTrackEdit.3 \
	MP4Dump.3 MP4FileInfo.3 MP4FindTrackId.3 MP4FindTrackIndex.3 MP4GetAudioProfileLevel.3 \
	MP4GetDuration.3 MP4GetGraphicsProfileLevel.3 MP4GetHintTrackReferenceTrackId.3 MP4GetHintTrackRtpPayload.3 \
	MP4GetHintTrackSdp.3 MP4GetNumberOfTracks.3 MP4GetODProfileLevel.3 MP4GetRtpHintNumberOfPackets.3 \
	MP4GetRtpPacketBFrame.3 MP4GetRtpPacketTransmitOffset.3 MP4GetRtpTimestampStart.3 \
	MP4GetSampleDuration.3 MP4GetSampleIdFromEditTime.3 MP4GetSampleIdFromTime.3 \
	MP4GetSampleRenderingOffset.3 MP4GetSampleSize.3 MP4GetSampleSync.3 MP4GetSampleTime.3 \
	MP4GetSceneProfileLevel.3 MP4GetSessionSdp.3 MP4GetTimeScale.3 MP4GetTrackAudioMpeg4Type.3 \
	MP4GetTrackAudioType.3 MP4GetTrackBitRate.3 MP4GetTrackDuration.3 MP4GetTrackESConfiguration.3 \
	MP4GetTrackEditDuration.3 MP4GetTrackEditDwell.3 MP4GetTrackEditMediaStart.3 MP4GetTrackEditStart.3 \
	MP4GetTrackEditTotalDuration.3 MP4GetTrackFixedSampleDuration.3 MP4GetTrackMaxSampleSize.3 \
	MP4GetTrackNumberOfEdits.3 MP4GetTrackNumberOfSamples.3 MP4GetTrackTimeScale.3 MP4GetTrackType.3 \
	MP4GetTrackVideoFrameRate.3 MP4GetTrackVideoHeight.3 MP4GetTrackVideoType.3 MP4GetTrackVideoWidth.3 \
	MP4GetVerbosity.3 MP4GetVideoProfileLevel.3 MP4Info.3 MP4MakeIsmaCompliant.3 \
	MP4Modify.3 MP4Optimize.3 MP4Read.3 MP4ReadRtpHint.3 MP4ReadRtpPacket.3 \
	MP4ReadSample.3 MP4ReadSampleFromEditTime.3 MP4ReadSampleFromTime.3 MP4SetAudioProfileLevel.3 \
	MP4SetGraphicsProfileLevel.3 MP4SetHintTrackRtpPayload.3 MP4SetHintTrackSdp.3 \
	MP4SetODProfileLevel.3 MP4SetRtpTimestampStart.3 MP4SetSampleRenderingOffset.3 \
	MP4SetSceneProfileLevel.3 MP4SetSessionSdp.3 MP4SetTimeScale.3 MP4SetTrackESConfiguration.3 \
	MP4SetTrackEditDuration.3 MP4SetTrackEditDwell.3 MP4SetTrackEditMediaStart.3 \
	MP4SetTrackTimeScale.3 MP4SetVerbosity.3 MP4SetVideoProfileLevel.3 \
	MP4WriteRtpHint.3 MP4WriteSample.3

.include <bsd.port.pre.mk>

###
## Auto detect possible extensions
###
# arts
.if exists(${LOCALBASE}/lib/libartsc.so.0)
WITH_ARTS=	yes
.endif
# esound
.if ${HAVE_GNOME:Mesound}!=""
WITH_ESOUND=	yes
.endif
# nas
.if exists(${LOCALBASE}/lib/libaudio.so.2)
WITH_NAS=	yes
.endif
# xvid
.if exists(${LOCALBASE}/lib/libxvidcore.so.4)
WITH_XVID=	yes
.endif

###
## Enable extensions based on user choices
###
# arts
.if defined(WITH_ARTS)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
.endif
# esound
.if defined(WITH_ESOUND)
USE_GNOME+=	esound

PKG_NAME_SUFFIX+=-esound
.endif
# nas
.if defined(WITH_NAS)
LIB_DEPENDS+=	audio.2:${PORTSDIR}/audio/nas
.endif

# ipv6
.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

# xvid
.if !defined(WITHOUT_XVID)
LIB_DEPENDS+=	xvidcore.4:${PORTSDIR}/multimedia/xvid

PLIST_SUB+=	XVID=""
.else
PLIST_SUB+=	XVID="@comment "
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile
.endif

#post-patch:
pre-configure:
	@${TOUCH} -f ${WRKSRC}/bootstrapped
# don't compile or use libmp4v2
	@${REINPLACE_CMD} -e 's|mp4v2||' \
		${WRKSRC}/lib/Makefile.in
	@${FIND} ${WRKSRC} -type f -name Makefile.in | \
		${XARGS} -n 10 ${REINPLACE_CMD} -e \
		's|-I$(top_srcdir)/lib/mp4v2||; \
		s|$$(top_builddir)/lib/mp4v2/libmp4v2.la||; \
		s|$$(top_srcdir)/lib/mp4v2/libmp4v2.la||; \
		s|@LIBS@|@LIBS@ -lmp4v2|; \
		s|nasm|yasm|'
	@${REINPLACE_CMD} -e 's|-Werror||' \
		${WRKSRC}/common/video/iso-mpeg4/src/Makefile.in
	@${REINPLACE_CMD} -e 's|mp4venc_template.par||' \
		${WRKSRC}/server/util/mp4encode/Makefile.in
	@${FIND} ${WRKSRC} -type f -name "*.[ch]" -or -name "*.cpp" | ${XARGS} -n 10 \
		${REINPLACE_CMD} -e \
		's|<stdint.h>|<inttypes.h>|; \
		s|<malloc.h>|<stdlib.h>|; \
		s|<avcodec.h>|<libavcodec/avcodec.h>|; \
		s|<swscale.h>|<libswscale/swscale.h>|; \
		s|<strstream.h>|<iostream>|'
# replacing distfile's libs with ports' versions
# SDL related fixes
# a few others
	@${REINPLACE_CMD} -E -e 's|lib/SDL/sdl-config|${SDL_CONFIG}|; \
		s|sdl-config|${SDL_CONFIG}|; \
		s|^(SDL_LIBS=).+$$|\1"`${SDL_CONFIG} --libs`"|; \
		s|-Wmissing-declarations||; s|-Wmissing-prototypes||; \
		s|>&/|>/|; s|nasm|yasm|' \
		${CONFIGURE_WRKSRC}/configure
# do not install manm man pages
	@${REINPLACE_CMD} -E \
		-e 's|api.mpt||' \
		-e 's|^(install-man.*)install-manm|\1|' \
		${WRKSRC}/doc/mp4v2/Makefile.in
# objformat
	@${FIND} ${WRKSRC} -name configure | ${XARGS} ${REINPLACE_CMD} -e 's|echo aout|echo elf|'
	@${REINPLACE_CMD} -e 's|$${enable_ffmpeg}/lib/libavcodec.a|-lavcodec -lswscale|g' \
		${WRKSRC}/configure

# replace bundled mp4v2 with placeholder
post-configure:
	@${RM} -rf ${WRKSRC}/lib/mp4v2
	@${MKDIR} ${WRKSRC}/lib/mp4v2
	@echo '#include "mpeg4ip.h"' > ${WRKSRC}/lib/mp4v2/mp4.h


post-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/server/util/mp4encode/mp4encode \
		 ${PREFIX}/bin
	${INSTALL_DATA} \
		${WRKSRC}/server/util/mp4encode/mp4venc_template.par \
		${DATADIR}
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for files in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${files} ${DOCSDIR}
.endfor
.endif

.if (defined(MACHINE_CPU) && ${MACHINE_CPU:Mmmx} == "mmx") && !defined(PACKAGE_BUILDING)
WITH_MMX=yes
.else
WITHOUT_MMX=yes
.endif

###
## Enable extensions based on arch detection
###
# mmx
.ifdef(WITHOUT_MMX)
CONFIGURE_ARGS+=	--disable-mmx
.else
BUILD_DEPENDS+=	yasm:${PORTSDIR}/devel/yasm
.endif
# compiler optimizations
.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math -fomit-frame-pointer
.endif

.include <bsd.port.post.mk>
