PORTNAME=	Py-BOBYQA
DISTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Flexible derivative-free solver for general objective minimization
WWW=		https://numericalalgorithmsgroup.github.io/pybobyqa/build/html/index.html

LICENSE=	GPLv3

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pandas>=0.17:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.17:science/py-scipy@${PY_FLAVOR}
		# extras: trustregion

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
