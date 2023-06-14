PORTNAME=	pyhdfe
DISTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	math python # statistics
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High dimensional fixed effect absorption
WWW=		https://github.com/jeffgortmaker/pyhdfe

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

PY_DEPENDS=	${PYNUMY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.0.0:science/py-scipy@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
