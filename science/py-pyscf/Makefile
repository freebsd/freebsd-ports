PORTNAME=	pyscf
DISTVERSIONPREFIX=	v
DISTVERSION=	2.14.0
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python module for quantum chemistry
WWW=		https://pyscf.org/ \
		https://github.com/pyscf/pyscf

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake-core \
		${PYTHON_PKGNAMEPREFIX}h5py>=2.7:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.13:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.6.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libcint.so:science/libcint \
		libxc.so:science/libxc \
		libxcfun.so:science/xcfun
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h5py>=2.7:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.13:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.6.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}

USES=		fortran blaslapack:openblas compiler:c++11-lang gmake python
USE_PYTHON=	distutils autoplist pytest
USE_GITHUB=	yes

POST_PLIST=	fix-plist

TEST_ENV=	${MAKE_ENV} \
		LD_LIBRARY_PATH= \
		PYTHONPATH=${FILESDIR}:${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/pyscf
TEST_ARGS=	--disable-plugin-autoload \
		--ignore=lib/vhf/test/test_nr_direct.py \
		--ignore=mcpdft/test/test_otfnal.py \
		--ignore=mcpdft/test/test_otpd.py \
		-c ${WRKSRC}/pytest.ini

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pyscf/lib/lib*.so

fix-plist:
	@${REINPLACE_CMD} -e 's|.*pyscf_lib_placeholder.so$$||' ${TMPPLIST}

post-test:
	@${ECHO} "==> simple test ..."
	@${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${FILESDIR}/test.py

# tests currently fail under the local aarch64 harness: pytest exits 255 with repeated "Too many args to microtask: 17!" during adc tests

.include <bsd.port.mk>
