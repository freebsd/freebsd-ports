# $FreeBSD$

PORTNAME=	webmachine
PORTVERSION=	1.10.9
CATEGORIES=	www devel
PKGNAMEPREFIX=	erlang-

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	HTTP semantic awareness on top mochiweb

LICENSE=	APACHE20

USES=		erlang:rebar
USE_GITHUB=     yes
GH_ACCOUNT=     webmachine

ERL_BUILD_DEPS=	www/erlang-mochiweb-basho
ERL_RUN_DEPS:=	${ERL_BUILD_DEPS}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
