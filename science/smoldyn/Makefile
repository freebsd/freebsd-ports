PORTNAME=	smoldyn
DISTVERSION=	2.75
CATEGORIES=	science
MASTER_SITES=	https://www.smoldyn.org/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Biochemical simulator for molecular diffusion, surface interactions
WWW=		https://www.smoldyn.org/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/License.txt

LIB_DEPENDS=	libtiff.so:graphics/tiff
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flaky>0:devel/py-flaky@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYNUMPY}

USES=		cmake:testing compiler:c++11-lang gl localbase:ldflags python:test tar:tgz shebangfix xorg
USE_GL=		gl glu glut
USE_XORG=	xi xmu
USE_LDCONFIG=	yes

SHEBANG_GLOB=	*.py.in

CMAKE_TESTING_ON=	OPTION_EXAMPLES # all tests fail to run, see https://github.com/ssandrews/Smoldyn/issues/127

OPTIONS_DEFINE=		PYTHON
OPTIONS_DEFAULT=	# PYTHON Tests ONLY pass when PYTHON=ON despite biology/py-biosimulators-utils being missing
OPTIONS_SUB=		yes

PYTHON_CMAKE_BOOL=	OPTION_PYTHON
PYTHON_USES=		python
PYTHON_CMAKE_ON=	-DPython3_EXECUTABLE=${PYTHON_CMD}
PYTHON_BUILD_DEPENDS=	${PY_SETUPTOOLS}
#PYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}biosimulators-utils>0:biology/py-biosimulators-utils@${PY_FLAVOR}
PYTHON_BROKEN=		some python dependencies aren't ported

post-extract: # see https://github.com/ssandrews/Smoldyn/issues/127
	@${CHMOD} +x ${WRKSRC}/scripts/run_pyscript.py.in

do-install-PYTHON-on: # workaround for https://github.com/ssandrews/Smoldyn/issues/129
	@cd ${BUILD_WRKSRC}/py && ${COPYTREE_SHARE} ${PORTNAME} ${STAGEDIR}${PYTHON_SITELIBDIR}
	@${RM} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/.DS_Store

.include <bsd.port.mk>
