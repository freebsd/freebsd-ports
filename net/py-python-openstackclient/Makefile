PORTNAME=	python-openstackclient
PORTVERSION=	7.2.1
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OpenStack Command-line Client
WWW=		https://docs.openstack.org/python-openstackclient/latest/ \
		https://github.com/openstack/python-openstackclient

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cliff>=3.5.0:devel/py-cliff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.11:devel/py-iso8601@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openstacksdk>=3.3.0:devel/py-openstacksdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}osc-lib>=2.3.0:devel/py-osc-lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=3.15.3:devel/py-oslo.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-cinderclient>=3.3.0:net/py-python-cinderclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-keystoneclient>=3.22.0:net/py-python-keystoneclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.27.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=2.0.1:devel/py-stevedore@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent cryptography pep517

NO_ARCH=	yes

SHEBANG_GLOB=	*.sh

.include <bsd.port.mk>
