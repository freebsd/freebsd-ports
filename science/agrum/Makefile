PORTNAME=	agrum
DISTVERSION=	2.2.1
CATEGORIES=	science math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Graphical modeler for Bayesian networks, influence diagrams, etc
WWW=		https://agrum.gitlab.io \
		https://gitlab.com/agrumery/aGrUM

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

TEST_DEPENDS=	swig:devel/swig

USES=		cmake compiler:c++20-lang shebangfix # the 'act' executable uses 'python' and is broken, when act is broken CMakeLists.txt builds with default configuration which is fine
USE_LDCONFIG=	yes

LLD_UNSAFE=	yes

USE_GITLAB=	yes
GL_ACCOUNT=	agrumery
GL_PROJECT=	aGrUM
GL_TAGNAME=	40993102

SHEBANG_FILES=	act

CMAKE_ARGS=	-DPython_EXECUTABLE=${PYTHON_CMD}
CMAKE_OFF=	USE_SWIG

PLIST_SUB+=	VERSION=${PORTVERSION}

OPTIONS_DEFINE=		ODBC OPENMP PYTHON
OPTIONS_DEFAULT=	OPENMP PYTHON
OPTIONS_SUB=		yes

ODBC_CMAKE_BOOL=	USE_NANODBC
ODBC_USES=		localbase:ldflags
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC

OPENMP_CMAKE_BOOL=	USE_OPENMP

PYTHON_CMAKE_BOOL=	BUILD_PYTHON
PYTHON_USES=		python
PYTHON_PLIST_SUB=	PYTHON_VER_MAJ=${PYTHON_VER:R}
PYTHON_RUN_DEPENDS=	${PYNUMPY} \
			${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}matplotlib-inline>0:math/py-matplotlib-inline@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}nbconvert>0:devel/py-nbconvert@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}nbformat>0:devel/py-nbformat@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pydotplus>0:graphics/py-pydotplus@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}scikit-learn>0:science/py-scikit-learn@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${PY_FLAVOR}
			# see wrappers/pyAgrum/requirements.txt and wrappers/pyAgrum/testunits/optional_requirements.txt

BINARY_ALIAS=	gcc=${CC} g++=${CXX} # only for tests, see https://gitlab.com/agrumery/aGrUM/-/issues/100

do-test:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ./act test release agrum -t all

# tests as of 2.2.1: Failed 0 of 1485 tests

.include <bsd.port.mk>
