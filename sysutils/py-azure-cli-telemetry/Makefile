PORTNAME=	azure-cli-telemetry
PORTVERSION=	1.1.0
PORTREVISION=	3
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Microsoft Azure CLI Telemetry Package
WWW=		https://github.com/Azure/azure-cli/tree/dev/src/azure-cli-telemetry \
		https://github.com/Azure/azure-cli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}applicationinsights>=0.11.1<0.12:devel/py-applicationinsights@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}portalocker>=1.6<4:devel/py-portalocker@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
