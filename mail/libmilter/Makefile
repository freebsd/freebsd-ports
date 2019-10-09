# $FreeBSD$

PORTNAME=	libmilter
PORTVERSION=	8.15.2
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.sendmail.org/pub/sendmail/
DISTNAME=	sendmail.${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Library providing Sendmail Mail Filter API

LICENSE=	Sendmail
LICENSE_NAME=	Sendmail License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

MILTER_SOVER?=	7

OPTIONS_DEFINE?=	IPV6 MILTER_SHARED MILTER_POOL DOCS
OPTIONS_DEFAULT?=	MILTER_SHARED MILTER_POOL
NO_OPTIONS_SORT=yes
OPTIONS_SUB=	yes
MILTER_SHARED_DESC=	Build shared libmilter
MILTER_POOL_DESC=	Enable milter thread pools

WRKSRC=		${WRKDIR}/sendmail-${PORTVERSION}
WCONF=		${WRKSRC}/devtools/Site
SITE=		${FILESDIR}/site.config.m4

IPV6_VARS=		SITE+=${FILESDIR}/site.config.m4.ipv6
MILTER_POOL_VARS=	SITE+=${FILESDIR}/site.config.m4.pool
MILTER_SHARED_MAKE_ENV=	MILTER_SOVER=${MILTER_SOVER}
MILTER_SHARED_PLIST_SUB=MILTER_SOVER=${MILTER_SOVER}
MILTER_SHARED_USE=	LDCONFIG=yes

post-patch-MILTER_SHARED-on:
	@${CP} -pR ${WRKSRC}/libmilter ${WRKSRC}/libsharedmilter
	${CP} ${FILESDIR}/sharedlibrary.m4 \
		${WRKSRC}/devtools/M4/UNIX/sharedlibrary.m4
	${REINPLACE_CMD} -e 's=`library=`sharedlibrary=' \
		${WRKSRC}/libsharedmilter/Makefile.m4

do-configure:
	${REINPLACE_CMD} -e "s|\`-O'|\`${CFLAGS}'|" \
		-e 's|%%CC%%|${CC}|' -e 's|%%LD%%|${LD}|' \
		${WRKSRC}/devtools/OS/FreeBSD
	${SED} -e "s=%%PREFIX%%=${PREFIX}=g" \
		-e "s=%%LOCALBASE%%=${LOCALBASE}=g" \
		${SITE} > ${WCONF}/site.config.m4

do-build:
	(cd ${BUILD_WRKSRC}/libmilter; ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

do-build-MILTER_SHARED-on:
	(cd ${BUILD_WRKSRC}/libsharedmilter; ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/libmilter
	${INSTALL_DATA} ${WRKSRC}/include/libmilter/mfapi.h \
		${WRKSRC}/include/libmilter/mfdef.h \
		${STAGEDIR}${PREFIX}/include/libmilter/
	${INSTALL_DATA} \
		${WRKSRC}/obj.`${WRKSRC}/devtools/bin/Build -A`/libmilter/libmilter.a \
		${STAGEDIR}${PREFIX}/lib/

post-install-MILTER_SHARED-on:
	${INSTALL_LIB} \
		${WRKSRC}/obj.`${WRKSRC}/devtools/bin/Build -A`/libsharedmilter/libmilter.so \
		${STAGEDIR}${PREFIX}/lib/libmilter.so.${MILTER_SOVER}
	${LN} -sf libmilter.so.${MILTER_SOVER} \
		${STAGEDIR}${PREFIX}/lib/libmilter.so

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/libmilter/README ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/libmilter/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
