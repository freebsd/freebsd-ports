PORTNAME=	ezc3d
DISTVERSIONPREFIX=	Release_
DISTVERSION=	1.5.7
CATEGORIES=	misc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C3D (biomechanics data format) reader/writer
WWW=		https://github.com/pyomeca/ezc3d

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scikit-build>0:devel/py-scikit-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		cmake:devel/cmake-core \
		swig:devel/swig
RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	distutils pytest # autoplist is broken due to https://github.com/pyomeca/ezc3d/issues/258 ; 3 tests fail, see https://github.com/pyomeca/ezc3d/issues/291

USE_GITHUB=	yes
GH_ACCOUNT=	pyomeca
GH_TUPLE=	google:googletest:3880b13:googletest/external/gtest # https://github.com/pyomeca/ezc3d/issues/256

TEST_ARGS=	${WRKSRC}/test/python3
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	# remove unnecessary C++ headers, see https://github.com/pyomeca/ezc3d/issues/258
	@${RM} -r ${STAGEDIR}${PREFIX}/include/*
	# strip binaries
	@cd ${STAGEDIR}/${PYTHON_SITELIBDIR} && \
		${STRIP_CMD} \
			ezc3d/_ezc3d.so \
			ezc3d/libezc3d.so

pre-test: # download test c3d files
	# download archives
	@${MKDIR} ${WRKSRC}/test/c3dFiles
	@cd ${WRKDIR} && ${FETCH_CMD} -q https://github.com/pyomeca/ezc3d-testFiles/archive/master.zip -o ${WRKSRC}/test/c3dFiles/ezc3d-testFiles-master.zip
.for f in Sample01.zip Sample02.zip
	@cd ${WRKDIR} && ${FETCH_CMD} -q https://www.c3d.org/data/${f} -o ${WRKSRC}/test/c3dFiles/${f}
.endfor
	# extract archives
.for n in ezc3d-testFiles-master Sample01 Sample02
	@cd ${WRKSRC}/test/c3dFiles && ${MKDIR} ${n} && cd ${n} && ${TAR} -xf ../${n}.zip
.endfor
	# move *.c3d files into a flat folder
	@${MKDIR} ${WRKSRC}/test/c3dTestFiles
	@${CP} `${FIND} ${WRKSRC} -name "*.c3d"` ${WRKSRC}/test/c3dTestFiles

.include <bsd.port.mk>
