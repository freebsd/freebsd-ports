PORTNAME=	blobfile
PORTVERSION=	2.0.2
DISTVERSIONPREFIX=	v
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Read GCS, ABS and local paths with the same interface
WWW=		https://github.com/blobfile/blobfile

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astor>=0.8.0:devel/py-astor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=42.0.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.33.6:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}filelock>=3.0<4:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=4.9<5:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodomex>=3.8<4:security/py-pycryptodomex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.25.3,1<3,1:net/py-urllib3@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

USE_GITHUB=	yes

.include <bsd.port.mk>
