# New ports collection makefile for:	mpeg4ip
# Date created:		Wed Jun  5 21:49:46 UTC 2002
# Whom:	          Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mpeg4ip
PORTVERSION=	0.9.6
CATEGORIES=	multimedia audio ipv6 net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lioux@FreeBSD.org

BUILD_DEPENDS=	libtool:${PORTSDIR}/devel/libtool \
		nasm:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${DATADIR} \
		--with-glib-prefix=${LOCALBASE} \
		--with-gtk-prefix=${LOCALBASE} \
		--program-transform-name=''

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

DOC_FILES=	COPYING README doc/MPEG4IP_Guide.pdf

MAN1=	gmp4player.1 mp4creator.1 mp4encode.1 mp4live.1
MAN3=   MP4.3 MP4AddAudioTrack.3 MP4AddHintTrack.3 MP4AddODTrack.3 \
	MP4AddRtpESConfigurationPacket.3 MP4AddRtpHint.3 \
	MP4AddRtpImmediateData.3 MP4AddRtpPacket.3 MP4AddRtpSampleData.3 \
	MP4AddRtpVideoHint.3 MP4AddSceneTrack.3 MP4AddSystemsTrack.3 \
	MP4AddTrack.3 MP4AddVideoTrack.3 MP4AppendHintTrackSdp.3 \
	MP4AddTrackEdit.3 \
	MP4AppendSessionSdp.3 MP4BinaryToBase16.3 MP4BinaryToBase64.3 \
	MP4CloneTrack.3 \
	MP4Close.3 MP4ConvertFromMovieDuration.3 \
	MP4ConvertFromTrackDuration.3 MP4ConvertFromTrackTimestamp.3 \
	MP4ConvertToTrackDuration.3 MP4ConvertToTrackTimestamp.3 \
	MP4CopySample.3 MP4CopyTrack.3 MP4DeleteTrackEdit.3 \
	MP4Create.3 MP4DeleteTrack.3 MP4Dump.3 MP4FindTrackId.3 \
	MP4FileInfo.3 \
	MP4FindTrackIndex.3 MP4GetAudioProfileLevel.3 MP4GetDuration.3 \
	MP4GetGraphicsProfileLevel.3 MP4GetHintTrackReferenceTrackId.3 \
	MP4GetHintTrackRtpPayload.3 MP4GetHintTrackSdp.3 \
	MP4GetNumberOfTracks.3 MP4GetODProfileLevel.3 \
	MP4GetRtpHintNumberOfPackets.3 MP4GetRtpPacketBFrame.3 \
	MP4GetRtpPacketTransmitOffset.3 MP4GetRtpTimestampStart.3 \
	MP4GetSampleDuration.3 MP4GetSampleIdFromTime.3 \
	MP4GetSampleIdFromEditTime.3 \
	MP4GetSampleRenderingOffset.3 MP4GetSampleSize.3 \
	MP4GetSampleSync.3 MP4GetSampleTime.3 MP4GetSceneProfileLevel.3 \
	MP4GetSessionSdp.3 MP4GetTimeScale.3 MP4GetTrackAudioType.3 \
	MP4GetTrackBitRate.3 MP4GetTrackDuration.3 \
	MP4GetTrackESConfiguration.3 MP4GetTrackFixedSampleDuration.3 \
	MP4GetTrackMaxSampleSize.3 MP4GetTrackNumberOfSamples.3 \
	MP4GetTrackTimeScale.3 MP4GetTrackType.3 \
	MP4GetTrackAudioMpeg4Type.3 MP4GetTrackEditDuration.3 \
	MP4GetTrackEditDwell.3 MP4GetTrackEditMediaStart.3 \
	MP4GetTrackEditStart.3 MP4GetTrackEditTotalDuration.3 \
	MP4GetTrackNumberOfEdits.3 \
	MP4GetTrackVideoFrameRate.3 MP4GetTrackVideoHeight.3 \
	MP4GetTrackVideoType.3 MP4GetTrackVideoWidth.3 MP4GetVerbosity.3 \
	MP4GetVideoProfileLevel.3 MP4MakeIsmaCompliant.3 MP4Modify.3 \
	MP4Info.3 \
	MP4Optimize.3 MP4Read.3 MP4ReadRtpHint.3 MP4ReadRtpPacket.3 \
	MP4ReadSample.3 MP4SetAudioProfileLevel.3 \
	MP4ReadSampleFromEditTime.3 MP4ReadSampleFromTime.3 \
	MP4SetGraphicsProfileLevel.3 MP4SetHintTrackRtpPayload.3 \
	MP4SetHintTrackSdp.3 MP4SetODProfileLevel.3 \
	MP4SetRtpTimestampStart.3 MP4SetSampleRenderingOffset.3 \
	MP4SetSceneProfileLevel.3 MP4SetSessionSdp.3 MP4SetTimeScale.3 \
	MP4SetTrackEditDuration.3 MP4SetTrackEditDwell.3 \
	MP4SetTrackEditMediaStart.3 \
	MP4SetTrackESConfiguration.3 MP4SetTrackTimeScale.3 \
	MP4SetVerbosity.3 MP4SetVideoProfileLevel.3 MP4WriteRtpHint.3 \
	MP4WriteSample.3

post-extract:
.for dir in SDL
	@${RM} -Rf ${WRKSRC}/lib/${dir}
.endfor

post-patch:
	@${FIND} ${WRKSRC} -type f -name "*.[ch]" | ${XARGS} -n 10 \
		${REINPLACE_CMD} -e \
		's|stdint\.h|inttypes.h|;s|malloc\.h|stdlib.h|'
# replacing distfile's libs with ports' versions
	@${REINPLACE_CMD} -E -e 's|(SUBDIRS.+)SDL|\1|' \
		${WRKSRC}/lib/Makefile.in
	@${REINPLACE_CMD} -E -e 's|lib/SDL/sdl-config|${SDL_CONFIG}|; \
		s|^(SDL_LIBS=).+$$|\1"`${SDL_CONFIG} --libs`"|' \
		${CONFIGURE_WRKSRC}/configure
	@${FIND} ${WRKSRC} -type f -name "Makefile.in" | ${XARGS} \
		-n 10 ${REINPLACE_CMD} -E -e \
		's|-I[^ ]+lib/SDL/include|-I${LOCALBASE}/include/SDL11|; \
		s|\$$[^ ]+/lib/SDL/src/main/libSDLmain.a|${LOCALBASE}/lib/libSDLmain-1.1.a|'
	@${REINPLACE_CMD} -E -e \
		's!SDL_(AudioDelayMsec|HasAudioDelayMsec).*;$$!0;!' \
		${WRKSRC}/player/src/audio_sdl.cpp

post-configure:
# disable GNU auto* tools
# remove -Werror
	@${FIND} ${WRKSRC} -type f -name "Makefile" | ${XARGS} \
		-n 10 ${REINPLACE_CMD} -E -e \
		's! (autoconf|autoheader|automake|aclocal)$$! ${TRUE}!; \
		s|-Werror||g'

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for files in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${files} ${DOCSDIR}/${files:C|^[^/]+/||}
.endfor
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
WITHOUT_MMX=	yes
.else 
. if (defined(MACHINE_CPU) && ${MACHINE_CPU:Mi486} == "i486")
WITH_OPTIMIZED_BYTESWAP=yes
. endif

. if defined(WITH_OPTIMIZED_BYTESWAP)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-include::mpeg4ip_byteswap.h
. endif
.endif

.if ${OSVERSION} >= 400014 && !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.ifdef(WITHOUT_MMX)
CONFIGURE_ARGS+=	--disable-mmx
.endif

pre-everything::
.ifndef(WITHOUT_IPV6)
	@${ECHO_MSG} '===> Define WITHOUT_IPV6 if you want to disable IPv6 support'
.endif
.ifndef(WITHOUT_MMX)
	@${ECHO_MSG} '===> Define WITHOUT_MMX if your system does not support MMX'
.endif
.ifndef(WITH_OPTIMIZED_BYTESWAP)
	@${ECHO_MSG}
	@${ECHO_MSG} '===> Define WITH_OPTIMIZED_BYTESWAP to use optimized byteswap'
	@${ECHO_MSG} '===> routines. This works only in the i386 architecture, and'
	@${ECHO_MSG} '===> only with 486 processors and above.'
.endif


.include <bsd.port.post.mk>
