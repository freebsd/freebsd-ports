# New ports collection Makefile for:	haproxy
# Date created:				Apr 30, 2003
# Whom:					Clement Laforet
#
# $FreeBSD$
#

PORTNAME=	haproxy
PORTVERSION=	1.2.17
CATEGORIES=	net www
MASTER_SITES=	http://haproxy.1wt.eu/download/1.2/src/

MAINTAINER=	clement@FreeBSD.org
COMMENT=	High-performance and highly-robust TCP/HTTP load balancer

USE_RC_SUBR=	haproxy.sh

STATS_INTERVAL?=	0
CFLAGS+=	-DSTATTIME=${STATS_INTERVAL}

.if defined(WITH_TPROXY)
CFLAGS+=	-DTPROXY
.endif

.if defined(WITH_PCRE)
PKGNAMESUFFIX=	-pcre
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
MAKE_ENV+=	"REGEX=pcre"
CFLAGS+=	-DUSE_PCRE -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lpcreposix -lpcre
.endif

.if defined(WITH_SMALLOPTS)
CFLAGS+=	-DBUFSIZE=8030 -DMAXREWRITE=1030 -DSYSTEM_MAXCONN=1024
.endif

MAKEFILE=	Makefile.bsd

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Available options:"
	@${ECHO_MSG} "WITH_PCRE:            Use pcre regex engine"
	@${ECHO_MSG} "WITH_TPROXY:         Enable Transparent proxy support"
	@${ECHO_MSG} "WITH_SMALLOPTS:         Enable low memory footprint support"
	@${ECHO_MSG} "STATS_INTERVAL=###:   Statistics interval in milliseconds,"
	@${ECHO_MSG} "                         (default to 0, disabled)"
	@${ECHO_MSG} ""

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/haproxy ${PREFIX}/sbin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/haproxy.cfg \
			${EXAMPLESDIR}/haproxy.cfg
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
