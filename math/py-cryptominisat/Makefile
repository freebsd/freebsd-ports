# $FreeBSD$

PORTNAME=	cryptominisat
DISTVERSION=	5.6.3
PORTREVISION=	1
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Bindings to CryptoMiniSat (a SAT solver)

LICENSE=	MIT LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_LGPL21=	${WRKSRC}/../LICENSE.txt
LICENSE_FILE_MIT=	${WRKSRC}/../LICENSE.txt

LIB_DEPENDS=	libcryptominisat5.so:math/cryptominisat

USES=		compiler:c++11-lib python
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes

GH_ACCOUNT=	msoos

WRKSRC_SUBDIR=	python

PYDISTUTILS_BUILDTARGET=	build_ext --include-dirs=${LOCALBASE}/include

post-patch:
	${REINPLACE_CMD} -e 's|@PROJECT_VERSION@|${PORTVERSION}|' \
		-e 's|$${CMAKE_C_COMPILER}|${CC}|' \
		-e 's|$${CMAKE_CXX_COMPILER}|${CXX}|' \
		-e 's|$${PY_C_CONFIG}||' \
		-e 's|$${PY_LD_CONFIG}||' \
		-e 's|$${APPLE}||' ${WRKSRC}/setup.py.in
	${CP} ${WRKSRC}/setup.py.in ${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pycryptosat.so

.include <bsd.port.mk>
