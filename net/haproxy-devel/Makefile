# New ports collection Makefile for:	haproxy
# Date created:				Apr 30, 2003
# Whom:					Clement Laforet
#
# $FreeBSD$
#

PORTNAME=	haproxy
PORTVERSION=	1.1.27
CATEGORIES=	net www
MASTER_SITES=	http://w.ods.org/tools/haproxy/src/ \
		http://w.ods.org/tools/haproxy/src/old/

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	High-performance and highly-robust TCP/HTTP load balancer

USE_REINPLACE=	yes

STATS_INTERVAL?=	0
CFLAGS+=	-DSTATTIME=${STATS_INTERVAL}

.if defined(WITH_TPROXY)
CFLAGS+=	-DTPROXY
.endif

.if defined(WITH_PCRE)
PKGNAMESUFFIX=	-pcre
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
CFLAGS+=	-DUSE_PCRE -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lpcreposix -lpcre
.endif

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Available options:"
	@${ECHO_MSG} "WITH_PCRE:            Use pcre regex engine"
	@${ECHO_MSG} "WITH_DTPROXY:         Enable Transparent proxy support"
	@${ECHO_MSG} "STATS_INTERVAL=###:   Statistics interval in milliseconds,"
	@${ECHO_MSG} "                         (default to 0, disabled)"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's!localtime(!localtime((time_t *)!' ${WRKSRC}/haproxy.c

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} ${PORTNAME}.c -o ${PORTNAME}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/haproxy ${PREFIX}/sbin
	@${INSTALL_DATA} ${WRKSRC}/examples/haproxy.cfg \
			${PREFIX}/etc/haproxy.cfg.sample
	@${INSTALL_SCRIPT} ${FILESDIR}/haproxy.sh \
			${PREFIX}/etc/rc.d/haproxy.sh.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
