PORTNAME=	hidden-lake
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.6
PORTREVISION=	1
CATEGORIES=	security net-p2p

MAINTAINER=	alster@vinterdalen.se
COMMENT=	F2F Anonymous network based on the QB-problem & GP/12 protocol stack
WWW=		https://github.com/number571/hidden-lake/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/number571/hidden-lake
GO_TARGET=	./cmd/hla/hla_tcp:hla_tcp \
		./cmd/hlc:hlc \
		./cmd/hlf:hlf \
		./cmd/hlm:hlm \
		./cmd/hlp:hlp \
		./cmd/hlr:hlr \
		./cmd/hls:hls

TEST_TARGET=	test-run

PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.md  ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.pdf ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
