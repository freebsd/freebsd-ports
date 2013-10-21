# Created by: Heiner <h.eichmann@gmx.de>
# $FreeBSD$

PORTNAME=	k3b
PORTVERSION=	2.0.2
PORTREVISION=	13
CATEGORIES=	sysutils multimedia kde
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE CD/DVD writing suite

LIB_DEPENDS=	cdda_paranoia:${PORTSDIR}/audio/cdparanoia \
		samplerate:${PORTSDIR}/audio/libsamplerate
RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrtools
BUILD_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrtools

LATEST_LINK=	${PORTNAME}-kde4

USE_BZIP2=	yes
USES=		cmake
CMAKE_ARGS=	-DK3B_BUILD_K3BSETUP:BOOL=OFF \
		-DK3B_ENABLE_MUSICBRAINZ:BOOL=OFF
USE_KDE4=	automoc4 kdeprefix kdelibs libkcddb sharedmime
USE_QT4=	gui dbus network phonon qt3support sql svg webkit xml \
		qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	CDRDAO DVDPLUSRW EMOVIX VCDIMAGER FFMPEG FLAC MAD \
		MUSEPACK SNDFILE VORBIS_DEC LAME SOX VORBIS_ENC \
		LIBDVDREAD NORMALIZE TAGLIB TRANSCODE
OPTIONS_DEFAULT=CDRDAO DVDPLUSRW FFMPEG FLAC MAD MUSEPACK SNDFILE \
		VORBIS_DEC VORBIS_ENC LIBDVDREAD TAGLIB
NO_OPTIONS_SORT=yes
CDRDAO_DESC=	Burning: cdrdao
DVDPLUSRW_DESC=	Burning: DVD+RW Tools (DVD+/-R(W))
EMOVIX_DESC=	Burning: eMovix (bootable video CDs)
VCDIMAGER_DESC=	Burning: VCDImager (video CDs)
FFMPEG_DESC=	Decoder: various (multimedia/ffmpeg)
FLAC_DESC=	Decoder: FLAC (audio/flac)
MAD_DESC=	Decoder: MP3 (audio/libmad)
MUSEPACK_DESC=	Decoder: Musepack (audio/musepack)
SNDFILE_DESC=	Decoder: various (audio/libsndfile)
VORBIS_DEC_DESC=Decoder: Ogg Vorbis
LAME_DESC=	Encoder: MP3 (audio/lame)
SOX_DESC=	Encoder: various (audio/sox)
VORBIS_ENC_DESC=Encoder: Ogg Vorbis
LIBDVDREAD_DESC=Misc: libdvdread (video DVD ripping)
NORMALIZE_DESC=	Misc: normalize (adjust audio to a std. level)
TAGLIB_DESC=	Misc: TagLib (reading/writing audio metadata)
TRANSCODE_DESC=	Misc: Transcode (DVD ripping)

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCDRDAO}
RUN_DEPENDS+=	cdrdao:${PORTSDIR}/sysutils/cdrdao
.endif

.if ${PORT_OPTIONS:MDVDPLUSRW}
RUN_DEPENDS+=	dvd+rw-format:${PORTSDIR}/sysutils/dvd+rw-tools
.endif

.if ${PORT_OPTIONS:MEMOVIX}
RUN_DEPENDS+=	mkmovixiso:${PORTSDIR}/multimedia/emovix
.endif

.if ${PORT_OPTIONS:MVCDIMAGER}
RUN_DEPENDS+=	vcdxrip:${PORTSDIR}/multimedia/vcdimager
.endif

.if ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	avcodec:${PORTSDIR}/multimedia/ffmpeg
PLIST_SUB+=	FFMPEG=""
.else
CMAKE_ARGS+=	-DK3B_BUILD_FFMPEG_DECODER_PLUGIN:BOOL=OFF
PLIST_SUB+=	FFMPEG="@comment "
.endif

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
PLIST_SUB+=	FLAC=""
.else
CMAKE_ARGS+=	-DK3B_BUILD_FLAC_DECODER_PLUGIN:BOOL=OFF
PLIST_SUB+=	FLAC="@comment "
.endif

.if ${PORT_OPTIONS:MMAD}
LIB_DEPENDS+=	mad:${PORTSDIR}/audio/libmad
PLIST_SUB+=	MAD=""
.else
CMAKE_ARGS+=	-DK3B_BUILD_MAD_DECODER_PLUGIN:BOOL=OFF
PLIST_SUB+=	MAD="@comment "
.endif

.if ${PORT_OPTIONS:MMUSEPACK}
CMAKE_ARGS+=	-DCMAKE_REQUIRED_INCLUDES:STRING="${LOCALBASE}/include"
LIB_DEPENDS+=	mpcdec:${PORTSDIR}/audio/musepack
PLIST_SUB+=	MUSEPACK=""
.else
CMAKE_ARGS+=	-DK3B_BUILD_MUSE_DECODER_PLUGIN:BOOL=OFF
PLIST_SUB+=	MUSEPACK="@comment "
.endif

.if ${PORT_OPTIONS:MSNDFILE}
LIB_DEPENDS+=	sndfile:${PORTSDIR}/audio/libsndfile
PLIST_SUB+=	SNDFILE=""
.else
CMAKE_ARGS+=	-DK3B_BUILD_SNDFILE_DECODER_PLUGIN:BOOL=OFF
PLIST_SUB+=	SNDFILE="@comment "
.endif

.if ${PORT_OPTIONS:MVORBIS_DEC}
LIB_DEPENDS+=	ogg:${PORTSDIR}/audio/libogg
PLIST_SUB+=	VORBIS_DEC=""
.else
CMAKE_ARGS+=	-DK3B_BUILD_OGGVORBIS_DECODER_PLUGIN:BOOL=OFF
PLIST_SUB+=	VORBIS_DEC="@comment "
.endif

.if ${PORT_OPTIONS:MLAME}
LIB_DEPENDS+=	mp3lame:${PORTSDIR}/audio/lame
PLIST_SUB+=	LAME=""
.else
CMAKE_ARGS+=	-DK3B_BUILD_LAME_ENCODER_PLUGIN:BOOL=OFF
PLIST_SUB+=	LAME="@comment "
.endif

.if ${PORT_OPTIONS:MSOX}
RUN_DEPENDS+=	sox:${PORTSDIR}/audio/sox
PLIST_SUB+=	SOX=""
.else
CMAKE_ARGS+=	-DK3B_BUILD_SOX_ENCODER_PLUGIN:BOOL=OFF
PLIST_SUB+=	SOX="@comment "
.endif

.if ${PORT_OPTIONS:MVORBIS_ENC}
LIB_DEPENDS+=	ogg:${PORTSDIR}/audio/libogg
PLIST_SUB+=	VORBIS_ENC=""
.else
CMAKE_ARGS+=	-DK3B_BUILD_OGGVORBIS_ENCODER_PLUGIN:BOOL=OFF
PLIST_SUB+=	VORBIS_ENC="@comment "
.endif

.if ${PORT_OPTIONS:MLIBDVDREAD}
LIB_DEPENDS+=	dvdread:${PORTSDIR}/multimedia/libdvdread
PLIST_SUB+=	LIBDVDREAD=""
.else
CMAKE_ARGS+=	-DK3B_ENABLE_DVD_RIPPING:BOOL=OFF
PLIST_SUB+=	LIBDVDREAD="@comment "
.endif

.if ${PORT_OPTIONS:MNORMALIZE}
RUN_DEPENDS+=	normalize:${PORTSDIR}/audio/normalize
.endif

.if ${PORT_OPTIONS:MTAGLIB}
LIB_DEPENDS+=	tag:${PORTSDIR}/audio/taglib
PLIST_SUB+=	TAGLIB=""
.else
CMAKE_ARGS+=	-DK3B_ENABLE_TAGLIB:BOOL=OFF
PLIST_SUB+=	TAGLIB="@comment "
.endif

.if ${PORT_OPTIONS:MTRANSCODE}
RUN_DEPENDS+=	transcode:${PORTSDIR}/multimedia/transcode
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
