# $FreeBSD$

PORTNAME=	mochiweb
PORTVERSION=	2.6.0
CATEGORIES=	www devel
MASTER_SITES=	GH

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Erlang library for building lightweight HTTP servers

LICENSE=	MIT

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

CONFLICTS=	mochiweb-basho-[0-9]*

PLIST_SUB=	VERSION="${PORTVERSION}"

USE_GITHUB=	yes
GH_ACCOUNT=	mochi
GH_PROJECT=	mochiweb
GH_COMMIT=	92b8f5b
GH_TAGNAME=	v${PORTVERSION}

PORTDOCS=	*

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@for FILE in CHANGES.md README; do \
		${INSTALL_DATA} ${WRKSRC}/$${FILE} ${DOCSDIR}; \
	done
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}
.endif
	@${MKDIR} ${PREFIX}/lib/erlang/lib/mochiweb-${PORTVERSION}
	@${MKDIR} ${PREFIX}/lib/erlang/lib/mochiweb-${PORTVERSION}/ebin
	@${MKDIR} ${PREFIX}/lib/erlang/lib/mochiweb-${PORTVERSION}/include
	@${MKDIR} ${PREFIX}/lib/erlang/lib/mochiweb-${PORTVERSION}/src
	@${INSTALL_DATA} ${WRKSRC}/ebin/* ${PREFIX}/lib/erlang/lib/mochiweb-${PORTVERSION}/ebin
	@${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/lib/erlang/lib/mochiweb-${PORTVERSION}/include
	@${INSTALL_DATA} ${WRKSRC}/src/* ${PREFIX}/lib/erlang/lib/mochiweb-${PORTVERSION}/src

.include <bsd.port.mk>
