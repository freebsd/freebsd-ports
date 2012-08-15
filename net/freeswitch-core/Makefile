# Ports collection makefile for:	freeswitch-core
# Date created:				May 11, 2010
# Whom:					Richard Neese <r.neese@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	freeswitch-core
PORTVERSION=	1.0.7.1
PORTREVISION=	2
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

MAINTAINER=	r.neese@gmail.com
COMMENT=	FreeSwitch SoftSwitch Port

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		jpeg:${PORTSDIR}/graphics/jpeg \
		tiff:${PORTSDIR}/graphics/tiff \
		odbc:${PORTSDIR}/databases/unixODBC

CONFLICTS=	freeswitch-core-devel-[0-9]*

WRKSRC=		${WRKDIR}/${BASE_PORTNAME}-${PORTVERSION}

USE_AUTOTOOLS=	autoconf:env automake:env libtool:env

USE_PERL5_BUILD=yes
USE_BISON=	both
USE_PKGCONFIG=	yes
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

OPTIONS=	MODSHOUT        "Enable mod_shout (streaming audio/mp3)" on \
		MODFLITE	"Enable mod_flite (Text to Speech)" on \
		MODUNIMRCP	"Enable mod_unimrcp tts" off \
		MODTTSCMDLINE	"Enable mod_tts_commandline" on \
		MODPOCKETSPHINX	"Enable mod_pockectsphinx (voice control)" on \
		MODCIDLOOKUP	"Enable mod_cidlookup()" on \
		MODDPDIRECTORY	"Enable mod_dialplan_directory()" off \
		MODDIRECTORY	"Enable mod_directory(dial name directory)" on \
 		MODDINGALING	"Enable mod_dingaling(google talk)" on \
		MODEASYROUTE	"Enable mod_easyroute(routing tool)" on \
		MODERLANGEVENT  "Enable mod_erlang_event (Call Center Dist)" off \
		MODLCR		"Enable mod_lcr (least cost routing)" on \
		MODSOUNDTOUCH	"Enable mod_soundtouch(Audio Effects)" on \
		MODRSS		"Enable mod_rss (rss feed reader)" on \
		MODSNOM		"Enable mod_snom (snom control)" on \
		MODAVMD		"Enable mod_avmd (Adavced v-mail detection)" on \
		MODVMD		"Enable mod_vmd (voice mail detection)" off \
		MODSPY		"Enable mod_spy(listen/breaking on calls)" on \
		MODAMRWB	"Enable mod_amrwb (amrwb codec)" on \
		MODCELT		"Enable mod_celt (celt 48k  codec)" on \
		MODSILK		"Enable mod_silk (Silk Codec)" on \
		MODCODEC2	"Enable mod_codec2 (Codec2 codec)" on \
		MODOPUS		"Enable mod_opus codec (Opus codec)" on \
		MODFREETDM	"Enable mod_freetdm (TDM Cards )" off \
		MODSKINNY	"Enable mod_skinny (Skinny Support)" on \
		MODMEMCACHE	"Enable mod_memcache ()" on \
		MODMULTICAST	"Enable mod_event_multicast()" on \
		MODNIBBLEBILL   "Enable mod_nibblebill (billing)" on \
		MODPORTAUDIO    "Enable mod_portaudio(souncard portaudio)" on \
		MODPASTREAM	"Enable mod_portaudio_stream (new)" on \
		MODSHELLSTREAM	"Enable mod_shell_stream (new)" on \
		MODPERL		"Enable mod_perl (perl support)" off \
		MODPYTHON	"Enable mod_python (python support)" off \
		MODCURL		"Enable mod_curl" on \
		MODXMLCURL	"Enable mod_xml_curl" on \
		MODDISTRIBUTOR	"Enable mod_distributor(c\# .net api)" off \
		MODSNAPSHOT	"Enable mod_snapshot (testing)" off \
		MODSAYDE	"Enable mod_say_de (German support)" off \
		MODSAYES	"Enable mod_say_se (Spanish support)" off \
		MODSAYEN	"Enable mod_say_en (English support)" on \
		MODSAYHE	"Enable mod_say_he (Hebrew support)" off \
		MODSAYHU	"Enable mod_say_hu (Hungarian support)" off \
		MODSAYFR	"Enable mod_say_fr (French support)" off \
		MODSAYIT	"Enable mod_say_it (Italian support)" off \
		MODSAYNL	"Enable mod_say_nl (Dutch support)" off \
		MODSAYRU	"Enable mod_say_ru (Russian support)" off \
		MODSAYTH	"Enable mod_say_th (Thi support)" off \
		MODSAYZH	"Enable mod_say_zh (Chinese support)" off \
		EXTENSIONS	"Include Default User Extensions" off \
		MODCALLCENTER	"Enable mod_callcenter (callcenter que)" on \
		MODFSK		"Enablle mod_fsck (caller_id related)" on \
		MODCDRPGCSV	"Enable mod_cdr_pg_csv( broken on 9.x )" off \
		MODSNMP		"Enable mod_snmp (network monitoring)" on \
		MODLADSPA	"Enable mod_ladspa(voice changer)(new)" on \
		MODRTMP		"Enable mod_rtmp(realtime media protocol)" on \
		MODDPASTERISK	"Enable mod_dialplan_asterisk(* dialplan)" off \
		MODBLACKLIST	"Enable mod_blacklist(Black list numbers)" on \
		MODHTTPCACHE	"Enable mod_http_cache(new)" on \
		MODEVENTZMQ     "Enable mod_event_zmq(build issues)(new)" on \
		SAMPLECONFIGS	"Enable Sample Configurations" on

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
.if !defined(WITH_${i})
PLIST_SUB+=	WITH_${i}="@comment "
.else
PLIST_SUB+=	WITH_${i}=""
.endif
.endfor

.if !defined(WITH_MODFREETDM)
PLIST_SUB+=	 WITH_MODFREETDM="@comment "
.else
.if ${OSVERSION} < 703000 || (${OSVERSION} >= 800000 && ${OSVERSION} < 800108)
IGNORE=	sorry you can not use mod_freetdm on this version of freebsd ( dahdi support broken ) please update
.endif
PLIST_SUB+=	WITH_MODFREETDM=""
CONFIGURE_ARGS+=	--with-libpri=${LOCALBASE}
BUILD_DEPENDS+=	libpri>=1.2.0:${PORTSDIR}/misc/libpri \
		${LOCALBASE}/include/dahdi/wctdm_user.h:${PORTSDIR}/misc/dahdi
LIB_DEPENDS+=	pri:${PORTSDIR}/misc/libpri
RUN_DEPENDS+=	${LOCALBASE}/include/dahdi/wctdm_user.h:${PORTSDIR}/misc/dahdi \
		${LOCALBASE}/lib/dahdi/dahdi.ko:${PORTSDIR}/misc/dahdi-kmod
.endif

.if !defined(WITH_MODSHOUT)
PLIST_SUB+=	WITH_MODSHOUT="@comment "
.else
PLIST_SUB+=	WITH_MODSHOUT=""
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis
.endif

.if !defined(WITH_MODPERL)
PLIST_SUB+=	WITH_MODPERL="@comment "
.else
PLIST_SUB+=	WITH_MODPERL=""
LIB_DEPENDS+=	gdbm:${PORTSDIR}/databases/gdbm \
		db:${PORTSDIR}/databases/db42
.endif

.if !defined(WITH_MODERLANGEVENT)
PLIST_SUB+=	WITH_MODERLANGEVENT="@comment "
.else
PLIST_SUB+=	WITH_MODERLANGEVENT=""
BUILD_DEPENDS+=	${LOCALBASE}/lib/erlang/usr/include/erl_driver.h:${PORTSDIR}/lang/erlang
.endif

.if !defined(WITH_MODPYTHON)
PLIST_SUB+=	WITH_MODPYTHON="@comment "
.else
PLIST_SUB+=	WITH_MODPYTHON=""
USE_PYTHON=	yes
.endif

.if !defined(WITH_MODCDRPGCSV)
PLIST_SUB+=	WITH_MODCDRPGCSV="@comment "
.else
PLIST_SUB+=	WITH_MODCDRPGCSV=""
USE_PGSQL=	yes
#WITH_PGSQL_VER=	90
.endif

.if !defined(WITH_MODSNMP)
PLIST_SUB+=	WITH_MODSNMP="@comment "
.else
PLIST_SUB+=	WITH_MODSNMP=""
BUILD_DEPENDS+=	${LOCALBASE}/include/net-snmp/definitions.h:${PORTSDIR}/net-mgmt/net-snmp
RUN_DEPENDS+=	${LOCALBASE}/include/net-snmp/definitions.h:${PORTSDIR}/net-mgmt/net-snmp
.endif

.if !defined(WITH_MODLADSPA)
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

# FreeBSD 7 doesn't have lrintl, but lrint will do the trick just fine
# It's quite cryptic as to why the reinplace doesn't work; there's no mention
# of lrintl anywhere in any source....
.if ${OSVERSION} < 800012
#	${REINPLACE_CMD} -e 's/lrintl/lrint/' \
#	    ${WRKSRC}/libs/spandsp/src/spandsp/saturated.h
BROKEN=	Requires lrintl, which is not present on FreeBSD 7
.endif

post-extract:
.for file in ${DISTFILES:M*\:[23]:C/\:[23]//}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${file} ${WRKSRC}/libs/
.endfor

pre-configure:
	@${REINPLACE_CMD} -e 's|base=http://files.freeswitch.org/downloads/libs/|base=file://${DISTDIR}/${DIST_SUBDIR}/|g' ${WRKSRC}/build/getlib.sh.in
	@${REINPLACE_CMD} -e 's|2.1.9|2.1.10|g' ${WRKSRC}/src/mod/event_handlers/mod_event_zmq/Makefile
.if !defined(WITH_SAMPLECONFIGS)
	@${REINPLACE_CMD} -e 's|$$(MAKE) samples-conf|##$$(MAKE) samples-conf|g' ${WRKSRC}/Makefile.am
.endif
	cd ${WRKSRC} && ./bootstrap.sh

post-configure:
.for i in mod_unimrcp mod_flite mod_pocketsphinx
.if defined(WITH_${i:C/_//g:U})
	@${REINPLACE_CMD} -e 's|#\(asr_tts/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.if defined(WITH_MODTTSCMDLINE)
	@${REINPLACE_CMD} -e 's|#asr_tts/mod_tts_commandline|asr_tts/mod_tts_commandline|g' ${WRKSRC}/modules.conf
.endif
.for i in mod_cidlookup mod_easyroute mod_lcr mod_soundtouch mod_rss mod_snom \
	mod_vmd mod_avmd mod_spy mod_curl mod_nibblebill mod_memcache mod_directory mod_distributor \
	mod_snapshot mod_callcenter mod_fsk mod_ladspa mod_blacklist mod_http_cache
.if defined(WITH_${i:C/_//g:U})
	@${REINPLACE_CMD} -e 's|#\(applications/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.for i in mod_amrwb mod_celt mod_silk mod_codec2 mod_opus
.if defined(WITH_${i:C/_//g:U})
	@${REINPLACE_CMD} -e 's|#\(codecs/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.for i in  mod_shell_stream mod_shout
.if defined(WITH_${i:C/_//g:U})
	@${REINPLACE_CMD} -e 's|#\(formats/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.if defined(WITH_MODPASTREAM)
	@${REINPLACE_CMD} -e 's|#formats/mod_portaudio_stream|formats/mod_portaudio_stream|g' ${WRKSRC}/modules.conf
.endif
.for i in mod_say_de mod_say_es mod_say_en mod_say_fr mod_say_he mod_say_hu mod_say_it mod_say_nl mod_say_ru mod_say_th mod_say_zh
.if defined(WITH_${i:C/_//g:U})
	@${REINPLACE_CMD} -e 's|#\(say/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.for i in mod_perl mod_python
.if defined(WITH_${i:C/_//g:U})
	@${REINPLACE_CMD} -e 's|#\(languages/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.for i in mod_skinny mod_portaudio mod_dingaling mod_rtmp
.if defined(WITH_${i:C/_//g:U})
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

pre-install:
	@${CHMOD} 664 ${WRKSRC}/libs/freetdm/conf/*
.if !defined(WITH_EXTENSIONS)
	@${FIND} ${WRKSRC}/conf/directory/default -type f -name '*.xml' -delete
.endif

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
	    ${SH} ${PKGINSTALL} ${BASE_PORTNAME} POST-INSTALL
.if !defined(WITH_SAMPLECONFIGS)
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
.if !defined(WITH_EXTENSIONS)
	@${MKDIR} ${PREFIX}/etc/${BASE_PORTNAME}/conf/directory/default
.endif
	@${FIND} ${PREFIX}/etc/${BASE_PORTNAME}/. -type d | ${XARGS} ${CHMOD} 774
	@${MKDIR} ${PREFIX}/share/${BASE_PORTNAME}/sounds
	@${CHMOD} -R 774 ${PREFIX}/share/${BASE_PORTNAME}
.if defined(WITH_SAMPLECONFIGS)
	@for i in $$(${FIND} ${PREFIX}/etc/${BASE_PORTNAME}/conf/ -type f -name '*.sample'); do if [ ! -f $${i%.sample} ]; then ${CP} -p $$i $${i%.sample}; fi; done
.endif
	@for i in $$(${FIND} ${PREFIX}/www/${BASE_PORTNAME}/htdocs/ -type f -name '*.sample'); do if [ ! -f $${i%.sample} ]; then ${CP} -p $$i $${i%.sample}; fi; done
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
