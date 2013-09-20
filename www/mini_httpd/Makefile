# Created by: se
# $FreeBSD$

PORTNAME=	mini_httpd
PORTVERSION=	1.19
PORTREVISION=	1
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.acme.com/software/mini_httpd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small HTTP server with support for GET, HEAD, POST, CGI, SSL, IPv6

.ifndef NO_SSL
MAKE_ARGS+=	-DUSE_OPENSSL
.endif

MAN1=	${PORTNAME}-htpasswd.1
MAN8=	${PORTNAME}.8

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's/htpasswd/${PORTNAME}-htpasswd/g' ${WRKSRC}/htpasswd.1
	${REINPLACE_CMD} -e 's/\(htpasswd(1)\)/${PORTNAME}-\1/g' ${WRKSRC}/${PORTNAME}.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mini_httpd ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/htpasswd ${PREFIX}/sbin/${PORTNAME}-htpasswd
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mini_httpd_wrapper ${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mini_httpd.sh ${PREFIX}/etc/rc.d/
	${INSTALL_MAN} ${WRKSRC}/htpasswd ${PREFIX}/man/man1/${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${MAN8} ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/mini_httpd.cnf ${PREFIX}/etc/mini_httpd.cnf.sample

.include <bsd.port.mk>
