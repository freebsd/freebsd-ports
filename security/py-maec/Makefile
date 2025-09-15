PORTNAME=	maec
PORTVERSION=	4.1.0.17
PORTREVISION=	3
DISTVERSIONPREFIX=	v
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python library for parsing, manipulating, and generating MAEC content
WWW=		https://github.com/MAECProject/python-maec

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=2.2.3:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cybox>=2.1.0.13:security/py-cybox@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mixbox>=0.0.13:security/py-mixbox@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	MAECProject
GH_PROJECT=	python-${PORTNAME}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	concurrent distutils autoplist
USE_LOCALE=	en_US.UTF-8

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
