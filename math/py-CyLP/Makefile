# $FreeBSD$

PORTNAME=	CyLP
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python interface to CLP, CBC, and CGL to solve LPs and MIPs

LICENSE=	CPL10
LICENSE_NAME=	Common Public License Version 1.0
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.10.0:science/py-scipy@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
LIB_DEPENDS=	libblas.so:math/blas \
		libCbc.so:math/cbc \
		libCgl.so:math/cgl \
		libClp.so:math/clp \
		liblapack.so:math/lapack
RUN_DEPENDS=	${PY_DEPENDS}

USES=		compiler:c++11-lang python
USE_GITHUB=	yes
GH_ACCOUNT=	coin-or
USE_PYTHON=	distutils cython autoplist

MAKE_ENV=	COIN_INSTALL_DIR=${LOCALBASE}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/cylp/cy/Cy*.so

.include <bsd.port.mk>
