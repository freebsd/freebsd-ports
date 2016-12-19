# $FreeBSD$

PORTNAME=	qmmp
PORTVERSION=	0.10.2
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://qmmp.ylsoftware.com/files/ \
	SF/qmmp-dev/${PORTNAME}/

MAINTAINER=	liangtai.s16@gmail.com
COMMENT=	Qt4-based multimedia player

LICENSE=	GPLv2

CONFLICTS=	${PORTNAME}-qt5-1.*
PORTSCOUT=	limit:^0.*

USES=		cmake:outsource localbase pathfix pkgconfig tar:bzip2
USE_QT4=	corelib gui network xml \
		linguisttools_build moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

OPTIONS_SUB=	yes
OPTIONS_GROUP=	DOCUMENTS PLUGIN_APPLICATION PLUGIN_FORMATS \
		PLUGIN_DSP_EFFECTS PLUGIN_VISUAL_EFFECTS PLUGIN_OUTPUT \
		PLUGIN_PLAYLIST PLUGIN_NETWORKING MISC

PLUGIN_APPLICATION_DESC=	Main program view
OPTIONS_GROUP_PLUGIN_APPLICATION=	GNOMEHOTKEY HOTKEY KDENOTIFY \
		NOTIFIER QMMP_DIALOG QSUI SKINNEDUI STATICON TWOPANELDIALOG

DOCUMENTS_DESC=	Documentation and API Reference
OPTIONS_GROUP_DOCUMENTS=	DOCS DOXYGEN

PLUGIN_FORMATS_DESC=	Support various media formats
OPTIONS_GROUP_PLUGIN_FORMATS=	CDDA FAAD FFMPEG FLAC GME MAD MODPLUG \
		MUSEPACK OPUS SNDFILE VORBIS WAVPACK WILDMIDI

PLUGIN_DSP_EFFECTS_DESC=	DSP effects
OPTIONS_GROUP_PLUGIN_DSP_EFFECTS=	BS2B CROSSFADE LADSPA SOXR STEREO

PLUGIN_VISUAL_EFFECTS_DESC=	Visual effects
OPTIONS_GROUP_PLUGIN_VISUAL_EFFECTS=	ANALYZER PROJECTM

PLUGIN_OUTPUT_DESC=	Output sound systems
OPTIONS_GROUP_PLUGIN_OUTPUT=	ALSA JACK NULLOUT OSS OSS4 \
		PULSEAUDIO QTMULTIMEDIA

PLUGIN_PLAYLIST_DESC=	Playlist operation
OPTIONS_GROUP_PLUGIN_PLAYLIST=	COPYPASTE DIR_ASSOC FILEOPS HAL \
		TRACKCHANGE UDISKS UDISKS2

PLUGIN_NETWORKING_DESC=	Features via the Net
OPTIONS_GROUP_PLUGIN_NETWORKING=	COVER CURL LYRICS MMS SB SCROBBLER

MISC_DESC=	Other features
OPTIONS_GROUP_MISC=	CONVERTER CUE ENCA MPLAYER1 MPLAYER2 MPRIS RGSCAN SID

OPTIONS_DEFAULT=	ALSA ANALYZER BS2B CDDA CONVERTER COPYPASTE COVER \
		CROSSFADE CUE CURL DIR_ASSOC ENCA FAAD FFMPEG FILEOPS FLAC \
		GNOMEHOTKEY GME HAL HOTKEY JACK KDENOTIFY LADSPA LYRICS MAD \
		MMS MODPLUG MPRIS MPLAYER1 MUSEPACK NOTIFIER NULLOUT \
		OPUS OSS4 PROJECTM PULSEAUDIO QMMP_DIALOG QSUI QTMULTIMEDIA \
		RGSCAN SB SCROBBLER SID SKINNEDUI SNDFILE SOXR STATICON STEREO \
		TRACKCHANGE TWOPANELDIALOG UDISKS2 VORBIS WAVPACK WILDMIDI

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

QSUI_DESC=	Simple UI based on standard widgets set
QSUI_USE=	QT4=uic_build
QSUI_CMAKE_BOOL=	USE_QSUI

SKINNEDUI_DESC=	Skinned GUI
SKINNEDUI_USE=	XORG=x11
SKINNEDUI_CMAKE_BOOL=	USE_SKINNED

DIR_ASSOC_DESC=	inode/directory mime type association
DIR_ASSOC_CMAKE_BOOL=	USE_DIR_ASSOC
DIR_ASSOC_USES=	desktop-file-utils

JACK_LIB_DEPENDS=	libjack.so:audio/jack \
		libsoxr.so:audio/libsoxr
JACK_BUILD_DEPENDS=	jackit>=0.121.2:audio/jack
JACK_CMAKE_BOOL=	USE_JACK

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_BOOL=	USE_ALSA

BS2B_DESC=		Support the Bauer stereophonic2binaural effect
BS2B_LIB_DEPENDS=	libbs2b.so:audio/libbs2b
BS2B_CMAKE_BOOL=	USE_BS2B

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	USE_PULSE

QTMULTIMEDIA_DESC=	Support to use Qt low-level multimedia API
QTMULTIMEDIA_USE=	QT4=multimedia
QTMULTIMEDIA_CMAKE_BOOL=	USE_QTMULTIMEDIA

FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac \
		libtag.so:audio/taglib
FLAC_CMAKE_BOOL=	USE_FLAC

MUSEPACK_LIB_DEPENDS=	libmpcdec.so:audio/musepack \
		libtag.so:audio/taglib
MUSEPACK_CMAKE_BOOL=	USE_MPC

GME_DESC=		Support video game music files
GME_LIB_DEPENDS=	libgme.so:audio/libgme
GME_CMAKE_BOOL=	USE_GME

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CMAKE_BOOL=	USE_FFMPEG

MODPLUG_LIB_DEPENDS=	libmodplug.so:audio/libmodplug
MODPLUG_CMAKE_BOOL=	USE_MODPLUG

FAAD_LIB_DEPENDS=	libfaad.so:audio/faad \
		libtag.so:audio/taglib
FAAD_CMAKE_BOOL=	USE_AAC

CDDA_LIB_DEPENDS=	libcdio.so:sysutils/libcdio \
		libcddb.so:audio/libcddb \
		libcdio_cdda.so:sysutils/libcdio-paranoia
CDDA_CMAKE_BOOL=	USE_CDA

ENCA_DESC=		Support automatic character set detection
ENCA_LIB_DEPENDS=	libenca.so:converters/enca
ENCA_CMAKE_BOOL=	USE_ENCA

MPLAYER1_DESC=	mplayer-1.x (multimedia/mplayer)
MPLAYER2_DESC=	mplayer-2.x (multimedia/mplayer2)
MPLAYER1_RUN_DEPENDS=	mplayer:multimedia/mplayer
MPLAYER2_RUN_DEPENDS=	mplayer:multimedia/mplayer2
MPLAYER1_PREVENTS=	MPLAYER2
MPLAYER2_PREVENTS=	MPLAYER1

PROJECTM_DESC=	Support the projectM music visualiser
PROJECTM_LIB_DEPENDS=	libprojectM.so.2:graphics/libprojectm
PROJECTM_USE=	GL=gl QT4=opengl
PROJECTM_CMAKE_BOOL=	USE_PROJECTM

OSS_CMAKE_BOOL=	USE_OSS

OSS4_DESC=		Open Sound System (ver4) support
OSS4_BUILD_DEPENDS=	${LOCALBASE}/lib/oss/include/sys/soundcard.h:audio/oss
OSS4_CMAKE_BOOL=	USE_OSS4

LADSPA_RUN_DEPENDS=	analyseplugin:audio/ladspa
LADSPA_CMAKE_BOOL=	USE_LADSPA

WILDMIDI_DESC=	Support to playback MIDI files
WILDMIDI_LIB_DEPENDS=	libWildMidi.so:audio/wildmidi
WILDMIDI_CMAKE_BOOL=	USE_MIDI

MAD_LIB_DEPENDS=	libmad.so:audio/libmad \
		libtag.so:audio/taglib
MAD_CMAKE_BOOL=	USE_MAD

OPUS_DESC=		Enable reading opusfile tags
OPUS_LIB_DEPENDS=	libopusfile.so:audio/opusfile \
		libopus.so:audio/opus \
		libtag.so:audio/taglib
OPUS_CMAKE_BOOL=	USE_OPUS

RGSCAN_DESC=	ReplayGain scanner
RGSCAN_LIB_DEPENDS=	libtag.so:audio/taglib
RGSCAN_CMAKE_BOOL=	USE_RGSCAN

SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
SNDFILE_CMAKE_BOOL=	USE_SNDFILE

VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg \
		libtag.so:audio/taglib
VORBIS_CMAKE_BOOL=	USE_VORBIS

WAVPACK_LIB_DEPENDS=	libwavpack.so:audio/wavpack
WAVPACK_CMAKE_BOOL=	USE_WAVPACK

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CMAKE_BOOL=	USE_CURL

MMS_LIB_DEPENDS=	libmms.so:net/libmms
MMS_CMAKE_BOOL=	USE_MMS

CUE_CMAKE_BOOL=	USE_CUE

NULLOUT_DESC=	Support null output
NULLOUT_CMAKE_BOOL=	USE_NULL

SOXR_LIB_DEPENDS=	libsoxr.so:audio/libsoxr
SOXR_CMAKE_BOOL=	USE_SOXR

CROSSFADE_DESC=	Support cross-fade effect
CROSSFADE_CMAKE_BOOL=	USE_CROSSFADE

STEREO_DESC=	Support stereo effect
STEREO_CMAKE_BOOL=	USE_STEREO

ANALYZER_DESC=	Support spectrum analyzer visualization
ANALYZER_CMAKE_BOOL=	USE_ANALYZER

CONVERTER_DESC=	Support file type converter
CONVERTER_LIB_DEPENDS=	libtag.so:audio/taglib
CONVERTER_CMAKE_BOOL=	USE_CONVERTER

COPYPASTE_DESC=	Enable copy/paste track infos between playlists
COPYPASTE_CMAKE_BOOL=	USE_COPYPASTE

MPRIS_DESC=	Support the Media Player Remote
MPRIS_USE=	QT4=dbus
MPRIS_CMAKE_BOOL=	USE_MPRIS

SCROBBLER_DESC=	Support Libre.fm/Last.fm scrobbler feature
SCROBBLER_CMAKE_BOOL=	USE_SCROBBLER

SID_DESC=	Support sid
SID_LIB_DEPENDS=	libsidplayfp.so:audio/libsidplayfp
SID_CMAKE_BOOL=	USE_SID

STATICON_DESC=	Support to show status icon
STATICON_CMAKE_BOOL=	USE_STATICON

SB_DESC=	Browser for IceCast stream directory
SB_CMAKE_BOOL=	USE_SB

NOTIFIER_DESC=	Support to popup notifier
NOTIFIER_CMAKE_BOOL=	USE_NOTIFIER

LYRICS_DESC=	Support to show lyrics using lyrics.wikia.com
LYRICS_CMAKE_BOOL=	USE_LYRICS

HAL_USE=	QT4=dbus
HAL_CMAKE_BOOL=	USE_HAL

HOTKEY_DESC=	Support global shortcut keys
HOTKEY_USE=	XORG=x11
HOTKEY_CMAKE_BOOL=	USE_HOTKEY

GNOMEHOTKEY_DESC=	Support GNOME/Cinnamon shortcut keys
GNOMEHOTKEY_USE=	QT4=dbus
GNOMEHOTKEY_CMAKE_BOOL=	USE_GNOMEHOTKEY

FILEOPS_DESC=	Support file operation
FILEOPS_CMAKE_BOOL=	USE_FILEOPS

COVER_DESC=	Support to show cover images
COVER_CMAKE_BOOL=	USE_COVER

KDENOTIFY_DESC=	Support to popup notifier for KDE
KDENOTIFY_USE=	QT4=dbus
KDENOTIFY_CMAKE_BOOL=	USE_KDENOTIFY

TRACKCHANGE_DESC=	Enable to run external command each track
TRACKCHANGE_CMAKE_BOOL=	USE_TRACKCHANGE

UDISKS_DESC=	Support removable disc detection (obsolete)
UDISKS2_DESC=	Support removable disc detection using UDisks
UDISKS_USE=	QT4=dbus
UDISKS2_USE=	QT4=dbus
UDISKS_CMAKE_BOOL=	USE_UDISKS
UDISKS2_CMAKE_BOOL=	USE_UDISKS2

QMMP_DIALOG_DESC=	An original dialog
QMMP_DIALOG_CMAKE_BOOL=	USE_QMMP_DIALOG

TWOPANELDIALOG_DESC=	File dialog by two-panel selector
TWOPANELDIALOG_CMAKE_BOOL=	USE_TWO_PANEL_DIALOG

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMPLAYER1} || ${PORT_OPTIONS:MMPLAYER2}
CMAKE_ARGS+=	-DUSE_MPLAYER:BOOL=TRUE
PLIST_SUB+=	MPLAYER=""
.else
CMAKE_ARGS+=	-DUSE_MPLAYER:BOOL=FALSE
PLIST_SUB+=	MPLAYER="@comment "
.endif

PLIST_SUB+=	SHLIB_VER=${PORTVERSION:C/-.*//}

PATHFIX_CMAKELISTSTXT=	\\"CMakeLists.txt -exec grep -l /pkgconfig {} +\\"
PORTDOCS=	README README.RUS AUTHORS
INSTALLS_ICONS=	yes

CMAKE_ARGS+=	-DUSE_FFMPEG_LEGACY:BOOL=FALSE

post-patch:
	@${GREP} -L '${LOCALBASE}/lib/oss' \
		${WRKSRC}/src/plugins/Output/oss4/CMakeLists.txt | ${XARGS} \
		${REINPLACE_CMD} -e 's|/usr/local/|${LOCALBASE}/|'

pre-configure:
	@${RM} ${BUILD_WRKSRC}/CMakeCache.txt

post-build-DOXYGEN-on:
	cd ${WRKSRC}/doc && doxygen Doxyfile

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}; \
		cd ${WRKSRC} && ${INSTALL_MAN} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-DOXYGEN-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html/search ; \
	cd ${WRKSRC}/doc/html && \
		${INSTALL_MAN} *.html *.png *.css ${STAGEDIR}${DOCSDIR}/html ; \
	cd ${WRKSRC}/doc/html/search && \
		${INSTALL_MAN} *.html *.png *.css *.js ${STAGEDIR}${DOCSDIR}/html/search ; \
	${RM} ${WRKDIR}/PLIST.doc ; \
	${FIND} ${STAGEDIR}${DOCSDIR}/html -type f | \
		${SED} 's|${STAGEDIR}${PREFIX}/||' \
		>> ${WRKDIR}/PLIST.doc ; \
	cd ${WRKDIR} ; ${SED} -i -e '/PLIST.doc/ r PLIST.doc' ${TMPPLIST}

.include <bsd.port.mk>
