# $FreeBSD$

PORTNAME=	webalizer
PORTVERSION=	2.23.5
PORTREVISION=	4
CATEGORIES+=	www
MASTER_SITES=	ftp://ftp.mrunix.net/pub/webalizer/:main \
MASTER_SITES=	ftp://ftp.mrunix.net/pub/webalizer/geodb/:geodb \
		ftp://ftp.dinoex.de/pub/FreeBSD/distfiles/:main \
		http://flags.blogpotato.de/zip/:flags
PKGNAMESUFFIX?=	${WEBALIZER_SUFFIX}${PKGNAMESUFFIX2}
DISTNAME=	${PORTNAME}-2.23-05-src
DISTFILES=	${DISTNAME}.tgz:main

MAINTAINER?=	dinoex@FreeBSD.org
COMMENT=	A web server log file analysis program

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
		FULL_CGI_REFS CLICKABLE_REFERER LARGE_URL
OPTIONS_DEFAULT=
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
DISTFILES+=	webalizer-geodb-20121201.tgz:geodb
.endif

# slave ports override with languages specific gd
.if !defined(LIB_DEPENDS)
LIB_DEPENDS=	gd:${PORTSDIR}/${GD_PORT}
.endif

.if ${PORT_OPTIONS:MGEOIP}
LIB_DEPENDS+=	GeoIP:${PORTSDIR}/net/GeoIP
.endif

.if ${PORT_OPTIONS:MGEODB}
.if empty(PORT_OPTIONS:MBDB1)
WITH_BDB=	yes
.endif
PLIST_SUB+=	WITH_GEODB=""
.else
PLIST_SUB+=	WITH_GEODB="@comment "
.endif

.if ${PORT_OPTIONS:MGEOIP}
WEBALIZER_SUFFIX=	-geoip
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
USE_BDB=	yes
INVALID_BDB_VER=	2 3 40
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
MAN1=		${PKGNAMEPREFIX}webalizer.1 ${PKGNAMEPREFIX}wcmgr.1
DOC1=		CHANGES Copyright INSTALL \
		README README.FIRST DNS.README country-codes.txt
DOC2=		INSTALL GeoIP.README
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
USE_ICONV=yes
# 	The patch file is written by URASHIMA Akira
#	see http://tyche.pu-toyama.ac.jp/~a-urasim/webalizer/
EXTRA_PATCHES+=		${FILESDIR}/webalizer-a-urasim_2.patch
CONFIGURE_ARGS+=	--enable-mininls
CONFIGURE_ENV+=		LIBS="-L${LOCALBASE}/lib -liconv"
CFLAGS+=		-I${LOCALBASE}/include
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
		${PREFIX}/bin/${PKGNAMEPREFIX}webalizer
	${INSTALL_PROGRAM} ${WRKSRC}/wcmgr \
		${PREFIX}/bin/${PKGNAMEPREFIX}wcmgr
	${LN} -sf ${PKGNAMEPREFIX}webalizer \
		${PREFIX}/bin/${PKGNAMEPREFIX}webazolver
	${INSTALL_DATA} ${WRKSRC}/sample.conf \
		${PREFIX}/etc/${PKGNAMEPREFIX}webalizer.conf-dist ;

post-install:
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${i:S/^${PKGNAMEPREFIX}//} ${PREFIX}/man/man1/${i}
.endfor
.if ${PORT_OPTIONS:MGEODB} || ${PORT_OPTIONS:MGEOIP} 
	${MKDIR} ${PREFIX}/share/geolizer
	@${INSTALL_DATA} ${WRKDIR}/flags/* ${PREFIX}/share/geolizer/
.endif
.if ${PORT_OPTIONS:MGEODB}
	@${INSTALL_DATA} ${WRKDIR}/GeoDB.dat ${PREFIX}/share/geolizer/
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOC1}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/${i}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
.for i in msfree.png sample.conf webalizer.png
	@${INSTALL_DATA} ${WRKSRC}/${i} ${EXAMPLESDIR}/${i}
.endfor
.endif

.include <bsd.port.mk>
