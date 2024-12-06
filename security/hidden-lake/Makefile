PORTNAME=	hidden-lake
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.7
CATEGORIES=	security net-p2p

MAINTAINER=	alster@vinterdalen.se
COMMENT=	F2F Anonymous network based on the QB-problem
WWW=		https://github.com/number571/hidden-lake/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules

GO_MODULE=	github.com/number571/hidden-lake
GO_TARGET=	./cmd/hla/common:hla \
		./cmd/hle:hlc \
		./cmd/hle:hle \
		./cmd/hlf:hlf \
		./cmd/hll:hll \
		./cmd/hlm:hlm \
		./cmd/hlr:hlr \
		./cmd/hls:hls \
		./cmd/hlt:hlt

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
