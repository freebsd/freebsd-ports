# New ports collection Makefile for:	haproxy
# Date created:				Apr 30, 2003
# Whom:					Clement Laforet
#
# $FreeBSD$
#

PORTNAME=	haproxy
PORTVERSION=	1.4.8
CATEGORIES=	net www
MASTER_SITES=	http://haproxy.1wt.eu/download/1.4/src/

MAINTAINER=	freebsd@linepoint.com
COMMENT=	The Reliable, High Performance TCP/HTTP Load Balancer

USE_RC_SUBR=	haproxy
USE_GMAKE=	YES
SUB_FILES=	pkg-message
MAN1=		haproxy.1

OPTIONS=	PCRE		"Use PCRE regex library"	On\
		STATIC_PCRE	"Use static PCRE regex library"	Off

.include <bsd.port.options.mk>

MAKE_ARGS=	TARGET=freebsd DEFINE=-DFREEBSD_PORTS

.if defined(WITH_PCRE)
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
MAKE_ARGS+=	"USE_PCRE=1"
.endif

.if defined(WITH_STATIC_PCRE)
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
MAKE_ARGS+=	"USE_STATIC_PCRE=1"
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
