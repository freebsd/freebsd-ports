# $FreeBSD$

PORTNAME=	cowboy
PORTVERSION=	1.0.2
CATEGORIES=	www
PKGNAMEPREFIX=	erlang-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Small, fast and modular HTTP server written in Erlang

LICENSE=	ISCL

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang \
		erlang-cowlib>=1.0.0:${PORTSDIR}/devel/erlang-cowlib
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang \
		erlang-cowlib>=1.0.0:${PORTSDIR}/devel/erlang-cowlib \
		erlang-ranch>=1.0.0:${PORTSDIR}/net/erlang-ranch

PLIST_SUB=	VERSION="${PORTVERSION}"

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	ninenines

do-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/ebin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/ebin/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/src

.include <bsd.port.mk>
