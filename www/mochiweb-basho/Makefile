# $FreeBSD$

PORTNAME=	mochiweb
PORTVERSION=	1.5.1p5
CATEGORIES=	www devel
MASTER_SITES=	GH
PKGNAMESUFFIX=	-basho

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Erlang library for building lightweight HTTP servers (Basho fork)

LICENSE=	MIT

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

CONFLICTS=	mochiweb-[0-9]*

PLIST_SUB=	VERSION="${PORTVERSION}"

USE_GITHUB=	yes
GH_ACCOUNT=	basho
GH_PROJECT=	mochiweb
GH_COMMIT=	b7c3f8f
GH_TAGNAME=	${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif

do-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@for FILE in README; do \
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

.include <bsd.port.post.mk>
