PORTNAME=	GridDataFormats
DISTVERSION=	1.0.1
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Handle data on a grid: NumPy n-dimensional arrays

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}mrcfile>0:biology/py-mrcfile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist concurrent pytest

USE_GITHUB=	yes
GH_ACCOUNT=	MDAnalysis

NO_ARCH=	yes

.include <bsd.port.mk>
