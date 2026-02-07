PORTNAME=	benford_py
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
PORTREVISION=	3
CATEGORIES=	math python
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for testing data sets with Benford's law
WWW=		https://github.com/milcent/benford_py

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	milcent

NO_ARCH=	yes

post-extract: # https://github.com/milcent/benford_py/issues/48
	${TOUCH} ${WRKSRC}/README-pypi.md

.include <bsd.port.mk>
