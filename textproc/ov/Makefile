PORTNAME=	ov
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15.0
PORTREVISION=	17
CATEGORIES=	textproc

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Feature rich terminal pager
WWW=		https://github.com/noborus/ov

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

_BUILD_VERSION=		${DISTVERSIONFULL}
_BUILD_REVISION=	dc0b5ca

GO_MODULE=	github.com/noborus/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X main.Version=${_BUILD_VERSION} \
		-X main.Revision=${_BUILD_REVISION}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md
PORTEXAMPLES=	${PORTNAME}-disable-default.yaml ${PORTNAME}-less.yaml \
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
