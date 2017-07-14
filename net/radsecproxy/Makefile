# Created by: Honza Betik
# $FreeBSD$

PORTNAME=	radsecproxy
PORTVERSION=	1.6.8
CATEGORIES=	net
MASTER_SITES=	https://software.nordu.net/radsecproxy/

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Radsecproxy is a generic RADIUS proxy

LICENSE=	GPLv2 BSD3CLAUSE
LICENSE_COMB=	dual

USES=		cpe tar:xz ssl
CPE_VENDOR=	nordunet

GNU_CONFIGURE=	yes
USE_RC_SUBR=	${PORTNAME}
CONFIGURE_ARGS=	--with-ssl=${OPENSSLBASE}

post-install:
	${MAKE} install-man -C ${WRKSRC} ${MAKE_ARGS}
	${INSTALL_DATA} ${WRKSRC}/radsecproxy.conf-example \
		${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
