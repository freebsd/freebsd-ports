# Ports collection makefile for: freeswitch
# Date created: Augets 9, 2009
# Whom: Richard Neese <r.neese@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	freeswitch
PORTVERSION=	1.0.4.3
CATEGORIES=	net
MASTER_SITES=	http://files.freeswitch.org/:source1 \
		http://dl.getdropbox.com/u/152504/:source2 \
		http://www.freeswitch.org/eg/:source3
DISTNAME=	${PORTNAME}-${PORTVERSION}
DISTFILES=	pizza_gram.tar.gz:source1 \
		${PORTNAME}-${PORTVERSION}.tar.gz:source2 \
		pizza_sounds.tar.gz:source3 \
		${PORTNAME}-sounds-en-us-callie-8000-1.0.11.tar.gz:source1 \
		${PORTNAME}-sounds-en-us-callie-16000-1.0.11.tar.gz:source1 \
		${PORTNAME}-sounds-en-us-callie-32000-1.0.11.tar.gz:source1 \
		${PORTNAME}-sounds-en-us-callie-48000-1.0.11.tar.gz:source1 \
		${PORTNAME}-sounds-music-8000-1.0.8.tar.gz:source1 \
		${PORTNAME}-sounds-music-16000-1.0.8.tar.gz:source1 \
		${PORTNAME}-sounds-music-32000-1.0.8.tar.gz:source1 \
		${PORTNAME}-sounds-music-48000-1.0.8.tar.gz:source1
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	r.neese@gmail.com
COMMENT=	FreeSwitch SoftSwitch Port

BUILD_DEPENDS=	wget:${PORTSDIR}/ftp/wget \
		bash:${PORTSDIR}/shells/bash \
		pkg-config:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		gnutls:${PORTSDIR}/security/gnutls
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

ONLY_FOR_ARCHS=	i386 amd64

USE_AUTOTOOLS=	autoconf:262:env automake:110:env libtool:22:env

USE_GMAKE=	yes
SUB_FILES=	pkg-message
USE_RC_SUBR=	freeswitch
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}/${PORTNAME} --with-libgnutls-prefix=${LOCALBASE} \
		--with-ogg=${LOCALBASE} --with-ogg-libraries=${LOCALBASE}/lib \
		--with-ogg-includes=${LOCALBASE}/include \
		--enable-core-libedit-support \
		--enable-core-odbc-support

CONFIGURE_ENV+=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${PREFIX}/include

OPTIONS=	MODSHOUT        "Enable mod_shout (streaming audio/mp3)" on \
		MODFLITE        "Enable mod_flite (Text to Speech)" on \
		MODPOCKETSPHINX	"Enable mod_pockectsphinx (voice control)" on \
		MODCIDLOOKUP	"Enable mod_cidlookup" on \
		MODDPDIRECTORY	"Enable mod_dialplan_directory" on \
		MODDINGALING    "Enable mod_dingaling(google talk)" on \
		MODEASYROUTE	"Enable mod_easyroute(routeing tool)" on \
		MODERLANGEVENT  "Enable mod_erlang_event (Call Center Dist)" off \
		MODFAX		"Enable mod_fax" on \
		MODLCR		"Enable mod_lcr (least cost routing)" on \
		MODSOUNDTOUCH	"Enable mod_soundtouch" on \
		MODRSS		"Enable mod_rss (rss feed reader)" on \
		MODSNOM		"Enable mod_snom (snom control)" on \
		MODVMD		"Enable mod_vmd (voice mail detection)" on \
		MODSPY		"Enable mod_spy" on \
		MODAMRWB	"Enable mod_amrwb (amrwb codec)" on \
		MODSIREN	"Enable mod_siren (siren codec)" on \
		MODCELT		"Enable mod_celt (celt codec)" on \
		MODOPENZAP	"Enable mod_openzap (zaptel support)" on \
		MODMULTICAST	"Enable mod_event_multicast" on \
		MODNIBBLEBILL   "Enable mod_nibblebill(billing)" on \
		MODPORTAUDIO	"Enable mod_portaudio" on \
		MODSPDRMNKYODBC	"Enable mod_spidermonkey_odbc (req odbc)" on \
		MODPERL		"Enable mod_perl (perl support)" on \
		MODXMLCURL	"Enable mod_xml_curl" on \
		MODSAYDE	"Enable mod_say_de (German support)" on \
		MODSAYES	"Enable mod_say_se (Spanish support)" on \
		MODSAYFR	"Enable mod_say_fr (French support)" on \
		MODSAYIT	"Enable mod_say_it (Italian support)" on \
		MODSAYNL	"Enable mod_say_nl (Dutch support)" on \
		MODSAYRU	"Enable mod_say_ru (Russian support)" on \
		MODSAYZH	"Enable mod_say_zh (Chinese support)" on \
		SAMPLES		"Install Sample Config Files" on \
		SOUNDS		"Install 8k Sound Files" on \
		HDSOUNDS	"Install 16k Sound (req 8k Sounds) " off \
		UHDSOUNDS	"Install 32k Sound (req 8k 16k Sounds)" off \
		CDSOUNDS	"Install CD Quality Sound (req 8k Sounds)" off \
		PIZZADEMO	"Install Pizza Demo (req mod_pcoketsphinx)" on \
		FAXUTILS        "Install Extra Fax Utils (Req MOD FAX)" on

.include <bsd.port.pre.mk>

.if !defined(WITH_MODOPENZAP)
PLIST_SUB+=	WITH_MODOPENZAP="@comment "
.else
PLIST_SUB+=	WITH_MODOPENZAP=""
BUILD_DEPENDS+=	libpri>=1.2.0:${PORTSDIR}/misc/libpri \
		${LOCALBASE}/include/zaptel/zaptel.h:${PORTSDIR}/misc/zaptel
LIB_DEPENDS+=	pri:${PORTSDIR}/misc/libpri
RUN_DEPENDS+=	${LOCALBASE}/include/zaptel/zaptel.h:${PORTSDIR}/misc/zaptel
.endif

.if !defined(WITH_MODSPDRMNKYODBC)
PLIST_SUB+=	WITH_MODSPDRMNKYODBC="@comment "
.else
PLIST_SUB+=	WITH_MODSPDRMNKYODBC=""
LIB_DEPENDS+=	odbc:${PORTSDIR}/databases/unixODBC
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
LIB_DEPENDS+=	tiff:${PORTSDIR}/graphics/tiff
.endif

.if !defined(WITH_MODFLITE)
PLIST_SUB+=	WITH_MODFLITE="@comment "
.else
PLIST_SUB+=	WITH_MODFLITE=""
.endif

.if !defined(WITH_MODPOCKETSPHINX)
 PLIST_SUB+=	WITH_MODPOCKETSPHINX="@comment "
.else
PLIST_SUB+=	WITH_MODPOCKETSPHINX=""
.endif

.if !defined(WITH_MODCIDLOOKUP)
 PLIST_SUB+=	WITH_MODCIDLOOKUO="@comment "
.else
PLIST_SUB+=	WITH_MODCIDLOOKUP=""
.endif

.if !defined(WITH_MODDPDIRECTORY)
 PLIST_SUB+=	WITH_MODDPDIRECTORY="@comment "
.else
PLIST_SUB+=	WITH_MODDPDIRECTORY=""
.endif

.if !defined(WITH_MODEASYROUTE)
 PLIST_SUB+=	WITH_MODEASYROUTE="@comment "
.else
PLIST_SUB+=	WITH_MODEASYROUTE=""
.endif

.if !defined(WITH_MODLCR)
PLIST_SUB+=	WITH_MODLCR="@comment "
.else
PLIST_SUB+=	WITH_MODLCR=""
.endif

.if !defined(WITH_MODSOUNDTOUCH)
PLIST_SUB+=	WITH_MODSOUNDTOUCH="@comment "
.else
PLIST_SUB+=	WITH_MODSOUNDTOUCH=""
.endif

.if !defined(WITH_MODRSS)
PLIST_SUB+=	WITH_MODRSS="@comment "
.else
PLIST_SUB+=	WITH_MODRSS=""
.endif

.if !defined(WITH_MODSNOM)
PLIST_SUB+=	WITH_MODSNOM="@comment "
.else
PLIST_SUB+=	WITH_MODSNOM=""
.endif

.if !defined(WITH_MODVMD)
PLIST_SUB+=	WITH_MODVMD="@comment "
.else
PLIST_SUB+=	WITH_MODVMD=""
.endif

.if !defined(WITH_MODSPY)
PLIST_SUB+=	WITH_MODSPY="@comment "
.else
PLIST_SUB+=	WITH_MODSPY=""
.endif

.if !defined(WITH_MODAMRWB)
PLIST_SUB+=	WITH_MODAMRWB="@comment "
.else
PLIST_SUB+=	WITH_MODAMRWB=""
.endif

.if !defined(WITH_MODSIREN)
PLIST_SUB+=	WITH_MODSIREN="@comment "
.else
PLIST_SUB+=	WITH_MODSIREN=""
.endif

.if !defined(WITH_MODCELT)
PLIST_SUB+=	WITH_MODCELT="@comment "
.else
PLIST_SUB+=	WITH_MODCELT=""
.endif

.if !defined(WITH_MODMULTICAST)
PLIST_SUB+=	WITH_MODMULTICAST="@comment "
.else
PLIST_SUB+=	WITH_MODMULTICAST=""
.endif

.if !defined(WITH_MODPORTAUDIO)
PLIST_SUB+=	WITH_MODPORTAUDIO=""
.else
PLIST_SUB+=	WITH_MODPORTAUDIO=""
.endif

.if !defined(WITH_MODXMLCURL)
PLIST_SUB+=	WITH_MODXMLCURL="@comment "
.else
PLIST_SUB+=	WITH_MODXMLCURL=""
.endif

.if !defined(WITH_MODSAYDE)
PLIST_SUB+=	WITH_MODSAYDE="@comment "
.else
PLIST_SUB+=	WITH_MODSAYDE=""
.endif

.if !defined(WITH_MODSAYES)
PLIST_SUB+=	WITH_MODSAYES="@comment "
.else
PLIST_SUB+=	WITH_MODSAYES=""
.endif

.if !defined(WITH_MODSAYIT)
PLIST_SUB+=	WITH_MODSAYFR="@comment "
.else
PLIST_SUB+=	WITH_MODSAYFR=""
.endif

.if !defined(WITH_MODSAYIT)
PLIST_SUB+=	WITH_MODSAYIT="@comment "
.else
PLIST_SUB+=	WITH_MODSAYIT=""
.endif

.if !defined(WITH_MODSAYNL)
PLIST_SUB+=	WITH_MODSAYNL="@comment "
.else
PLIST_SUB+=	WITH_MODSAYNL=""
.endif

.if !defined(WITH_MODSAYRU)
PLIST_SUB+=	WITH_MODSAYRU="@comment "
.else
PLIST_SUB+=	WITH_MODSAYRU=""
.endif

.if !defined(WITH_MODSAYZH)
PLIST_SUB+=	WITH_MODSAYZH="@comment "
.else
PLIST_SUB+=	WITH_MODSAYZH=""
.endif

.if !defined(WITH_SAMPLES)
PLIST_SUB+=	WITH_SAMPLES="@comment "
.else
PLIST_SUB+=	WITH_SAMPLES=""
.endif

.if !defined(WITH_SOUNDS)
PLIST_SUB+=	WITH_SOUNDS="@comment "
.else
PLIST_SUB+=	WITH_SOUNDS=""
.endif

.if !defined(WITH_HDSOUNDS)
PLIST_SUB+=	WITH_HDSOUNDS="@comment "
.else
PLIST_SUB+=	WITH_HDSOUNDS=""
.endif

.if !defined(WITH_UHDSOUNDS)
PLIST_SUB+=	WITH_UHDSOUNDS="@comment "
.else
PLIST_SUB+=	WITH_UHDSOUNDS=""
.endif

.if !defined(WITH_CDSOUNDS)
PLIST_SUB+=	WITH_CDSOUNDS="@comment "
.else
PLIST_SUB+=	WITH_CDSOUNDS=""
.endif

.if !defined(WITH_PIZZADEMO)
PLIST_SUB+=	WITH_PIZZADEMO="@comment "
.else
PLIST_SUB+=	WITH_PIZZADEMO=""
.endif

.if !defined(WITH_FAXUTILS)
PLIST_SUB+=	WITH_FAXUTILS="@comment "
.else
PLIST_SUB+=	WITH_FAXUTILS=""
RUN_DEPENDS+=	tiff2png:${PORTSDIR}/graphics/tiff2png
.endif

.if !defined(WITH_MODNIBBLEBILL)
PLIST_SUB+=	WITH_MODNIBBLEBILL="@comment "
.else
PLIST_SUB+=	WITH_MODNIBBLEBILL=""
.endif

.if !defined(WITH_MODDINGALING)
 PLIST_SUB+=	WITH_MODDINGALING="@comment "
.else
PLIST_SUB+=	WITH_MODDINGALING=""
.endif

.if !defined(WITH_MODERLANGEVENT)
PLIST_SUB+=	WITH_MODERLANGEVENT="@comment "
.else
PLIST_SUB+=	WITH_MODERLANGEVENT=""
.endif

pre-configure:
	@cd ${WRKSRC} && ./bootstrap.sh
	@${CP} ${WRKSRC}/build/modules.conf.in ${WRKSRC}/modules.conf
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${LOCALBASE}/${PORTNAME}/libdata/pkgconfig|g' ${WRKSRC}/libs/*/Makefile.am
	@${REINPLACE_CMD} -e 's|$(DESTDIR)$$(libdir)/pkgconfig|${LOCALBASE}/${PORTNAME}/libdata/pkgconfig|g' ${WRKSRC}/libs/*/Makefile.in

post-configure:
.if defined(WITH_MODSHOUT)
	@${REINPLACE_CMD} -e 's|#formats/mod_shout|formats/mod_shout|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODFLITE)
	@${REINPLACE_CMD} -e 's|#asr_tts/mod_flite|asr_tts/mod_flite|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODPOCKETSPHINX)
	@${REINPLACE_CMD} -e 's|#asr_tts/mod_pocketsphinx|asr_tts/mod_pocketsphinx|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODCIDLOOKUP)
	@${REINPLACE_CMD} -e 's|#applications/mod_cidlookup|applications/mod_cidlookup|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODDPDIRECTORY)
	@${REINPLACE_CMD} -e 's|#dialplans/mod_dialplan_directory|dialplans/mod_dialplan_directory|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODEASYROUTE)
	@${REINPLACE_CMD} -e 's|#applications/mod_easyroute|applications/mod_easyroute|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODFAX)
	@${REINPLACE_CMD} -e 's|#applications/mod_fax|applications/mod_fax|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODLCR)
	@${REINPLACE_CMD} -e 's|#applications/mod_lcr|applications/mod_lcr|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODSOUNDTOUCH)
	@${REINPLACE_CMD} -e 's|#applications/mod_soundtouch|applications/mod_soundtouch|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODRSS)
	@${REINPLACE_CMD} -e 's|#applications/mod_rss|applications/mod_rss|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODSNOM)
	@${REINPLACE_CMD} -e 's|#applications/mod_snom|applications/mod_snom|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODVMD)
	@${REINPLACE_CMD} -e 's|#applications/mod_vmd|applications/mod_vmd|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODSPY)
	@${REINPLACE_CMD} -e 's|#applications/mod_spy|applications/mod_spy|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODAMRWB)
	@${REINPLACE_CMD} -e 's|#codecs/mod_amrwb|codecs/mod_amrwb|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODSIREN)
	@${REINPLACE_CMD} -e 's|#codecs/mod_siren|codecs/mod_siren|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODCELT)
	@${REINPLACE_CMD} -e 's|#codecs/mod_celt|codecs/mod_celt|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODOPENZAP)
	@${REINPLACE_CMD} -e 's|#../../libs/openzap/mod_openzap|../../libs/openzap/mod_openzap|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODMULTICAST)
	@${REINPLACE_CMD} -e 's|#event_handlers/mod_event_multicast|event_handlers/mod_event_multicast|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODSPDRMNKYODBC)
	@${REINPLACE_CMD} -e 's|#languages/mod_spidermonkey_odbc|languages/mod_spidermonkey_odbc|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODPORTAUDIO)
	@${REINPLACE_CMD} -e 's|#endpoints/mod_portaudio|endpoints/mod_portaudio|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODPERL)
	@${REINPLACE_CMD} -e 's|#languages/mod_perl|languages/mod_perl|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODXMLCURL)
	@${REINPLACE_CMD} -e 's|#xml_int/mod_xml_curl|xml_int/mod_xml_curl|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODSAYDE)
	@${REINPLACE_CMD} -e 's|#say/mod_say_de|say/mod_say_de|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODSAYES)
	@${REINPLACE_CMD} -e 's|#say/mod_say_es|say/mod_say_es|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODSAYFR)
	@${REINPLACE_CMD} -e 's|#say/mod_say_fr|say/mod_say_fr|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODSAYIT)
	@${REINPLACE_CMD} -e 's|#say/mod_say_it|say/mod_say_it|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODSAYNL)
	@${REINPLACE_CMD} -e 's|#say/mod_say_nl|say/mod_say_nl|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODSAYRU)
	@${REINPLACE_CMD} -e 's|#say/mod_say_ru|say/mod_say_ru|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODSAYZH)
	@${REINPLACE_CMD} -e 's|#say/mod_say_zh|say/mod_say_zh|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODNIBBLEBILL)
	@${REINPLACE_CMD} -e 's|#applications/mod_nibblebill|applications/mod_nibblebill|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODDINGALING)
	${REINPLACE_CMD} -e 's|#endpoints/mod_dingaling|endpoints/mod_dingaling|g' ${WRKSRC}/modules.conf
.endif

.if defined(WITH_MODERLANGEVENT)
	@${REINPLACE_CMD} -e 's|#event_handlers/mod_erlang_event|event_handlers/mod_erlang_event|g' ${WRKSRC}/modules.conf
.endif

post-patch:
	@${GREP} -Rl '/bin/bash' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|g'

post-install:
	@${MKDIR} ${PREFIX}/${PORTNAME}/sounds

.if defined(WITH_SOUNDS)
	@${TAR} -xzvf ${DISTDIR}/freeswitch-sounds-en-us-callie-8000-1.0.11.tar.gz -C ${PREFIX}/${PORTNAME}/sounds/
	@${TAR} -xzvf ${DISTDIR}/freeswitch-sounds-music-8000-1.0.8.tar.gz -C ${PREFIX}/${PORTNAME}/sounds/
.endif

.if defined(WITH_HDSOUNDS)
	@${TAR} -xzvf ${DISTDIR}/freeswitch-sounds-en-us-callie-16000-1.0.11.tar.gz -C ${PREFIX}/${PORTNAME}/sounds/
	@${TAR} -xzvf ${DISTDIR}/freeswitch-sounds-music-16000-1.0.8.tar.gz -C ${PREFIX}/${PORTNAME}/sounds/
.endif

.if defined(WITH_UHDSOUNDS)
	@${TAR} -xzvf ${DISTDIR}/freeswitch-sounds-en-us-callie-32000-1.0.11.tar.gz -C ${PREFIX}/${PORTNAME}/sounds/
	@${TAR} -xzvf ${DISTDIR}/freeswitch-sounds-music-32000-1.0.8.tar.gz -C ${PREFIX}/${PORTNAME}/sounds/
.endif

.if defined(WITH_CDSOUNDS)
	@${TAR} -xzvf ${DISTDIR}/freeswitch-sounds-en-us-callie-48000-1.0.11.tar.gz -C ${PREFIX}/${PORTNAME}/sounds/
	@${TAR} -xzvf ${DISTDIR}/freeswitch-sounds-music-48000-1.0.8.tar.gz -C ${PREFIX}/${PORTNAME}/sounds/
.endif

.if defined(WITH_SAMPLES)
	@cd ${WRKSRC} && ${GMAKE} samples
.endif

.if defined(WITH_PIZZADEMO)
	@${REINPLACE_CMD} -e 's|js_modules/SpeechTools.jm|javascript/js_modules/SpeechTools.jm|g' ${WRKSRC}/scripts/javascript/ps_pizza.js
	@${REINPLACE_CMD} -e 's|/root/pizza|/${LOCALBASE}/freeswitch/sounds/en/us/pizza/|g' ${WRKSRC}/scripts/javascript/ps_pizza.js
	@cd ${WRKSRC}/scripts/javascript/ && ${RM} -rf aadir api.js dtmftest.js pizza.js ps_pizza.js.bak .svn js_modules/.svn
	@${CP} -r ${WRKSRC}/scripts/javascript ${LOCALBASE}/${PORTNAME}/scripts/
	@${TAR} -xvzf ${DISTDIR}/pizza_gram.tar.gz -C ${LOCALBASE}/${PORTNAME}/grammar
	@${TAR} -xzvf ${DISTDIR}/pizza_sounds.tar.gz -C ${LOCALBASE}/${PORTNAME}/sounds/en/us
.endif

	@${CAT} ${PKGMESSAGE}

.if ${OSVERSION} < 700000
IGNORE=		it's to unsupported before FreeBSD 7.X
.endif

.include <bsd.port.post.mk>
