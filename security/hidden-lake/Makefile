PORTNAME=	hidden-lake
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.0
PORTREVISION=	1
CATEGORIES=	security net-p2p

MAINTAINER=	alven@FreeBSD.org
COMMENT=	F2F Anonymous network based on the QB-problem & GP/12 protocol stack
WWW=		https://github.com/number571/hidden-lake/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/number571/hidden-lake
GO_TARGET=	./cmd/hla/hla-http:hla-http \
		./cmd/hla/hla-tcp:hla-tcp \
		./cmd/hlc:hlc \
		./cmd/hlk:hlk \
		./cmd/hls/hls-filesharer:hls-filesharer \
		./cmd/hls/hls-messenger:hls-messenger \
		./cmd/hls/hls-pinger:hls-pinger \
		./cmd/hls/hls-remoter:hls-remoter

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
