# $FreeBSD$

PORTNAME=	ex_doc
PORTVERSION=	0.7.3
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Tool to generate documentation for Elixir projects

LICENSE=	APACHE20 MIT
LICENSE_COMB=	multi

USE_GITHUB=	yes
GH_ACCOUNT=	elixir-lang

MIX_BUILD_DEPS=	textproc/elixir-earmark
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

.include "${.CURDIR}/../../lang/elixir/bsd.elixir.mk"
.include <bsd.port.mk>
