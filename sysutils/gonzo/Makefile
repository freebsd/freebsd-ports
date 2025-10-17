PORTNAME=	gonzo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
CATEGORIES=	sysutils

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	TUI for log analysis
WWW=		https://www.controltheory.com/gonzo/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules

#NOT_FOR_ARCHS=	armv6 armv7 i386

_BUILD_DATE=	$$(date -u +"%FT%T%z")
_BUILD_HASH=	6d2d1ad

GO_MODULE=	github.com/control-theory/${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X main.version=${DISTVERSION} \
		-X main.buildTime=${_BUILD_DATE} \
		-X main.commit=${_BUILD_HASH}"

PLIST_FILES=	bin/${PORTNAME}
_DOCS=		CONTRIBUTING.md README.md USAGE_GUIDE.md
PORTDOCS=	${_DOCS:T}
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${_DOCS} \
		${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
