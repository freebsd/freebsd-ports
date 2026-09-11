PORTNAME=	liboqs-python
DISTVERSION=	0.16.0
CATEGORIES=	security
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for quantum-resistant cryptography
WWW=		https://openquantumsafe.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
LIB_DEPENDS=	liboqs.so:security/liboqs
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tomli>=2:textproc/py-tomli@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist nose2

USE_GITHUB=	yes
GH_ACCOUNT=	open-quantum-safe

NO_ARCH=	yes

# tests as of 0.16.0: Ran 955 tests in 212.627s

.include <bsd.port.mk>
