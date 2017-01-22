# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	stix
PORTVERSION=	1.2.0.2
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python library for parsing, manipulating, and generating STIX content

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.3:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}cybox>=2.1.0.11:security/py-cybox \
		${PYTHON_PKGNAMEPREFIX}mixbox>=1.0.1:security/py-mixbox
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}maec>=4.1.0.13:security/py-maec

NO_ARCH=	yes
USES=		python
USE_PYTHON=	distutils autoplist

PORTDOCS=	README.rst
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} nosetests-${PYTHON_VER})

.include <bsd.port.mk>
