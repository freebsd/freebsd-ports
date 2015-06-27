# $FreeBSD$

PORTNAME=	mochiweb
PORTVERSION=	2.9.0p1
CATEGORIES=	www devel
PKGNAMEPREFIX=	erlang-
PKGNAMESUFFIX=	-basho

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Erlang library for building lightweight HTTP servers (Basho fork)

LICENSE=	MIT

BUILD_DEPENDS=	erl:${PORTSDIR}/lang/erlang
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS=	mochiweb-[0-9]*

PLIST_SUB=	VERSION="${PORTVERSION}"

USE_GITHUB=	yes
GH_ACCOUNT=	basho
GH_TAGNAME=	ade2a9b	# required

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	for FILE in CHANGES.md README.md; do \
		${INSTALL_DATA} ${WRKSRC}/$${FILE} ${STAGEDIR}${DOCSDIR}; \
	done
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/ebin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/include
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/ebin/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/include/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/include
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/src

.include <bsd.port.mk>
