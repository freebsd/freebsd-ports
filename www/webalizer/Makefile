PORTNAME=	webalizer
PORTVERSION=	2.23.8
PORTREVISION=	14
CATEGORIES+=	www
MASTER_SITES=	ftp://ftp.mrunix.net/pub/webalizer/:main \
		ftp://ftp.dinoex.de/pub/FreeBSD/distfiles/:main \
		http://flags.blogpotato.de/zip/:flags
PKGNAMESUFFIX?=	${WEBALIZER_SUFFIX}${PKGNAMESUFFIX2}
DISTNAME=	${PORTNAME}-2.23-08-src
DISTFILES=	${DISTNAME}.tgz:main

MAINTAINER?=	dinoex@FreeBSD.org
COMMENT=	Web server log file analysis program

LICENSE=	GPLv2

LIB_DEPENDS+=	libpng.so:graphics/png

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
WEBALIZER_CONV_DESC=Japanese character code convert patch
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
DISTFILES+=	webalizer-flags.tgz:main
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
SUPP_LANG=	albanian arabic catalan chinese croatian czech danish dutch \
		english estonian finnish french galician german greek \
		hungarian icelandic indonesian italian japanese korean \
		latvian lithuanian malay norwegian polish portuguese \
		portuguese_brazil romanian romanian-iso-8859-2 russian \
		serbian simplified_chinese slovak slovene spanish swedish \
		thai turkish ukrainian

.if defined(WEBALIZER_LANG)
CONFIGURE_ARGS+=	--with-language=${WEBALIZER_LANG}
#	The patch file is written by URASHIMA Akira
#	see http://tyche.pu-toyama.ac.jp/~a-urasim/webalizer/
.if ${WEBALIZER_LANG} == japanese
EXTRA_PATCHES+=		${FILESDIR}/ja-webalizer.conf-dist.patch
.endif
.endif

.if ${PORT_OPTIONS:MWEBALIZER_CONV}
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
	${INSTALL_MAN} ${WRKSRC}/${i:S/^${PKGNAMEPREFIX}//} ${STAGEDIR}${PREFIX}/man/man1/${i}
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
