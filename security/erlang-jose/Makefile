# $FreeBSD$

PORTNAME=	jose
PORTVERSION=	1.7.5
CATEGORIES=	security
PKGNAMEPREFIX=	erlang-

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	JSON Object Signing and Encryption (JOSE) for Erlang

LICENSE=	MPL

USES=		erlang:rebar
USE_GITHUB=	yes
GH_ACCOUNT=	potatosalad
GH_PROJECT=	erlang-jose
ERL_APP_NAME=	erlang-jose
DOCSDIR=	${PREFIX}/share/doc/${ERL_APP_NAME}

ERL_BUILD_DEPS=	converters/erlang-base64url
ERL_RUN_DEPS:=	${ERL_BUILD_DEPS}

.include <bsd.port.mk>
