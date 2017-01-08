# Created by: Babak Farrokhi <farrokhi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fast_tls
PORTVERSION=	1.0.9
CATEGORIES=	security
PKGNAMEPREFIX=	erlang-

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	TLS / SSL OpenSSL-based native driver for Erlang / Elixir

LICENSE=	APACHE20

USES=		erlang:rebar ssl
USE_GITHUB=	yes
GH_ACCOUNT=	processone

ERL_BUILD_DEPS=	textproc/erlang-p1_utils
ERL_RUN_DEPS:=	${ERL_BUILD_DEPS}
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${OPENSSLINC}
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/priv/lib/*.so

.include <bsd.port.mk>
