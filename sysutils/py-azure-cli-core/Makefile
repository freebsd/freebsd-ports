PORTNAME=	azure-cli-core
PORTVERSION=	2.25.0
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Microsoft Azure Command-Line Tools Core Module

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}adal>=1.2.7:net-mgmt/py-adal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}argcomplete>=1.8:devel/py-argcomplete@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-cli-telemetry>=1.0.6:sysutils/py-azure-cli-telemetry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-common>=1.1:www/py-azure-common@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.4.1:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}humanfriendly>=4.7<10.0:textproc/py-humanfriendly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jmespath>=0:devel/py-jmespath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}knack>=0.8.2:devel/py-knack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msal>=1.10.0<2.0.0:devel/py-msal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msrest>=0.5.0:net-mgmt/py-msrest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msrestazure>=0.6.3:net-mgmt/py-msrestazure@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>=2.0.8<3.0.0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=0:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=17.1.0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.22:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.12:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.30.0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-resource>=10.2.0:devel/py-azure-mgmt-resource@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pkginfo>=1.5.0.1:sysutils/py-pkginfo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}azure-mgmt-core>=1.2.0<2.0.0:devel/py-azure-mgmt-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5.8:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography@${PY_FLAVOR}
		# cryptography>=3.2<3.4 issue with py-openssl and py-cryptography on FreeBSD 11

USES=		azurepy python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
