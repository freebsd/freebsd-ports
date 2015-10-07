# Created by: Babak Farrokhi <farrokhi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	p1tls
PORTVERSION=	0.20150803
CATEGORIES=	security
PKGNAMEPREFIX=	erlang-

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	TLS / SSL native driver for Erlang

LICENSE=	GPLv2

USE_OPENSSL=	yes
USES=		erlang:rebar
USE_GITHUB=	yes
GH_ACCOUNT=	processone
GH_PROJECT=	tls
GH_TAGNAME=	e56321a

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/priv/lib/*.so

.include <bsd.port.mk>
