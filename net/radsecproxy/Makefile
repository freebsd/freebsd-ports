# New ports collection makefile for: radsecproxy
# Date created: 2011-10-25
# Whom: Honza Betik
#
# $FreeBSD$

PORTNAME=	radsecproxy
PORTVERSION=	1.4.2
CATEGORIES=	net
MASTER_SITES=	http://software.uninett.no/radsecproxy/

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Radsecproxy is a generic RADIUS proxy

LICENSE=	GPLv2 BSD
LICENSE_COMB=	dual

MAN1=		radsecproxy.1
MAN5=		radsecproxy.conf.5

GNU_CONFIGURE=	yes
USE_RC_SUBR=	${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/radsecproxy ${PREFIX}/bin/catgconf
	${INSTALL_PROGRAM} ${WRKSRC}/radsecproxy ${PREFIX}/sbin/radsecproxy
	${INSTALL_DATA} ${WRKSRC}/radsecproxy.conf-example ${PREFIX}/etc/radsecproxy.conf-example
	${INSTALL_MAN} ${WRKSRC}/radsecproxy.1 ${PREFIX}/man/man1/radsecproxy.1
	${INSTALL_MAN} ${WRKSRC}/radsecproxy.conf.5 ${PREFIX}/man/man5/radsecproxy.conf.5
	${INSTALL_DATA} ${WRKSRC}/radsecproxy.conf-example ${PREFIX}/etc/radsecproxy.conf-example
.include <bsd.port.mk>
