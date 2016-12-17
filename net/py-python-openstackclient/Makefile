# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	python-openstackclient
PORTVERSION=	3.4.1
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	Client for the OpenStack

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.8:devel/py-pbr
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=2.3.4:devel/py-babel \
		${PYTHON_PKGNAMEPREFIX}cliff>=2.3.0:devel/py-cliff \
		${PYTHON_PKGNAMEPREFIX}keystoneauth1>=2.14.0:devel/py-keystoneauth1 \
		${PYTHON_PKGNAMEPREFIX}openstacksdk>=0.9.10:devel/py-openstacksdk \
		${PYTHON_PKGNAMEPREFIX}osc-lib>=1.2.0:devel/py-osc-lib \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=2.1.0:devel/py-oslo.i18n \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.18.0:devel/py-oslo.utils \
		${PYTHON_PKGNAMEPREFIX}python-glanceclient>=2.5.0:net/py-python-glanceclient \
		${PYTHON_PKGNAMEPREFIX}python-keystoneclient>=3.6.0:net/py-python-keystoneclient \
		${PYTHON_PKGNAMEPREFIX}python-novaclient>=0:net/py-python-novaclient \
		${PYTHON_PKGNAMEPREFIX}python-cinderclient>=0:net/py-python-cinderclient \
		${PYTHON_PKGNAMEPREFIX}python-neutronclient>=0:net/py-python-neutronclient

USES=		python
USE_PYTHON=	distutils autoplist noegginfo
NO_ARCH=	yes

.include <bsd.port.mk>
