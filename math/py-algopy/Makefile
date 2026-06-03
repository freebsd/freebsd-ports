PORTNAME=	algopy
DISTVERSION=	0.5.7
PORTREVISION=	6
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Algorithmic Differentiation (AD) and Taylor polynomial approximations
WWW=		https://pythonhosted.org/algopy/

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}

USES=		python zip
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
