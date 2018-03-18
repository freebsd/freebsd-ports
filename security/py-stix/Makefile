# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	stix
PORTVERSION=	1.2.0.5
DISTVERSIONPREFIX=	v
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python library for parsing, manipulating, and generating STIX content

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.3:devel/py-lxml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cybox>=2.1.0.13:security/py-cybox@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mixbox>=1.0.2:security/py-mixbox@${FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}maec>=4.1.0.13:security/py-maec@${FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	STIXProject
GH_PROJECT=	python-${PORTNAME}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	concurrent distutils autoplist

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
