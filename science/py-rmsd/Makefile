PORTNAME=	rmsd
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	1.6.3
PORTREVISION=	1
CATEGORIES=	science
#MASTER_SITES=	PYPI # missing test files, see https://github.com/charnley/rmsd/issues/123
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Calculate root-mean-square deviation (RMSD) between coordinate sets
WWW=		https://github.com/charnley/rmsd

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist concurrent pytest

USE_GITHUB=	yes
GH_ACCOUNT=	charnley

# tests as of 1.6.3: 1 failed, 51 passed, 1 skipped in 8.53s, failure due to the missing science/py-qmllib that fails to build

.include <bsd.port.mk>
