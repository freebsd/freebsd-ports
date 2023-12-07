PORTNAME=	gokart
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.1
PORTREVISION=	10
CATEGORIES=	security

MAINTAINER=	nulldutra@proton.me
COMMENT=	Go Security Static Analysis
WWW=		https://github.com/praetorian-inc/gokart

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/praetorian-inc/gokart
GO_TARGET=	gokart

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
