PORTNAME=	fontparts
PORTVERSION=	1.1.1
CATEGORIES=	print python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	API for interacting with the parts of fonts during the font development process
WWW=		https://github.com/robotools/fontParts

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=42:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=9.2.2:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vcs-versioning>=0:devel/py-vcs-versioning@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}booleanOperations>=0.9.0:x11-fonts/py-booleanOperations@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defcon>=0.10.2:x11-fonts/py-defcon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fontMath>=0.9.3:x11-fonts/py-fontMath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonttools>=4.60.2:print/py-fonttools@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
