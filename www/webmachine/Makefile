# $FreeBSD$

PORTNAME=	webmachine
PORTVERSION=	1.10.8
CATEGORIES=	www devel

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	HTTP semantic awareness on top mochiweb

LICENSE=	APACHE20

BUILD_DEPENDS=	erl:${PORTSDIR}/lang/erlang \
		mochiweb-basho>=2.9.0p1:${PORTSDIR}/www/mochiweb-basho
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_SUB=      VERSION="${PORTVERSION}"

USES=		gmake
USE_GITHUB=     yes
GH_ACCOUNT=     basho

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e "s/{vsn, git}/{vsn,\"${PORTVERSION}\"}/" ${WRKSRC}/src/webmachine.app.src
	@${RM} ${WRKSRC}/src/*.bak
	@${RM} ${WRKSRC}/demo/priv/www/uploads/.gitignore

do-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	for FILE in README.org; do \
		${INSTALL_DATA} ${WRKSRC}/$${FILE} ${STAGEDIR}${DOCSDIR}; \
	done
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/demo && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}
.endif
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
