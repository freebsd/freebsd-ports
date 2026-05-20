PORTNAME=	volatility3
DISTVERSIONPREFIX=	v
DISTVERSION=	2.28.0
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Advanced memory forensics framework
WWW=		https://www.volatilityfoundation.org/

LICENSE=	VSL
LICENSE_NAME=	Volatility Software License
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}capstone>=0:devel/py-capstone@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pefile>=0:devel/py-pefile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yara-python>=0:security/py-yara@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	volatilityfoundation

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
