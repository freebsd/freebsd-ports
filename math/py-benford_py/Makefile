PORTNAME=	benford_py
DISTVERSION=	0.4.1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for testing data sets with Benford's law

LICENSE=	GPLv3

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

post-extract: # https://github.com/milcent/benford_py/issues/48
	${TOUCH} ${WRKSRC}/README-pypi.md

.include <bsd.port.mk>
