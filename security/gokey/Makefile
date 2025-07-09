PORTNAME=	gokey
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.3
PORTREVISION=	3
CATEGORIES=	security

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple password manager write in Go
WWW=		https://github.com/cloudflare/gokey

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/cloudflare/gokey
GO_TARGET=	./cmd/gokey

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
