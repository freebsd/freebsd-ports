# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	srelay
PORTVERSION=	0.4.8p1
CATEGORIES=	net
MASTER_SITES=	SOURCEFORGE/socks-relay/socks-relay/${PORTNAME}-0.4.8

MAINTAINER=	decke@FreeBSD.org
COMMENT=	SOCKS4/5 proxy and relay

LICENSE=	BSD3CLAUSE

HAS_CONFIGURE=	yes
USE_RC_SUBR=	srelay

do-install:
	${INSTALL_DATA} ${WRKSRC}/srelay.conf ${STAGEDIR}${PREFIX}/etc/srelay.conf.sample
	${INSTALL_DATA} ${WRKSRC}/srelay.passwd ${STAGEDIR}${PREFIX}/etc/srelay.passwd.sample
	${INSTALL_MAN} ${WRKSRC}/srelay.8 ${STAGEDIR}${PREFIX}/man/man8
	${INSTALL_PROGRAM} ${WRKSRC}/srelay ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
