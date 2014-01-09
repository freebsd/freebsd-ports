# Created by: Honza Betik
# $FreeBSD$

PORTNAME=	radsecproxy
PORTVERSION=	1.6.5
CATEGORIES=	net
MASTER_SITES=	http://software.uninett.no/radsecproxy/

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Radsecproxy is a generic RADIUS proxy

LICENSE=	GPLv2 BSD
LICENSE_COMB=	dual

GNU_CONFIGURE=	yes
USE_RC_SUBR=	${PORTNAME}
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--with-ssl=${OPENSSLBASE}

post-install:
	${MAKE} install-man -C ${WRKSRC} ${MAKE_ARGS}
	${INSTALL_DATA} ${WRKSRC}/radsecproxy.conf-example \
		${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
