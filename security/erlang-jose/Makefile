# $FreeBSD$

PORTNAME=	jose
PORTVERSION=	1.9.0
CATEGORIES=	security
PKGNAMEPREFIX=	erlang-

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	JSON Object Signing and Encryption (JOSE) for Erlang

LICENSE=	MPL20

USES=		erlang:rebar
USE_GITHUB=	yes
GH_ACCOUNT=	potatosalad
GH_PROJECT=	erlang-jose
ERL_APP_NAME=	erlang-jose
DOCSDIR=	${PREFIX}/share/doc/${ERL_APP_NAME}
NO_ARCH=	yes

ERL_BUILD_DEPS=	converters/erlang-base64url
ERL_RUN_DEPS:=	${ERL_BUILD_DEPS}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
