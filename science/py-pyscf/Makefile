PORTNAME=	pyscf
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.0
PORTREVISION=	1
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python module for quantum chemistry
WWW=		https://pyscf.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>=2.7:science/py-h5py@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		cmake:devel/cmake-core \
		gmake:devel/gmake
LIB_DEPENDS=	libcint.so:science/libcint \
		libxc.so:science/libxc \
		libxcfun.so:science/xcfun
RUN_DEPENDS=	${PY_DEPENDS}

USES=		fortran blaslapack:openblas compiler:c++11-lang python
USE_PYTHON=	distutils autoplist pytest # 3818 warnings, 57 errors in tests, see https://github.com/pyscf/pyscf/issues/1536
USE_GITHUB=	yes

POST_PLIST=	fix-plist

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/pyscf
TEST_ARGS=	-c ${WRKSRC}/setup.cfg

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pyscf/lib/lib*.so

fix-plist:
	@${REINPLACE_CMD} -e 's|.*pyscf_lib_placeholder.so$$||' ${TMPPLIST}

post-test:
	@${ECHO} "==> simple test ..."
	@${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${FILESDIR}/test.py

.include <bsd.port.mk>
