# Created by: Richard Neese <r.neese@gmail.com>
# $FreeBSD$

PORTNAME=	freeswitch
PORTREVISION=	2
DISTVERSION=	1.2.3
CATEGORIES=	net
MASTER_SITES=	http://files.freeswitch.org/ \
		http://files.freeswitch.org/downloads/libs/:2 \
		http://download.zeromq.org/:3
PKGNAMESUFFIX=	-core-devel
DISTFILES=	${PORTNAME}-${DISTVERSION}.tar.bz2 \
		opus-1.0.1.tar.gz:2 \
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

MAINTAINER=	ports@FreeBSD.org
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
USES=		bison:both pkgconfig
USE_GCC=	any
USE_GMAKE=	yes
SUB_FILES=	pkg-install
USE_RC_SUBR=	freeswitch
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
INCLUDES+=	-I${LOCALBASE}/include
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
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ENV+=	INCLUDES="${INCLUDES}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
CPPFLAGS+=	-I${LOCALBASE}/include

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

OPTIONS_DEFINE=	REBOOTSTRAP MODABSTRACTION MODAVMD MODCALLCENTER MODCIDLOOKUP MODBLACKLIST MODCURL \
		MODDISTRIBUTOR MODEASYROUTE MODFSK MODHTTAPI MODHTTPCACHE MODDIRECTORY MODLADSPA \
		MODLCR MODMEMCACHE MODNIBBLEBILL MODRSS MODSNOM MODSPY MODSOUNDTOUCH MODSTRESS MODSNAPSHOT \
		MODVMD MODVOICEMAILIVR MODAMRWB MODCELT MODCODEC2 MODILBC MODISAC MODOPUS MODSILK MODSIREN MODDPASTERISK \
		MODDPDIRECTORY MODDINGALING MODFREETDM MODPORTAUDIO MODRTMP MODSKINNY MODFLITE MODPOCKETSPHINX \
		MODTTSCMDLINE MODUNIMRCP MODCDRPGCSV MODERLANGEVENT MODMULTICAST MODEVENTZMQ MODSNMP MODVLC \
		MODPASTREAM MODSHELLSTREAM MODSHOUT MODMANAGED MODPERL MODPYTHON MODPOSIXTIMER MODXMLCURL \
		MODXMLODBC MODXMLRPC MODSAYDE MODSAYES MODSAYEN MODSAYFR MODSAYHE MODSAYHU MODSAYIT MODSAYNL \
		MODSAYPT MODSAYRU MODSAYTH MODSAYZH

REBOOTSTRAP_DESC=	Rebootstrap freeswitch build
MODABSTRACTION_DESC=	Simplify/Standarize API
MODAVMD_DESC=		Detects voicemail generalized approach
MODCALLCENTER_DESC=	Call queuing application
MODCIDLOOKUP_DESC=	Lookup CID via database, url
MODBLACKLIST_DESC=	Blacklisk phone numbers
MODCURL_DESC=		Allows scripts to make HTTP requests
MODDISTRIBUTOR_DESC=	Simple round-robin style distributions
MODEASYROUTE_DESC=	DID Database lookup
MODFSK_DESC=		FSK (Frequency-Shift Keying) data transfer
MODHTTAPI_DESC=		HTTP API
MODHTTPCACHE_DESC=	HTTP GET with caching
MODDIRECTORY_DESC=	Dial by name directory
MODLADSPA_DESC=		use Auto-tune on your call
MODLCR_DESC=		Least Cost Routing
MODMEMCACHE_DESC=	Memcached API
MODNIBBLEBILL_DESC=	Billing Module
MODRSS_DESC=		RSS feed text to speech
MODSNOM_DESC=		Controlling softkeys on Snom phones
MODSPY_DESC=		Extension/Call Spy tool
MODSOUNDTOUCH_DESC=	Pitch shifting audio effects
MODSTRESS_DESC=		Detect Stress in voice
MODSNAPSHOT_DESC=	Audio/Disk Snapshot Tool
MODVMD_DESC=		Voicemail Beep Detection
MODVOICEMAILIVR_DESC=	IVR Based Voicemail(NEW)
MODAMRWB_DESC=		GSM-AMRWB (ARM Wide Band) codec
MODCELT_DESC=		Celt ultra-low delay audio codec
MODCODEC2_DESC=		Freeswitch Codec2 Module
MODILBC_DESC=		ILBX Codec
MODISAC_DESC=		Isac Codec (New Codec)
MODOPUS_DESC=		OPUS ultra-low delay audio codec
MODSILK_DESC=		Skype Silk Codec (Broken/BUILD ISSUES)
MODSIREN_DESC=		Siren Codec
MODDPASTERISK_DESC=	Asterisk Dialplan (Old School Dialplan)
MODDPDIRECTORY_DESC=	obtain dialplan from a directory resource
MODDINGALING_DESC=	Jabber/Google Talk integration module
MODFREETDM_DESC=	Interface to Zaptel hardware End Points
MODPORTAUDIO_DESC=	Portaudio API
MODRTMP_DESC=		Real time media protocol
MODSKINNY_DESC=		Skinny/SCCP
MODFLITE_DESC=		Free open source Text to Speech
MODPOCKETSPHINX_DESC=	Free open source Speech Recognition
MODTTSCMDLINE_DESC=	Play Sounds via commandline
MODUNIMRCP_DESC=	Open MRCP implementation ASR/Text
MODCDRPGCSV_DESC=	Asterisk Compatible CDR PostgreSQL
MODERLANGEVENT_DESC=	send/receive events/commands in Erlang
MODMULTICAST_DESC=	Broadcasts events to netmask
MODEVENTZMQ_DESC=	Zeroconf config socket
MODSNMP_DESC=		SNMP AgentX module
MODVLC_DESC=		Play local mp3 files any rate(NEW Testing)
MODPASTREAM_DESC=	PortAudio Streaming Module
MODSHELLSTREAM_DESC=	Stream audio via shell command
MODSHOUT_DESC=		Play local mp3/shoutcast (Build Error)
MODMANAGED_DESC=	Common Language Infrastructure API
MODPERL_DESC=		Perl Lang Support
MODPYTHON_DESC=		Python Lang Suppot
MODPOSIXTIMER_DESC=	Posix timer (New/Testing)
MODXMLCURL_DESC=	XML dynamically control of FreeSWITCH
MODXMLODBC_DESC=	XML ODBC Module
MODXMLRPC_DESC=		XML Remote Procedure Calls
MODSAYDE_DESC=		German Voice Prompts
MODSAYES_DESC=		Spanish Voice Prompts
MODSAYEN_DESC=		English Voice Prompts
MODSAYFR_DESC=		French Voice Prompts
MODSAYHE_DESC=		Hebrew Voice Prompts
MODSAYHU_DESC=		Hungarian Voice Propmts
MODSAYIT_DESC=		Italian Voice Propmts
MODSAYNL_DESC=		Dutch Voice Propmts
MODSAYPT_DESC=		Portuguese Voice Propmts
MODSAYRU_DESC=		Russian Voice Propmts
MODSAYTH_DESC=		Thai Voice Propmts
MODSAYZH_DESC=		Chinese Voice Propmts

OPTIONS_DEFAULT=	REBOOTSTRAP MODABSTRACTION MODAVMD MODCALLCENTER MODCIDLOOKUP MODBLACKLIST MODCURL \
			MODDISTRIBUTOR MODEASYROUTE MODFSK MODHTTAPI MODHTTPCACHE MODDIRECTORY MODLADSPA MODLCR MODMEMCACHE \
			MODNIBBLEBILL MODRSS MODSNOM MODSPY MODVMD MODVOICEMAILIVR MODAMRWB MODCELT MODCODEC2 MODISAC MODILBC MODOPUS \
			MODSIREN MODDPDIRECTORY MODDINGALING MODPORTAUDIO MODRTMP MODSKINNY MODFLITE MODPOCKETSPHINX MODTTSCMDLINE MODUNIMRCP \
			MODMULTICAST MODEVENTZMQ MODPASTREAM MODSHELLSTREAM MODPERL MODPYTHON MODPOSIXTIMER MODXMLCURL MODXMLODBC \
			MODXMLRPC MODSAYEN

NO_OPTIONS_SORT=	yes

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

.for opt in ${ALL_OPTIONS}
.if $(PORT_OPTIONS:M${opt})
PLIST_SUB+=	${opt}=""
.else
PLIST_SUB+=	${opt}="@comment "
.endif
.endfor

.if ${PORT_OPTIONS:MMODFREETDM}
CONFIGURE_ARGS+=	--with-libpri=${LOCALBASE}
BUILD_DEPENDS+=	${LOCALBASE}/include/dahdi/wctdm_user.h:${PORTSDIR}/misc/dahdi
LIB_DEPENDS+=	pri:${PORTSDIR}/misc/libpri
RUN_DEPENDS+=	${LOCALBASE}/include/dahdi/wctdm_user.h:${PORTSDIR}/misc/dahdi
.endif

.if ${PORT_OPTIONS:MMODSHOUT}
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
.endif

.if ${PORT_OPTIONS:MMODPERL}
USE_BDB=	42+
LIB_DEPENDS+=	gdbm:${PORTSDIR}/databases/gdbm
.endif

.if ${PORT_OPTIONS:MMODERLANGEVENT}
BUILD_DEPENDS+=	${LOCALBASE}/lib/erlang/usr/include/erl_driver.h:${PORTSDIR}/lang/erlang
.endif

.if ${PORT_OPTIONS:MMODPYTHON}
USE_PYTHON=	yes
.endif

.if ${PORT_OPTIONS:MMODCDRPGCSV}
USE_PGSQL=	yes
.endif

.if ${PORT_OPTIONS:MMODSNMP}
BUILD_DEPENDS+=	${LOCALBASE}/include/net-snmp/definitions.h:${PORTSDIR}/net-mgmt/net-snmp
RUN_DEPENDS+=	${LOCALBASE}/include/net-snmp/definitions.h:${PORTSDIR}/net-mgmt/net-snmp
.endif

.if ${PORT_OPTIONS:MMODLADSPA}
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

.if ${PORT_OPTIONS:MMODVLC}
LIB_DEPENDS+=	vlc:/${PORTSDIR}/multimedia/vlc
RUN_DEPENDS+=	vlc:/${PORTSDIR}/multimedia/vlc
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|base=http://files.freeswitch.org/downloads/libs/|base=file://${DISTDIR}/${DIST_SUBDIR}/|g' ${WRKSRC}/build/getlib.sh.in
	@${REINPLACE_CMD} -e 's|2.1.9|2.1.11|g' ${WRKSRC}/src/mod/event_handlers/mod_event_zmq/Makefile
	@${REINPLACE_CMD} -e 's|ZMQ_BASEURL=http://download.zeromq.org|ZMQ_BASEURL=file://${DISTDIR}/${DIST_SUBDIR}/|g' ${WRKSRC}/src/mod/event_handlers/mod_event_zmq/Makefile
	@${REINPLACE_CMD} -e 's|\$$(MAKE) samples-conf|##\$$(MAKE) samples-conf|g' ${WRKSRC}/Makefile.am
.if ${PORT_OPTIONS:MREBOOTSTRAP}
	cd ${WRKSRC} && ./rebootstrap.sh
.endif

post-configure:
.for i in mod_unimrcp mod_flite mod_pocketsphinx
.if ${PORT_OPTIONS:M${i:S/_//g:U}}
	@${REINPLACE_CMD} -e 's|#\(asr_tts/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.if ${PORT_OPTIONS:MMODTTSCMDLINE}}
	@${REINPLACE_CMD} -e 's|#asr_tts/mod_tts_commandline|asr_tts/mod_tts_commandline|g' ${WRKSRC}/modules.conf
.endif
.for i in mod_cidlookup mod_easyroute mod_lcr mod_soundtouch mod_rss mod_snom \
	mod_vmd mod_avmd mod_spy mod_curl mod_nibblebill mod_memcache mod_directory mod_distributor \
	mod_snapshot mod_callcenter mod_fsk mod_ladspa mod_blacklist mod_http_cache mod_abstraction \
	mod_voicemail_ivr mod_httapi
.if ${PORT_OPTIONS:M${i:S/_//g:U}}
	@${REINPLACE_CMD} -e 's|#\(applications/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.for i in mod_amrwb mod_celt mod_silk mod_codec2 mod_opus mod_isac mod_ilbc mod_siren
.if ${PORT_OPTIONS:M${i:S/_//g:U}}
	@${REINPLACE_CMD} -e 's|#\(codecs/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.for i in  mod_shell_stream mod_shout mod_vlc
.if ${PORT_OPTIONS:M${i:S/_//g:U}}
	@${REINPLACE_CMD} -e 's|#\(formats/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.if ${PORT_OPTIONS:MMODPASTREAM}}
	@${REINPLACE_CMD} -e 's|#formats/mod_portaudio_stream|formats/mod_portaudio_stream|g' ${WRKSRC}/modules.conf
.endif
.for i in mod_say_de mod_say_es mod_say_en mod_say_fr mod_say_he mod_say_hu mod_say_it mod_say_nl mod_say_pt mod_say_ru mod_say_th mod_say_zh
.if ${PORT_OPTIONS:M${i:S/_//g:U}}
	@${REINPLACE_CMD} -e 's|#\(say/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.for i in mod_perl mod_python
.if ${PORT_OPTIONS:M${i:S/_//g:U}}
	@${REINPLACE_CMD} -e 's|#\(languages/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.for i in mod_skinny mod_portaudio mod_dingaling mod_rtmp mod_khomp
.if ${PORT_OPTIONS:M${i:S/_//g:U}}
	@${REINPLACE_CMD} -e 's|#\(endpoints/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.if ${PORT_OPTIONS:MMODDPDIRECTORY}
	@${REINPLACE_CMD} -e 's|#dialplans/mod_dialplan_directory|dialplans/mod_dialplan_directory|g' ${WRKSRC}/modules.conf
.endif
.if ${PORT_OPTIONS:MMODFREETDM}
	@${REINPLACE_CMD} -e 's|#../../libs/freetdm/mod_freetdm|../../libs/freetdm/mod_freetdm|g' ${WRKSRC}/modules.conf
.endif
.if ${PORT_OPTIONS:MMODMULTICAST}
	@${REINPLACE_CMD} -e 's|#event_handlers/mod_event_multicast|event_handlers/mod_event_multicast|g' ${WRKSRC}/modules.conf
.endif
.if ${PORT_OPTIONS:MMODERLANGEVENT}
	@${REINPLACE_CMD} -e 's|#event_handlers/mod_erlang_event|event_handlers/mod_erlang_event|g' ${WRKSRC}/modules.conf
.endif
.if ${PORT_OPTIONS:MMODCDRPGCSV}
	@${REINPLACE_CMD} -e 's|#event_handlers/mod_cdr_pg_csv|event_handlers/mod_cdr_pg_csv|g' ${WRKSRC}/modules.conf
.endif
.if ${PORT_OPTIONS:MMODSNMP}
	@${REINPLACE_CMD} -e 's|#event_handlers/mod_snmp|event_handlers/mod_snmp|g' ${WRKSRC}/modules.conf
.endif
.if ${PORT_OPTIONS:MMODXMLCURL}
	@${REINPLACE_CMD} -e 's|#xml_int/mod_xml_curl|xml_int/mod_xml_curl|g' ${WRKSRC}/modules.conf
.endif
.if empty(PORT_OPTIONS:MMODDPASTERISK)
	@${REINPLACE_CMD} -e 's|dialplans/mod_dialplan_asterisk|#dialplans/mod_dialplan_asterisk|g' ${WRKSRC}/modules.conf
.endif
.if ${PORT_OPTIONS:MMODEVENTZMQ}
	@${REINPLACE_CMD} -e 's|#event_handlers/mod_event_zmq|event_handlers/mod_event_zmq|g' ${WRKSRC}/modules.conf
.endif
.if ${PORT_OPTIONS:MMODXMLODBC}
	@${REINPLACE_CMD} -e 's|#../../contrib/mod/xml_int/mod_xml_odbc|../../contrib/mod/xml_int/mod_xml_odbc|g' ${WRKSRC}/modules.conf
.endif
.if ${PORT_OPTIONS:MMODPOSIXTIMER}
	@${REINPLACE_CMD} -e 's|#timers/mod_posix_timer|timers/mod_posix_timer|g' ${WRKSRC}/modules.conf
.endif

pre-install:
	@${CHMOD} 664 ${WRKSRC}/libs/freetdm/conf/*
	@${MKDIR} ${ETCDIR}/conf
	@${TOUCH} ${ETCDIR}/conf/.freeswitch-core-devel
.if ${PORT_OPTIONS:MMODFREETDM}
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
