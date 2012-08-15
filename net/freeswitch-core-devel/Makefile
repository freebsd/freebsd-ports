# Ports collection makefile for:	freeswitch-core-devel
# Date created:				May 14, 2012
# Whom:					Richard Neese <r.neese@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	freeswitch
DISTVERSION=	1.2.rc2
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://files.freeswitch.org/ \
		http://files.freeswitch.org/downloads/libs/:2 \
		http://download.zeromq.org/:3
PKGNAMESUFFIX=	-core-devel
DISTFILES=	${PORTNAME}-${DISTVERSION}.tar.bz2 \
		opus-0.9.0.tar.gz:2 \
		celt-0.10.0.tar.gz:2 \
		flite-1.5.4-current.tar.bz2:2 \
		json-c-0.9.tar.gz:2 \
		lame-3.98.4.tar.gz:2 \
		libmemcached-0.32.tar.gz:2 \
		libshout-2.2.2.tar.gz:2 \
		mpg123-1.13.2.tar.gz:2 \
		openldap-2.4.11.tar.gz:2 \
		pocketsphinx-0.7.tar.gz:2 \
		soundtouch-1.6.0.tar.gz:2 \
		sphinxbase-0.7.tar.gz:2 \
		communicator_semi_6000_20080321.tar.gz:2 \
		zeromq-2.1.11.tar.gz:3
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}.tar.bz2

MAINTAINER=	r.neese@gmail.com
COMMENT=	FreeSwitch SoftSwitch Port

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		jpeg:${PORTSDIR}/graphics/jpeg \
		tiff:${PORTSDIR}/graphics/tiff \
		odbc:${PORTSDIR}/databases/unixODBC

CONFLICTS=	freeswitch-core-[0-9]*
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

USE_AUTOTOOLS=	autoconf:env automake:env libtool:env

USE_PERL5_BUILD=yes
USE_BISON=	both
USE_PKGCONFIG=	yes
USE_GMAKE=	yes
SUB_FILES=	pkg-install
USE_RC_SUBR=	freeswitch
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
INCLUDES=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=--prefix=${PREFIX} \
		--bindir=${PREFIX}/bin \
		--datadir=${VARBASE}/db/${PORTNAME} \
		--includedir=${PREFIX}/include/${PORTNAME} \
		--libdir=${PREFIX}/lib/${PORTNAME}/lib \
		--localstatedir=${VARBASE} \
		--sysconfdir=${PREFIX}/etc/${PORTNAME}/conf \
		--with-htdocsdir=${PREFIX}/www/${PORTNAME}/htdocs \
		--with-soundsdir=${PREFIX}/share/${PORTNAME}/sounds \
		--with-grammardir=${PREFIX}/etc/${PORTNAME}/grammar \
		--with-scriptdir=${PREFIX}/etc/${PORTNAME}/scripts \
		--with-modinstdir=${PREFIX}/lib/${PORTNAME}/mod \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--with-storagedir=${VARBASE}/${PORTNAME} \
		--with-recordingsdir=${VARBASE}/${PORTNAME}/recordings \
		--with-ogg=${LOCALBASE} \
		--with-ogg-libraries=${LOCALBASE}/lib \
		--with-ogg-includes=${LOCALBASE}/include

CONFIGURE_ENV+=	INCLUDES="${INCLUDES}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

FREESWITCH_USER?=	freeswitch
FREESWITCH_GROUP?=	${FREESWITCH_USER}
FREESWITCH_UID?=	610
FREESWITCH_GID?=	${FREESWITCH_UID}

USERS=	${FREESWITCH_USER}
GROUPS=	${FREESWITCH_GROUP}

SUB_LIST=	FREESWITCH_USER=${FREESWITCH_USER} \
		FREESWITCH_GROUP=${FREESWITCH_GROUP}

VARBASE=	/var
ETCDIR=	${PREFIX}/etc/${PORTNAME}
WWWDIR=	${PREFIX}/www/${PORTNAME}

SAMPLESDIR=	conf conf/autoload_configs

OPTIONS=	REBOOTSTRAP     	"Rebootstrap freeswitch build" on \
		MODABSTRACTION		"Simplify/Standarize API" on \
		MODAVMD			"Detects voicemail generalized approach" on \
		MODCALLCENTER		"Call queuing application" on \
		MODCIDLOOKUP		"Lookup CID via database, url" on\
		MODBLACKLIST		"Blacklisk phone numbers" on \
		MODCURL			"Allows scripts to make HTTP requests" off \
		MODDISTRIBUTOR		"Simple round-robin style distributions" on \
		MODEASYROUTE		"DID Database lookup" off \
		MODFSK			"FSK (Frequency-Shift Keying) data transfer" on \
		MODHTTAPI		"HTTP API" on \
		MODHTTPCACHE		"HTTP GET with caching" off \
		MODDIRECTORY		"Dial by name directory" on \
 		MODLADSPA		"use Auto-tune on your call" off \
		MODLCR			"Least Cost Routing" off \
		MODMEMCACHE		"Memcached API" off \
		MODNIBBLEBILL		"Billing Module" off \
		MODRSS			"RSS feed text to speech" on \
		MODSNOM			"Controlling softkeys on Snom phones" on \
		MODSPY			"Extension/Call Spy tool" on \
		MODSOUNDTOUCH		"Pitch shifting audio effects" on \
		MODSTRESS		"Detect Stress in voice" off \
		MODSNAPSHOT		"Audio/Disk Snapshot Tool" off \
		MODVMD			"Voicemail Beep Detection" on \
		MODVOICEMAILIVR		"IVR Based Voicemail(NEW)" on \
		MODAMRWB		"GSM-AMRWB (ARM Wide Band) codec" on \
		MODCELT			"Celt ultra-low delay audio codec" on \
		MODCODEC2		"Freeswitch Codec2 Module" on \
		MODISAC			"Isac Codec (New Codec)" on \
		MODOPUS			"OPUS ultra-low delay audio codec" on \
		MODSILK			"Skype Silk Codec (Broken/BUILD ISSUES)" off \
		MODDPASTERISK		"Asterisk Dialplan (Old School Dialplan)" off \
		MODDPDIRECTORY		"obtain dialplan from a directory resource" off \
		MODDINGALING		"Jabber/Google Talk integration module" on \
		MODFREETDM		"Interface to Zaptel hardware End Points" off \
		MODPORTAUDIO		"Portaudio API" on \
		MODRTMP			"Real time media protocol" on \
		MODSKINNY		"Skinny/SCCP" on \
		MODFLITE		"Free open source Text to Speech" on \
		MODPOCKETSPHINX		"Free open source Speech Recognition" on \
		MODTTSCMDLINE		"Play Sounds via commandline" on \
		MODUNIMRCP		"Open MRCP implementation ASR/Text" off \
		MODCDRPGCSV		"Asterisk Compatible CDR PostgreSQL" off \
		MODERLANGEVENT		"send/receive events/commands in Erlang" off \
		MODMULTICAST		"Broadcasts events to netmask" on \
		MODEVENTZMQ		"Zeroconf config socket" off \
		MODSNMP			"SNMP AgentX module" off \
		MODVLC			"Play local mp3 files any rate(NEW Testing)" off \
		MODPASTREAM		"PortAudio Streaming Module" on \
		MODSHELLSTREAM		"Stream audio via shell command" on \
		MODSHOUT		"Play local mp3 files any rate(Build Error)" off \
		MODMANAGED		"Common Language Infrastructure API" off \
		MODPERL			"Perl Lang Support" on \
		MODPYTHON		"Python Lang Suppot" on \
		MODPOSIXTIMER		"Posix timer (New/Testing)" on \
		MODXMLCURL		"XML dynamically control of FreeSWITCH" on \
		MODXMLODBC		"XML ODBC Module" on \
		MODXMLRPC		"XML Remote Procedure Calls" on \
		MODSAYDE		"German Voice Prompts" off \
		MODSAYES		"Spanish Voice Prompts" off \
		MODSAYEN		"English Voice Prompts" on \
		MODSAYFR		"French Voice Prompts" off \
		MODSAYHE		"Hebrew Voice Prompts" off \
		MODSAYHU		"Hungarian Voice Propmts" off \
		MODSAYIT		"Italian Voice Propmts" off \
		MODSAYNL		"Dutch Voice Propmts" off \
		MODSAYPT		"Portuguese Voice Propmts" off \
		MODSAYRU		"Russian Voice Propmts" off \
		MODSAYTH		"Thai Voice Propmts" off \
		MODSAYZH		"Chinese Voice Propmts" off

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

.for i in  ${OPTIONS:Non:Noff:N"*"}
.if defined(WITH_${i})
PLIST_SUB+=	${i}=""
.else
PLIST_SUB+=	${i}="@comment "
.endif
.endfor

.if defined(WITH_MODFREETDM)
.if ${OSVERSION} < 703000 || (${OSVERSION} >= 800000 && ${OSVERSION} < 800108)
IGNORE=	sorry you can not use mod_freetdm on this version of freebsd ( dahdi support broken ) please update
.else
CONFIGURE_ARGS+=	--with-libpri=${LOCALBASE}
BUILD_DEPENDS+=	${LOCALBASE}/include/dahdi/wctdm_user.h:${PORTSDIR}/misc/dahdi
LIB_DEPENDS+=	pri:${PORTSDIR}/misc/libpri
RUN_DEPENDS+=	${LOCALBASE}/include/dahdi/wctdm_user.h:${PORTSDIR}/misc/dahdi
.endif
.endif

.if defined(WITH_MODSHOUT)
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
.endif

.if defined(WITH_MODPERL)
LIB_DEPENDS+=	gdbm:${PORTSDIR}/databases/gdbm \
		db:${PORTSDIR}/databases/db42
.endif

.if defined(WITH_MODERLANGEVENT)
BUILD_DEPENDS+=	${LOCALBASE}/lib/erlang/usr/include/erl_driver.h:${PORTSDIR}/lang/erlang
.endif

.if defined(WITH_MODPYTHON)
USE_PYTHON=	yes
.endif

.if defined(WITH_MODCDRPGCSV)
USE_PGSQL=	yes
.endif

.if defined(WITH_MODSNMP)
BUILD_DEPENDS+=	${LOCALBASE}/include/net-snmp/definitions.h:${PORTSDIR}/net-mgmt/net-snmp
RUN_DEPENDS+=	${LOCALBASE}/include/net-snmp/definitions.h:${PORTSDIR}/net-mgmt/net-snmp
.endif

.if defined(WITH_MODLADSPA)
BUILD_DEPENDS+=	${LOCALBASE}/lib/ladspa/amp.so:${PORTSDIR}/audio/ladspa \
		${LOCALBASE}/lib/ladspa/tap_autopan.so:${PORTSDIR}/audio/tap-plugins \
		${LOCALBASE}/lib/ladspa/cmt.so:${PORTSDIR}/audio/cmt \
		${LOCALBASE}/lib/ladspa/alias_1407.so:${PORTSDIR}/audio/swhplugins \
		${LOCALBASE}/lib/ladspa/autotalent.so:${PORTSDIR}/audio/autotalent
RUN_DEPENDS+=	${LOCALBASE}/lib/ladspa/amp.so:${PORTSDIR}/audio/ladspa \
		${LOCALBASE}/lib/ladspa/tap_autopan.so:${PORTSDIR}/audio/tap-plugins \
		${LOCALBASE}/lib/ladspa/cmt.so:${PORTSDIR}/audio/cmt \
		${LOCALBASE}/lib/ladspa/alias_1407.so:${PORTSDIR}/audio/swhplugins \
		${LOCALBASE}/lib/ladspa/autotalent.so:${PORTSDIR}/audio/autotalent
.endif

.if defined(WITH_MODVLC)
LIB_DEPENDS+=	vlc:/${PORTSDIR}/multimedia/vlc
RUN_DEPENDS+=	vlc:/${PORTSDIR}/multimedia/vlc
.endif

# FreeBSD 7 doesn't have lrintl, but lrint will do the trick just fine
# It's quite cryptic as to why the reinplace doesn't work; there's no mention
# of lrintl anywhere in any source....
.if ${OSVERSION} < 800012
BROKEN=	Requires lrintl, which is not present on FreeBSD 7
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|base=http://files.freeswitch.org/downloads/libs/|base=file://${DISTDIR}/${DIST_SUBDIR}/|g' ${WRKSRC}/build/getlib.sh.in
	@${REINPLACE_CMD} -e 's|2.1.9|2.1.11|g' ${WRKSRC}/src/mod/event_handlers/mod_event_zmq/Makefile
	@${REINPLACE_CMD} -e 's|\$$(MAKE) samples-conf|##\$$(MAKE) samples-conf|g' ${WRKSRC}/Makefile.am
.if defined(WITH_REBOOTSTRAP)
	cd ${WRKSRC} && ./rebootstrap.sh
.endif

post-configure:
.for i in mod_unimrcp mod_flite mod_pocketsphinx
.if defined(WITH_${i:S/_//g:U})
	@${REINPLACE_CMD} -e 's|#\(asr_tts/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.if defined(WITH_MODTTSCMDLINE)
	@${REINPLACE_CMD} -e 's|#asr_tts/mod_tts_commandline|asr_tts/mod_tts_commandline|g' ${WRKSRC}/modules.conf
.endif
.for i in mod_cidlookup mod_easyroute mod_lcr mod_soundtouch mod_rss mod_snom \
	mod_vmd mod_avmd mod_spy mod_curl mod_nibblebill mod_memcache mod_directory mod_distributor \
	mod_snapshot mod_callcenter mod_fsk mod_ladspa mod_blacklist mod_http_cache mod_abstraction \
	mod_voicemail_ivr mod_httapi
.if defined(WITH_${i:S/_//g:U})
	@${REINPLACE_CMD} -e 's|#\(applications/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.for i in mod_amrwb mod_celt mod_silk mod_codec2 mod_opus mod_isac
.if defined(WITH_${i:S/_//g:U})
	@${REINPLACE_CMD} -e 's|#\(codecs/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.for i in  mod_shell_stream mod_shout mod_vlc
.if defined(WITH_${i:S/_//g:U})
	@${REINPLACE_CMD} -e 's|#\(formats/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.if defined(WITH_MODPASTREAM)
	@${REINPLACE_CMD} -e 's|#formats/mod_portaudio_stream|formats/mod_portaudio_stream|g' ${WRKSRC}/modules.conf
.endif
.for i in mod_say_de mod_say_es mod_say_en mod_say_fr mod_say_he mod_say_hu mod_say_it mod_say_nl mod_say_pt mod_say_ru mod_say_th mod_say_zh
.if defined(WITH_${i:S/_//g:U})
	@${REINPLACE_CMD} -e 's|#\(say/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.for i in mod_perl mod_python
.if defined(WITH_${i:S/_//g:U})
	@${REINPLACE_CMD} -e 's|#\(languages/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.for i in mod_skinny mod_portaudio mod_dingaling mod_rtmp mod_khomp
.if defined(WITH_${i:S/_//g:U})
	@${REINPLACE_CMD} -e 's|#\(endpoints/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.if defined(WITH_MODDPDIRECTORY)
	@${REINPLACE_CMD} -e 's|#dialplans/mod_dialplan_directory|dialplans/mod_dialplan_directory|g' ${WRKSRC}/modules.conf
.endif
.if defined(WITH_MODFREETDM)
	@${REINPLACE_CMD} -e 's|#../../libs/freetdm/mod_freetdm|../../libs/freetdm/mod_freetdm|g' ${WRKSRC}/modules.conf
.endif
.if defined(WITH_MODMULTICAST)
	@${REINPLACE_CMD} -e 's|#event_handlers/mod_event_multicast|event_handlers/mod_event_multicast|g' ${WRKSRC}/modules.conf
.endif
.if defined(WITH_MODERLANGEVENT)
	@${REINPLACE_CMD} -e 's|#event_handlers/mod_erlang_event|event_handlers/mod_erlang_event|g' ${WRKSRC}/modules.conf
.endif
.if defined(WITH_MODCDRPGCSV)
	@${REINPLACE_CMD} -e 's|#event_handlers/mod_cdr_pg_csv|event_handlers/mod_cdr_pg_csv|g' ${WRKSRC}/modules.conf
.endif
.if defined(WITH_MODSNMP)
	@${REINPLACE_CMD} -e 's|#event_handlers/mod_snmp|event_handlers/mod_snmp|g' ${WRKSRC}/modules.conf
.endif
.if defined(WITH_MODXMLCURL)
	@${REINPLACE_CMD} -e 's|#xml_int/mod_xml_curl|xml_int/mod_xml_curl|g' ${WRKSRC}/modules.conf
.endif
.if !defined(WITH_MODDPASTERISK)
	@${REINPLACE_CMD} -e 's|dialplans/mod_dialplan_asterisk|#dialplans/mod_dialplan_asterisk|g' ${WRKSRC}/modules.conf
.endif
.if defined(WITH_MODEVENTZMQ)
	@${REINPLACE_CMD} -e 's|#event_handlers/mod_event_zmq|event_handlers/mod_event_zmq|g' ${WRKSRC}/modules.conf
.endif
.if defined(WITH_MODXMLODBC)
	@${REINPLACE_CMD} -e 's|#../../contrib/mod/xml_int/mod_xml_odbc|../../contrib/mod/xml_int/mod_xml_odbc|g' ${WRKSRC}/modules.conf
.endif
.if defined(WITH_MODPOSIXTIMER)
	@${REINPLACE_CMD} -e 's|#timers/mod_posix_timer|timers/mod_posix_timer|g' ${WRKSRC}/modules.conf
.endif

pre-install:
	@${CHMOD} 664 ${WRKSRC}/libs/freetdm/conf/*
	@${MKDIR} ${ETCDIR}/conf
	@${TOUCH} ${ETCDIR}/conf/.freeswitch-core-devel
.if defined(WITH_MODFREETDM)
	@${MKDIR} ${ETCDIR}/conf/autoload_configs
.endif

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
	    ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CHOWN} -R ${USERS}:${GROUPS} ${ETCDIR} ${DATADIR} \
		${PREFIX}/include/${PORTNAME} \
		${PREFIX}/lib/${PORTNAME}
	@${FIND} ${ETCDIR} -type d | ${XARGS} ${CHMOD} 770
	@${MKDIR} ${DATADIR}/sounds
	@${CHMOD} -R 770 ${DATADIR}
	@${FIND} ${ETCDIR} ${WWWDIR} -type f | ${XARGS} ${CHMOD} 660

.include <bsd.port.mk>
