PORTNAME=	ase
DISTVERSION=	3.26.0
CATEGORIES=	science python # chemistry
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Atomic simulation environment
WWW=		https://ase-lib.org/ \
		https://gitlab.com/ase/ase

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.1.0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.1.0:science/py-scipy@${PY_FLAVOR}
#		nwchem:science/nwchem
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=1.30.0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asap3>0:science/py-asap3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netCDF4>0:science/py-netCDF4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spglib>0:science/py-spglib@${PY_FLAVOR}
# optional dependencies: x11-toolkits/py-tkinter, www/py-flask (see https://wiki.fysik.dtu.dk/ase/install.html)

USES=		python
USE_PYTHON=	distutils concurrent autoplist pytest

NO_ARCH=	yes

# tests as of 3.26.0: 25 failed, 3036 passed, 538 skipped, 5 xfailed, 49 warnings, 10 errors in 2377.98s (0:39:37), see https://gitlab.com/ase/ase/-/issues/1746, https://gitlab.com/ase/ase/-/issues/1747

.include <bsd.port.mk>
