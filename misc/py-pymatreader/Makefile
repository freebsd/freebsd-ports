PORTNAME=	pymatreader
DISTVERSION=	1.0.0
CATEGORIES=	misc
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Convenient reader for Matlab mat files
WWW=		https://gitlab.com/obob/pymatreader

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-regex-commit>0:devel/py-hatch-regex-commit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h5py>0:science/py-h5py@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.7.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>=0:devel/py-xmltodict@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # tests fail to run, see https://gitlab.com/obob/pymatreader/-/issues/20

NO_ARCH=	yes

# tests as of 1.0.0: 25 passed, 629 warnings in 136.24s (0:02:16

.include <bsd.port.mk>
