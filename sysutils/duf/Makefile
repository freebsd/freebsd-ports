PORTNAME=	duf
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Disk Usage/Free Utility
WWW=		https://github.com/muesli/duf

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

_BUILD_VERSION=	${DISTVERSION}
_BUILD_SHA=	b2f01a1

GO_MODULE=	github.com/muesli/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X main.Version=${_BUILD_VERSION} \
		-X main.CommitSHA=${_BUILD_SHA}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

PORTSCOUT=	skipv:v0.37.0

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
