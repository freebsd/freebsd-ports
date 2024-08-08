PORTNAME=	sphinx
PORTVERSION=	5.3.0
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Sphinx-${PORTVERSION}
DIST_SUBDIR=	python

# NOTE: before committing to this port, contact portmgr to arrange for an
# experimental ports run.  Untested commits may be backed out at portmgr's
# discretion.
MAINTAINER=	python@FreeBSD.org
COMMENT=	Python documentation generator
WWW=		https://www.sphinx-doc.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.7:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinxcontrib-applehelp>=0:textproc/py-sphinxcontrib-applehelp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-devhelp>=0:textproc/py-sphinxcontrib-devhelp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-jsmath>=0:textproc/py-sphinxcontrib-jsmath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-htmlhelp>=2.0.0:textproc/py-sphinxcontrib-htmlhelp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-serializinghtml>=1.1.5:textproc/py-sphinxcontrib-serializinghtml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-qthelp>=0:textproc/py-sphinxcontrib-qthelp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.12:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.14,1<0.22,1:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}snowballstemmer>=2.0:textproc/py-snowballstemmer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Babel>=2.9:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}alabaster>=0.7<0.8:textproc/py-alabaster@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}imagesize>=1.3:graphics/py-imagesize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.5.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=21.0:devel/py-packaging@${PY_FLAVOR} \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}html5lib>=0:www/py-html5lib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython_test pep517 pytest

NO_ARCH=	yes
PYTEST_BROKEN_TESTS=	test_anchors_ignored \
			test_defaults \
			test_defaults_json \
			test_ext_imgconverter \
			test_latex_images

# Upstream archive contains files with UTF-8 names (#246618)
# https://github.com/sphinx-doc/sphinx/issues/2395
EXTRACT_CMD=	${SETENV} LC_ALL=en_US.UTF-8 /usr/bin/bsdtar

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=4.8:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
