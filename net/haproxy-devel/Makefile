# Created by: Hugo Saro <hugo@barafranca.com>
# $FreeBSD$

PORTNAME=	haproxy
DISTVERSION=	1.5-dev17
CATEGORIES=	net
MASTER_SITES=	http://haproxy.1wt.eu/download/1.5/src/devel/
PKGNAMESUFFIX=	-devel

MAINTAINER=	demon@FreeBSD.org
COMMENT=	The Reliable, High Performance TCP/HTTP Load Balancer

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

CONFLICTS=	haproxy-[1234567890]\*
USE_RC_SUBR=	haproxy
USE_GMAKE=	YES
SUB_FILES=	pkg-message
MAN1=		haproxy.1

OPTIONS_DEFINE=		PCRE OPENSSL
OPTIONS_SINGLE=		PCRE
OPTIONS_SINGLE_PCRE=	DPCRE SPCRE
DPCRE_DESC=		Link dynamically
SPCRE_DESC=		Link statically
OPTIONS_DEFAULT=	PCRE DPCRE OPENSSL

.include <bsd.port.options.mk>

MAKE_ARGS=	TARGET=freebsd DEFINE=-DFREEBSD_PORTS USE_GETADDRINFO=1 \
		USE_ZLIB=1 CC="${CC}" CFLAGS="${CFLAGS}"

.if ${PORT_OPTIONS:MPCRE}
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre

.if ${PORT_OPTIONS:MDPCRE}
MAKE_ARGS+=	"USE_PCRE=1"
.endif
.if ${PORT_OPTIONS:MSPCRE}
MAKE_ARGS+=	"USE_STATIC_PCRE=1"
.endif
.endif

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
MAKE_ARGS+=	USE_OPENSSL=1
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/haproxy ${PREFIX}/sbin/
	@${INSTALL_MAN} ${WRKSRC}/doc/haproxy.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
