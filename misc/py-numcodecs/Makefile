PORTNAME=	numcodecs
DISTVERSION=	0.16.5
PORTREVISION=	1
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package providing buffer compression and transformation codecs for use
WWW=		https://numcodecs.readthedocs.io/en/stable/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.24:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}py-cpuinfo>0:sysutils/py-py-cpuinfo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.24:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zfp>0:devel/py-zfp@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzstd>=0:archivers/py-pyzstd@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils cython autoplist pytest
# tests as of 0.16.5
CXXFLAGS_i386=	-msse2 # otherwise it fails to compile: #error SSE2 is not supported by the target architecture/platform and/or this compiler.

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/numcodecs/tests

OPTIONS_DEFINE=		AVX2

AVX2_DESC=		Use AVX2 SIMD instructions
AVX2_CONFIGURE_ENV_OFF=	DISABLE_NUMCODECS_AVX2=yes
AVX2_MAKE_ENV_OFF=	DISABLE_NUMCODECS_AVX2=yes

.include <bsd.port.options.mk>

.if ${ARCH} == i386
MAKE_ENV+=	DISABLE_NUMCODECS_SSE2=yes DISABLE_NUMCODECS_AVX2=yes
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/numcodecs/*${PYTHON_TAG}.so

.include <bsd.port.mk>
