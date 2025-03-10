PORTNAME=	Py-BOBYQA
DISTVERSION=	1.5.0
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/:tl}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Flexible derivative-free solver for general objective minimization
WWW=		https://numericalalgorithmsgroup.github.io/pybobyqa/build/html/index.html

LICENSE=	GPLv3

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pandas>=0.17:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.17:science/py-scipy@${PY_FLAVOR}
		# extras: trustregion

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
