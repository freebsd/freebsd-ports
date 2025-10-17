PORTNAME=	extruct
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.0
CATEGORIES=	www python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extract embedded metadata from HTML markup
WWW=		https://github.com/scrapinghub/extruct

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml-html-clean>=0:devel/py-lxml-html-clean@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rdflib>=6.0.0:textproc/py-rdflib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyRdfa3>0:textproc/py-pyRdfa3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mf2py>0:textproc/py-mf2py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}w3lib>0:www/py-w3lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html-text>=0.5.1:textproc/py-html-text@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jstyleson>0:devel/py-jstyleson@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist concurrent pytest

USE_GITHUB=	yes
GH_ACCOUNT=	scrapinghub

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -rs -v tests/

# tests as of 0.18.0: 70 passed in 7.17s

.include <bsd.port.mk>
