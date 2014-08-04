# $FreeBSD$

PORTNAME=	cowboy
PORTVERSION=	1.0.0
CATEGORIES=	www

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Small, fast and modular HTTP server written in Erlang

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang \
		cowlib>=1.0.0:${PORTSDIR}/devel/cowlib
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang \
		cowlib>=1.0.0:${PORTSDIR}/devel/cowlib \
		ranch>=1.0.0:${PORTSDIR}/net/ranch

PLIST_SUB=	VERSION="${PORTVERSION}"

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	ninenines
GH_PROJECT=	cowboy
GH_COMMIT=	021f4f6
GH_TAGNAME=	${PORTVERSION}

do-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/cowboy-${PORTVERSION}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/cowboy-${PORTVERSION}/ebin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/cowboy-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/ebin/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/cowboy-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/cowboy-${PORTVERSION}/src

.include <bsd.port.mk>
