# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	openstackclient
PORTVERSION=	3.4.1
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

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
		${PYTHON_PKGNAMEPREFIX}glanceclient>=2.5.0:net/py-glanceclient \
		${PYTHON_PKGNAMEPREFIX}keystoneclient>=3.6.0:net/py-keystoneclient \
		${PYTHON_PKGNAMEPREFIX}novaclient>=0:net/py-novaclient \
		${PYTHON_PKGNAMEPREFIX}cinderclient>=0:net/py-cinderclient \
		${PYTHON_PKGNAMEPREFIX}neutronclient>=0:net/py-neutronclient

USES=		python
USE_PYTHON=	distutils autoplist noegginfo
NO_ARCH=	yes

.include <bsd.port.mk>
