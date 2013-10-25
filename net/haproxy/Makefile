# Created by: Clement Laforet
# $FreeBSD$

PORTNAME=	haproxy
PORTVERSION=	1.4.24
PORTREVISION=	1
CATEGORIES=	net www
MASTER_SITES=	http://haproxy.1wt.eu/download/1.4/src/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	The Reliable, High Performance TCP/HTTP Load Balancer

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

CONFLICTS=	haproxy-devel-[0-9]*

USES=		gmake
USE_RC_SUBR=	haproxy
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	PCRE
OPTIONS_SINGLE=		PCRE
OPTIONS_SINGLE_PCRE=	DPCRE SPCRE
DPCRE_DESC=	Link dynamically
SPCRE_DESC=	Link statically
OPTIONS_DEFAULT=PCRE DPCRE

.include <bsd.port.options.mk>

MAKE_ARGS=	TARGET=freebsd DEFINE=-DFREEBSD_PORTS CC=${CC}

.if ${PORT_OPTIONS:MDPCRE}
LIB_DEPENDS+=	libpcre.so:${PORTSDIR}/devel/pcre
MAKE_ARGS+=	"USE_PCRE=1"
.endif
.if ${PORT_OPTIONS:MSPCRE}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libpcre.a:${PORTSDIR}/devel/pcre
MAKE_ARGS+=	"USE_STATIC_PCRE=1"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/haproxy ${STAGEDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/doc/haproxy.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
