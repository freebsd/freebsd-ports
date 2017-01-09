# Created by: Hugo Saro <hugo@barafranca.com>
# $FreeBSD$

PORTNAME=	haproxy
DISTVERSION=	1.7-dev6
CATEGORIES=	net www
MASTER_SITES=	http://www.haproxy.org/download/1.7/src/devel/
PKGNAMESUFFIX=	-devel
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Reliable, high performance TCP/HTTP load balancer

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

CONFLICTS_INSTALL=	haproxy-[1234567890]\*
IGNORE=		no devel version available

USES=		cpe gmake
USE_RC_SUBR=	haproxy

DEVICEATLAS_VERSION=	2.1
DEVICEATLAS_DISTFILE=	deviceatlas-enterprise-c-${DEVICEATLAS_VERSION}
DEVICEATLAS_REGISTRATION_URL=	https://deviceatlas.com/deviceatlas-haproxy-module

MAKE_ARGS=	TARGET=freebsd DEFINE=-DFREEBSD_PORTS USE_GETADDRINFO=1 \
		USE_ZLIB=1 USE_CPU_AFFINITY=1 CC="${CC}" CFLAGS="${CFLAGS}"

OPTIONS_DEFINE=		DOCS EXAMPLES LUA OPENSSL DEVICEATLAS
OPTIONS_RADIO=		PCRE
OPTIONS_RADIO_PCRE=	DPCRE SPCRE
DPCRE_DESC=		Link dynamically
SPCRE_DESC=		Link statically
DEVICEATLAS_DESC=	DeviceAtlas Device Detection support
OPTIONS_DEFAULT=	SPCRE OPENSSL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDPCRE}
LIB_DEPENDS+=	libpcre.so:devel/pcre
MAKE_ARGS+=	USE_PCRE=1 USE_PCRE_JIT=1
.endif

.if ${PORT_OPTIONS:MSPCRE}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libpcre.a:devel/pcre
MAKE_ARGS+=	USE_PCRE=1 USE_STATIC_PCRE=1 USE_PCRE_JIT=1
.endif

.if ${PORT_OPTIONS:MDEVICEATLAS}
.if !exists(${DISTDIR}/${DEVICEATLAS_DISTFILE}.zip)
IGNORE?=	you must manually fetch the DeviceAtlas Device Detection C API from ${DEVICEATLAS_REGISTRATION_URL} and place it in ${DISTDIR} and then run make again
.else
RESTRICTED=	The redistribution of the DeviceAtlas Device Detection C API is not permitted
DISTFILES+=	${DEVICEATLAS_DISTFILE}.zip
MAKE_ARGS+=	USE_DEVICEATLAS=1 DEVICEATLAS_SRC=${WRKDIR}/deviceatlas-enterprise-c-${DEVICEATLAS_VERSION}
.endif
.if ! ${PORT_OPTIONS:MDPCRE} && ! ${PORT_OPTIONS:MSPCRE}
IGNORE?=	enable PCRE support to use DeviceAtlas
.endif
.endif

.if ${PORT_OPTIONS:MOPENSSL}
USES+=		ssl
MAKE_ARGS+=	USE_OPENSSL=1
.if !empty(SSL_DEFAULT:Mlibressl*)
BROKEN= does not build with libressl
.endif
.endif

.if ${PORT_OPTIONS:MLUA}
USES+=		lua:53
MAKE_ARGS+=	USE_LUA=1 LUA_INC=${LUA_INCDIR} LUA_LIB=${LUA_LIBDIR} LUA_LIB_NAME=lua-${LUA_VER}
.endif

post-build:
	cd ${WRKSRC}/contrib/halog && ${MAKE_CMD} ${MAKE_ENV}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/haproxy ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/contrib/halog/halog ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/doc/haproxy.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
