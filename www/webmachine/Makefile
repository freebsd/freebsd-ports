# $FreeBSD$

PORTNAME=	webmachine
PORTVERSION=	1.10.5
CATEGORIES=	www devel

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
GH_COMMIT=      4e2d89c
GH_TAGNAME=     ${PORTVERSION}

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e "s/{vsn, git}/{vsn,\"${PORTVERSION}\"}/" ${WRKSRC}/src/webmachine.app.src
	@${RM} ${WRKSRC}/src/*.bak

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	for FILE in README.org; do \
		${INSTALL_DATA} ${WRKSRC}/$${FILE} ${STAGEDIR}${DOCSDIR}; \
	done
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/demo && ${COPYTREE_SHARE} \* ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/webmachine-${PORTVERSION}
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/webmachine-${PORTVERSION}/ebin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/webmachine-${PORTVERSION}/include
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/webmachine-${PORTVERSION}/priv
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/webmachine-${PORTVERSION}/src
	${INSTALL_DATA} ${WRKSRC}/ebin/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/webmachine-${PORTVERSION}/ebin
	${INSTALL_DATA} ${WRKSRC}/include/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/webmachine-${PORTVERSION}/include
	${INSTALL_DATA} ${WRKSRC}/src/* ${STAGEDIR}${PREFIX}/lib/erlang/lib/webmachine-${PORTVERSION}/src
	cd ${WRKSRC}/priv && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/lib/erlang/lib/webmachine-${PORTVERSION}/priv

.include <bsd.port.mk>
