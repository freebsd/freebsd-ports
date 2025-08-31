PORTNAME=	optking
DISTVERSION=	0.3.0
PORTREVISION=	2
CATEGORIES=	science python # chemistry
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python version of the PSI4 geometry optimization program by R.A. King
WWW=		https://github.com/psi-rking/optking

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=1.0:devel/py-msgpack@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}qcelemental>=0.20.0:science/py-qcelemental@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qcengine>=0.20.0:science/py-qcengine@${PY_FLAVOR}
TEST_DEPENDS=	dftd3:science/dftd3

USES=		python
USE_PYTHON=	distutils autoplist pytest # some tests fail

USE_GITHUB=	yes
GH_ACCOUNT=	psi-rking

NO_ARCH=	yes

.include <bsd.port.mk>
