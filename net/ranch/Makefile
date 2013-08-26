# $FreeBSD$

PORTNAME=	ranch
PORTVERSION=	0.8.5
CATEGORIES=	net
MASTER_SITES=	GH

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Erlang socket acceptor pool for TCP protocols

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

PLIST_SUB=	VERSION="${PORTVERSION}"

USE_GMAKE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	extend
GH_PROJECT=	ranch
GH_COMMIT=	4170575
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
	@${MKDIR} ${PREFIX}/lib/erlang/lib/ranch-${PORTVERSION}
	@${MKDIR} ${PREFIX}/lib/erlang/lib/ranch-${PORTVERSION}/ebin
	@${MKDIR} ${PREFIX}/lib/erlang/lib/ranch-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/ebin/* ${PREFIX}/lib/erlang/lib/ranch-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/src/* ${PREFIX}/lib/erlang/lib/ranch-${PORTVERSION}/src

.include <bsd.port.mk>
