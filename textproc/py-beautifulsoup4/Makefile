# Created by: Carlos J. Puga Medina <cpm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	beautifulsoup4
PORTVERSION=	4.4.1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Python screen-scraping library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING.txt

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
DOCS_PORTDOCS=	*
DOCS_VARS=	PYDISTUTILS_BUILD_TARGET=build_ext

USES=		python:3
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-build-DOCS-on:
	(cd ${WRKSRC}/doc ; ${MAKE} html)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/build/html && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name .buildinfo -and ! -name objects.inv")

.include <bsd.port.mk>
