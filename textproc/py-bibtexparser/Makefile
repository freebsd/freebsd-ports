PORTNAME=	bibtexparser
DISTVERSION=	2.0.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Bibtex parser
WWW=		https://github.com/sciunto-org/python-bibtexparser

LICENSE=	BSD3CLAUSE LGPL3
LICENSE_COMB=	dual

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pylatexenc>=2.10:textproc/py-pylatexenc@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

#PYTEST_BROKEN_TESTS=	test_sort_order_custom_case_sensitive
TEST_ARGS=	--disable-plugin-autoload \
		-k "not test_sort_order_custom_case_sensitive" \
		-p pytest_cov \
		-p xdist

# tests as of 2.0.1: 2776 passed, 12 skipped, 1 deselected, 4 warnings in 5.38s

.include <bsd.port.mk>
