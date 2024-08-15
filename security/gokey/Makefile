PORTNAME=	gokey
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.2
PORTREVISION=	16
CATEGORIES=	security

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple password manager write in Go
WWW=		https://github.com/cloudflare/gokey

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	nodefault
GH_TUPLE=	golang:sys:v0.6.0:sys

GO_MODULE=	github.com/cloudflare/gokey
GO_TARGET=	./cmd/gokey

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

pre-build:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
