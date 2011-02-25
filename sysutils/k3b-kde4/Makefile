# New ports collection makefile for:    k3b
# Date created:                         2003/02/13
# Whom:                                 Heiner <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	k3b
PORTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	sysutils multimedia kde
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	A CD/DVD recording GUI for KDE4

BUILD_DEPENDS=	${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml
LIB_DEPENDS=	cdda_paranoia:${PORTSDIR}/audio/cdparanoia \
		samplerate:${PORTSDIR}/audio/libsamplerate \
		kcddb:${PORTSDIR}/multimedia/kdemultimedia4

LATEST_LINK=	${PORTNAME}-kde4

USE_BZIP2=	yes
USE_CMAKE=	yes
CMAKE_ARGS=	-DK3B_BUILD_K3BSETUP:BOOL=OFF
USE_KDE4=	automoc4 kdeprefix kdelibs
USE_CDRTOOLS=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui dbus network phonon qt3support sql svg webkit xml \
		qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS=	CDRDAO "Burning: Use cdrdao" ON \
		DVDPLUSRW "Burning: DVD+RW Tools (DVD+/-R(W))" ON \
		EMOVIX "Burning: eMovix (bootable video CDs)" OFF \
		VCDIMAGER "Burning: VCDImager (video CDs)" OFF \
		FFMPEG "Decoder: various (multimedia/ffmpeg)" ON \
		FLAC "Decoder: flac (audio/flac)" ON \
		MAD "Decoder: mp3 (audio/libmad)" ON \
		MUSEPACK "Decoder: musepack (audio/musepack)" ON \
		SNDFILE "Decoder: various (audio/libsndfile)" ON \
		VORBIS_DEC "Decoder: ogg/vorbis" ON \
		LAME "Encoder: mp3 (audio/lame)" OFF \
		SOX "Encoder: various (audio/sox)" OFF \
		VORBIS_ENC "Encoder: ogg/vorbis" ON \
		LIBDVDREAD "Misc: libdvdread (video dvd ripping)" ON \
		MUSICBRAINZ "Misc: Musicbrainz (audio metadata lookup)" ON \
		NORMALIZE "Misc: Normalize (adjust audio to a std. level)" OFF \
		TAGLIB "Misc: taglib (reading/writing audio metadata)" ON \
		TRANSCODE "Misc: Transcode (for DVD ripping)" OFF

.include <bsd.port.options.mk>

.if defined(WITH_CDRDAO)
RUN_DEPENDS+=	cdrdao:${PORTSDIR}/sysutils/cdrdao
.endif

.if defined(WITH_DVDPLUSRW)
RUN_DEPENDS+=	dvd+rw-format:${PORTSDIR}/sysutils/dvd+rw-tools
.endif

.if defined(WITH_EMOVIX)
RUN_DEPENDS+=	mkmovixiso:${PORTSDIR}/multimedia/emovix
.endif

.if defined(WITH_VCDIMAGER)
RUN_DEPENDS+=	vcdxrip:${PORTSDIR}/multimedia/vcdimager
.endif

.if defined(WITH_FFMPEG)
LIB_DEPENDS+=	avcodec:${PORTSDIR}/multimedia/ffmpeg
PLIST_SUB+=	FFMPEG=""
.else
CMAKE_ARGS+=	-DK3B_BUILD_FFMPEG_DECODER_PLUGIN:BOOL=OFF
PLIST_SUB+=	FFMPEG="@comment "
.endif

.if defined(WITH_FLAC)
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
PLIST_SUB+=	FLAC=""
.else
CMAKE_ARGS+=	-DK3B_BUILD_FLAC_DECODER_PLUGIN:BOOL=OFF
PLIST_SUB+=	FLAC="@comment "
.endif

.if defined(WITH_MAD)
LIB_DEPENDS+=	mad:${PORTSDIR}/audio/libmad
PLIST_SUB+=	MAD=""
.else
CMAKE_ARGS+=	-DK3B_BUILD_MAD_DECODER_PLUGIN:BOOL=OFF
PLIST_SUB+=	MAD="@comment "
.endif

.if defined(WITH_MUSEPACK)
CMAKE_ARGS+=	-DCMAKE_REQUIRED_INCLUDES:STRING="${LOCALBASE}/include"
LIB_DEPENDS+=	mpcdec:${PORTSDIR}/audio/musepack
PLIST_SUB+=	MUSEPACK=""
.else
CMAKE_ARGS+=	-DK3B_BUILD_MUSE_DECODER_PLUGIN:BOOL=OFF
PLIST_SUB+=	MUSEPACK="@comment "
.endif

.if defined(WITH_SNDFILE)
LIB_DEPENDS+=	sndfile:${PORTSDIR}/audio/libsndfile
PLIST_SUB+=	SNDFILE=""
.else
CMAKE_ARGS+=	-DK3B_BUILD_SNDFILE_DECODER_PLUGIN:BOOL=OFF
PLIST_SUB+=	SNDFILE="@comment "
.endif

.if defined(WITH_VORBIS_DEC)
LIB_DEPENDS+=	ogg:${PORTSDIR}/audio/libogg
PLIST_SUB+=	VORBIS_DEC=""
.else
CMAKE_ARGS+=	-DK3B_BUILD_OGGVORBIS_DECODER_PLUGIN:BOOL=OFF
PLIST_SUB+=	VORBIS_DEC="@comment "
.endif

.if defined(WITH_LAME)
LIB_DEPENDS+=	mp3lame:${PORTSDIR}/audio/lame
PLIST_SUB+=	LAME=""
.else
CMAKE_ARGS+=	-DK3B_BUILD_LAME_ENCODER_PLUGIN:BOOL=OFF
PLIST_SUB+=	LAME="@comment "
.endif

.if defined(WITH_SOX)
RUN_DEPENDS+=	sox:${PORTSDIR}/audio/sox
PLIST_SUB+=	SOX=""
.else
CMAKE_ARGS+=	-DK3B_BUILD_SOX_ENCODER_PLUGIN:BOOL=OFF
PLIST_SUB+=	SOX="@comment "
.endif

.if defined(WITH_VORBIS_ENC)
LIB_DEPENDS+=	ogg:${PORTSDIR}/audio/libogg
PLIST_SUB+=	VORBIS_ENC=""
.else
CMAKE_ARGS+=	-DK3B_BUILD_OGGVORBIS_ENCODER_PLUGIN:BOOL=OFF
PLIST_SUB+=	VORBIS_ENC="@comment "
.endif

.if defined(WITH_LIBDVDREAD)
LIB_DEPENDS+=	dvdread.4:${PORTSDIR}/multimedia/libdvdread
PLIST_SUB+=	LIBDVDREAD=""
.else
CMAKE_ARGS+=	-DK3B_ENABLE_DVD_RIPPING:BOOL=OFF
PLIST_SUB+=	LIBDVDREAD="@comment "
.endif

.if defined(WITH_MUSICBRAINZ)
LIB_DEPENDS+=	musicbrainz:${PORTSDIR}/audio/libmusicbrainz
PLIST_SUB+=	MUSICBRAINZ=""
.else
CMAKE_ARGS+=	-DK3B_ENABLE_MUSICBRAINZ:BOOL=OFF
PLIST_SUB+=	MUSICBRAINZ="@comment "
.endif

.if defined(WITH_NORMALIZE)
RUN_DEPENDS+=	normalize:${PORTSDIR}/audio/normalize
.endif

.if defined(WITH_TAGLIB)
LIB_DEPENDS+=	tag:${PORTSDIR}/audio/taglib
PLIST_SUB+=	TAGLIB=""
.else
CMAKE_ARGS+=	-DK3B_ENABLE_TAGLIB:BOOL=OFF
PLIST_SUB+=	TAGLIB="@comment "
.endif

.if defined(WITH_TRANSCODE)
RUN_DEPENDS+=	transcode:${PORTSDIR}/multimedia/transcode
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
