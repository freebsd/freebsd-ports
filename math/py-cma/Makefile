# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	cma
PORTVERSION=	3.1.0
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CMA-ES for non-linear numerical optimization in Python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/cma/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	PLOTTING
PLOTTING_DESC=	Plotting support

PLOTTING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR}

.include <bsd.port.mk>
