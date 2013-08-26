# $FreeBSD$

PORTNAME=	cowboy
PORTVERSION=	0.8.6
CATEGORIES=	www
MASTER_SITES=	GH

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Small, fast and modular HTTP server written in Erlang

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang \
		ranch>=0:${PORTSDIR}/net/ranch

PLIST_SUB=	VERSION="${PORTVERSION}"

USE_GMAKE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	extend
GH_PROJECT=	cowboy
GH_COMMIT=	9eaee45
GH_TAGNAME=	${PORTVERSION}

PORTDOCS=	*

.include <bsd.port.options.mk>

do-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/guide/* ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif
	@${MKDIR} ${PREFIX}/lib/erlang/lib/cowboy-${PORTVERSION}
	@${MKDIR} ${PREFIX}/lib/erlang/lib/cowboy-${PORTVERSION}/ebin
	@${MKDIR} ${PREFIX}/lib/erlang/lib/cowboy-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/ebin/* ${PREFIX}/lib/erlang/lib/cowboy-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/src/* ${PREFIX}/lib/erlang/lib/cowboy-${PORTVERSION}/src

.include <bsd.port.mk>
