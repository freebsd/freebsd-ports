# $FreeBSD$

PORTNAME=	webmachine
PORTVERSION=	1.10.1
CATEGORIES=	www devel
MASTER_SITES=	GH

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	HTTP semantic awareness on top mochiweb

LICENSE=	AL2

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang \
		mochiweb-basho>=0:${PORTSDIR}/www/mochiweb-basho
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang \
		mochiweb-basho>=0:${PORTSDIR}/www/mochiweb-basho

PLIST_SUB=      VERSION="${PORTVERSION}"

USE_GITHUB=     yes
GH_ACCOUNT=     basho
GH_PROJECT=     webmachine
GH_COMMIT=      d600c0e
GH_TAGNAME=     ${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif

do-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@for FILE in README.org; do \
		${INSTALL_DATA} ${WRKSRC}/$${FILE} ${DOCSDIR}; \
	done
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/demo && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}
.endif
	@${MKDIR} ${PREFIX}/lib/erlang/lib/webmachine-${PORTVERSION}
	@${MKDIR} ${PREFIX}/lib/erlang/lib/webmachine-${PORTVERSION}/ebin
	@${MKDIR} ${PREFIX}/lib/erlang/lib/webmachine-${PORTVERSION}/include
	@${MKDIR} ${PREFIX}/lib/erlang/lib/webmachine-${PORTVERSION}/priv
	@${MKDIR} ${PREFIX}/lib/erlang/lib/webmachine-${PORTVERSION}/src
	@${INSTALL_DATA} ${WRKSRC}/ebin/* ${PREFIX}/lib/erlang/lib/webmachine-${PORTVERSION}/ebin
	@${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/lib/erlang/lib/webmachine-${PORTVERSION}/include
	@${INSTALL_DATA} ${WRKSRC}/src/* ${PREFIX}/lib/erlang/lib/webmachine-${PORTVERSION}/src
	@cd ${WRKSRC}/priv && ${COPYTREE_SHARE} \* ${PREFIX}/lib/erlang/lib/webmachine-${PORTVERSION}/priv

.include <bsd.port.post.mk>
