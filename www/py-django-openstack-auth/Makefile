# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	django-openstack-auth
PORTVERSION=	3.0.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_openstack_auth-${PORTVERSION}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	Django authentication backend for use with OpenStack Identity

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.6:devel/py-pbr
RUN_DEPENDS:=	${BUILD_DEPENDS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}keystoneauth1>=2.14.0:devel/py-keystoneauth1 \
		${PYTHON_PKGNAMEPREFIX}keystoneclient>=3.6.0:net/py-keystoneclient \
		${PYTHON_PKGNAMEPREFIX}oslo.policy>=1.15.0:devel/py-oslo.policy \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=0:devel/py-oslo.config \
		${PYTHON_PKGNAMEPREFIX}django18>=0:www/py-django18

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
