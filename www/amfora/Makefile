PORTNAME=	amfora
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.0
PORTREVISION=	11
CATEGORIES=	www

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Fancy terminal browser for the Gemini protocol
WWW=		https://github.com/makeworld-the-better-one/amfora

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

_BUILD_VERSION=	${DISTVERSIONFULL}
_BUILD_COMMIT=	61d8645

GO_MODULE=	github.com/makeworld-the-better-one/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X main.version=${_BUILD_VERSION} \
		-X main.commit=${_BUILD_COMMIT}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	NOTES.md README.md THANKS.md
PORTEXAMPLES=	default-config.toml

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
