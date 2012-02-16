# New ports collection Makefile for:	qmmp
# Date created:		Fri Jan 30 01:13:20 JST 2009
# Whom:      SimaMoto,RyoTa <liangtai.s4@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	qmmp
PORTVERSION=	0.5.2
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://qmmp.ylsoftware.com/files/ \
		${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	liangtai.s4@gmail.com
COMMENT=	A Qt4-based multimedia player

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_QT_VER=	4
USE_CMAKE=	yes
QT_COMPONENTS=	corelib gui network xml dbus \
		qmake_build rcc_build uic_build moc_build linguist_build
USE_LDCONFIG=	yes

OPTIONS=	SKINNEDUI	"Skinned GUI" on \
		APIDOC	"Doxygen generated class reference document" off \
		PULSE	"Support the PulseAudio output" on \
		ALSA	"Support the ALSA output" off \
		OSS	"Support the OSS output" on \
		OSS4	"Support the OSS4 output" off \
		JACK	"Support the JACK output" on \
		NULLOUT "Support a null output" on \
		FLAC	"Support to playback FLAC files" on \
		MUSEPACK	"Support to playback MPC files" on \
		FFMPEG	"Support to playback FFMPEG files" on \
		MODPLUG	"Support to playback MOD files" on \
		WILDMIDI	"Support to playback MIDI files" on \
		GME	"Support video game music files" on \
		MAD	"Support to playback MAD files" on \
		VORBIS	"Support to playback Vorbis/OGG files" on \
		SNDFILE "Support to playback Sndfile files" on \
		WAVPACK "Support to playback WAVPack files" on \
		CUE	"Support to CUE sheets" on \
		CDIO	"Support to playback compact discs" on \
		FAAD	"Support to playback through FAAD decoder" on \
		LADSPA	"Support the LADSPA effect" on \
		CROSSFADE "Support cross-fade effect" on \
		BS2B	"Support the Bauer stereophonic2binaural effect" on \
		STEREO	"Support stereo effect" on \
		SRCONV 	"Support the sample rate converter" on \
		MPLAYER	"Support VIDEO playback through Mplayer" on \
		CURL	"Support cURL streaming transport" on \
		MMS	"Support MMS streaming transport" on \
		PROJECTM	"Support the projectM music visualiser" on \
		ANALYZER	"Supoort spectrum analyzer visualization" on \
		ENCA	"Support automatic character set detection" on \
		MPRIS	"Support the Media Player Remote" on \
		SCROBBLER	"Support Libre.fm/Last.fm scrobbler feature" on \
		STATICON	"Support to show status icon" on \
		NOTIFIER	"Support to popup notifier" on \
		LYRICS	"Support to show lyrics using lyrics.wikia.com" on \
		HOTKEY	"Support to set shortcut keys" on \
		FILEOPS	"Support file operation" on \
		COVER	"Support to show cover images" on \
		KDENOTIFY	"Support to popup notifier for KDE" on \
		HAL "Support removable disc detection using HAL" on \
		UDISKS	"Support removable disc detection using UDisks" on \
		QMMP_DIALOG	"An original dialog" on

.include <bsd.port.options.mk>

.ifndef(WITHOUT_APIDOC)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
.endif

.ifndef(WITHOUT_SKINNEDUI)
PLIST_SUB+=	SKINNEDUI=""
PLUGIN_OPTIONS_CMAKE+=	-DUSE_SKINNED:BOOL=TRUE
.else
PLIST_SUB+=	SKINNEDUI="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_SKINNED:BOOL=FALSE
.endif

.ifndef(WITHOUT_JACK)
PLIST_SUB+=	JACK=""
#LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
BUILD_DEPENDS+=	jackit>=0.121.2:${PORTSDIR}/audio/jack
PLUGIN_OPTIONS_CMAKE+=	-DUSE_JACK:BOOL=TRUE
.else
PLIST_SUB+=	JACK="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_JACK:BOOL=FALSE
.endif

.ifndef(WITHOUT_ALSA)
PLIST_SUB+=	ALSA=""
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
PLUGIN_OPTIONS_CMAKE+=	-DUSE_ALSA:BOOL=TRUE
.else
PLIST_SUB+=	ALSA="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_ALSA:BOOL=FALSE
.endif

.ifndef(WITHOUT_BS2B)
PLIST_SUB+=	BS2B=""
LIB_DEPENDS+=	bs2b.0:${PORTSDIR}/audio/libbs2b
PLUGIN_OPTIONS_CMAKE+=	-DUSE_BS2B:BOOL=TRUE
.else
PLIST_SUB+=	BS2B="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_BS2B:BOOL=FALSE
.endif

.ifndef(WITHOUT_PULSE)
PLIST_SUB+=	PULSE_AUDIO=""
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
PLUGIN_OPTIONS_CMAKE+=	-DUSE_PULSE:BOOL=TRUE
.else
PLIST_SUB+=	PULSE_AUDIO="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_PULSE:BOOL=FALSE
.endif

.ifndef(WITHOUT_FLAC)
PLIST_SUB+=	FLAC=""
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac
PLUGIN_OPTIONS_CMAKE+=	-DUSE_FLAC:BOOL=TRUE
.else
PLIST_SUB+=	FLAC="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_FLAC:BOOL=FALSE
.endif

.ifndef(WITHOUT_MUSEPACK)
PLIST_SUB+=	MUSEPACK=""
LIB_DEPENDS+=	mpcdec.7:${PORTSDIR}/audio/musepack
PLUGIN_OPTIONS_CMAKE+=	-DUSE_MPC:BOOL=TRUE
.else
PLIST_SUB+=	MUSEPACK="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_MPC:BOOL=FALSE
.endif

.ifndef(WITHOUT_GME)
PLIST_SUB+=	GME=""
LIB_DEPENDS+=	gme.0:${PORTSDIR}/audio/libgme
PLUGIN_OPTIONS_CMAKE+=	-DUSE_GME:BOOL=TRUE
.else
PLIST_SUB+=	GME="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_GME:BOOL=FALSE
.endif

.ifndef(WITHOUT_FFMPEG)
PLIST_SUB+=	FFMPEG=""
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg
PLUGIN_OPTIONS_CMAKE+=	-DUSE_FFMPEG:BOOL=TRUE
.else
PLIST_SUB+=	FFMPEG="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_FFMPEG:BOOL=FALSE
.endif

.ifndef(WITHOUT_MODPLUG)
PLIST_SUB+=	MODPLUG=""
LIB_DEPENDS+=	modplug.1:${PORTSDIR}/audio/libmodplug
PLUGIN_OPTIONS_CMAKE+=	-DUSE_MODPLUG:BOOL=TRUE
.else
PLIST_SUB+=	MODPLUG="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_MODPLUG:BOOL=FALSE
.endif

.ifndef(WITHOUT_FAAD)
PLIST_SUB+=	FAAD=""
LIB_DEPENDS+=	faad.2:${PORTSDIR}/audio/faad
PLUGIN_OPTIONS_CMAKE+=	-DUSE_AAC:BOOL=TRUE
.else
PLIST_SUB+=	FAAD="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_AAC:BOOL=FALSE
.endif

.ifndef(WITHOUT_CDIO)
PLIST_SUB+=	CDIO=""
LIB_DEPENDS+=	cdio.13:${PORTSDIR}/sysutils/libcdio
PLUGIN_OPTIONS_CMAKE+=	-DUSE_CDA:BOOL=TRUE
.else
PLIST_SUB+=	CDIO="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_CDA:BOOL=FALSE
.endif

.ifndef(WITHOUT_ENCA)
PLIST_SUB+=	ENCA=""
LIB_DEPENDS+=	enca.5:${PORTSDIR}/converters/enca
PLUGIN_OPTIONS_CMAKE+=	-DUSE_ENCA:BOOL=TRUE
.else
PLIST_SUB+=	ENCA="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_ENCA:BOOL=FALSE
.endif

.ifndef(WITHOUT_MPLAYER)
PLIST_SUB+=	MPLAYER=""
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
PLUGIN_OPTIONS_CMAKE+=	-DUSE_MPLAYER:BOOL=TRUE
.else
PLIST_SUB+=	MPLAYER="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_MPLAYER:BOOL=FALSE
.endif

.ifndef(WITHOUT_PROJECTM)
PLIST_SUB+=	PROJECTM=""
LIB_DEPENDS+=	projectM.2:${PORTSDIR}/graphics/libprojectm
PLUGIN_OPTIONS_CMAKE+=	-DUSE_PROJECTM:BOOL=TRUE
.else
PLIST_SUB+=	PROJECTM="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_PROJECTM:BOOL=FALSE
.endif

.ifndef(WITHOUT_OSS)
PLIST_SUB+=	OSS=""
PLUGIN_OPTIONS_CMAKE+=	-DUSE_OSS:BOOL=TRUE
.else
PLIST_SUB+=	OSS="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_OSS:BOOL=FALSE
.endif

.ifndef(WITHOUT_OSS4)
PLIST_SUB+=	OSS4=""
BUILD_DEPENDS+=	${LOCALBASE}/lib/oss/include/sys/soundcard.h:${PORTSDIR}/audio/oss
PLUGIN_OPTIONS_CMAKE+=	-DUSE_OSS4:BOOL=TRUE
.else
PLIST_SUB+=	OSS4="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_OSS4:BOOL=FALSE
.endif

.ifndef(WITHOUT_LADSPA)
PLIST_SUB+=	LADSPA=""
RUN_DEPENDS+=	analyseplugin:${PORTSDIR}/audio/ladspa
PLUGIN_OPTIONS_CMAKE+=	-DUSE_LADSPA:BOOL=TRUE
.else
PLIST_SUB+=	LADSPA="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_LADSPA:BOOL=FALSE
.endif

.ifndef(WITHOUT_WILDMIDI)
PLIST_SUB+=	WILDMIDI=""
LIB_DEPENDS+=	WildMidi.1:${PORTSDIR}/audio/wildmidi
PLUGIN_OPTIONS_CMAKE+=	-DUSE_MIDI:BOOL=TRUE
.else
PLIST_SUB+=	WILDMIDI="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_MIDI:BOOL=FALSE
.endif

.ifndef(WITHOUT_MAD)
PLIST_SUB+=	MAD=""
LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad
PLUGIN_OPTIONS_CMAKE+=	-DUSE_MAD:BOOL=TRUE
.else
PLIST_SUB+=	MAD="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_MAD:BOOL=FALSE
.endif

.ifndef(WITHOUT_SNDFILE)
PLIST_SUB+=	SNDFILE=""
LIB_DEPENDS+=	sndfile.1:${PORTSDIR}/audio/libsndfile
PLUGIN_OPTIONS_CMAKE+=	-DUSE_SNDFILE:BOOL=TRUE
.else
PLIST_SUB+=	SNDFILE="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_SNDFILE:BOOL=FALSE
.endif

.ifndef(WITHOUT_VORBIS)
PLIST_SUB+=	VORBIS=""
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis
PLUGIN_OPTIONS_CMAKE+=	-DUSE_VORBIS:BOOL=TRUE
.else
PLIST_SUB+=	VORBIS="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_VORBIS:BOOL=FALSE
.endif

.ifndef(WITHOUT_WAVPACK)
PLIST_SUB+=	WAVPACK=""
LIB_DEPENDS+=	wavpack.2:${PORTSDIR}/audio/wavpack
PLUGIN_OPTIONS_CMAKE+=	-DUSE_WAVPACK:BOOL=TRUE
.else
PLIST_SUB+=	WAVPACK="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_WAVPACK:BOOL=FALSE
.endif

.ifndef(WITHOUT_CURL)
PLIST_SUB+=	CURL=""
LIB_DEPENDS+=	curl.6:${PORTSDIR}/ftp/curl
PLUGIN_OPTIONS_CMAKE+=	-DUSE_CURL:BOOL=TRUE
.else
PLIST_SUB+=	CURL="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_CURL:BOOL=FALSE
.endif

.ifndef(WITHOUT_MMS)
PLIST_SUB+=	MMS=""
LIB_DEPENDS+=	mms.0:${PORTSDIR}/net/libmms
PLUGIN_OPTIONS_CMAKE+=	-DUSE_MMS:BOOL=TRUE
.else
PLIST_SUB+=	MMS="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_MMS:BOOL=FALSE
.endif

.ifndef(WITHOUT_CUE)
PLIST_SUB+=	CUE=""
PLUGIN_OPTIONS_CMAKE+=	-DUSE_CUE:BOOL=TRUE
.else
PLIST_SUB+=	CUE="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_CUE:BOOL=FALSE
.endif

.ifndef(WITHOUT_NULLOUT)
PLIST_SUB+=	NULLOUT=""
PLUGIN_OPTIONS_CMAKE+=	-DUSE_NULL:BOOL=TRUE
.else
PLIST_SUB+=	NULLOUT="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_NULL:BOOL=FALSE
.endif

.ifndef(WITHOUT_SRCONV)
PLIST_SUB+=	SRCONV=""
PLUGIN_OPTIONS_CMAKE+=	-DUSE_SRC:BOOL=TRUE
.else
PLIST_SUB+=	SRCONV="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_SRC:BOOL=FALSE
.endif

.ifndef(WITHOUT_CROSSFADE)
PLIST_SUB+=	CROSSFADE=""
PLUGIN_OPTIONS_CMAKE+=	-DUSE_CROSSFADE:BOOL=TRUE
.else
PLIST_SUB+=	CROSSFADE="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_CROSSFADE:BOOL=FALSE
.endif

.ifndef(WITHOUT_STEREO)
PLIST_SUB+=	STEREO=""
PLUGIN_OPTIONS_CMAKE+=	-DUSE_STEREO:BOOL=TRUE
.else
PLIST_SUB+=	STEREO="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_STEREO:BOOL=FALSE
.endif

.ifndef(WITHOUT_ANALYZER)
PLIST_SUB+=	ANALYZER=""
PLUGIN_OPTIONS_CMAKE+=	-DUSE_ANALYZER:BOOL=TRUE
.else
PLIST_SUB+=	ANALYZER="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_ANALYZER:BOOL=FALSE
.endif

.ifndef(WITHOUT_MPRIS)
PLIST_SUB+=	MPRIS=""
PLUGIN_OPTIONS_CMAKE+=	-DUSE_MPRIS:BOOL=TRUE
.else
PLIST_SUB+=	MPRIS="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_MPRIS:BOOL=FALSE
.endif

.ifndef(WITHOUT_SCROBBLER)
PLIST_SUB+=	SCROBBLER=""
PLUGIN_OPTIONS_CMAKE+=	-DUSE_SCROBBLER:BOOL=TRUE
.else
PLIST_SUB+=	SCROBBLER="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_SCROBBLER:BOOL=FALSE
.endif

.ifndef(WITHOUT_STATICON)
PLIST_SUB+=	STATICON=""
PLUGIN_OPTIONS_CMAKE+=	-DUSE_STATICON:BOOL=TRUE
.else
PLIST_SUB+=	STATICON="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_STATICON:BOOL=FALSE
.endif

.ifndef(WITHOUT_NOTIFIER)
PLIST_SUB+=	NOTIFIER=""
PLUGIN_OPTIONS_CMAKE+=	-DUSE_NOTIFIER:BOOL=TRUE
.else
PLIST_SUB+=	NOTIFIER="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_NOTIFIER:BOOL=FALSE
.endif

.ifndef(WITHOUT_LYRICS)
PLIST_SUB+=	LYRICS=""
PLUGIN_OPTIONS_CMAKE+=	-DUSE_LYRICS:BOOL=TRUE
.else
PLIST_SUB+=	LYRICS="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_LYRICS:BOOL=FALSE
.endif

.ifndef(WITHOUT_HAL)
PLIST_SUB+=	HAL=""
PLUGIN_OPTIONS_CMAKE+=	-DUSE_HAL:BOOL=TRUE
.else
PLIST_SUB+=	HAL="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_HAL:BOOL=FALSE
.endif

.ifndef(WITHOUT_HOTKEY)
PLIST_SUB+=	HOTKEY=""
PLUGIN_OPTIONS_CMAKE+=	-DUSE_HOTKEY:BOOL=TRUE
.else
PLIST_SUB+=	HOTKEY="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_HOTKEY:BOOL=FALSE
.endif

.ifndef(WITHOUT_FILEOPS)
PLIST_SUB+=	FILEOPS=""
PLUGIN_OPTIONS_CMAKE+=	-DUSE_FILEOPS:BOOL=TRUE
.else
PLIST_SUB+=	FILEOPS="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_FILEOPS:BOOL=FALSE
.endif

.ifndef(WITHOUT_COVER)
PLIST_SUB+=	COVER=""
PLUGIN_OPTIONS_CMAKE+=	-DUSE_COVER:BOOL=TRUE
.else
PLIST_SUB+=	COVER="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_COVER:BOOL=FALSE
.endif

.ifndef(WITHOUT_KDENOTIFY)
PLIST_SUB+=	KDENOTIFY=""
PLUGIN_OPTIONS_CMAKE+=	-DUSE_KDENOTIFY:BOOL=TRUE
.else
PLIST_SUB+=	KDENOTIFY="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_KDENOTIFY:BOOL=FALSE
.endif

.ifndef(WITHOUT_UDISKS)
PLIST_SUB+=	UDISKS=""
PLUGIN_OPTIONS_CMAKE+=	-DUSE_UDISKS:BOOL=TRUE
.else
PLIST_SUB+=	UDISKS="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_UDISKS:BOOL=FALSE
.endif

.ifndef(WITHOUT_QMMP_DIALOG)
PLIST_SUB+=	QMMP_DIALOG=""
PLUGIN_OPTIONS_CMAKE+=	-DUSE_QMMP_DIALOG:BOOL=TRUE
.else
PLIST_SUB+=	QMMP_DIALOG="@comment "
PLUGIN_OPTIONS_CMAKE+=	-DUSE_QMMP_DIALOG:BOOL=FALSE
.endif

.if !defined(WITHOUT_FAAD) || !defined(WITHOUT_MAD) \
	|| !defined(WITHOUT_MUSEPACK) || !defined(WITHOUT_FLAC) \
	|| !defined(WITHOUT_VORBIS)
LIB_DEPENDS+=	tag.1:${PORTSDIR}/audio/taglib
.endif

PORTDOCS=	README README.RUS AUTHORS
SUB_FILES=	qmmp
INSTALLS_ICONS=	yes

CMAKE_ARGS+=	${PLUGIN_OPTIONS_CMAKE} \
	-DCMAKE_REQUIRED_INCLUDES:PATH=${LOCALBASE}/include
CMAKE_OUTSOURCE=yes
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

post-patch:
	${REINPLACE_CMD} -e 's| -ldl| $${CMAKE_DL_LIBS}|' \
		${WRKSRC}/src/plugins/Effect/ladspa/CMakeLists.txt
	${REINPLACE_CMD} -e 's|/usr/|${LOCALBASE}/|g' \
		${WRKSRC}/src/plugins/Output/oss4/CMakeLists.txt
	${REINPLACE_CMD} -e 's|DESTINATION bin|DESTINATION libexec|' \
		${WRKSRC}/src/ui/CMakeLists.txt

pre-configure:
	${RM} -f ${BUILD_WRKSRC}/CMakeCache.txt

post-build:
.ifndef(WITHOUT_APIDOC)
	cd ${WRKSRC}/doc && doxygen Doxyfile
.endif

post-install:
.ifndef(WITHOUT_SKINNEDUI)
	${INSTALL_SCRIPT} ${WRKDIR}/qmmp ${PREFIX}/bin
.endif
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}; \
	cd ${WRKSRC} && ${INSTALL_MAN} ${PORTDOCS} ${DOCSDIR}
.endif
.ifndef(WITHOUT_APIDOC)
	${MKDIR} ${DOCSDIR}/html/search ; \
	cd ${WRKSRC}/doc/html && ${INSTALL_MAN} *.html *.png *.css ${DOCSDIR}/html ; \
	cd ${WRKSRC}/doc/html/search && \
		${INSTALL_MAN} *.html *.png *.css *.js ${DOCSDIR}/html/search ; \
	${RM} -f ${WRKDIR}/PLIST.doc ; \
	${FIND} ${DOCSDIR}/html -type f | ${SED} 's|${LOCALBASE}/||' \
		>> ${WRKDIR}/PLIST.doc ; \
	${FIND} ${DOCSDIR}/html -type d | ${SED} 's|${LOCALBASE}/|@dirrm |' \
		| ${SORT} -r >> ${WRKDIR}/PLIST.doc ; \
	cd ${WRKDIR} ; ${SED} -i -e '/PLIST.doc/ r PLIST.doc' ${TMPPLIST}
.endif

.include <bsd.port.mk>
