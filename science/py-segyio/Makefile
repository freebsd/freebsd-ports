PORTNAME=	segyio
DISTVERSION=	1.9.9
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for segyio, the seismic data library

LICENSE=	LGPL3+

BUILD_DEPENDS=	cmake:devel/cmake \
		pybind11>0:devel/pybind11 \
		${PYTHON_PKGNAMEPREFIX}distro>0:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build>0:devel/py-scikit-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR}
LIB_DEPENDS=	libsegyio.so:science/segyio
RUN_DEPENDS=	${PYNUMPY}

USES=		compiler:c++11-lang python:3.6+
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	equinor

WRKSRC_SUBDIR=	python

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/segyio/_segyio*.so

do-test: # tests fail: https://github.com/equinor/segyio/issues/511
	@cd ${WRKSRC} && \
		${PYTHON_CMD} ${PYSETUP} build_ext --inplace && \
		${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
