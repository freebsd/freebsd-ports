# $FreeBSD$

PORTNAME=	cowboy
PORTVERSION=	0.10.0
CATEGORIES=	www

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Small, fast and modular HTTP server written in Erlang

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang \
		cowlib>=0.6.2:${PORTSDIR}/devel/cowlib
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang \
		cowlib>=0.6.2:${PORTSDIR}/devel/cowlib \
		ranch>=0.10.0:${PORTSDIR}/net/ranch

PLIST_SUB=	VERSION="${PORTVERSION}"

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	extend
GH_PROJECT=	cowboy
GH_COMMIT=	ee3ad5e
GH_TAGNAME=	${PORTVERSION}

PORTDOCS=	*

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/guide/* ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/cowboy-${PORTVERSION}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/cowboy-${PORTVERSION}/ebin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/cowboy-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/ebin/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/cowboy-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/cowboy-${PORTVERSION}/src

.include <bsd.port.mk>
