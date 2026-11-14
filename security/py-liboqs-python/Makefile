PORTNAME=	liboqs-python
DISTVERSION=	0.16.0.2
CATEGORIES=	security
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for quantum-resistant cryptography
WWW=		https://openquantumsafe.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
LIB_DEPENDS=	liboqs.so:security/liboqs
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyasn1-alt-modules>=0.4.6:devel/py-pyasn1-alt-modules@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1>=0.6.4:devel/py-pyasn1@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist nose2

USE_GITHUB=	yes
GH_ACCOUNT=	open-quantum-safe

NO_ARCH=	yes

# tests as of 0.16.0.2: Ran 1465 tests in 217.919s, OK

.include <bsd.port.mk>
