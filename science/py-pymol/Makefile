PORTNAME=	pymol
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.0
CATEGORIES=	science biology python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OpenGL-based molecular visualization system
WWW=		https://pymol.org/

LICENSE=	PyMOL
LICENSE_NAME=	Open-Source PyMOL Copyright
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.26.4,1:math/py-numpy@${PY_FLAVOR} \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		${LOCALBASE}/include/glm/glm.hpp:math/glm \
		${LOCALBASE}/include/mmtf.hpp:science/mmtf-cpp
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libnetcdf.so:science/netcdf \
		libpng16.so:graphics/png
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Pmw>0:x11-toolkits/py-Pmw@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.26.4,1:math/py-numpy@${PY_FLAVOR}

USES=		cmake:indirect compiler:c++11-lang gl gnome python tar:bz2
USE_GL=		gl glew glu
USE_GNOME=	libxml2
USE_PYTHON=	autoplist concurrent pep517

USE_GITHUB=	yes
GH_ACCOUNT=	schrodinger
GH_PROJECT=	${PORTNAME}-open-source

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}chempy # chempy port is unrelated, see https://github.com/schrodinger/pymol-open-source/issues/100

CXXFLAGS+=	-DMSGPACK_NO_BOOST # in line with MSGPACK_USE_BOOST=OFF in devel/msgpack-cxx

.if !exists(/usr/include/omp.h)
PEP517_BUILD_CONFIG_SETTING+=	-C use-openmp=no
.endif

OPTIONS_SINGLE=		GUI
OPTIONS_SINGLE_GUI=	QT TK
OPTIONS_DEFAULT=	QT

QT_USES=		pyqt:6
QT_USE=			PYQT=pyqt6:run

post-patch-TK-on:
	@${REINPLACE_CMD} -e "s|os.environ.get('QT_API', '')|os.environ.get('QT_API', 'none')|" \
		${WRKSRC}/modules/${PORTNAME}/Qt/__init__.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/_cmd*.so
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/chempy/champ/_champ*.so

.include <bsd.port.mk>
