PORTNAME=	segyio
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.14
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for segyio, the seismic data library
WWW=		https://github.com/equinor/segyio

LICENSE=	LGPL3+

BUILD_DEPENDS=	cmake:devel/cmake-core \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0:devel/py-scikit-build-core@${PY_FLAVOR}
LIB_DEPENDS=	libsegyio.so:science/segyio
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}

USES=		compiler:c++11-lang python
USE_PYTHON=	autoplist pep517 pytest

USE_GITHUB=	yes
GH_ACCOUNT=	equinor

WRKSRC_SUBDIR=	python

TEST_ARGS=	--ignore=test/benchmarks.py --ignore=test/large.py --ignore=test/stream.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/segyio/_segyio*.so

# tests as of 1.9.14: 209 passed, 8 warnings in 3.22s

.include <bsd.port.mk>
