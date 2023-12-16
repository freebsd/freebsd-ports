PORTNAME=	osv-scanner
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.3
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Vulnerability scanner written in Go which uses the OSV database
WWW=		https://github.com/google/osv-scanner

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

_BUILD_VERSION=	${DISTVERSION}
_BUILD_COMMIT=	6316373
_BUILD_DATE=	$$(date +%Y-%m-%d)

GO_MODULE=	github.com/google/${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X main.version=${_BUILD_VERSION} \
		-X main.date=${_BUILD_DATE} \
		-X main.commit=${_BUILD_COMMIT}"

PORTDOCS=	README.md
PLIST_FILES=	${GO_TARGET:C/.\/cmd/bin/}

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
