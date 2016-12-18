# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	python-heatclient
PORTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	OpenStack Orchestration API Client Library

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.8:devel/py-pbr
RUN_DEPENDS:=	${BUILD_DEPENDS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}requests>=2.10.0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}python-swiftclient>=2.2.0:databases/py-python-swiftclient \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.18.0:devel/py-oslo.utils \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=1.10.0:devel/py-oslo.serialization \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=2.1.0:devel/py-oslo.i18n \
		${PYTHON_PKGNAMEPREFIX}osc-lib>=1.2.0:devel/py-osc-lib \
		${PYTHON_PKGNAMEPREFIX}keystoneauth1>=2.14.0:devel/py-keystoneauth1 \
		${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.11:devel/py-iso8601 \
		${PYTHON_PKGNAMEPREFIX}cliff>=2.2.0:devel/py-cliff \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.10.0:devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}prettytable>=0:devel/py-prettytable \
		${PYTHON_PKGNAMEPREFIX}Babel>=2.3.4:devel/py-babel

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
