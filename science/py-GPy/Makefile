PORTNAME=	GPy
DISTVERSION=	1.13.2
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Gaussian process toolbox
WWW=		https://sheffieldml.github.io/GPy/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.3.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramz>=0.9.6:science/py-paramz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.3.0:science/py-scipy@${PY_FLAVOR}

USES=		localbase python
USE_PYTHON=	distutils autoplist pytest # 12 tests fail see https://github.com/SheffieldML/GPy/issues/1075

POST_PLIST=	fix-plist

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/GPy/*/*${PYTHON_EXT_SUFFIX}.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/GPy/*/*/*${PYTHON_EXT_SUFFIX}.so

fix-plist: # workaroud for /usr/ports/science/py-GPy/work-py311/.PLIST.mktmp
	@${REINPLACE_CMD} -e "s|.*__pycache__/mpi_test__.*$$||" ${TMPPLIST}

.include <bsd.port.mk>
