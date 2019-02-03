# $FreeBSD$

PORTNAME=	ex_doc
PORTVERSION=	0.18.4
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc
PKGNAMEPREFIX=	elixir-

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Tool to generate documentation for Elixir projects

LICENSE=	APACHE20 MIT
LICENSE_COMB=	multi

BROKEN=		fails to build
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2019-03-05

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	elixir-lang

MIX_BUILD_DEPS=	textproc/elixir-earmark
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}
MIX_REWRITE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
