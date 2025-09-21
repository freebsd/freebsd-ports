PORTNAME=	salome-kernel
DISTVERSIONPREFIX=	V
DISTVERSION=	9_11_0
PORTREVISION=	5
CATEGORIES=	science # physics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Salome Project: Multi-physics simulations: Kernel
WWW=		https://www.salome-platform.org/ \
		https://github.com/SalomePlatform/kernel/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}omniorb>0:devel/py-omniorb \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS} \
		salome-configuration>0:science/salome-configuration \
		swig:devel/swig
LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libhdf5.so:science/hdf5 \
		libomniORB4.so:devel/omniORB
RUN_DEPENDS=	${PY_DEPENDS} \
		bash:shells/bash

USES=		cmake compiler:c++11-lang gnome python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	SalomePlatform
GH_PROJECT=	kernel
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

SHEBANG_FILES=	bin/appliskel/.bashrc bin/appliskel/.salome_run \
		bin/appliskel/salome bin/appliskel/salome_mesa
SHEBANG_GLOB=	*.py *.sh

CMAKE_ARGS=	-DCONFIGURATION_ROOT_DIR=${LOCALBASE}/share/salome/configuration \
		-DOMNIORBPY_ROOT_DIR=${LOCALBASE} \
		-DPython_EXECUTABLE=${PYTHON_CMD}
CMAKE_OFF=	SALOME_BUILD_DOC SALOME_BUILD_TESTS

CFLAGS+=	-DSIZEOF_INT=4 -DSIZEOF_LONG=4
LDFLAGS+=	-lexecinfo

DATADIR=	${PREFIX}/share/salome

.include <bsd.port.mk>
