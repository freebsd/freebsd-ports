PORTNAME=	siphash24
DISTVERSION=	1.8
CATEGORIES=	security devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Streaming-capable SipHash-1-3 and SipHash-2-4 Implementation
WWW=		https://pypi.org/project/siphash24/

LICENSE=	APACHE20 LGPL21+
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSES/Apache-2.0.txt
LICENSE_FILE_LGPL21+ =	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

BUILD_DEPENDS=	${LOCALBASE}/include/c-stdaux.h:devel/c-stdaux \
		${PYTHON_PKGNAMEPREFIX}meson-python>=0.18.0:devel/meson-python@${PY_FLAVOR}
LIB_DEPENDS=	libcsiphash-1.so:security/c-siphash

USES=		compiler:c11 pkgconfig python
USE_PYTHON=	autoplist concurrent cython pep517 pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

BINARY_ALIAS=	cython=cython-${PYTHON_VER}

do-test:
	(cd ${WRKSRC} && \
		${SETENV} ${TEST_ENV} ${PYTHON_CMD} ./test.py)

.include <bsd.port.mk>
