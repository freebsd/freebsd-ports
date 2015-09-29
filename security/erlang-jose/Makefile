# $FreeBSD$

PORTNAME=	erlang-jose
PORTVERSION=	1.3.0
CATEGORIES=	security

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	JSON Object Signing and Encryption (JOSE) for Erlang

LICENSE=	MPL

USES=		erlang:rebar
USE_GITHUB=	yes
GH_ACCOUNT=	potatosalad

ERL_BUILD_DEPS=	converters/erlang-base64url
ERL_RUN_DEP:=	${ERL_BUILD_DEPS}

.include <bsd.port.mk>
