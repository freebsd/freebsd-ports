# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	stund
PORTVERSION=	0.96
CATEGORIES=	net
MASTER_SITES=	SF/stun/stun/${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_Aug13
EXTRACT_SUFX=	.tgz

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	Simple STUN (RFC 3489) server and client

USES=		gmake
USE_RC_SUBR=	stund

MAKE_ENV=	"CXX=${CXX}"

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/server ${STAGEDIR}${PREFIX}/sbin/stund
	${INSTALL_PROGRAM} ${WRKSRC}/client ${STAGEDIR}${PREFIX}/bin/stun_client

.include <bsd.port.mk>
