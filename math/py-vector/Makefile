PORTNAME=	vector
PORTVERSION=	1.6.3
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Vector classes and utilities
WWW=		https://vector.readthedocs.io/en/latest/ \
		https://github.com/scikit-hep/vector

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.13.3,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=19:devel/py-packaging@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	AWKWARD NUMBA SYMPY
AWKWARD_DESC=	Awkward arrays
NUMBA_DESC=	Numba-compiled functions
SYMPY_DESC=	SymPy expressions

AWKWARD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}awkward>=2:math/py-awkward@${PY_FLAVOR}
SYMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sympy>=0:math/py-sympy@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MNUMBA} && ${PYTHON_REL} < 31400
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}numba>=0.57:devel/py-numba@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
