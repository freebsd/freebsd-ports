PORTNAME=	azure-cli-core
PORTVERSION=	2.86.0
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	azure_cli_core-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Microsoft Azure Command-Line Tools Core Module
WWW=		https://learn.microsoft.com/en-us/cli/azure/?view=azure-cli-latest \
		https://github.com/Azure/azure-cli/tree/dev/src/azure-cli-core \
		https://github.com/Azure/azure-cli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argcomplete>=3.5.2:devel/py-argcomplete@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-telemetry>=1.1.0:sysutils/py-azure-cli-telemetry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-core>=1.39.0:devel/py-azure-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-core>=1.2.0<2:devel/py-azure-mgmt-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}humanfriendly>=10.0<11:textproc/py-humanfriendly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jmespath>=0:devel/py-jmespath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}knack>=0.11.0:devel/py-knack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}microsoft-security-utilities-secret-masker>=1.0.0b4<1.1:devel/py-microsoft-security-utilities-secret-masker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msal>=1.35.1:devel/py-msal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msal-extensions>=1.3.1:devel/py-msal-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.9:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pkginfo>=1.5.0.1:sysutils/py-pkginfo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5.9:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}py-deviceid>=0:devel/py-py-deviceid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=2.1.0:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyopenssl>=17.1.0,1:security/py-pyopenssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cryptography pep517

NO_ARCH=	yes

.include <bsd.port.mk>
