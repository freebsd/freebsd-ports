PORTNAME=	gpaw
DISTVERSION=	24.6.0
PORTREVISION=	4
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DFT and beyond within the projector-augmented wave method in chemistry
WWW=		https://wiki.fysik.dtu.dk/gpaw/ \
		https://gitlab.com/gpaw/gpaw

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libblas.so:math/blas \
		libmpich.so:net/mpich \
		libopenblas.so:math/openblas \
		libxc.so:science/libxc
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ase>0:science/py-ase@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		gpaw-setups>0:science/gpaw-setups

USES=		gettext-runtime localbase python shebangfix
USE_PYTHON=	distutils concurrent autoplist

SHEBANG_FILES=	tools/*

LDFLAGS=	-lmpi # otherwise: ImportError: /usr/local/lib/python3.8/site-packages/_gpaw.cpython-38.so: Undefined symbol "MPI_Comm_rank"

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_gpaw*.so

do-test: install # tests fail to run, see https://gitlab.com/gpaw/gpaw/-/issues/1273
	@${ECHO} "== Performing a test calculation on one CPU =="
	@gpaw test
	@${ECHO} "== Performing a test calculation on 8 CPUs =="
	@gpaw -P 8 test

.include <bsd.port.mk>
