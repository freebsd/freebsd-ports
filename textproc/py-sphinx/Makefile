PORTNAME=	sphinx
PORTVERSION=	9.0.4
PORTEPOCH=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

# NOTE: before committing to this port, contact portmgr to arrange for an
# experimental ports run.  Untested commits may be backed out at portmgr's
# discretion.
MAINTAINER=	python@FreeBSD.org
COMMENT=	Python documentation generator
WWW=		https://www.sphinx-doc.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.7:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinxcontrib-applehelp>=1.0.7:textproc/py-sphinxcontrib-applehelp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-devhelp>=1.0.6:textproc/py-sphinxcontrib-devhelp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-jsmath>=1.0.1:textproc/py-sphinxcontrib-jsmath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-htmlhelp>=2.0.6:textproc/py-sphinxcontrib-htmlhelp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-serializinghtml>=1.1.9:textproc/py-sphinxcontrib-serializinghtml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-qthelp>=1.0.6:textproc/py-sphinxcontrib-qthelp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.17:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.21,1<0.23,1:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}snowballstemmer>=2.2:textproc/py-snowballstemmer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Babel>=2.13:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}alabaster>=0.7.14<0.8:textproc/py-alabaster@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}imagesize>=1.3:graphics/py-imagesize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.30.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}roman-numerals>=1.0.0:textproc/py-roman-numerals@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=23.0:devel/py-packaging@${PY_FLAVOR} \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defusedxml>=0:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=3.4:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=70.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.9:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python:3.11+
USE_PYTHON=	autoplist concurrent pep517 pytest

PYTEST_BROKEN_TESTS=	test_copy_images

NO_ARCH=	yes

.include <bsd.port.mk>
