# Created by: se
# $FreeBSD$

PORTNAME=	mini_httpd
PORTVERSION=	1.20
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.acme.com/software/mini_httpd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small HTTP server with support for GET, HEAD, POST, CGI, SSL, IPv6

LICENSE=	BSD2CLAUSE

OPTIONS_DEFINE=	SSL
SSL_MAKE_ARGS=	-DUSE_OPENSSL

post-patch:
	${REINPLACE_CMD} -e 's/htpasswd/${PORTNAME}-htpasswd/g' ${WRKSRC}/htpasswd.1
	${REINPLACE_CMD} -e 's/\(htpasswd(1)\)/${PORTNAME}-\1/g' ${WRKSRC}/${PORTNAME}.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mini_httpd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/htpasswd ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}-htpasswd
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mini_httpd_wrapper ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mini_httpd.sh ${STAGEDIR}${PREFIX}/etc/rc.d
	${INSTALL_MAN} ${WRKSRC}/htpasswd.1 ${STAGEDIR}${PREFIX}/man/man1/${PORTNAME}-htpasswd.1
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/mini_httpd.cnf ${STAGEDIR}${PREFIX}/etc/mini_httpd.cnf.sample

.include <bsd.port.mk>
