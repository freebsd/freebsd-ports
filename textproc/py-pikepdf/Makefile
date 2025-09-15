PORTNAME=	pikepdf
DISTVERSION=	9.9.0
PORTREVISION=	3
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Read and write PDFs with Python, powered by qpdf
WWW=		https://github.com/pikepdf/pikepdf

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>=2.10.1:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.37:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libqpdf.so:print/qpdf
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}deprecated>0:devel/py-deprecated@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=4.8:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=10.0.1:graphics/py-pillow@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=20.2.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.8.0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>=0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5<6:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>=2.6.0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=4.4.0,1<7.3.5,1:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-helpers-namespace>=2019.1.8:devel/py-pytest-helpers-namespace@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>=1.3.3:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=1.28:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}python-xmp-toolkit>=2.0.1:textproc/py-python-xmp-toolkit@${PY_FLAVOR}

USES=		compiler:c++14-lang cpe localbase python
USE_PYTHON=	autoplist pep517

CPE_VENDOR=	pikepdf_project

TEST_ENV=	LC_ALL=en_US.UTF-8

OPTIONS_DEFINE=	JBIG2
OPTIONS_DEFAULT=	JBIG2

JBIG2_DESC=	Support for extracting JBIG2 images

JBIG2_RUN_DEPENDS=	jbig2dec:graphics/jbig2dec

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pikepdf/_*.so

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -rs -v -o addopts=

.include <bsd.port.mk>
