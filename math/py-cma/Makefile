PORTNAME=	cma
PORTVERSION=	4.0.0
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CMA-ES for non-linear numerical optimization in Python
WWW=		https://github.com/CMA-ES/pycma

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/cma/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	CONSTRAINED_SOLUTION_TRACKING PLOTTING
CONSTRAINED_SOLUTION_TRACKING_DESC=	Convergence tracking support
PLOTTING_DESC=	Plotting support

CONSTRAINED_SOLUTION_TRACKING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}moarchiving>=0:math/py-moarchiving@${PY_FLAVOR}
PLOTTING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR}

.include <bsd.port.mk>
