# New ports collection makefile for:    mini_httpd
# Date created:         24 July 2002
# Whom:                 se
#
# $FreeBSD$
#

PORTNAME=	mini_httpd
PORTVERSION=	1.19
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/mini_httpd/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	se@FreeBSD.org
COMMENT=	Small HTTP server with support for GET, HEAD, POST, CGI, SSL, IPv6

.ifndef NO_SSL
USE_OPENSSL=	YES
.endif

MAN8=		mini_httpd.8 htpasswd.8

post-build:
	-${MV} ${WRKSRC}/htpasswd.1 ${WRKSRC}/htpasswd.8 

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mini_httpd ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/htpasswd ${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mini_httpd_wrapper ${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mini_httpd.sh ${PREFIX}/etc/rc.d/
	@for file in ${MAN8}; \
	do \
		${INSTALL_MAN} ${WRKSRC}/$$file ${MAN8PREFIX}/man/man8/; \
	done
	${INSTALL_DATA} ${WRKSRC}/mini_httpd.cnf ${PREFIX}/etc/mini_httpd.cnf.sample

.include <bsd.port.mk>
