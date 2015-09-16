# $FreeBSD$

PORTNAME=	funnel
PORTVERSION=	0.4.1
CATEGORIES=	textproc
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Streaming Elixir API built upon ElasticSearch's percolation

LICENSE=	APACHE20

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	chatgris

MIX_BUILD_DEPS=	devel/elixir-poison \
		devel/erlang-poolboy \
		misc/elixir-uuid \
		www/elixir-httpoison
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

.include <bsd.port.mk>
