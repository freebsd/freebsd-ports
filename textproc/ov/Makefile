PORTNAME=	ov
DISTVERSIONPREFIX=	v
DISTVERSION=	0.54.0
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Feature rich terminal pager
WWW=		https://github.com/noborus/ov

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

_BUILD_VERSION=		${DISTVERSION}
_BUILD_REVISION=	0a791c8

GO_MODULE=	github.com/noborus/${PORTNAME}
GO_LDFLAGS=	-w \
		-X main.Version=${_BUILD_VERSION} \
		-X main.Revision=${_BUILD_REVISION}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md
PORTEXAMPLES=	${PORTNAME}-disable-default.yaml \
		${PORTNAME}-less.yaml \
		${PORTNAME}.yaml

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} \
		${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/|} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
