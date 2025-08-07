PORTNAME=	git-chglog
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15.4
PORTREVISION=	17
CATEGORIES=	textproc

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	CHANGELOG generator implemented in Go
WWW=		https://github.com/git-chglog/git-chglog

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:modules
GO_MODULE=	github.com/${PORTNAME}/${PORTNAME}

_BUILD_VERSION=	${DISTVERSIONFULL}

GO_MODULE=	github.com/${PORTNAME}/${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X main.version=${_BUILD_VERSION}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md CONTRIBUTING.md README.md
_EXAMPLES=	.chglog/CHANGELOG.tpl.md .chglog/config.yml
PORTEXAMPLES=	${_EXAMPLES:T}

OPTIONS_DEFINE=	DOCS EXAMPLES
EXAMPLES_DESC=	Install example template format and configuration

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${_EXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
