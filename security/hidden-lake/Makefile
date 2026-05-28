PORTNAME=	hidden-lake
DISTVERSIONPREFIX=	v
DISTVERSION=	1.11.1
CATEGORIES=	security net-p2p

MAINTAINER=	alven@FreeBSD.org
COMMENT=	F2F Anonymous network based on the QB-problem & GP/12 protocol stack
WWW=		https://github.com/number571/hidden-lake/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/number571/hidden-lake
GO_TARGET=	./cmd/hla/hla-http:hla-http \
		./cmd/hla/hla-https:hla-https \
		./cmd/hla/hla-tcp:hla-tcp \
		./cmd/hlc:hlc \
		./cmd/hlk:hlk \
		./cmd/hls/hls-filesharer:hls-filesharer \
		./cmd/hls/hls-messenger:hls-messenger \
		./cmd/hls/hls-pinger:hls-pinger

TEST_TARGET=	test-run

PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${INSTALL_DATA} *.md *.pdf *.svg ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
