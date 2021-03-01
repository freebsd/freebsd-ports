# $FreeBSD$

PORTNAME=	agrum
DISTVERSION=	0.19.2
CATEGORIES=	science math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Graphical modeler for Bayesian networks, influence diagrams, etc

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++14-lang # the 'act' executable uses 'python' and is broken, when act is broken CMakeLists.txt builds with default configuration which is fine
USE_LDCONFIG=	yes
LLD_UNSAFE=	yes

USE_GITLAB=	yes
GL_ACCOUNT=	agrumery
GL_PROJECT=	aGrUM
GL_COMMIT=	97b2f930a7dfd3ef85d3f494e4c8a6d2832f3d76

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
PYTHON_USES=		python:3.7+
PYTHON_PLIST_SUB=	PYTHON_VER_MAJ=${PYTHON_VER:R}
PYTHON_RUN_DEPENDS=	${PYNUMPY} \
			${PYTHON_PKGNAMEPREFIX}configparser>0:devel/py-configparser@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}ipython>0:devel/ipython@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}nbconvert>0:devel/py-nbconvert@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}nbformat>0:devel/py-nbformat@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pydotplus>0:graphics/py-pydotplus@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}scikit-learn>0:science/py-scikit-learn@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${PY_FLAVOR}
			# see wrappers/pyAgrum/requirements.txt and wrappers/pyAgrum/testunits/optional_requirements.txt

.include <bsd.port.mk>
