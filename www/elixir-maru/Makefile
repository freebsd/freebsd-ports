# $FreeBSD$

PORTNAME=	maru
PORTVERSION=	0.3.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Elixir RESTful framework

LICENSE=	BSD3CLAUSE

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	falood

MIX_BUILD_DEPS=	devel/elixir-plug \
		devel/elixir-poison \
		www/erlang-cowboy
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}
MIX_DOC_DIRS=	guide

.include <bsd.port.mk>
