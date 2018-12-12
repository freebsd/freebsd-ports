# $FreeBSD$

PORTNAME=	piranha
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11
PORTREVISION=	3
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for Piranha, the computer algebra system

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING.gpl3
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.lgpl3

BUILD_DEPENDS=	${LOCALBASE}/include/piranha/piranha.hpp:math/${PORTNAME}
LIB_DEPENDS=	libboost_iostreams.so:devel/boost-libs \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		${PY_BOOST}

USES=		cmake:outsource compiler:c++14-lang python
USE_GITHUB=	yes
GH_ACCOUNT=	bluescarni
USE_PYTHON=	flavors

PYTHON_SUFFIX_LETTER=	${PYTHON_VER:C/^2.*//:C/^3.*/m/}

CMAKE_ON=	BUILD_PYRANHA
CMAKE_OFF=	PIRANHA_INSTALL_HEADERS
CMAKE_ARGS=	-DPYTHON_EXECUTABLE:STRING=${PYTHON_CMD} \
		-DPYTHON_LIBRARIES:STRING=${LOCALBASE}/lib/libpython${PYTHON_VER}${PYTHON_SUFFIX_LETTER}.so \
		-DPYTHON_INCLUDE_DIRS:STRING=${LOCALBASE}/include/python${PYTHON_VER}${PYTHON_SUFFIX_LETTER} \
		-DPYTHONLIBS_VERSION_STRING:STRING=${PYTHON_VER} \
		-DPYTHON_VERSION_MAJOR:STRING=${PYTHON_MAJOR_VER} \
		-DPYTHON_VERSION_MINOR:STRING=${PYTHON_VER:C/[0-9]\.//}

post-patch: # FIND_PACKAGE(Boost) only supports modules python and python3
	@${REINPLACE_CMD} -e 's|$${REQUIRED_BOOST_LIBS} python)|$${REQUIRED_BOOST_LIBS} python${PYTHON_MAJOR_VER:S/2//})|' ${WRKSRC}/CMakeLists.txt

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pyranha/_core.so

.include <bsd.port.mk>
