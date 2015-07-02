# $FreeBSD$

PORTNAME=	phoenix
PORTVERSION=	0.14.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	www
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Web framework for Elixir

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	phoenixframework

OPTIONS_DEFINE=	COWBOY
COWBOY_DESC=	Use Cowboy library

COWBOY_BUILD_DEPENDS=	erlang-cowboy>=0:${PORTSDIR}/www/erlang-cowboy
COWBOY_RUN_DEPENDS=	erlang-cowboy>=0:${PORTSDIR}/www/erlang-cowboy

.include <bsd.port.options.mk>

MIX_BUILD_DEPS=	devel/elixir-plug \
		devel/elixir-poison
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}
MIX_EXTRA_APPS=	installer
MIX_EXTRA_DIRS=	installer/lib installer/templates

.include "${.CURDIR}/../../lang/elixir/bsd.elixir.mk"
.include <bsd.port.mk>
