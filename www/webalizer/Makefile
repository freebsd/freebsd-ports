PORTNAME=	webalizer
PORTVERSION=	2.23.8
PORTREVISION=	18
CATEGORIES+=	www
MASTER_SITES=	ftp://ftp.dinoex.de/pub/webalizer/ \
		https://ftp.dinoex.de/pub/webalizer/ \
		https://ftp.dinoex.org/pub/webalizer/
PKGNAMESUFFIX?=	${WEBALIZER_SUFFIX}${PKGNAMESUFFIX2}
DISTNAME=	${PORTNAME}-2.23-08-src
DISTFILES=	${DISTNAME}.tgz

MAINTAINER?=	dinoex@FreeBSD.org
COMMENT=	Web server log file analysis program
WWW=		https://webalizer.net/

LICENSE=	GPLv2

LIB_DEPENDS+=	libpng.so:graphics/png

USES=		iconv:build
GNU_CONFIGURE=	yes
DOCSDIR?=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR?=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
GD_PORT?=	graphics/gd

CONFLICTS=	geolizer-2*

.if defined(BATCH)
# no cosmetique spaces allowed
WEBALIZER_LANG?=english
.endif

OPTIONS_DEFINE=	GEOIP GEODB WEBALIZER_CONV \
		FULL_CGI_REFS CLICKABLE_REFERER \
		IP_AS_HOSTNAME LARGE_URL \
		DOCS EXAMPLES
OPTIONS_DEFAULT?=	BDB1
OPTIONS_SINGLE=		DB
OPTIONS_SINGLE_DB=	BDB1 BDB
NO_OPTIONS_SORT=yes
OPTIONS_SUB=yes
GEODB_DESC=Enable Webalizers IP-Database support
WEBALIZER_CONV_DESC=Japanese character code convert to EUC-JP
FULL_CGI_REFS_DESC=Show full cgi parameters in referers
CLICKABLE_REFERER_DESC=Make referers clickable
IP_AS_HOSTNAME_DESC=Show IP as hostname when IP does not resolve
LARGE_URL_DESC=Enable URLs longer 512 bytes

GEODB_IMPLIES=		BDB
GEODB_PREVENTS=		BDB1
GEODB_RUN_DEPENDS=	${LOCALBASE}/share/geolizer/GeoDB.dat:net/webalizer-geodb
GEOIP_CONFIGURE_ON=	--enable-geoip \
			--with-geoip-lib=${LOCALBASE}/lib \
			--with-geoip-inc=${LOCALBASE}/include
GEOIP_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb
GEOIP_USES=		compiler:c++11-lang
BDB1_CFLAGS=		-DUSE_DB185
BDB_USES=		bdb
BDB_LDFLAGS=		-L${BDB_LIB_DIR}
BDB_CFLAGS=		-I${BDB_INCLUDE_DIR}
WEBALIZER_CONV_USES=		iconv
WEBALIZER_CONV_CONFIGURE_ON=	--enable-mininls
WEBALIZER_CONV_CPPFLAGS=	-I${LOCALBASE}/include
WEBALIZER_CONV_LIBS=		-L${LOCALBASE}/lib ${ICONV_LIB}
FULL_CGI_REFS_CFLAGS=		-DUSE_FULL_CGI_REFS
CLICKABLE_REFERER_CFLAGS=	-DUSE_CLICKABLE_REFERER
IP_AS_HOSTNAME_CFLAGS=		-DUSE_IP_AS_HOSTNAME

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGEODB} || ${PORT_OPTIONS:MGEOIP} || make(makesum) || defined(FETCH_ALL)
DISTFILES+=	webalizer-flags.tgz
.endif

# slave ports override with languages specific gd
.if empty(LIB_DEPENDS:Mlibgd*)
LIB_DEPENDS+=	libgd.so:${GD_PORT}
.endif

.if ${PORT_OPTIONS:MGEOIP}
CONFLICTS+=	${PKGNAMEPREFIX}webalizer-2*
.else
CONFLICTS+=	${PKGNAMEPREFIX}webalizer-geoip-2*
.endif

.if ${PORT_OPTIONS:MGEODB} || ${PORT_OPTIONS:MGEOIP}
PLIST_SUB+=	WITH_ICONS=""
.else
PLIST_SUB+=	WITH_ICONS="@comment "
.endif

CONFIGURE_ARGS+=	--enable-dns \
			--enable-bz2 \
			--with-geodb=${PREFIX}/share/geolizer \
			--sysconfdir=${PREFIX}/etc \
			--with-gdlib=${LOCALBASE}/lib \
			--with-gd=${LOCALBASE}/include

LDFLAGS+=	-L${PREFIX}/lib
CFLAGS+=	-Wall
LMAN1=		${PKGNAMEPREFIX}webalizer.1 ${PKGNAMEPREFIX}wcmgr.1
DOC1=		CHANGES Copyright INSTALL \
		README README.FIRST DNS.README country-codes.txt
EXAMPLES1=	msfree.png sample.conf webalizer.png
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src$//}
PLIST_SUB+=	PKGNAMEPREFIX=${PKGNAMEPREFIX}
CHARSETS=	ISO-8859-1 ISO-8859-2 ISO-8859-5 ISO-8859-7 ISO-8859-13 \
		ISO-8859-15 BIG5 EUC-CN EUC-JP EUC-KR TIS620 WINDOWS-1250
CHARSET_ISO-8859-1=	catalan danish finnish french galician galician \
			german icelandic norwegian portuguese \
			portuguese_brazil spanish swedish
CHARSET_ISO-8859-2=	czech hungarian polish slovak
CHARSET_ISO-8859-7=	greek
CHARSET_ISO-8859-5=	russian ukrainian
CHARSET_ISO-8859-13=	latvian lithuanian 
CHARSET_ISO-8859-15=	estonian
CHARSET_BIG5=	chinese
CHARSET_EUC-CN=	simplified_chinese
CHARSET_EUC-JP=	japanese
CHARSET_EUC-KR=	korean
CHARSET_TIS620=	thai
CHARSET_WINDOWS-1250=	slovene
SUPP_LANG=	albanian arabic catalan catalan-utf8 chinese chinese-utf8 \
		croatian czech czech-utf8 danish danish-utf8 dutch english \
		estonian estonian-utf8 finnish finnish-utf8 \
		french french-utf8 galician galician-utf8 german german-utf8 \
		greek greek-utf8 hungarian hungarian-utf8 \
		icelandic icelandic-uf8 indonesian italian \
		japanese japanese-utf8 korean korean-utf8 \
		latvian latvian-utf8 lithuanian lithuanian-utf8 malay \
		norwegian norwegian-utf8 polish polish-utf8 \
		portuguese portuguese-utf8 \
		portuguese_brazil portuguese_brazil-utf8 \
		romanian romanian-iso-8859-2 russian russian-utf8 \
		serbian simplified_chinese simplified_chinese-utf8 \
		slovak slovak-utf8 slovene slovene-utf8 spanish spanish-utf8 \
		swedish swedish-utf8 thai thai-utf8 turkish \
		ukrainian ukrainian-utf8
.if defined(WEBALIZER_LANG)
CONFIGURE_ARGS+=	--with-language=${WEBALIZER_LANG}
.endif

.if ${PORT_OPTIONS:MWEBALIZER_CONV}
.if ${WEBALIZER_LANG} != japanese
BROKEN=		no conversion from UTF-8 needed
.endif
#	The patch file is written by URASHIMA Akira
#	see http://tyche.pu-toyama.ac.jp/~a-urasim/webalizer/
EXTRA_PATCHES+=		${FILESDIR}/webalizer-a-urasim_2.patch
.endif

pre-configure:
	${REINPLACE_CMD} -e "s|/etc|${PREFIX}/etc|" \
		${WRKSRC}/webalizer.1
	${REINPLACE_CMD} \
		-e "s|webalizer.conf|${PKGNAMEPREFIX}webalizer.conf|" \
		${WRKSRC}/webalizer.c
.if ${PORT_OPTIONS:MLARGE_URL}
	${REINPLACE_CMD} \
		-e "s|MAXURLH  512 |MAXURLH  2048|" \
		${WRKSRC}/webalizer.h
.endif
.if ${PORT_OPTIONS:MBDB}
	${REINPLACE_CMD} -e "s|-ldb|-l${BDB_LIB_NAME}|" \
		-e "s|GeoIP[.]h|maxminddb.h|" \
		-e "s|-lGeoIP|-lmaxminddb|" \
		${WRKSRC}/configure
.else
	${REINPLACE_CMD} -e "s|-ldb||" \
		-e "s|GeoIP[.]h|maxminddb.h|" \
		-e "s|-lGeoIP|-lmaxminddb|" \
		${WRKSRC}/configure
.endif
.for charset in ${CHARSETS}
.for i in ${CHARSET_${charset}}
	${ICONV_CMD} -f ${charset} -t UTF-8 ${WRKSRC}/lang/webalizer_lang.${i} \
		> ${WRKSRC}/lang/webalizer_lang.${i}-utf8
.endfor
.endfor
.if defined(WEBALIZER_LANG)
.if ${WEBALIZER_LANG} == japanese
	${REINPLACE_CMD} -e 's|charset=UTF-8|charset=x-euc-jp|' \
		${WRKSRC}/sample.conf
.endif
.endif

.if !defined(WEBALIZER_LANG)
	@${ECHO_MSG} "You can customize the language by typing"
	@${ECHO_MSG} "       make WEBALIZER_LANG=<lang>"
	@${ECHO_MSG} "where <lang> is one of:"
	@${ECHO_MSG} ${SUPP_LANG}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/webalizer \
		${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}webalizer
	${INSTALL_PROGRAM} ${WRKSRC}/wcmgr \
		${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}wcmgr
	${LN} -sf ${PKGNAMEPREFIX}webalizer \
		${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}webazolver
	${INSTALL_DATA} ${WRKSRC}/sample.conf \
		${STAGEDIR}${PREFIX}/etc/${PKGNAMEPREFIX}webalizer.conf-dist ;
.for i in ${LMAN1}
	${INSTALL_MAN} ${WRKSRC}/${i:S/^${PKGNAMEPREFIX}//} ${STAGEDIR}${PREFIX}/share/man/man1/${i}
.endfor
.if ${PORT_OPTIONS:MGEODB} || ${PORT_OPTIONS:MGEOIP}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/geolizer
	${INSTALL_DATA} ${WRKDIR}/flags/* ${STAGEDIR}${PREFIX}/share/geolizer/
.endif

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC1:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLES1:S,^,${WRKSRC}/,} ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
