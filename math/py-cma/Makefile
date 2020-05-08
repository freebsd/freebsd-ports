# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cma
PORTVERSION=	3.0.3
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CMA-ES for non-linear numerical optimization in Python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/cma/LICENSE

RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	PLOTTING SKOPT
PLOTTING_DESC=	Plotting support
SKOPT_DESC=	Scikit-Optimize (skopt) support

PLOTTING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR}
SKOPT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scikit-optimize>=0:science/py-scikit-optimize@${PY_FLAVOR}

.include <bsd.port.mk>
