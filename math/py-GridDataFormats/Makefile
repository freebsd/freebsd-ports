PORTNAME=	GridDataFormats
DISTVERSION=	1.2.0
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Handle data on a grid: NumPy n-dimensional arrays
WWW=		https://github.com/MDAnalysis/GridDataFormats

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}versioningit>0:devel/py-versioningit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.21:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mrcfile>0:biology/py-mrcfile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist concurrent pytest

USE_GITHUB=	yes
GH_ACCOUNT=	MDAnalysis

MAKE_ENV=	MY_PROJECT_VERSION=${DISTVERSION}

BINARY_ALIAS=	git=false

NO_ARCH=	yes

post-patch:
	@${ECHO} ${DISTVERSION} > ${WRKSRC}/VERSION

# tests as of 1.2.0: 123 passed, 26 skipped in 2.62s

.include <bsd.port.mk>
