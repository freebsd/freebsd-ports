# $FreeBSD$

PORTNAME=	webmachine
PORTVERSION=	1.10.8
CATEGORIES=	www devel
PKGNAMEPREFIX=	erlang-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	HTTP semantic awareness on top mochiweb

LICENSE=	APACHE20

USES=		erlang:rebar
USE_GITHUB=     yes
GH_ACCOUNT=     basho

ERL_BUILD_DEPS=	www/erlang-mochiweb-basho
ERL_RUN_DEPS:=	${ERL_BUILD_DEPS}

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/demo && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
