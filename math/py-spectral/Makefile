PORTNAME=	spectral
DISTVERSION=	0.25
CATEGORIES=	math
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Spectral Python is a Python module for hyperspectral image processing
WWW=		https://www.spectralpython.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} \
		${PYTHON_CMD} -m spectral.tests.spyfile

# tests as of 0.25: 156 OK (spyfile tests; other tests require external data files)

.include <bsd.port.mk>
