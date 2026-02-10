PORTNAME=	NATTEN
DISTVERSIONPREFIX=	v
DISTVERSION=	0.21.5
CATEGORIES=	misc python # machine-learning
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Neighborhood Attention Extension for PyTorch
WWW=		https://natten.org/ \
		https://github.com/SHI-Labs/NATTEN

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# this BUILD_DEPENDS should be used when CUDA would be available
BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		cmake:devel/cmake-core \
		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytorch>=2.0.0:misc/py-pytorch@${PY_FLAVOR}

USES=		localbase python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	SHI-Labs
GH_PROJECT=	NATTEN

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes # no arch w/out CUDA

post-install:
	# delete stray files, see https://github.com/SHI-Labs/NATTEN/issues/152
	@${RM} -r \
		${STAGEDIR}${PYTHON_SITELIBDIR}/CMakeFiles \
		${STAGEDIR}${PYTHON_SITELIBDIR}/CMakeCache.txt \
		${STAGEDIR}${PYTHON_SITELIBDIR}/cmake_install.cmake \
		${STAGEDIR}${PYTHON_SITELIBDIR}/Makefile

# tests as of 0.21.0: 1 passed, 55 skipped, 1 warning in 14.76s

.include <bsd.port.mk>
