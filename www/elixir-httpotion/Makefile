# $FreeBSD$

PORTNAME=	httpotion
PORTVERSION=	2.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	The HTTP client for Elixir

LICENSE=	MIT

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	myfreeweb

MIX_BUILD_DEPS=	www/erlang-ibrowse
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

.include <bsd.port.mk>
