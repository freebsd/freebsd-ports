# New ports collection Makefile for:	qmmp
# Date created:		Fri Jan 30 01:13:20 JST 2009
# Whom:      SimaMoto,RyoTa <liangtai.s4@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	qmmp
PORTVERSION=	0.4.5
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://qmmp.ylsoftware.com/files/ \
	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	liangtai.s4@gmail.com
COMMENT=	A Qt4-based multimedia player

LICENSE=	GPLv2

LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/libmad \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		ogg.7:${PORTSDIR}/audio/libogg \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		wavpack.2:${PORTSDIR}/audio/wavpack \
		tag.1:${PORTSDIR}/audio/taglib \
		curl.6:${PORTSDIR}/ftp/curl \
		mms.0:${PORTSDIR}/net/libmms

USE_BZIP2=	yes
USE_QT_VER=	4
USE_GMAKE=	yes
QT_COMPONENTS=	corelib gui network xml dbus \
		qmake_build rcc_build uic_build moc_build linguist_build
USE_LDCONFIG=	yes

OPTIONS=	JACK "Support the JACK output server" on \
		PULSE "Support the PulseAudio output" on \
		ALSA "Support the ALSA output" off \
		BS2B "Support the Bauer stereophonic2binaural" on \
		FLAC "Support to playback FLAC files" on \
		MUSEPACK "Support to playback MPC files" on \
		FFMPEG "Support to playback FFMPEG files" on \
		MODPLUG "Support to playback MOD files" on \
		FAAD "Support to playback through FAAD decoder" on \
		CDIO "Support to playback compact discs" on \
		LADSPA "Support the LADSPA effect" on \
		ENCA "Support the sample rate converter" on \
		MPLAYER "Support to playback through Mplayer" on \
		PROJECTM "Support the projectM music visualiser" on

.include <bsd.port.pre.mk>

PLUGIN_OPTIONS?=	OSS_PLUGIN #default

.if !defined(WITHOUT_JACK)
PLIST_SUB+=	JACK=""
LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
PLUGIN_OPTIONS+=	JACK_PLUGIN
.else
PLIST_SUB+=	JACK="@comment "
.endif

.if !defined(WITHOUT_ALSA)
PLIST_SUB+=	ALSA=""
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
PLUGIN_OPTIONS+=	ALSA_PLUGIN
.else
PLIST_SUB+=	ALSA="@comment "
.endif

.if !defined(WITHOUT_BS2B)
PLIST_SUB+=	BS2B=""
LIB_DEPENDS+=	bs2b.0:${PORTSDIR}/audio/libbs2b
PLUGIN_OPTIONS+=	BS2B_PLUGIN
.else
PLIST_SUB+=	BS2B="@comment "
.endif

.if !defined(WITHOUT_PULSE)
PLIST_SUB+=	PULSE_AUDIO=""
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
PLUGIN_OPTIONS+=	PULSE_AUDIO_PLUGIN
.else
PLIST_SUB+=	PULSE_AUDIO="@comment "
.endif

.if !defined(WITHOUT_FLAC)
PLIST_SUB+=	FLAC=""
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac
PLUGIN_OPTIONS+=	FLAC_PLUGIN
.else
PLIST_SUB+=	FLAC="@comment "
.endif

.if !defined(WITHOUT_MUSEPACK)
PLIST_SUB+=	MUSEPACK=""
LIB_DEPENDS+=	mpcdec.7:${PORTSDIR}/audio/musepack
PLUGIN_OPTIONS+=	MUSEPACK_PLUGIN
.else
PLIST_SUB+=	MUSEPACK="@comment "
.endif

.if !defined(WITHOUT_FFMPEG)
PLIST_SUB+=	FFMPEG=""
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg
PLUGIN_OPTIONS+=	FFMPEG_PLUGIN
.else
PLIST_SUB+=	FFMPEG="@comment "
.endif

.if !defined(WITHOUT_MODPLUG)
PLIST_SUB+=	MODPLUG=""
LIB_DEPENDS+=	modplug.1:${PORTSDIR}/audio/libmodplug
PLUGIN_OPTIONS+=	MODPLUG_PLUGIN
.else
PLIST_SUB+=	MODPLUG="@comment "
.endif

.if !defined(WITHOUT_FAAD)
PLIST_SUB+=	FAAD=""
LIB_DEPENDS+=	faad.2:${PORTSDIR}/audio/faad
PLUGIN_OPTIONS+=	AAC_PLUGIN
.else
PLIST_SUB+=	FAAD="@comment "
.endif

.if !defined(WITHOUT_CDIO)
PLIST_SUB+=	CDIO=""
LIB_DEPENDS+=	cdio.12:${PORTSDIR}/sysutils/libcdio
PLUGIN_OPTIONS+=	CDAUDIO_PLUGIN
.else
PLIST_SUB+=	CDIO="@comment "
.endif

.if !defined(WITHOUT_ENCA)
PLIST_SUB+=	ENCA=""
LIB_DEPENDS+=	enca.5:${PORTSDIR}/converters/enca
PLUGIN_OPTIONS+=	WITH_ENCA
.else
PLIST_SUB+=	ENCA="@comment "
.endif

.if !defined(WITHOUT_MPLAYER)
PLIST_SUB+=	MPLAYER=""
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
PLUGIN_OPTIONS+=	MPLAYER_PLUGIN
.else
PLIST_SUB+=	MPLAYER="@comment "
.endif

.if !defined(WITHOUT_PROJECTM)
PLIST_SUB+=	PROJECTM=""
LIB_DEPENDS+=	projectM.2:${PORTSDIR}/graphics/libprojectm
PLUGIN_OPTIONS+=	PROJECTM_PLUGIN WITH_PROJECTM20
.else
PLIST_SUB+=	PROJECTM="@comment "
.endif

.if !defined(WITHOUT_LADSPA)
PLIST_SUB+=	LADSPA=""
RUN_DEPENDS+=	analyseplugin:${PORTSDIR}/audio/ladspa
PLUGIN_OPTIONS+=	LADSPA_PLUGIN
.else
PLIST_SUB+=	LADSPA="@comment "
.endif

PORTDOCS=	README README.RUS AUTHORS
SUB_FILES=	qmmp
INSTALLS_ICONS=	yes

QMAKE_ARGS+=	CONFIG+="${PLUGIN_OPTIONS}" PREFIX=${PREFIX} \
		LIB_DIR=${PREFIX}/lib

post-patch:
	${REINPLACE_CMD} -e 's|^CONFIG += |#CONFIG +=|' \
		${WRKSRC}/qmmp.pri
	${FIND} ${WRKSRC} -name Makefile -delete
	${REINPLACE_CMD} -e 's|/usr/|${PREFIX}/|g' \
		${WRKSRC}/src/plugins/Input/ffmpeg/ffmpeg.pro \
		${WRKSRC}/src/plugins/Input/mpc/mpc.pro
	${REINPLACE_CMD} -e 's| /include| $$$$PREFIX/include|' \
		${WRKSRC}/src/qmmp/qmmp.pro ${WRKSRC}/src/qmmpui/qmmpui.pro
	${REINPLACE_CMD} -e 's| /bin| $$$$PREFIX/libexec|; \
		s| /share| $$$$PREFIX/share|' \
		${WRKSRC}/src/ui/ui.pro ${WRKSRC}/src/plugins/Input/cue/cue.pro

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKE_ARGS}

pre-install:
	${STRIP_CMD} ${WRKSRC}/bin/qmmp

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/qmmp ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}; \
	cd ${WRKSRC} && ${INSTALL_MAN} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
