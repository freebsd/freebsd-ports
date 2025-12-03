PORTNAME=	gokey
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Simple password manager write in Go
WWW=		https://github.com/cloudflare/gokey

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/go-md2man:textproc/go-md2man

USES=		go:modules

GO_MODULE=	github.com/cloudflare/gokey
GO_TARGET=	./cmd/gokey

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-build:
	go-md2man -in=${WRKSRC}/gokey.1.md -out=${WRKSRC}/gokey.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install:
	${INSTALL_MAN} ${WRKSRC}/gokey.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
