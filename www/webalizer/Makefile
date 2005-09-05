# New ports collection makefile for:	webalizer
# Date created:		02.Jun 1998
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	webalizer
PORTVERSION=	2.1.10
PORTREVISION=	5
CATEGORIES+=	www
MASTER_SITES=	ftp://ftp.mrunix.net/pub/webalizer/:main \
		ftp://ftp.dinoex.de/pub/FreeBSD/distfiles/:main \
		http://sysd.org/proj/:geo
PKGNAMESUFFIX?=	${WEBALIZER_SUFFIX}${PKGNAMESUFFIX2}
DISTNAME=	${PORTNAME}-2.01-10-src
DISTFILES=	${DISTNAME}.tar.bz2:main

MAINTAINER?=	dinoex@FreeBSD.org
COMMENT=	A web server log file analysis program

.if !defined(LIB_DEPENDS)
LIB_DEPENDS=	gd.4:${PORTSDIR}/${GD_PORT}
.endif
.if defined(WITH_GEOIP)
LIB_DEPENDS+=	GeoIP.4:${PORTSDIR}/net/GeoIP
.endif

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
DOCSDIR?=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR?=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
GD_PORT?=	graphics/gd

CONFLICTS=	geolizer-2*

.if defined(WITH_GEOIP) || make(makesum) || defined(FETCH_ALL)
DISTFILES+=	geolizer_2.01-10-patch.20050520.tar.bz2:geo
.endif

.if defined(WITH_GEOIP)
WEBALIZER_SUFFIX=	-geoip
CONFLICTS+=	${PKGNAMEPREFIX}webalizer-2*
EXTRA_PATCHES+=	${WRKDIR}/geolizer_2.01-10-patch/geolizer.patch
EXTRA_PATCHES+=	${FILESDIR}/output.geo.patch
EXTRA_PATCHES+=	${FILESDIR}/linklist.geo.patch
PATCH_STRIP=	-p1
CONFIGURE_ARGS+=	--enable-geoip \
			--with-geoip-lib=${LOCALBASE}/lib \
			--with-geoip-inc=${LOCALBASE}/include
PLIST_SUB+=	WITH_GEOIP=""
.else
CONFLICTS+=	${PKGNAMEPREFIX}webalizer-geoip-2*
EXTRA_PATCHES+=	${FILESDIR}/output.patch
EXTRA_PATCHES+=	${FILESDIR}/linklist.patch
PLIST_SUB+=	WITH_GEOIP="@comment "
.endif

.if defined(BATCH)
# no cosmetique spaces allowed
WEBALIZER_LANG?=english
.endif

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--enable-dns \
			--with-etcdir=${PREFIX}/etc \
			--with-gdlib=${LOCALBASE}/lib \
			--with-gd=${LOCALBASE}/include

CONFIGURE_ENV+=	LDFLAGS="-L${PREFIX}/lib"
CFLAGS+=	-DLINKLIST_MAX_STRING=256
MAN1=		${PKGNAMEPREFIX}webalizer.1
DOC1=		CHANGES Copyright INSTALL \
		README README.FIRST DNS.README country-codes.txt
DOC2=		INSTALL GeoIP.README
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src$//}
PLIST_SUB+=	PKGNAMEPREFIX=${PKGNAMEPREFIX}
SUPP_LANG=	catalan chinese croatian czech danish dutch english \
		estonian finnish french galician german greek hungarian \
		icelandic indonesian italian japanese korean latvian \
		malay norwegian polish portuguese portuguese_brazil \
		romanian romanian-iso-8859-2 russian serbian \
		simplified_chinese slovak slovene spanish swedish \
		turkish ukrainian

.if defined(WEBALIZER_LANG)
CONFIGURE_ARGS+=	--with-language=${WEBALIZER_LANG}
#	The patch file is written by URASHIMA Akira
#	see http://tyche.pu-toyama.ac.jp/~a-urasim/webalizer/
.if ${WEBALIZER_LANG} == japanese
EXTRA_PATCHES+=		${FILESDIR}/ja-webalizer.conf-dist.patch
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

pre-configure:
	@${MV} ${WRKSRC}/webalizer.1 ${WRKSRC}/webalizer.1.sed
	${SED} -e "s=/etc=${PREFIX}/etc=" \
		${WRKSRC}/webalizer.1.sed > ${WRKSRC}/webalizer.1
	@${MV} ${WRKSRC}/webalizer.c ${WRKSRC}/webalizer.c.sed
	${SED} -e "s=webalizer.conf=${PKGNAMEPREFIX}webalizer.conf=" \
		${WRKSRC}/webalizer.c.sed > ${WRKSRC}/webalizer.c
.if !defined(WEBALIZER_LANG)
	@${ECHO_MSG} "You can customize the language by typing"
	@${ECHO_MSG} "       make WEBALIZER_LANG=<lang>"
	@${ECHO_MSG} "where <lang> is one of:"
	@${ECHO_MSG} ${SUPP_LANG}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/webalizer \
		${PREFIX}/bin/${PKGNAMEPREFIX}webalizer
	${LN} -sf ${PKGNAMEPREFIX}webalizer \
		${PREFIX}/bin/${PKGNAMEPREFIX}webazolver
	${INSTALL_DATA} ${WRKSRC}/sample.conf \
		${PREFIX}/etc/${PKGNAMEPREFIX}webalizer.conf-dist ;

post-install:
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/webalizer.1 ${PREFIX}/man/man1/${i}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOC1}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/${i}
.endfor
	${MKDIR} ${EXAMPLESDIR}
.for i in msfree.png sample.conf webalizer.png
	@${INSTALL_DATA} ${WRKSRC}/${i} ${EXAMPLESDIR}/${i}
.endfor
.if defined(WITH_GEOIP)
	${MKDIR} ${DOCSDIR}/geolizer
.for i in ${DOC2}
	@${INSTALL_DATA} ${WRKDIR}/geolizer_2.01-10-patch/${i} \
		${DOCSDIR}/geolizer/${i}
.endfor
.endif
.endif

.include <bsd.port.post.mk>
