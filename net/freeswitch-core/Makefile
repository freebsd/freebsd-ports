# Created by: Richard Neese <r.neese@gmail.com>
# $FreeBSD$

PORTNAME=	freeswitch-core
PORTVERSION=	1.0.7.1
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	http://dl.dropbox.com/u/152504/ \
		http://files.freeswitch.org/downloads/libs/:2 \
		http://download.zeromq.org/:3
DISTFILES=	${BASE_PORTNAME}-${PORTVERSION}.tar.gz \
		opus-0.9.0.tar.gz:2 \
		celt-0.10.0.tar.gz:2 \
		flite-1.5.1-current.tar.bz2:2 \
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
		zeromq-2.1.10.tar.gz:3
DIST_SUBDIR=	${BASE_PORTNAME}
EXTRACT_ONLY=	${BASE_PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FreeSwitch SoftSwitch Port

BROKEN=		Does not build

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		jpeg:${PORTSDIR}/graphics/jpeg \
		tiff:${PORTSDIR}/graphics/tiff \
		odbc:${PORTSDIR}/databases/unixODBC

CONFLICTS=	freeswitch-core-devel-[0-9]*

WRKSRC=		${WRKDIR}/${BASE_PORTNAME}-${PORTVERSION}

USE_AUTOTOOLS=	autoconf:env automake:env libtool:env

USE_PERL5_BUILD=yes
USES=		bison:both pkgconfig
USE_GCC=	any
USE_GMAKE=	yes
SUB_FILES=	pkg-install pkg-message
USE_RC_SUBR=	freeswitch
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
INCLUDES+=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=--prefix=${PREFIX} \
		--bindir=${PREFIX}/bin \
		--sysconfdir=${PREFIX}/etc/${BASE_PORTNAME}/conf \
		--includedir=${PREFIX}/include/${BASE_PORTNAME} \
		--libdir=${PREFIX}/lib/${BASE_PORTNAME}/lib \
		--localstatedir="${VARBASE}" \
		--with-modinstdir=${PREFIX}/lib/${BASE_PORTNAME}/mod \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--with-libgnutls-prefix=${LOCALBASE} \
		--with-ogg=${LOCALBASE} \
		--with-ogg-libraries=${LOCALBASE}/lib \
		--with-ogg-includes=${LOCALBASE}/include

CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}" \
		INCLUDES="${INCLUDES}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

FREESWITCH_USER?=	freeswitch
FREESWITCH_GROUP?=	${FREESWITCH_USER}
FREESWITCH_UID?=	610
FREESWITCH_GID?=	${FREESWITCH_UID}

USERS=	${FREESWITCH_USER}
GROUPS=	${FREESWITCH_GROUP}

SUB_LIST=	FREESWITCH_USER=${FREESWITCH_USER} FREESWITCH_GROUP=${FREESWITCH_GROUP}

BASE_PORTNAME=	${FREESWITCH_USER}

VARBASE?=	/var

OPTIONS_DEFINE=	MODSHOUT MODFLITE MODUNIMRCP MODTTSCMDLINE MODPOCKETSPHINX \
		MODCIDLOOKUP MODDPDIRECTORY MODDIRECTORY MODDINGALING \
		MODEASYROUTE MODERLANGEVENT MODLCR MODSOUNDTOUCH MODRSS \
		MODSNOM MODAVMD MODVMD MODSPY MODAMRWB MODCELT MODSILK \
		MODCODEC2 MODOPUS MODFREETDM MODSKINNY MODMEMCACHE \
		MODMULTICAST MODNIBBLEBILL MODPORTAUDIO MODSHELLSTREAM \
		MODPERL MODPYTHON MODCURL MODXMLCURL MODDISTRIBUTOR \
		MODSNAPSHOT MODSAYDE MODSAYES MODSAYEN MODSAYHE MODSAYHU \
		MODSAYFR MODSAYIT MODSAYNL MODSAYRU MODSAYTH MODSAYZH \
		EXTENSIONS MODCALLCENTER MODFSK MODCDRPGCSV MODSNMP MODLADSPA \
		MODRTMP MODDPASTERISK MODBLACKLIST MODHTTPCACHE MODEVENTZMQ \
		SAMPLECONFIGS
OPTIONS_DEFAULT=	MODSHOUT MODFLITE MODTTSCMDLINE MODPOCKETSPHINX \
			MODCIDLOOKUP MODDIRECTORY MODDINGALING MODEASYROUTE \
			MODLCR MODSOUNDTOUCH MODRSS MODSNOM MODAVMD MODSPY \
			MODAMRWB MODCELT MODSILK MODCODEC2 MODOPUS MODSKINNY \
			MODMEMCACHE MODMULTICAST MODNIBBLEBILL MODPORTAUDIO \
			MODPASTREAM MODSHELLSTREAM MODCURL MODXMLCURL \
			MODSAYEN MODCALLCENTER MODFSK MODSNMP MODLADSPA \
			MODRTMP MODBLACKLIST MODHTTPCACHE MOVEVENTZMQ \
			SAMPLECONFIGS

MODSHOUT_DESC=		mod_shout (streaming audio/mp3)
MODFLITE_DESC=		mod_flite (Text to Speech)
MODUNIMRCP_DESC=	mod_unimrcp tts
MODTTSCMDLINE_DESC=	mod_tts_commandline
MODPOCKETSPHINX_DESC=	mod_pockectsphinx (voice control)
MODCIDLOOKUP_DESC=	mod_cidlookup
MODDPDIRECTORY_DESC=	mod_dialplan_directory
MODDIRECTORY_DESC=	mod_directory (dial name directory)
MODDINGALING_DESC=	mod_dingaling (Google talk)
MODEASYROUTE_DESC=	mod_easyroute (routing tool)
MODERLANGEVENT_DESC=	mod_erlang_event (Call Center Dist)
MODLCR_DESC=		mod_lcr (least cost routiwng)
MODSOUNDTOUCH_DESC=	mod_soundtouch (Audio Effects)
MODRSS_DESC=		mod_rss (rss feed reader)
MODSNOM_DESC=		mod_snom (snom control)
MODAVMD_DESC=		mod_avmd (Adavced v-mail detection)
MODVMD_DESC=		mod_vmd (voice mail detection)
MODSPY_DESC=		mod_spy (listen/breaking on calls)
MODAMRWB_DESC=		mod_amrwb (amrwb codec)
MODCELT_DESC=		mod_celt (celt 48k codec)
MODSILK_DESC=		mod_silk (Silk Codec)
MODCODEC2_DESC=		mod_codec2 (Codec2 codec)
MODOPUS_DESC=		mod_opus codec (Opus codec)
MODFREETDM_DESC=	mod_freetdm (TDM Cards)
MODSKINNY_DESC=		mod_skinny (Skinny Support)
MODMEMCACHE_DESC=	mod_memcache
MODMULTICAST_DESC=	mod_event_multicast
MODNIBBLEBILL_DESC=	mod_nibblebill (billing)
MODPORTAUDIO_DESC=	mod_portaudio (souncard portaudio)
MODPASTREAM_DESC=	mod_portaudio_stream (new)
MODSHELLSTREAM_DESC=	mod_shell_stream (new)
MODPYTHON_DESC=		mod_python (python support)
MODCURL_DESC=		mod_curl
MODXMLCURL_DESC=	mod_xml_curl
MODDISTRIBUTOR_DESC=	mod_distributor (C\# .NET API)
MODSNAPSHOT_DESC=	mod_snapshot (testing)
MODSAYDE_DESC=		mod_say_de (German support)
MODSAYES_DESC=		mod_say_se (Spanish support)
MODSAYEN_DESC=		mod_say_en (English support)
MODSAYHE_DESC=		mod_say_he (Hebrew support)
MODSAYHU_DESC=		mod_say_hu (Hungarian support)
MODSAYFR_DESC=		mod_say_fr (French support)
MODSAYIT_DESC=		mod_say_it (Italian support)
MODSAYNL_DESC=		mod_say_nl (Dutch support)
MODSAYRU_DESC=		mod_say_ru (Russian support)
MODSAYTH_DESC=		mod_say_th (Thi support)
MODSAYZH_DESC=		mod_say_zh (Chinese support)
EXTENSIONS_DESC=	Include Default User Extensions
MODCALLCENTER_DESC=	mod_callcenter (callcenter queue)
MODFSK_DESC=		mod_fsck (caller_id related)
MODCDRPGCSV_DESC=	mod_cdr_pg_csv (broken on 9.X)
MODSNMP_DESC=		mod_snmp (network monitoring)
MODLADSPA_DESC=		mod_ladspa (voice changer) (new)
MODRTMP_DESC=		mod_rtmp (realtime media protocol)
MODDPASTERISK_DESC=	mod_dialplan_asterisk (* dialplan)
MODBLACKLIST_DESC=	mod_blacklist (Black list numbers)
MODHTTPCACHE_DESC=	mod_http_cache (new)
MODEVENTZMQ_DESC=	mod_event_zmq (build issues) (new)
SAMPLECONFIGS_DESC=	Sample Configurations

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

.for i in MODFLITE MODPOCKETSPHINX MODCIDLOOKUP MODDPDIRECTORY MODEASYROUTE MODLCR MODSOUNDTOUCH MODRSS \
	MODSNOM MODAVMD MODVMD MODSPY MODAMRWB MODCELT MODMULTICAST MODPORTAUDIO MODCURL MODXMLCURL \
	MODSAYDE MODSAYEN MODSAYES MODSAYFR MODSAYHE MODSAYHU MODSAYIT MODSAYNL MODSAYRU MODSAYTH MODSAYZH \
	MODNIBBLEBILL MODDINGALING MODDIRECTORY MODMEMCACHE MODPASTREAM MODSHELLSTREAM 	MODSILK MODUNIMRCP \
	MODTTSCMDLINE MODDISTRIBUTOR MODSNAPSHOT MODSKINNY EXTENSIONS MODCALLCENTER MODCODEC2 MODFSK MODOPUS \
	MODDPASTERISK MODRTMP SAMPLECONFIGS MODBLACKLIST MODHTTPCACHE MODEVENTZMQ
.if ! ${PORT_OPTIONS:M${i}}
PLIST_SUB+=	WITH_${i}="@comment "
.else
PLIST_SUB+=	WITH_${i}=""
.endif
.endfor

.if ! ${PORT_OPTIONS:MMODFREETDM}
PLIST_SUB+=	 WITH_MODFREETDM="@comment "
.else
PLIST_SUB+=	WITH_MODFREETDM=""
CONFIGURE_ARGS+=	--with-libpri=${LOCALBASE}
BUILD_DEPENDS+=	libpri>=1.2.0:${PORTSDIR}/misc/libpri \
		${LOCALBASE}/include/dahdi/wctdm_user.h:${PORTSDIR}/misc/dahdi
LIB_DEPENDS+=	pri:${PORTSDIR}/misc/libpri
RUN_DEPENDS+=	${LOCALBASE}/include/dahdi/wctdm_user.h:${PORTSDIR}/misc/dahdi \
		${LOCALBASE}/lib/dahdi/dahdi.ko:${PORTSDIR}/misc/dahdi-kmod
.endif

.if ! ${PORT_OPTIONS:MMODSHOUT}
PLIST_SUB+=	WITH_MODSHOUT="@comment "
.else
PLIST_SUB+=	WITH_MODSHOUT=""
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
.endif

.if ! ${PORT_OPTIONS:MMODPERL}
PLIST_SUB+=	WITH_MODPERL="@comment "
.else
PLIST_SUB+=	WITH_MODPERL=""
LIB_DEPENDS+=	gdbm:${PORTSDIR}/databases/gdbm \
		db:${PORTSDIR}/databases/db42
.endif

.if ! ${PORT_OPTIONS:MMODERLANGEVENT}
PLIST_SUB+=	WITH_MODERLANGEVENT="@comment "
.else
PLIST_SUB+=	WITH_MODERLANGEVENT=""
BUILD_DEPENDS+=	${LOCALBASE}/lib/erlang/usr/include/erl_driver.h:${PORTSDIR}/lang/erlang
.endif

.if ! ${PORT_OPTIONS:MMODPYTHON}
PLIST_SUB+=	WITH_MODPYTHON="@comment "
.else
PLIST_SUB+=	WITH_MODPYTHON=""
USE_PYTHON=	yes
.endif

.if ! ${PORT_OPTIONS:MMODCDRPGCSV}
PLIST_SUB+=	WITH_MODCDRPGCSV="@comment "
.else
PLIST_SUB+=	WITH_MODCDRPGCSV=""
USE_PGSQL=	yes
#WITH_PGSQL_VER=	90
.endif

.if ! ${PORT_OPTIONS:MMODSNMP}
PLIST_SUB+=	WITH_MODSNMP="@comment "
.else
PLIST_SUB+=	WITH_MODSNMP=""
BUILD_DEPENDS+=	${LOCALBASE}/include/net-snmp/definitions.h:${PORTSDIR}/net-mgmt/net-snmp
RUN_DEPENDS+=	${LOCALBASE}/include/net-snmp/definitions.h:${PORTSDIR}/net-mgmt/net-snmp
.endif

.if ! ${PORT_OPTIONS:MMODLADSPA}
PLIST_SUB+=	WITH_MODLADSPA="@comment "
.else
PLIST_SUB+=	WITH_MODLADSPA=""
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

post-extract:
.for file in ${DISTFILES:M*\:[23]:C/\:[23]//}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${file} ${WRKSRC}/libs/
.endfor

pre-configure:
	@${REINPLACE_CMD} -e 's|base=http://files.freeswitch.org/downloads/libs/|base=file://${DISTDIR}/${DIST_SUBDIR}/|g' ${WRKSRC}/build/getlib.sh.in
	@${REINPLACE_CMD} -e 's|2.1.9|2.1.10|g' ${WRKSRC}/src/mod/event_handlers/mod_event_zmq/Makefile
.if ! ${PORT_OPTIONS:MSAMPLECONFIGS}
	@${REINPLACE_CMD} -e 's|$$(MAKE) samples-conf|##$$(MAKE) samples-conf|g' ${WRKSRC}/Makefile.am
.endif
	cd ${WRKSRC} && ./bootstrap.sh

post-configure:
.for i in mod_unimrcp mod_flite mod_pocketsphinx
.if defined(WITH_${i:C/_//g:U})
	@${REINPLACE_CMD} -e 's|#\(asr_tts/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.if ${PORT_OPTIONS:MMODTTSCMDLINE}
	@${REINPLACE_CMD} -e 's|#asr_tts/mod_tts_commandline|asr_tts/mod_tts_commandline|g' ${WRKSRC}/modules.conf
.endif
.for i in mod_cidlookup mod_easyroute mod_lcr mod_soundtouch mod_rss mod_snom \
	mod_vmd mod_avmd mod_spy mod_curl mod_nibblebill mod_memcache mod_directory mod_distributor \
	mod_snapshot mod_callcenter mod_fsk mod_ladspa mod_blacklist mod_http_cache
.if ${PORT_OPTIONS:M${i:C/_//g:U}}
	@${REINPLACE_CMD} -e 's|#\(applications/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.for i in mod_amrwb mod_celt mod_silk mod_codec2 mod_opus
.if ${PORT_OPTIONS:M${i:C/_//g:U}}
	@${REINPLACE_CMD} -e 's|#\(codecs/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.for i in mod_shell_stream mod_shout
.if ${PORT_OPTIONS:M${i:C/_//g:U}}
	@${REINPLACE_CMD} -e 's|#\(formats/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.if ${PORT_OPTIONS:MMODPASTREAM}
	@${REINPLACE_CMD} -e 's|#formats/mod_portaudio_stream|formats/mod_portaudio_stream|g' ${WRKSRC}/modules.conf
.endif
.for i in mod_say_de mod_say_es mod_say_en mod_say_fr mod_say_he mod_say_hu mod_say_it mod_say_nl mod_say_ru mod_say_th mod_say_zh
.if ${PORT_OPTIONS:M${i:C/_//g:U}}
	@${REINPLACE_CMD} -e 's|#\(say/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.for i in mod_perl mod_python
.if ${PORT_OPTIONS:M${i:C/_//g:U}}
	@${REINPLACE_CMD} -e 's|#\(languages/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.for i in mod_skinny mod_portaudio mod_dingaling mod_rtmp
.if ${PORT_OPTIONS:M${i:C/_//g:U}}
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
.if ! ${PORT_OPTIONS:MMODDPASTERISK}
	@${REINPLACE_CMD} -e 's|dialplans/mod_dialplan_asterisk|#dialplans/mod_dialplan_asterisk|g' ${WRKSRC}/modules.conf
.endif
.if ${PORT_OPTIONS:MMODEVENTZMQ}
	@${REINPLACE_CMD} -e 's|#event_handlers/mod_event_zmq|event_handlers/mod_event_zmq|g' ${WRKSRC}/modules.conf
.endif

pre-install:
	@${CHMOD} 664 ${WRKSRC}/libs/freetdm/conf/*
.if ! ${PORT_OPTIONS:MEXTENSIONS}
	@${FIND} ${WRKSRC}/conf/directory/default -type f -name '*.xml' -delete
.endif

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
	    ${SH} ${PKGINSTALL} ${BASE_PORTNAME} POST-INSTALL
.if ! ${PORT_OPTIONS:MSAMPLECONFIGS}
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/skinny_profiles
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/sip_profiles/internal
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/sip_profiles/external
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/sip_profiles
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/mrcp_profiles
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/lang/ru/vm
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/lang/ru/dir
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/lang/ru/demo
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/lang/ru
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/lang/he/vm
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/lang/he/dir
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/lang/he/demo
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/lang/he
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/lang/fr/vm
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/lang/fr/dir
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/lang/fr/demo
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/lang/fr
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/lang/en/vm
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/lang/en/ivr
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/lang/en/dir
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/lang/en/demo
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/lang/en
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/lang/de/vm
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/lang/de/demo
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/lang/de
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/lang
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/jingle_profiles
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/ivr_menus
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/directory/default
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/directory
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/dialplan/skinny-patterns
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/dialplan/public
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/dialplan/default
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/dialplan
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/autoload_configs
.endif
.if ! ${PORT_OPTIONS:MEXTENSIONS}
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/directory/default
.endif
	@${FIND} ${PREFIX}/etc/${BASE_PORTNAME}/. -type d | ${XARGS} ${CHMOD} 774
	@${MKDIR} ${PREFIX}/share/${BASE_PORTNAME}/sounds
	@${CHMOD} -R 774 ${PREFIX}/share/${BASE_PORTNAME}
.if ${PORT_OPTIONS:MSAMPLECONFIGS}
	@for i in $$(${FIND} ${PREFIX}/etc/${BASE_PORTNAME}/conf/ -type f -name '*.sample'); do if [ ! -f $${i%.sample} ]; then ${CP} -p $$i $${i%.sample}; fi; done
.endif
	@for i in $$(${FIND} ${PREFIX}/www/${BASE_PORTNAME}/htdocs/ -type f -name '*.sample'); do if [ ! -f $${i%.sample} ]; then ${CP} -p $$i $${i%.sample}; fi; done
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
