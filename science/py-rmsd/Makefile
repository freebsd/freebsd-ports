PORTNAME=	rmsd
DISTVERSION=	1.4
CATEGORIES=	science
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Calculate root-mean-square deviation (RMSD) between coordinate sets
WWW=		https://github.com/charnley/rmsd

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist concurrent

.include <bsd.port.mk>
