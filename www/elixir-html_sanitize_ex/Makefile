# $FreeBSD$

PORTNAME=	html_sanitize_ex
PORTVERSION=	1.3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www
PKGNAMEPREFIX=	elixir-

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	HTML sanitizer for Elixir

LICENSE=	MIT

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	rrrene

MIX_BUILD_DEPS=	www/erlang-mochiweb
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}
MIX_REWRITE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
