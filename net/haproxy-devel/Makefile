# New ports collection makefile for:    haproxy-devel
# Date created:         Thu May  3 16:30:19 WEST 2007
# Whom:                 Hugo Saro <hugo@barafranca.com>
#
# $FreeBSD$
#

PORTNAME=	haproxy
PORTVERSION=	1.3.18
CATEGORIES=	net
MASTER_SITES=	http://haproxy.1wt.eu/download/1.3/src/
PKGNAMESUFFIX=	-devel

MAINTAINER=	hugo@barafranca.com
COMMENT=	The Reliable, High Performance TCP/HTTP Load Balancer

CONFLICTS=	haproxy-1.2*
USE_RC_SUBR=	haproxy

MAKEFILE=	Makefile.bsd

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/haproxy ${PREFIX}/sbin

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/design-thoughts
	@${MKDIR} ${DOCSDIR}/internals
	@${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DOCSDIR}/
	@(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} internals ${DOCSDIR}/)
	@(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} design-thoughts ${DOCSDIR}/)
.endif
	@${INSTALL_DATA} ${WRKSRC}/examples/haproxy.cfg \
				${PREFIX}/etc/haproxy.conf-dist

post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} ""
	@${ECHO_MSG} ""
	@${ECHO_MSG} "${PORTNAME} is now installed."
	@${ECHO_MSG} "To configure it, rename ${PREFIX}/etc/haproxy.conf-dist"
	@${ECHO_MSG} "and add haproxy_enable=\"YES\" to /etc/rc.conf"
	@${ECHO_MSG} ""
	@${ECHO_MSG} ""

.include <bsd.port.mk>
