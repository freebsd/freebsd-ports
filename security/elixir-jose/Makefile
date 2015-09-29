# $FreeBSD$

PORTNAME=	elixir-jose
PORTVERSION=	1.3.0
CATEGORIES=	security
DISTNAME=	${GH_ACCOUNT}-erlang-jose-${PORTVERSION}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	JSON Object Signing and Encryption (JOSE) for Elixir

LICENSE=	MPL

WRKSRC=		${WRKDIR}/erlang-jose-${PORTVERSION}
ELIXIR_APP_NAME=jose
USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	potatosalad

MIX_BUILD_DEPS=	converters/erlang-base64url \
		security/erlang-jose
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

.include <bsd.port.mk>
