# $FreeBSD$

PORTNAME=	phoenix_ecto
PORTVERSION=	0.5.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Ecto integration for the Phoenix framework

LICENSE=	MIT

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	phoenixframework

MIX_BUILD_DEPS=	databases/elixir-ecto \
		devel/elixir-plug \
		devel/elixir-poison
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

.include <bsd.port.mk>
