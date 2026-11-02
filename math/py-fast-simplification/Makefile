PORTNAME=	fast_simplification
DISTVERSION=	0.2.0
CATEGORIES=	math cad
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Wrapper around the Fast-Quadric-Mesh-Simplification library
WWW=		https://github.com/pyvista/fast-simplification

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nanobind>0:devel/py-nanobind@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>0:devel/py-scikit-build-core@${PY_FLAVOR}
BUILD_RUN_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}numpy>=1.26:math/py-numpy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyvista>0:graphics/py-pyvista@${PY_FLAVOR}

USES=		cmake:indirect python

USE_PYTHON=	pep517

.if !defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

PLIST_SUB=	VER=${PORTVERSION}

.include <bsd.port.mk>
