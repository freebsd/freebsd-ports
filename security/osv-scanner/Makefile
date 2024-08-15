PORTNAME=	osv-scanner
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.2
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Vulnerability scanner written in Go which uses the OSV database
WWW=		https://github.com/google/osv-scanner

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.21,modules

_BUILD_VERSION=	${DISTVERSION}
_BUILD_COMMIT=	1ea785e
_BUILD_DATE=	$$(date +%Y-%m-%d)

GO_MODULE=	github.com/google/${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X main.version=${_BUILD_VERSION} \
		-X main.date=${_BUILD_DATE} \
		-X main.commit=${_BUILD_COMMIT}"

PORTDOCS=	CHANGELOG.md CONTRIBUTING.md README.md
PLIST_FILES=	${GO_TARGET:C/.\/cmd/bin/}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,%%GO_SUFFIX%%,${GO_SUFFIX},' \
		${WRKSRC}/internal/sourceanalysis/go.go

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
