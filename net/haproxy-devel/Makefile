# Created by: Hugo Saro <hugo@barafranca.com>
# $FreeBSD$

PORTNAME=	haproxy
DISTVERSION=	1.5.0
CATEGORIES=	net
MASTER_SITES=	http://haproxy.1wt.eu/download/1.5/src/
PKGNAMESUFFIX=	-devel

MAINTAINER=	demon@FreeBSD.org
COMMENT=	The Reliable, High Performance TCP/HTTP Load Balancer

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

IGNORE=		No devel version available at this time

USES=		gmake
CONFLICTS=	haproxy-[1234567890]\*
USE_RC_SUBR=	haproxy
SUB_FILES=	pkg-message

OPTIONS_DEFINE=		OPENSSL
OPTIONS_RADIO=		PCRE
OPTIONS_RADIO_PCRE=	DPCRE SPCRE
DPCRE_DESC=		Link dynamically
SPCRE_DESC=		Link statically
OPTIONS_DEFAULT=	SPCRE OPENSSL

.include <bsd.port.options.mk>

MAKE_ARGS=	TARGET=freebsd DEFINE=-DFREEBSD_PORTS USE_GETADDRINFO=1 \
		USE_ZLIB=1 CC="${CC}" CFLAGS="${CFLAGS}"

.if ${PORT_OPTIONS:MDPCRE}
LIB_DEPENDS+=	libpcre.so:${PORTSDIR}/devel/pcre
MAKE_ARGS+=	USE_PCRE=1 USE_PCRE_JIT=1
.endif
.if ${PORT_OPTIONS:MSPCRE}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libpcre.a:${PORTSDIR}/devel/pcre
MAKE_ARGS+=	USE_STATIC_PCRE=1 USE_PCRE_JIT=1
.endif

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
MAKE_ARGS+=	USE_OPENSSL=1
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/haproxy ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/doc/haproxy.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
