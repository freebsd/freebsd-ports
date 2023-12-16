PORTNAME=	fontparts
PORTVERSION=	0.12.1
PORTREVISION=	1
CATEGORIES=	print python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	fontParts-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	API for interacting with the parts of fonts during the font development process
WWW=		https://github.com/robotools/fontParts

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=42:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=3.4:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}booleanOperations>=0.9.0:x11-fonts/py-booleanOperations@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defcon>=0.6.0:x11-fonts/py-defcon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fontMath>=0.4.8:x11-fonts/py-fontMath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fontpens>=0.1.0:print/py-fontpens@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fonttools>=3.32.0:print/py-fonttools@${PY_FLAVOR}

USES=		python zip
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
