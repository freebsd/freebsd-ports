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

BUILD_DEPENDS=	elixir:${PORTSDIR}/lang/elixir \
		elixir-plug>=0:${PORTSDIR}/devel/elixir-plug \
		elixir-poison>=0:${PORTSDIR}/devel/elixir-poison
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	phoenixframework

OPTIONS_DEFINE=	COWBOY
COWBOY_DESC=	Use Cowboy library

COWBOY_BUILD_DEPENDS=	erlang-cowboy>=0:${PORTSDIR}/www/erlang-cowboy
COWBOY_RUN_DEPENDS=	erlang-cowboy>=0:${PORTSDIR}/www/erlang-cowboy

.include <bsd.port.options.mk>

do-build:
	@cd ${WRKSRC} && LANG=en_US.UTF-8 MIX_ENV=prod mix compile
	@cd ${WRKSRC}/installer && LANG=en_US.UTF-8 MIX_ENV=prod mix compile

post-build:
	@${LN} -s ${WRKSRC}/_build/prod/lib/${PORTNAME}/ebin ${WRKSRC}/ebin

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/elixir/lib/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/elixir/lib/${PORTNAME}/ebin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/elixir/lib/${PORTNAME}/installer
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/elixir/lib/${PORTNAME}/lib
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/elixir/lib/${PORTNAME}/priv
	${INSTALL_DATA} ${WRKSRC}/ebin/* ${STAGEDIR}${PREFIX}/lib/elixir/lib/${PORTNAME}/ebin
	cd ${WRKSRC}/lib && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/lib/elixir/lib/${PORTNAME}/lib
	cd ${WRKSRC}/priv && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/lib/elixir/lib/${PORTNAME}/priv
.for dir in lib templates
	cd ${WRKSRC}/installer && ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${PREFIX}/lib/elixir/lib/${PORTNAME}/installer
.endfor
	${INSTALL_DATA} ${WRKSRC}/installer/_build/prod/lib/phoenix_new/ebin/* \
		${STAGEDIR}${PREFIX}/lib/elixir/lib/${PORTNAME}/ebin

.include <bsd.port.mk>
