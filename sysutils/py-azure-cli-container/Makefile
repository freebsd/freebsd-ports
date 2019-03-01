# $FreeBSD$

PORTNAME=	azure-cli-container
PORTVERSION=	0.3.14
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Microsoft Azure Command-Line Tools container Command Module

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-mgmt-containerinstance>=1.4.0:devel/py-azure-mgmt-containerinstance@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-loganalytics>=0.2.0:devel/py-azure-mgmt-loganalytics@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-resource>=2.0.0:devel/py-azure-mgmt-resource@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-network>=2.4.0:devel/py-azure-mgmt-network@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-authorization>=0.50.0:devel/py-azure-mgmt-authorization@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-core>=0:sysutils/py-azure-cli-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.13:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websocket-client>=0:www/py-websocket-client@${PY_FLAVOR}

USES=		azurepy python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
