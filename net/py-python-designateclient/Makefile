# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	python-designateclient
PORTVERSION=	2.4.0
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	OpenStack DNS-as-a-Service - Client

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.8:devel/py-pbr@${FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}stevedore>=1.17.1:devel/py-stevedore@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.10.0:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.18.0:devel/py-oslo.utils@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}osc-lib>=1.2.0:devel/py-osc-lib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keystoneauth1>=2.14.0:devel/py-keystoneauth1@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=0:devel/py-jsonschema@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}debtcollector>=1.2.0:devel/py-debtcollector@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cliff>=2.3.0:devel/py-cliff@${FLAVOR}

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
