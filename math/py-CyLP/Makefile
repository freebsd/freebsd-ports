PORTNAME=	CyLP
DISTVERSIONPREFIX=	v
DISTVERSION=	0.92.3
PORTREVISION=	2
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python interface to CLP, CBC, and CGL to solve LPs and MIPs
WWW=		https://github.com/coin-or/CyLP

LICENSE=	CPL10
LICENSE_NAME=	Common Public License Version 1.0
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libblas.so:math/blas \
		libCbc.so:math/cbc \
		libCgl.so:math/cgl \
		libClp.so:math/clp \
		libCoinUtils.so:math/coinutils \
		liblapack.so:math/lapack \
		libOsi.so:math/osi
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.10.0:science/py-scipy@${PY_FLAVOR}

USES=		compiler:c++11-lang python
USE_PYTHON=	autoplist cython3 pep517 pytest

USE_GITHUB=	yes
GH_ACCOUNT=	coin-or

MAKE_ENV=	COIN_INSTALL_DIR=${LOCALBASE}

TEST_WRKSRC=	${WRKSRC}/cylp
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/cylp/cy/Cy*.so

.include <bsd.port.mk>
