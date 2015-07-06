# $FreeBSD$

PORTNAME=	webmachine
PORTVERSION=	1.10.8
CATEGORIES=	www devel
PKGNAMEPREFIX=	erlang-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	HTTP semantic awareness on top mochiweb

LICENSE=	APACHE20

BUILD_DEPENDS=	erl:${PORTSDIR}/lang/erlang \
		erlang-mochiweb-basho>=2.9.0p1:${PORTSDIR}/www/erlang-mochiweb-basho
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_SUB=      VERSION="${PORTVERSION}"

USES=		gmake
USE_GITHUB=     yes
GH_ACCOUNT=     basho

post-patch:
	@${REINPLACE_CMD} -i '' -e 's/{ *vsn, git *}/{vsn, "${PORTVERSION}"}/' ${WRKSRC}/src/*.app.src
	@${RM} ${WRKSRC}/demo/priv/www/uploads/.gitignore

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	for FILE in README.org; do \
		${INSTALL_DATA} ${WRKSRC}/$${FILE} ${STAGEDIR}${DOCSDIR}; \
	done
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/demo && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/ebin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/include
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/priv
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/ebin/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/include/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/include
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/src
	cd ${WRKSRC}/priv && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}/priv

.include <bsd.port.mk>
