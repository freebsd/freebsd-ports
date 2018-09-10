# $FreeBSD$

PORTNAME=	cowboy
PORTVERSION=	1.1.2
CATEGORIES=	www
PKGNAMEPREFIX=	erlang-

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Small, fast and modular HTTP server written in Erlang

LICENSE=	ISCL

USES=		erlang:rebar
USE_GITHUB=	yes
GH_ACCOUNT=	ninenines

ERL_BUILD_DEPS=	www/erlang-cowlib
ERL_RUN_DEPS=	www/erlang-cowlib \
		net/erlang-ranch

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
