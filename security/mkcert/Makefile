PORTNAME=	mkcert
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.4
CATEGORIES=	security

MAINTAINER=	owlandrews@protonmail.com
COMMENT=	Simple tool for making locally-trusted development certificates
WWW=		https://mkcert.dev

LICENSE=	BSD3CLAUSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	FiloSottile

GO_MOD_DIST=	github
GO_MODULE=	filippo.io/mkcert

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

pre-configure:
	@${CP} ${FILESDIR}/truststore_freebsd.go ${WRKSRC}/truststore_freebsd.go

do-install-DOCS-on:
	        ${MKDIR} ${STAGEDIR}${DOCSDIR}
		        ${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
