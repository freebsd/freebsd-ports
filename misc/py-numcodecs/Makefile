PORTNAME=	numcodecs
DISTVERSION=	0.17.0
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package providing buffer compression and transformation codecs for use
WWW=		https://numcodecs.readthedocs.io/en/stable/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}meson-python>=0.17:devel/meson-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=2:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=2:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}crc32c>=2.7:devel/py-crc32c@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-crc32c>=1.5:devel/py-google-crc32c@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pcodec>=1:math/py-pcodec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzstd>=0:archivers/py-pyzstd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zfp>0:devel/py-zfp@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist cython pep517 pytest

SHEBANG_FILES=	src/numcodecs/_build_utils/gitversion.py

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload -p pytest_cov

OPTIONS_DEFINE=		AVX2

AVX2_DESC=		Use AVX2 SIMD instructions
AVX2_VARS_OFF=		PEP517_BUILD_CONFIG_SETTING+="-Csetup-args=-Davx2=disabled"

.include <bsd.port.options.mk>

.if ${ARCH} == i386
PEP517_BUILD_CONFIG_SETTING+=	"-Csetup-args=-Dsse2=disabled" \
				"-Csetup-args=-Davx2=disabled"
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/numcodecs/*${PYTHON_TAG}.so

# tests as of 0.17.0: 862 passed, 22 skipped in 5.15s

.include <bsd.port.mk>
