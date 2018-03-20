# Created by: mat
# $FreeBSD$

PORTNAME=	acme-tiny
DISTVERSION=	4.0.3
CATEGORIES=	security python

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Tiny script to issue and renew TLS certs from Let's Encrypt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python shebangfix ssl
SHEBANG_FILES=	acme_tiny.py

USE_GITHUB=	yes
GH_ACCOUNT=	diafygi

NO_BUILD=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/acme_tiny

OPTIONS_DEFINE=	DOCS

DOCS_SUB_FILES=	pkg-message
PORTDOCS=	README.md

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/acme_tiny.py ${STAGEDIR}${PREFIX}/bin/acme_tiny

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
