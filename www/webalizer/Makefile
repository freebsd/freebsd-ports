# New ports collection makefile for:	webalizer
# Date created:		02.Jun 1998
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	webalizer
PORTVERSION=	2.20.1
CATEGORIES+=	www
MASTER_SITES=	ftp://ftp.mrunix.net/pub/webalizer/:main \
		ftp://ftp.dinoex.de/pub/FreeBSD/distfiles/:main \
		http://flags.blogpotato.de/zip/:flags
PKGNAMESUFFIX?=	${WEBALIZER_SUFFIX}${PKGNAMESUFFIX2}
DISTNAME=	${PORTNAME}-2.20-01-src
DISTFILES=	${DISTNAME}.tgz:main webalizer-geodb-20080701.tgz:main
.if defined(WITH_GEOIP) || make(makesum) || defined(FETCH_ALL)
DISTFILES+=	world.small.zip:flags special.small.zip:flags
.endif

MAINTAINER?=	dinoex@FreeBSD.org
COMMENT=	A web server log file analysis program

.if !defined(LIB_DEPENDS)
LIB_DEPENDS=	gd.4:${PORTSDIR}/${GD_PORT}
.endif
.if defined(WITH_GEOIP)
LIB_DEPENDS+=	GeoIP.5:${PORTSDIR}/net/GeoIP
EXTRACT_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
.endif

USE_BZIP2=	yes
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

.if defined(WITH_GEOIP)
WEBALIZER_SUFFIX=	-geoip
CONFLICTS+=	${PKGNAMEPREFIX}webalizer-2*
CONFIGURE_ARGS+=	--enable-geoip \
			--with-geoip-lib=${LOCALBASE}/lib \
			--with-geoip-inc=${LOCALBASE}/include
PLIST_SUB+=	WITH_GEOIP=""
.else
CONFLICTS+=	${PKGNAMEPREFIX}webalizer-geoip-2*
PLIST_SUB+=	WITH_GEOIP="@comment "
.endif

CONFIGURE_ARGS+=	--enable-dns \
			--with-geodb=${PREFIX}/share/webalizer \
			--sysconfdir=${PREFIX}/etc \
			--with-gdlib=${LOCALBASE}/lib \
			--with-gd=${LOCALBASE}/include

CONFIGURE_ENV+=	LDFLAGS="-L${PREFIX}/lib"
CFLAGS+=	-DUSE_DB185 -Wall
MAN1=		${PKGNAMEPREFIX}webalizer.1 ${PKGNAMEPREFIX}wcmgr.1
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

.if !defined(WITHOUT_WEBALIZER_FULL_CGI_REFS)
CFLAGS+=	-DUSE_FULL_CGI_REFS
.endif

.if defined(WITH_WEBALIZER_CLICKABLE_REFERER)
CFLAGS+=	-DUSE_CLICKABLE_REFERER
.endif

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@for f in ${EXTRACT_ONLY}; do \
		case $$f in \
		*.Z|*.gz|*.tgz) \
			if ! (cd ${WRKDIR} && \
				${GZCAT} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$$f ${EXTRACT_AFTER_ARGS});\
			then \
				exit 1; \
			fi \
			;; \
		*.bz2) \
			if ! (cd ${WRKDIR} && \
				${BZCAT} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$$f ${EXTRACT_AFTER_ARGS});\
			then \
				exit 1; \
			fi \
			;; \
		*.zip) \
			if ! (cd ${WRKDIR} && \
				${UNZIP_CMD} -qo ${_DISTDIR}/$$f -d ${WRKDIR});\
			then \
				exit 1; \
			fi \
			;; \
		*) \
			exit 1; \
			;; \
		esac; \
	done
.if !defined(EXTRACT_PRESERVE_OWNERSHIP)
	@if [ `${ID} -u` = 0 ]; then \
		${CHMOD} -R ug-s ${WRKDIR}; \
		${CHOWN} -R 0:0 ${WRKDIR}; \
	fi
.endif

pre-configure:
	${REINPLACE_CMD} -e "s|/etc|${PREFIX}/etc|" \
		${WRKSRC}/webalizer.1
	${REINPLACE_CMD} \
		-e "s|webalizer.conf|${PKGNAMEPREFIX}webalizer.conf|" \
		${WRKSRC}/webalizer.c
	${REINPLACE_CMD} -e "s|-ldb||" \
		${WRKSRC}/configure
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
.if defined(WITH_GEOIP)
	${MKDIR} ${PREFIX}/share/geolizer
	@${INSTALL_DATA} ${WRKDIR}/*.png ${PREFIX}/share/geolizer/
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
