# $FreeBSD$

PORTNAME=	hackney
PORTVERSION=	1.2.0
CATEGORIES=	www
PKGNAMEPREFIX=	erlang-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Simple HTTP client in Erlang

LICENSE=	APACHE20

BUILD_DEPENDS=	erl:${PORTSDIR}/lang/erlang \
		erlang-idna>=0:${PORTSDIR}/dns/erlang-idna \
		erlang-ssl_verify_hostname>=0:${PORTSDIR}/devel/erlang-ssl_verify_hostname
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_SUB=	VERSION="${PORTVERSION}"

USE_GITHUB=	yes
GH_ACCOUNT=	benoitc

pre-build:
	@${LN} -s ${WRKSRC}/_build/default/lib/${PORTNAME}/ebin ${WRKSRC}
	@${MKDIR} ${WRKSRC}/_build/default/lib
.for lib in idna ssl_verify_hostname
	@${LN} -s ${PREFIX}/lib/erlang/lib/${lib}-* ${WRKSRC}/_build/default/lib/${lib}
.endfor

do-build:
	@${RM} ${WRKSRC}/rebar.lock
	@cd ${WRKSRC} && ./rebar3 compile

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/ebin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/include
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/priv
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/ebin/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/include/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/include
	${INSTALL_DATA} ${WRKSRC}/priv/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/priv
	cd ${WRKSRC}/src && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/src

.include <bsd.port.mk>
