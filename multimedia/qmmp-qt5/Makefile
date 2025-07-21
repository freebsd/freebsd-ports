PORTNAME=	qmmp
PORTVERSION=	1.7.7
CATEGORIES=	multimedia
MASTER_SITES=	http://qmmp.ylsoftware.com/files/${PORTNAME}/${DISTVERSION:R}/ \
		SF/qmmp-dev/${PORTNAME}/${DISTVERSION:R}/
PKGNAMESUFFIX=	-qt5

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Qt5-based multimedia player
WWW=		https://qmmp.ylsoftware.com/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake desktop-file-utils gl gnome iconv:wchar_t pathfix \
		pkgconfig qt:5 tar:bzip2 xorg
USE_GL=		opengl
PATHFIX_CMAKELISTSTXT=	src/qmmpui/CMakeLists.txt src/qmmp/CMakeLists.txt
USE_QT=		core dbus gui network sql widgets x11extras xml \
		buildtools:build linguisttools:build qmake:build
USE_XORG=	x11 xcb
USE_LDCONFIG=	yes

CONFLICTS=	${PORTNAME}-qt6
PORTSCOUT=	limit:^1\..*

PLIST_SUB=	SHLIB_VER=${DISTVERSION:C/-.*//} \
		LIB_SUFFX=-${DISTVERSION:R} \
		BIN_SUFFX=-${DISTVERSION:R:R}

PORTDOCS=	README README.RUS AUTHORS

CMAKE_OFF=	USE_CDA \
		USE_MAD \
		USE_MMS \
		USE_MPC \
		USE_MPLAYER
CMAKE_ON=	USE_ANALYZER \
		USE_COPYPASTE \
		USE_COVER \
		USE_CROSSFADE \
		USE_CUE \
		USE_DIR_ASSOC \
		USE_FILEOPS \
		USE_GNOMEHOTKEY \
		USE_HISTORY \
		USE_KDENOTIFY \
		USE_HOTKEY \
		USE_MPRIS \
		USE_NOTIFIER \
		USE_NULL \
		USE_SKINNED \
		USE_STATICON \
		USE_STEREO \
		USE_TRACKCHANGE

OPTIONS_SUB=	yes
OPTIONS_GROUP=	DOCUMENTS PLUGIN_APPLICATION PLUGIN_FORMATS \
		PLUGIN_DSP_EFFECTS PLUGIN_VISUAL_EFFECTS PLUGIN_OUTPUT \
		PLUGIN_PLAYLIST PLUGIN_NETWORKING MISC

OPTIONS_GROUP_DOCUMENTS=		DOCS DOXYGEN

OPTIONS_GROUP_MISC=			CONVERTER ENCA FILEWRITER \
					RGSCAN SID

OPTIONS_GROUP_PLUGIN_APPLICATION=	QMMP_DIALOG QSUI TWOPANELDIALOG

OPTIONS_GROUP_PLUGIN_DSP_EFFECTS=	BS2B LADSPA SOXR

OPTIONS_GROUP_PLUGIN_FORMATS=		ARCHIVE FAAD FFMPEG FLAC GME \
					MPG123 OPUS SNDFILE \
					VORBIS WAVPACK WILDMIDI XMP

OPTIONS_GROUP_PLUGIN_NETWORKING=	CURL LYRICS SB SCROBBLER

OPTIONS_GROUP_PLUGIN_OUTPUT=		ALSA JACK OSS OSS4 \
					PIPEWIRE PULSEAUDIO QTMULTIMEDIA SHOUTCAST

OPTIONS_GROUP_PLUGIN_PLAYLIST=		UDISKS

OPTIONS_GROUP_PLUGIN_VISUAL_EFFECTS=	PROJECTM

OPTIONS_DEFAULT=	ALSA ARCHIVE BS2B CONVERTER CURL ENCA \
			FFMPEG FILEWRITER FLAC GME JACK LADSPA \
			LYRICS OPUS OSS4 PROJECTM PIPEWIRE \
			PULSEAUDIO QMMP_DIALOG QSUI RGSCAN SHOUTCAST SB \
			SCROBBLER SID SNDFILE SOXR TWOPANELDIALOG \
			UDISKS VORBIS WAVPACK WILDMIDI XMP

OPTIONS_EXCLUDE_i386=	ARCHIVE

ARCHIVE_DESC=			Read archived media file
BS2B_DESC=			Support the Bauer stereophonic2binaural effect
CONVERTER_DESC=			Support file type converter
DOCUMENTS_DESC=			Documentation and API Reference
ENCA_DESC=			Support automatic character set detection
FILEWRITER_DESC=		Dump output sound into ogg audio file
GME_DESC=			Support video game music files
LYRICS_DESC=			Support to show lyrics using lyrics.wikia.com
MISC_DESC=			Other features
OPUS_DESC=			Enable reading opusfile tags
OSS4_DESC=			Open Sound System (ver4) support
PLUGIN_APPLICATION_DESC=	Main program view
PLUGIN_DSP_EFFECTS_DESC=	DSP effects
PLUGIN_FORMATS_DESC=		Support various media formats
PLUGIN_NETWORKING_DESC=		Features via the Net
PLUGIN_OUTPUT_DESC=		Output sound systems
PLUGIN_PLAYLIST_DESC=		Playlist operation
PLUGIN_VISUAL_EFFECTS_DESC=	Visual effects
PROJECTM_DESC=			Support the projectM music visualiser
QMMP_DIALOG_DESC=		An original dialog
QSUI_DESC=			Simple UI based on standard widgets set
QTMULTIMEDIA_DESC=		Support to use Qt low-level multimedia API
RGSCAN_DESC=			ReplayGain scanner
SB_DESC=			Browser for IceCast stream directory
SCROBBLER_DESC=			Support Libre.fm/Last.fm scrobbler feature
SID_DESC=			Support sid
TWOPANELDIALOG_DESC=		File dialog by two-panel selector
UDISKS_DESC=			Support removable disc detection using UDisks
WILDMIDI_DESC=			Support to playback MIDI files
XMP_DESC=			Support various module formats using libxmp

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	USE_ALSA

ARCHIVE_USES=		libarchive
ARCHIVE_CMAKE_BOOL=	USE_ARCHIVE

BS2B_LIB_DEPENDS=	libbs2b.so:audio/libbs2b
BS2B_CMAKE_BOOL=	USE_BS2B

CONVERTER_LIB_DEPENDS=	libtag.so:audio/taglib
CONVERTER_CMAKE_BOOL=	USE_CONVERTER

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CMAKE_BOOL=	USE_CURL

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

ENCA_LIB_DEPENDS=	libenca.so:converters/enca
ENCA_CMAKE_BOOL=	USE_ENCA

FAAD_LIB_DEPENDS=	libfaad.so:audio/faad \
			libtag.so:audio/taglib
FAAD_CMAKE_BOOL=	USE_AAC

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CMAKE_BOOL=	USE_FFMPEG

FILEWRITER_LIB_DEPENDS=	libvorbisenc.so:audio/libvorbis
FILEWRITER_CMAKE_BOOL=	USE_FILEWRITER

FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac \
			libtag.so:audio/taglib
FLAC_CMAKE_BOOL=	USE_FLAC

GME_LIB_DEPENDS=	libgme.so:audio/libgme
GME_CMAKE_BOOL=		USE_GME

JACK_BUILD_DEPENDS=	jackit>=0.121.2:audio/jack
JACK_LIB_DEPENDS=	libjack.so:audio/jack \
			libsoxr.so:audio/libsoxr
JACK_CMAKE_BOOL=	USE_JACK

LADSPA_RUN_DEPENDS=	analyseplugin:audio/ladspa
LADSPA_CMAKE_BOOL=	USE_LADSPA

LYRICS_CMAKE_BOOL=	USE_LYRICS

MPG123_LIB_DEPENDS=	libmpg123.so:audio/mpg123 \
			libtag.so:audio/taglib
MPG123_CMAKE_BOOL=	USE_MPG123

OPUS_LIB_DEPENDS=	libopusfile.so:audio/opusfile \
			libopus.so:audio/opus \
			libtag.so:audio/taglib
OPUS_CMAKE_BOOL=	USE_OPUS

OSS_CMAKE_BOOL=		USE_OSS

OSS4_BUILD_DEPENDS=	${LOCALBASE}/lib/oss/include/sys/soundcard.h:audio/oss
OSS4_CMAKE_BOOL=	USE_OSS4

PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_CMAKE_BOOL=	USE_PIPEWIRE

PROJECTM_LIB_DEPENDS=	libprojectM.so:graphics/libprojectm
PROJECTM_CMAKE_BOOL=	USE_PROJECTM

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	USE_PULSE

QMMP_DIALOG_CMAKE_BOOL=	USE_QMMP_DIALOG

QSUI_CMAKE_BOOL=	USE_QSUI

QTMULTIMEDIA_USE=	QT=multimedia
QTMULTIMEDIA_CMAKE_BOOL=USE_QTMULTIMEDIA

RGSCAN_LIB_DEPENDS=	libtag.so:audio/taglib
RGSCAN_CMAKE_BOOL=	USE_RGSCAN

SB_CMAKE_BOOL=		USE_SB

SCROBBLER_CMAKE_BOOL=	USE_SCROBBLER

SHOUTCAST_LIB_DEPENDS=	libogg.so:audio/libogg \
			libshout.so:audio/libshout \
			libsoxr.so:audio/libsoxr \
			libvorbis.so:audio/libvorbis
SHOUTCAST_CMAKE_BOOL=	USE_SHOUT

SID_LIB_DEPENDS=	libsidplayfp.so:audio/libsidplayfp
SID_CMAKE_BOOL=		USE_SID

SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
SNDFILE_CMAKE_BOOL=	USE_SNDFILE

SOXR_LIB_DEPENDS=	libsoxr.so:audio/libsoxr
SOXR_CMAKE_BOOL=	USE_SOXR

TWOPANELDIALOG_CMAKE_BOOL=	USE_TWO_PANEL_DIALOG

UDISKS_RUN_DEPENDS=	bsdisks:sysutils/bsdisks
UDISKS_CMAKE_BOOL=	USE_UDISKS

VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
			libogg.so:audio/libogg \
			libtag.so:audio/taglib
VORBIS_CMAKE_BOOL=	USE_VORBIS

WAVPACK_LIB_DEPENDS=	libwavpack.so:audio/wavpack
WAVPACK_CMAKE_BOOL=	USE_WAVPACK

WILDMIDI_LIB_DEPENDS=	libWildMidi.so:audio/wildmidi
WILDMIDI_CMAKE_BOOL=	USE_MIDI

XMP_LIB_DEPENDS=	libxmp.so:audio/libxmp
XMP_CMAKE_BOOL=		USE_XMP

post-patch:
	@${GREP} -L '${LOCALBASE}/lib/oss' \
		${WRKSRC}/src/plugins/Output/oss4/CMakeLists.txt | ${XARGS} \
		${REINPLACE_CMD} -e 's|/usr/local/|${LOCALBASE}/|'
	@${REINPLACE_CMD} -e 's|Qt6Multimedia|Qt5Multimedia|g' ${WRKSRC}/src/plugins/Output/CMakeLists.txt

post-build-DOXYGEN-on:
	cd ${WRKSRC}/doc && doxygen Doxyfile

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}; \
		cd ${WRKSRC} && ${INSTALL_MAN} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-DOXYGEN-on:
	cd ${WRKSRC}/doc/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/html
	@${FIND} -P ${STAGEDIR}${DOCSDIR}/html -type f 2>/dev/null | \
		${SED} -ne 's|^${STAGEDIR}${PREFIX}/||p' >> ${TMPPLIST}

.include <bsd.port.mk>
