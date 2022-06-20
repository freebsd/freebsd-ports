PORTNAME=	ezc3d
DISTVERSIONPREFIX=	Release_
DISTVERSION=	1.5.0
CATEGORIES=	misc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C3D (biomechanics data format) reader/writer

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scikit-build>0:devel/py-scikit-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		cmake:devel/cmake \
		swig:devel/swig
RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	distutils pytest # autoplist is broken due to https://github.com/pyomeca/ezc3d/issues/258 ; tests fail, see https://github.com/pyomeca/ezc3d/issues/259

USE_GITHUB=	yes
GH_ACCOUNT=	pyomeca
GH_TUPLE=	google:googletest:3880b13:googletest/external/gtest # https://github.com/pyomeca/ezc3d/issues/256

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	# remove unnecessary C++ headers, see https://github.com/pyomeca/ezc3d/issues/258
	@${RM} -r ${STAGEDIR}${PREFIX}/include/*
	# strip binaries
	@cd ${STAGEDIR}/${PYTHON_SITELIBDIR} && \
		${STRIP_CMD} \
			ezc3d/_ezc3d.so \
			ezc3d/libezc3d.so

.include <bsd.port.mk>
