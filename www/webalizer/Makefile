# New ports collection makefile for:	webalizer
# Date created:		02.Jun 1998
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	webalizer
PORTVERSION=	2.21.2
PORTREVISION=	3
CATEGORIES+=	www
MASTER_SITES=	ftp://ftp.mrunix.net/pub/webalizer/:main \
MASTER_SITES=	ftp://ftp.mrunix.net/pub/webalizer/geodb/:geodb \
		ftp://ftp.dinoex.de/pub/FreeBSD/distfiles/:main \
		http://flags.blogpotato.de/zip/:flags
PKGNAMESUFFIX?=	${WEBALIZER_SUFFIX}${PKGNAMESUFFIX2}
DISTNAME=	${PORTNAME}-2.21-02-src
DISTFILES=	${DISTNAME}.tgz:main

MAINTAINER?=	dinoex@FreeBSD.org
COMMENT=	A web server log file analysis program

GNU_CONFIGURE=	yes
DOCSDIR?=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR?=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
GD_PORT?=	graphics/gd

CONFLICTS=	geolizer-2*

.if defined(BATCH)
# no cosmetique spaces allowed
WEBALIZER_LANG?=english
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_GEODB) || defined(WITH_GEOIP)|| make(makesum) || defined(FETCH_ALL)
DISTFILES+=	webalizer-flags.tgz:main
.endif
.if defined(WITH_GEODB) || make(makesum) || defined(FETCH_ALL)
DISTFILES+=	webalizer-geodb-20100601.tgz:geodb
.endif

.if !defined(LIB_DEPENDS)
LIB_DEPENDS=	gd.4:${PORTSDIR}/${GD_PORT}
.endif
.if defined(WITH_GEOIP)
LIB_DEPENDS+=	GeoIP.5:${PORTSDIR}/net/GeoIP
.endif

.if defined(WITH_GEODB)
PLIST_SUB+=	WITH_GEODB=""
.else
PLIST_SUB+=	WITH_GEODB="@comment "
.endif

.if defined(WITH_GEOIP)
WEBALIZER_SUFFIX=	-geoip
CONFLICTS+=	${PKGNAMEPREFIX}webalizer-2*
CONFIGURE_ARGS+=	--enable-geoip \
			--with-geoip-lib=${LOCALBASE}/lib \
			--with-geoip-inc=${LOCALBASE}/include
.else
CONFLICTS+=	${PKGNAMEPREFIX}webalizer-geoip-2*
.endif

.if defined(WITH_GEODB) || defined(WITH_GEOIP)
PLIST_SUB+=	WITH_GEOIP=""
.else
PLIST_SUB+=	WITH_GEOIP="@comment "
.endif

.if defined(WITH_BDB_VER) || defined(WITH_BDB)
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

CONFIGURE_ENV+=	LDFLAGS="-L${PREFIX}/lib"
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
.if ${WEBALIZER_LANG} == ukrainian
EXTRA_PATCHES+=		${FILESDIR}/uk-lang.h
EXTRA_PATCHES+=		${FILESDIR}/uk-output.c
.endif
.endif

.if defined(WITH_WEBALIZER_CONV)
USE_ICONV=yes
# 	The patch file is written by URASHIMA Akira
#	see http://tyche.pu-toyama.ac.jp/~a-urasim/webalizer/
EXTRA_PATCHES+=		${FILESDIR}/webalizer-a-urasim_2.patch
CONFIGURE_ARGS+=	--enable-mininls
CONFIGURE_ENV+=		LIBS="-L${LOCALBASE}/lib -liconv"
CFLAGS+=		-I${LOCALBASE}/include
.endif

.if !defined(WITHOUT_WEBALIZER_FULL_CGI_REFS)
CFLAGS+=	-DUSE_FULL_CGI_REFS
.endif

.if defined(WITH_WEBALIZER_CLICKABLE_REFERER)
CFLAGS+=	-DUSE_CLICKABLE_REFERER
.endif

pre-configure:
	${REINPLACE_CMD} -e "s|/etc|${PREFIX}/etc|" \
		${WRKSRC}/webalizer.1
	${REINPLACE_CMD} \
		-e "s|webalizer.conf|${PKGNAMEPREFIX}webalizer.conf|" \
		${WRKSRC}/webalizer.c
.if defined(WITH_MAXURLH)
	${REINPLACE_CMD} \
		-e "s|MAXURLH  512 |MAXURLH  2048|" \
		${WRKSRC}/webalizer.h
.endif
.if defined(WITH_BDB_VER) || defined(WITH_BDB)
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
.if defined(WITH_GEODB) || defined(WITH_GEOIP)
	${MKDIR} ${PREFIX}/share/geolizer
	@${INSTALL_DATA} ${WRKDIR}/flags/* ${PREFIX}/share/geolizer/
.endif
.if defined(WITH_GEODB)
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

.include <bsd.port.post.mk>
