# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	python-heatclient
PORTVERSION=	1.7.0
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	OpenStack Orchestration API Client Library

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.8:devel/py-pbr@${FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.10.0:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-swiftclient>=3.2.0:databases/py-python-swiftclient@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.18.0:devel/py-oslo.utils@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=1.10.0:devel/py-oslo.serialization@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=2.1.0:devel/py-oslo.i18n@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}osc-lib>=1.2.0:devel/py-osc-lib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keystoneauth1>=2.16.0:devel/py-keystoneauth1@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.11:devel/py-iso8601@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cliff>=2.3.0:devel/py-cliff@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.10.0:devel/py-yaml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prettytable>=0:devel/py-prettytable@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Babel>=2.3.4:devel/py-babel@${FLAVOR}

NO_ARCH=	yes

USES=		python:2.7 shebangfix
USE_PYTHON=	autoplist distutils
SHEBANG_FILES=	heatclient/tests/functional/hooks/post_test_hook.sh

.include <bsd.port.mk>
