PORTNAME=	colorbrewer
DISTVERSION=	0.3
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Constants from Cynthia Brewer's ColorBrewer
WWW=		https://github.com/dsc/colorbrewer-python

LICENSE=	APACHE20

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist
NO_ARCH=	yes

# tests as of 0.3: 1 test OK in 0.000s

.include <bsd.port.mk>
