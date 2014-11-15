# $FreeBSD$

PORTNAME=       rejik
PORTVERSION=    3.2.11
CATEGORIES=     www
MASTER_SITES=   http://www.rejik.ru/download/
DISTNAME=       redirector-${PORTVERSION}_squid_3.4

MAINTAINER=     roma.a.g@gmail.com
COMMENT=        Squid redirector used for blocking unwanted content

LICENSE=        BSD4CLAUSE

RUN_DEPENDS=    ${LOCALBASE}/sbin/squid:${PORTSDIR}/www/squid
LIB_DEPENDS+=   libpcre.so:${PORTSDIR}/devel/pcre

USES=           perl5 tar:tgz
USE_GCC=        any

post-patch:
	 @${REINPLACE_CMD} -e 's|gcc|${CC}|; s|INSTALL_PATH=/usr/local/rejik3|INSTALL_PATH=${STAGEDIR}${PREFIX}/rejik3|; s|>> ${INSTALL_PATH}|/usr/local/rejik3|g' ${WRKSRC}/Makefile
post-install:
	 ${STRIP_CMD} ${STAGEDIR}${PREFIX}/rejik3/make-cache
	 ${STRIP_CMD} ${STAGEDIR}${PREFIX}/rejik3/redirector

.include <bsd.port.mk>
