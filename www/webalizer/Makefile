# $FreeBSD$

PORTNAME=	webalizer
PORTVERSION=	2.23.8
PORTREVISION=	5
CATEGORIES+=	www
MASTER_SITES=	ftp://ftp.mrunix.net/pub/webalizer/:main \
		ftp://ftp.mrunix.net/pub/webalizer/geodb/:geodb \
		ftp://ftp.dinoex.de/pub/FreeBSD/distfiles/:main \
		http://flags.blogpotato.de/zip/:flags
PKGNAMESUFFIX?=	${WEBALIZER_SUFFIX}${PKGNAMESUFFIX2}
DISTNAME=	${PORTNAME}-2.23-08-src
DISTFILES=	${DISTNAME}.tgz:main

MAINTAINER?=	dinoex@FreeBSD.org
COMMENT=	Web server log file analysis program

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
DOCSDIR?=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR?=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
GD_PORT?=	graphics/gd

CONFLICTS=	geolizer-2*

.if defined(BATCH)
# no cosmetique spaces allowed
WEBALIZER_LANG?=english
.endif

OPTIONS_DEFINE=	GEOIP GEODB BDB1 BDB WEBALIZER_CONV \
		FULL_CGI_REFS CLICKABLE_REFERER LARGE_URL \
		DOCS EXAMPLES
OPTIONS_DEFAULT?=
NO_OPTIONS_SORT=yes
GEODB_DESC=Enable Webalizers IP-Database support
WEBALIZER_CONV_DESC=Japanese character code convert patch
FULL_CGI_REFS_DESC=Show full cgi parameters in referers
CLICKABLE_REFERER_DESC=Make referers clickable
LARGE_URL_DESC=Enable URLs longer 512 bytes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGEODB} || ${PORT_OPTIONS:MGEOIP} || make(makesum) || defined(FETCH_ALL)
DISTFILES+=	webalizer-flags.tgz:main
.endif
.if ${PORT_OPTIONS:MGEODB} || make(makesum) || defined(FETCH_ALL)
DISTFILES+=	webalizer-geodb-20150901.tgz:geodb
.endif

# slave ports override with languages specific gd
.if !defined(LIB_DEPENDS)
LIB_DEPENDS+=	libgd.so:${GD_PORT}
.endif

.if ${PORT_OPTIONS:MGEOIP}
LIB_DEPENDS+=	libGeoIP.so:net/GeoIP
.endif

.if ${PORT_OPTIONS:MGEODB}
.if empty(PORT_OPTIONS:MBDB1)
USES+=		bdb
.endif
PLIST_SUB+=	WITH_GEODB=""
.else
PLIST_SUB+=	WITH_GEODB="@comment "
.endif

.if ${PORT_OPTIONS:MGEOIP}
CONFLICTS+=	${PKGNAMEPREFIX}webalizer-2*
CONFIGURE_ARGS+=	--enable-geoip \
			--with-geoip-lib=${LOCALBASE}/lib \
			--with-geoip-inc=${LOCALBASE}/include
.else
CONFLICTS+=	${PKGNAMEPREFIX}webalizer-geoip-2*
.endif

.if ${PORT_OPTIONS:MGEODB} || ${PORT_OPTIONS:MGEOIP}
PLIST_SUB+=	WITH_GEOIP=""
.else
PLIST_SUB+=	WITH_GEOIP="@comment "
.endif

.if defined(WITH_BDB_VER) || ${PORT_OPTIONS:MBDB}
USES+=		bdb
LDFLAGS+=	-L${BDB_LIB_DIR}
CFLAGS+=	-I${BDB_INCLUDE_DIR}
.else
CFLAGS+=	-DUSE_DB185
.endif

CONFIGURE_ARGS+=	--enable-dns \
			--enable-bz2 \
			--with-geodb=${PREFIX}/share/webalizer \
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
USES+=			iconv
# 	The patch file is written by URASHIMA Akira
#	see http://tyche.pu-toyama.ac.jp/~a-urasim/webalizer/
EXTRA_PATCHES+=		${FILESDIR}/webalizer-a-urasim_2.patch
CONFIGURE_ARGS+=	--enable-mininls
CPPFLAGS+=		-I${LOCALBASE}/include
LIBS+=			-L${LOCALBASE}/lib ${ICONV_LIB}
.endif

.if ${PORT_OPTIONS:MFULL_CGI_REFS}
CFLAGS+=	-DUSE_FULL_CGI_REFS
.endif

.if ${PORT_OPTIONS:MCLICKABLE_REFERER}
CFLAGS+=	-DUSE_CLICKABLE_REFERER
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
.if defined(WITH_BDB_VER) || ${PORT_OPTIONS:MBDB}
	${REINPLACE_CMD} -e "s|-ldb|-l${BDB_LIB_NAME}|" \
		${WRKSRC}/configure
.else
	${REINPLACE_CMD} -e "s|-ldb||" \
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
.if ${PORT_OPTIONS:MGEODB}
	${INSTALL_DATA} ${WRKDIR}/GeoDB.dat ${STAGEDIR}${PREFIX}/share/geolizer/
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC1:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLES1:S,^,${WRKSRC}/,} ${STAGEDIR}${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>
