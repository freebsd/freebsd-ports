PORTNAME=	hostctl
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.4
PORTREVISION=	15
CATEGORIES=	sysutils

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Command-line tool to manage your hosts file
WWW=		https://guumaster.github.io/hostctl/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/guumaster/${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X ${GO_MODULE}/cmd/${PORTNAME}/actions.version=${DISTVERSION}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CODE_OF_CONDUCT.md CONTRIBUTING.md README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
