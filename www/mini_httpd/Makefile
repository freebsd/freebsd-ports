# Created by: Stefan Esser <se@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mini_httpd
PORTVERSION=	1.30
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	https://www.acme.com/software/mini_httpd/

MAINTAINER=	leres@FreeBSD.org
COMMENT=	Small HTTP server with support for GET, HEAD, POST, CGI, SSL, IPv6

LICENSE=	BSD2CLAUSE

USES=		cpe ssl
CPE_VENDOR=	acme

OPTIONS_DEFINE+=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's/htpasswd/${PORTNAME}-htpasswd/' \
		${WRKSRC}/htpasswd.1
	@${REINPLACE_CMD} -e 's/\(htpasswd(1)\)/${PORTNAME}-\1/' \
		${WRKSRC}/${PORTNAME}.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mini_httpd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/htpasswd \
		${STAGEDIR}${PREFIX}/sbin/${PORTNAME}-htpasswd
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mini_httpd_wrapper \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mini_httpd.sh \
		${STAGEDIR}${PREFIX}/etc/rc.d/mini_httpd
	${INSTALL_MAN} ${WRKSRC}/htpasswd.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/${PORTNAME}-htpasswd.1
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 \
		${STAGEDIR}${MANPREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/mini_httpd.cnf \
		${STAGEDIR}${PREFIX}/etc/mini_httpd.cnf.sample
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/500.mini_httpd-rotate \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
