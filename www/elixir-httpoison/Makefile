# $FreeBSD$

PORTNAME=	httpoison
PORTVERSION=	0.8.3
DISTVERSIONPREFIX=	v
CATEGORIES=	www
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	HTTP client for Elixir powered by hackney

LICENSE=	MIT

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	edgurgel

MIX_BUILD_DEPS=	www/erlang-hackney
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

.include <bsd.port.mk>
