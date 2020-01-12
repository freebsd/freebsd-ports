# $FreeBSD$

PORTNAME=	gau2grid
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.4
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast computation of a gaussian and its derivative on a grid

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY} \
		cmake:devel/cmake
RUN_DEPENDS=	${PYNUMPY}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		cmake compiler:c11 python
USE_GITHUB=	yes
GH_ACCOUNT=	dgasmith
USE_PYTHON=	flavors

CMAKE_ON=	INSTALL_PYMOD
CMAKE_ARGS=	-DPYMOD_INSTALL_LIBDIR:STRING=${PYTHON_SITELIBDIR} -DFREEBSD_PYTHON_VER:STRING=${PYTHON_VER}

post-install:
	@${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}/gau2grid/__pycache__
	@${RM} -r ${STAGEDIR}${LOCALBASE}//lib/usr # LICENSE is installed under there

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest

.include <bsd.port.mk>
