PORTNAME=	azure-cli-telemetry
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Microsoft Azure CLI Telemetry Package
WWW=		https://pypi.org/project/azure-cli-telemetry/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}applicationinsights>=0.11.1<0.12:devel/py-applicationinsights@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}portalocker>=1.6<3:devel/py-portalocker@${PY_FLAVOR}

USES=		azurepy python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
