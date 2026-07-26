PORTNAME=	rmsd
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	1.6.5
CATEGORIES=	science
#MASTER_SITES=	PYPI # missing test files, see https://github.com/charnley/rmsd/issues/123
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Calculate root-mean-square deviation (RMSD) between coordinate sets
WWW=		https://github.com/charnley/rmsd

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist concurrent pytest

USE_GITHUB=	yes
GH_ACCOUNT=	charnley

# tests as of 1.6.5: 52 passed, 1 skipped in 0.84s

.include <bsd.port.mk>
