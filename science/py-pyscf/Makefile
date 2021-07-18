PORTNAME=	pyscf
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.0a-103
DISTVERSIONSUFFIX=	-ga81f201c4
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python module for quantum chemistry

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS} \
		cmake:devel/cmake \
		gmake:devel/gmake
LIB_DEPENDS=	libcint.so:science/libcint \
		libxc.so:science/libxc \
		libxcfun.so:science/xcfun
RUN_DEPENDS=	${PY_DEPENDS}

USES=		fortran blaslapack:openblas compiler:c++11-lang python
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes

POST_PLIST=	fix-plist

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pyscf/lib/lib*.so

fix-plist:
	@${REINPLACE_CMD} -e 's|.*pyscf_lib_placeholder.so$$||' ${TMPPLIST}

do-test: install
	@${PYTHON_CMD} ${FILESDIR}/test.py

.include <bsd.port.mk>
