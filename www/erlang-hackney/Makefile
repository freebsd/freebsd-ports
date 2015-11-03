# $FreeBSD$

PORTNAME=	hackney
PORTVERSION=	1.4.1
CATEGORIES=	www
PKGNAMEPREFIX=	erlang-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Simple HTTP client in Erlang

LICENSE=	APACHE20

USES=		erlang:rebar3
USE_GITHUB=	yes
GH_ACCOUNT=	benoitc

ERL_BUILD_DEPS=	dns/erlang-idna \
		devel/erlang-certifi \
		devel/erlang-ssl_verify_hostname \
		misc/erlang-mimerl
ERL_RUN_DEPS:=	${ERL_BUILD_DEPS}

pre-build:
	@${MKDIR} ${WRKSRC}/_build/default/lib
.for lib in idna certifi mimerl ssl_verify_hostname
	@${LN} -s ${PREFIX}/lib/erlang/lib/${lib}-* ${WRKSRC}/_build/default/lib/${lib}
.endfor

.include <bsd.port.mk>
