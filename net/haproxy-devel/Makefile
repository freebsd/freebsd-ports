# New ports collection Makefile for:	haproxy
# Date created:				Apr 30, 2003
# Whom:					Clement Laforet
#
# $FreeBSD$
#

PORTNAME=	haproxy
PORTVERSION=	1.1.21
PORTREVISION=	0
CATEGORIES=	net www
MASTER_SITES=	http://w.ods.org/tools/haproxy/ \
		http://w.ods.org/tools/haproxy/old/

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	High-performance and highly-robust TCP/HTTP load balancer

STATS_INTERVAL?= 0
REGEX_TYPE?=	libc

MAKE_ENV+=	REGEX=${REGEX_TYPE} INTERVAL=${STATS_INTERVAL}

.if defined(WITH_PCRE)
REGEX_TYPE=	pcre
PKGNAMESUFFIX=	-pcre
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
.endif

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Available options:"
	@${ECHO_MSG} "WITH_PCRE:            Use pcre regex engine"
	@${ECHO_MSG} "STATS_INTERVAL=###:   Statistics interval in milliseconds,"
	@${ECHO_MSG} "                         (default to 0, disabled)"
	@${ECHO_MSG} ""

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/haproxy ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/examples/haproxy.cfg \
			${PREFIX}/etc/haproxy.cfg.sample
	${INSTALL_SCRIPT} ${FILESDIR}/haproxy.sh \
			${PREFIX}/etc/rc.d/haproxy.sh.sample

.include <bsd.port.mk>
