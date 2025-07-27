PORTNAME=	acme-tiny
DISTVERSION=	4.1.0
CATEGORIES=	security python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tiny script to issue and renew TLS certs from Let's Encrypt
WWW=		https://github.com/diafygi/acme-tiny

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python shebangfix ssl

USE_GITHUB=	yes
GH_ACCOUNT=	diafygi

SHEBANG_FILES=	acme_tiny.py

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/acme_tiny

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

DOCS_SUB_FILES=	pkg-message

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/acme_tiny.py ${STAGEDIR}${PREFIX}/bin/acme_tiny

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
