# Ports collection makefile for: freeswitch-core
# Date created: May 11, 2010
# Whom: Eric F Crist <ecrist@secure-computing.net>
#
# $FreeBSD$
#

PORTNAME=	freeswitch-core
PORTVERSION=	1.0.6
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://files.freeswitch.org/:1 \
		http://files.freeswitch.org/downloads/libs/:2
DISTFILES=	freeswitch-${PORTVERSION}.tar.gz:1 \
		celt-0.7.1.tar.gz:2 \
		flite-1.3.99-latest.tar.gz:2 \
		json-c-0.9.tar.gz \
		lame-3.97.tar.gz:2 \
		libmemcached-0.32.tar.gz \
		libshout-2.2.2.tar.gz:2 \
		mpg123.tar.gz:2 \
		openldap-2.4.11.tar.gz:2 \
		pocketsphinx-0.5.99-20091212.tar.gz:2 \
		soundtouch-1.3.1.tar.gz:2 \
		sphinxbase-0.4.99-20091212.tar.gz:2 \
		communicator_semi_6000_20080321.tar.gz:2
EXTRACT_ONLY=	freeswitch-${PORTVERSION}.tar.gz

MAINTAINER=	ecrist@secure-computing.net
COMMENT=	FreeSwitch SoftSwitch Port

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		gnutls:${PORTSDIR}/security/gnutls \
		odbc:${PORTSDIR}/databases/unixODBC

WRKSRC=		${WRKDIR}/freeswitch-${PORTVERSION}

ONLY_FOR_ARCHS=	i386 amd64

USE_AUTOTOOLS=	autoconf:262:env automake:110:env libtool:22:env

USE_PERL5_BUILD=yes

USE_GMAKE=	yes
SUB_FILES=	pkg-install pkg-message
USE_RC_SUBR=	freeswitch
HAS_CONFIGURE=	yes
VARBASE?=	/var
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--bindir=${PREFIX}/bin \
		--sysconfdir=${PREFIX}/etc/${PORTNAME}/conf \
		--includedir=${PREFIX}/include/${PORTNAME} \
		--libdir=${PREFIX}/lib/${PORTNAME}/lib \
		--with-modinstdir=${PREFIX}/lib/${PORTNAME}/mod \
		--with-rundir=${VARBASE}/run/freeswitch \
		--with-libgnutls-prefix=${LOCALBASE} \
		--with-ogg=${LOCALBASE} \
		--with-ogg-libraries=${LOCALBASE}/lib \
		--with-ogg-includes=${LOCALBASE}/include

CONFIGURE_ENV+=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${PREFIX}/include

FREESWITCH_USER=	freeswitch
FREESWITCH_GROUP=	${FREESWITCH_USER}

SUB_LIST=	FREESWITCH_USER=${FREESWITCH_USER} FREESWITCH_GROUP=${FREESWITCH_GROUP}

OPTIONS=	MODSHOUT        "Enable mod_shout (streaming audio/mp3)" on \
		MODFLITE	"Enable mod_flite (Text to Speech)" on \
		MODUNIMRCP	"Enable mod_unimrcp tts (new testing)" off \
		MODTTSCMDLINE	"Enable mod_tts_commandline (testing)" off \
		MODPOCKETSPHINX	"Enable mod_pockectsphinx (voice control)" on \
		MODCIDLOOKUP	"Enable mod_cidlookup" on \
		MODDPDIRECTORY	"Enable mod_dialplan_directory" off \
		MODDIRECTORY	"Enable mod_directory" on \
 		MODDINGALING	"Enable mod_dingaling(google talk)" on \
		MODEASYROUTE	"Enable mod_easyroute(routeing tool)" on \
		MODERLANGEVENT  "Enable mod_erlang_event (Call Center Dist)" off \
		MODFAX		"Enable mod_fax" on \
		MODLCR		"Enable mod_lcr (least cost routing)" on \
		MODSOUNDTOUCH	"Enable mod_soundtouch" on \
		MODRSS		"Enable mod_rss (rss feed reader)" on \
		MODSNOM		"Enable mod_snom (snom control)" off \
		MODVMD		"Enable mod_vmd (voice mail detection)" on \
		MODSPY		"Enable mod_spy" on \
		MODAMRWB	"Enable mod_amrwb (amrwb codec)" on \
		MODCELT		"Enable mod_celt (celt codec)" on \
		MODSILK		"Enable mod_silk (New Silk Codec)" on \
		MODOPENZAP	"Enable mod_openzap dahdi support" off \
		MODSKINNY	"Enable mod_skinny Skinny Support (Beta)" off \
		MODMEMCACHE	"Enable mod_memcache" on \
		MODMULTICAST	"Enable mod_event_multicast" on \
		MODNIBBLEBILL   "Enable mod_nibblebill(billing)" on \
		MODPORTAUDIO    "Enable mod_portaudio" on \
		MODPASTREAM	"Enable mod_portaudio_stream (new)" on \
		MODSHELLSTREAM	"Enable mod_SHELL_stream (New)" on \
		MODPERL		"Enable mod_perl (perl support)" off \
		MODPYTHON	"Enable mod_python (python lang)" off \
		MODCURL		"Enable mod_curl" off \
		MODXMLCURL	"Enable mod_xml_curl" off \
		MODDISTRIBUTOR	"Enable mod_distributor (testing)" off \
		MODSNAPSHOT	"Enable mod_snapshot (testing)" off \
		MODSAYDE	"Enable mod_say_de (German support)" off \
		MODSAYES	"Enable mod_say_se (Spanish support)" off \
		MODSAYEN	"Enable mod_say_en (English support)" on \
		MODSAYHU	"Enable mod_say_hu (Hungarian support(new)" off \
		MODSAYFR	"Enable mod_say_fr (French support)" off \
		MODSAYIT	"Enable mod_say_it (Italian support)" off \
		MODSAYNL	"Enable mod_say_nl (Dutch support)" off \
		MODSAYRU	"Enable mod_say_ru (Russian support)" on \
		MODSAYTH	"Enable mod_say_th (Thi support(new)" off \
		MODSAYZH	"Enable mod_say_zh (Chinese support)" off \
		EXTENSIONS	"Include Default User Extensions" off

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

.for i in MODFLITE MODPOCKETSPHINX MODCIDLOOKUP MODDPDIRECTORY MODEASYROUTE MODLCR MODSOUNDTOUCH \
	MODRSS MODSNOM MODVMD MODSPY MODAMRWB MODCELT MODMULTICAST MODPORTAUDIO MODCURL MODXMLCURL \
	MODSAYDE MODSAYEN MODSAYES MODSAYFR MODSAYHU MODSAYIT MODSAYNL MODSAYRU MODSAYTH MODSAYZH \
	MODNIBBLEBILL MODDINGALING MODDIRECTORY MODMEMCACHE MODPYTHON MODPASTREAM MODSHELLSTREAM \
	MODSILK MODUNIMRCP MODTTSCMDLINE MODDISTRIBUTOR MODSNAPSHOT MODSKINNY EXTENSIONS
.if !defined(WITH_${i})
PLIST_SUB+=	WITH_${i}="@comment "
.else
PLIST_SUB+=	WITH_${i}=""
.endif
.endfor

.if !defined(WITH_MODOPENZAP)
PLIST_SUB+=	WITH_MODOPENZAP="@comment "
.else
PLIST_SUB+=	WITH_MODOPENZAP=""
CONFIGURE_ARGS+=	--with-libpri
BUILD_DEPENDS+=	libpri>=1.2.0:${PORTSDIR}/misc/libpri \
		${LOCALBASE}/include/dahdi/wctdm_user.h:${PORTSDIR}/misc/dahdi
LIB_DEPENDS+=	pri:${PORTSDIR}/misc/libpri
RUN_DEPENDS+=	${LOCALBASE}/include/dahdi/wctdm_user.h:${PORTSDIR}/misc/dahdi
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

.if !defined(WITH_MODFAX)
PLIST_SUB+=	WITH_MODFAX="@comment "
.else
PLIST_SUB+=	WITH_MODFAX=""
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg
.endif

.if !defined(WITH_MODERLANGEVENT)
PLIST_SUB+=	WITH_MODERLANGEVENT="@comment "
.else
PLIST_SUB+=	WITH_MODERLANGEVENT=""
BUILD_DEPENDS+=	${LOCALBASE}/lib/erlang/usr/include/erl_driver.h:${PORTSDIR}/lang/erlang-lite
.endif

pre-configure:
	cd ${WRKSRC} && ./rebootstrap.sh
	@${REINPLACE_CMD} -e 's|pkgconfigdir = $$(libdir)/pkgconfig|pkgconfigdir = ${PREFIX}/libdata/libdata/pkgconfig|g' ${WRKSRC}/libs/*/Makefile.am
	@${REINPLACE_CMD} -e 's|pkgconfigdir = $$(libdir)/pkgconfig|pkgconfigdir = ${PREFIX}/libdata/pkgconfig|g' ${WRKSRC}/libs/*/Makefile.in
	@${REINPLACE_CMD} -e 's|pkgconfigdir = $$(libdir)/pkgconfig|pkgconfigdir = ${PREFIX}/libdata/libdata/pkgconfig|g' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|pkgconfigdir = $$(libdir)/pkgconfig|pkgconfigdir = ${PREFIX}/libdata/libdata/pkgconfig|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|base=http://files.freeswitch.org/downloads/libs/|base=file:///usr/ports/distfiles/|g' ${WRKSRC}/build/getlib.sh.in

.if defined(WITH_VOICEMAILPATCH)
	@${REINPLACE_CMD} -e 's|${storage_dir}/|${voicemail_dir}|g' ${WRKSRC}/src/mod/applications/mod_voicemail/mod_voicemail.c
	@${REINPLACE_CMD} -e 's|<!--<param name="storage-dir" value="/tmp"/>-->|<!--<param name="voicemail-dir" value="/var/spool/freeswitch/voicemail"/>-->|g' ${WRKSRC}/conf/autoload_configs/voicemail.conf.xml
.endif

post-configure:
.for i in mod_unimrcp mod_flite mod_pocketsphinx
.if defined(WITH_${i:C/_//g:U})
	@${REINPLACE_CMD} -e 's|#\(asr_tts/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.if defined(WITH_MODTTSCMDLINE)
	@${REINPLACE_CMD} -e 's|#asr_tts/mod_tts_commandline|asr_tts/mod_tts_commandline|g' ${WRKSRC}/modules.conf
.endif
.for i in mod_cidlookup mod_easyroute mod_fax mod_lcr mod_soundtouch mod_rss mod_snom \
	mod_vmd mod_spy mod_curl mod_nibblebill mod_memcache mod_directory mod_distributor \
	mod_snapshot
.if defined(WITH_${i:C/_//g:U})
	@${REINPLACE_CMD} -e 's|#\(applications/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.for i in mod_amrwb mod_celt mod_silk
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
.for i in mod_say_de mod_say_es mod_say_en mod_say_fr mod_say_hu mod_say_it mod_say_nl mod_say_ru mod_say_th mod_say_zh
.if defined(WITH_${i:C/_//g:U})
	@${REINPLACE_CMD} -e 's|#\(say/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.for i in mod_perl mod_python
.if defined(WITH_${i:C/_//g:U})
	@${REINPLACE_CMD} -e 's|#\(languages/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.for i in mod_skinny mod_portaudio mod_dingaling
.if defined(WITH_${i:C/_//g:U})
	@${REINPLACE_CMD} -e 's|#\(endpoints/${i}\)|\1|g' ${WRKSRC}/modules.conf
.endif
.endfor
.if defined(WITH_MODDPDIRECTORY)
	@${REINPLACE_CMD} -e 's|#dialplans/mod_dialplan_directory|dialplans/mod_dialplan_directory|g' ${WRKSRC}/modules.conf
.endif
.if defined(WITH_MODOPENZAP)
	@${REINPLACE_CMD} -e 's|#../../libs/openzap/mod_openzap|../../libs/openzap/mod_openzap|g' ${WRKSRC}/modules.conf
.endif
.if defined(WITH_MODMULTICAST)
	@${REINPLACE_CMD} -e 's|#event_handlers/mod_event_multicast|event_handlers/mod_event_multicast|g' ${WRKSRC}/modules.conf
.endif
.if defined(WITH_MODERLANGEVENT)
	@${REINPLACE_CMD} -e 's|#event_handlers/mod_erlang_event|event_handlers/mod_erlang_event|g' ${WRKSRC}/modules.conf
.endif
.if defined(WITH_MODXMLCURL)
	@${REINPLACE_CMD} -e 's|#xml_int/mod_xml_curl|xml_int/mod_xml_curl|g' ${WRKSRC}/modules.conf
.endif

pre-install:
	@${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

.if !defined(WITH_EXTENSIONS)
	@${RM} ${WRKSRC}/conf/directory/default/*
.endif

post-install:
.if !defined(WITH_EXTENSIONS)
	@${MKDIR} ${PREFIX}/etc/${PORTNAME}/conf/directory/default
.endif
	@${MKDIR} ${PREFIX}/share/${PORTNAME}/sounds
	@${CHOWN} -R ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${PREFIX}/etc/${PORTNAME}
	@${CHOWN} -R ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${PREFIX}/share/${PORTNAME}
	@${CHOWN} -R ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${VARBASE}/db/${PORTNAME}
	@${CHOWN} -R ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${VARBASE}/log/${PORTNAME}
	@${CHOWN} -R ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${VARBASE}/${PORTNAME}
	@${CHOWN} -R ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${VARBASE}/run/${PORTNAME}
	@${CHOWN} -R ${FREESWITCH_USER}:${FREESWITCH_GROUP} ${VARBASE}/spool/${PORTNAME}
	@for i in $$(${FIND} ${PREFIX}/etc/${PORTNAME}/conf/ -type f -name '*.sample'); do if [ ! -f $${i%.sample} ]; then ${CP} -p $$i $${i%.sample}; fi; done
	@${CAT} ${PKGMESSAGE}

.if ${OSVERSION} < 700000
IGNORE=		freeswitch is only supported on FreeBSD 7 or newer
.endif

	@${ECHO_MSG} "This port chown -R various directories ${FREESWITCH_USER}:${FREESWITCH_GROUP} "
	@${ECHO_MSG} "this is for port security . in the event something should stop working."
	@${ECHO_MSG} "Please take the time to check chownership of the dir's"
	@${ECHO_MSG} "${VARBASE}/db/${PORTNAME} ${VARBASE}/log/${PORTNAME} ${VARBAE}/${PORTNAME} ${PREFIX}/etc/${PORTNAME}"

.include <bsd.port.mk>
