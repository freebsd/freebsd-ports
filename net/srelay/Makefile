# Created by: Bernhard Froehlich <decke@bluelife.at>
# $FreeBSD$

PORTNAME=	srelay
PORTVERSION=	0.4.8b6
CATEGORIES=	net

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Srelay is a SOCKS4/5 proxy and Relay

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	gco
GH_TAGNAME=	9461835

HAS_CONFIGURE=	yes
USE_RC_SUBR=	srelay

do-install:
	${INSTALL_DATA} ${WRKSRC}/srelay.conf ${STAGEDIR}${PREFIX}/etc/srelay.conf.sample
	${INSTALL_DATA} ${WRKSRC}/srelay.passwd ${STAGEDIR}${PREFIX}/etc/srelay.passwd.sample
	${INSTALL_MAN} ${WRKSRC}/srelay.8 ${STAGEDIR}${PREFIX}/man/man8
	${INSTALL_PROGRAM} ${WRKSRC}/srelay ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
