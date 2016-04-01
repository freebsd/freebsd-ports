# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	googlecl
PORTVERSION=	0.9.14
CATEGORIES=	net www python
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Command line tools for the Google Data APIs

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gdata>0:devel/py-gdata

USES=		python:2
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	man/man1/google.1.gz
PORTDOCS=	*

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/google.1 ${STAGEDIR}${MANPREFIX}/man/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
