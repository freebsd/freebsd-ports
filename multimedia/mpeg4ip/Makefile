# New ports collection makefile for:	mpeg4ip
# Date created:		Wed Jun  5 21:49:46 UTC 2002
# Whom:	          Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mpeg4ip
PORTVERSION=	0.9.9
PORTREVISION=	1
CATEGORIES=	multimedia audio ipv6 net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Standards-based system to encode, stream and play MPEG-4 audio/video

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm \
		pkg-config:${PORTSDIR}/devel/pkgconfig

USE_GNOME=	gtk20
USE_GMAKE=	yes
USE_SDL=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--datadir=${DATADIR} \
		--with-glib-prefix=${LOCALBASE} \
		--with-gtk-prefix=${X11BASE} \
		--program-transform-name=''
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"
INSTALLS_SHLIB=	yes

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

.include <bsd.port.pre.mk>

post-patch:
	@${FIND} ${WRKSRC} -type f -name "*.[ch]" -or -name "*.cpp" | ${XARGS} -n 10 \
		${REINPLACE_CMD} -e \
		's|stdint\.h|inttypes.h|;s|malloc\.h|stdlib.h|'
# replacing distfile's libs with ports' versions
# CFLAGS safeness
	@${REINPLACE_CMD} -E -e 's|lib/SDL/sdl-config|${SDL_CONFIG}|; \
		s|^(SDL_LIBS=).+$$|\1"`${SDL_CONFIG} --libs`"|' \
		${CONFIGURE_WRKSRC}/configure
	@${FIND} ${WRKSRC} -type f -name "Makefile.in" | ${XARGS} \
		-n 10 ${REINPLACE_CMD} -E -e \
		's|-I[^ ]+lib/SDL/include|-I${LOCALBASE}/include/SDL11|; \
		s|-O[0-3]|-O|; \
		s|\$$[^ ]+/lib/SDL/src/main/libSDLmain.a|${LOCALBASE}/lib/libSDLmain-1.1.a|'
	@${REINPLACE_CMD} -E -e \
		's!SDL_(AudioDelayMsec|HasAudioDelayMsec).*;$$!0;!' \
		${WRKSRC}/player/src/audio_sdl.cpp
# do not install manm man pages
	@${REINPLACE_CMD} -E \
		-e 's|api.mpt||' \
		-e 's|^(install-man.*)install-manm|\1|' \
		${WRKSRC}/doc/mp4v2/Makefile.in
.if ${ARCH} != "i386"
# emms opcode should be noop in non-i386 non-MMX ARCH
	@${ECHO_CMD} '#define EMMS()' \
		>> ${WRKSRC}/lib/xvid/portab.h
.endif

post-configure:
# disable GNU auto* tools
# remove -Werror
	@${FIND} ${WRKSRC} -type f -name "Makefile" | ${XARGS} \
		-n 10 ${REINPLACE_CMD} -E -e \
		's! (autoconf|autoheader|automake|aclocal)$$! ${TRUE}!; \
		s|-Werror||g'
# configure is not propagating PTHREAD_LIBS to the makefiles
# investigated by David Yeske <dyeske@yahoo.com>
.if ${OSVERSION} >= 500000
	@${REINPLACE_CMD} -E \
		-e 's|(-lSDL-...)|"${PTHREAD_LIBS} \1"|' \
		${WRKSRC}/player/src/Makefile \
		${WRKSRC}/util/yuv/Makefile \
		${WRKSRC}/util/iptv/Makefile
.endif

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for files in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${files} ${DOCSDIR}/${files:C|^[^/]+/||}
.endfor
.endif

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

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math -fomit-frame-pointer
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
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG}
	@${ECHO_MSG} '===> You can enable additional compilation optimizations'
	@${ECHO_MSG} '===> by defining WITH_OPTIMIZED_CFLAGS'
.endif

.include <bsd.port.post.mk>
