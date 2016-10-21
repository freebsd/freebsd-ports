# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	openstackclient
PORTVERSION=	3.2.0
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	Client for the OpenStack

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.6:devel/py-pbr
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=2.3.4:devel/py-babel \
		${PYTHON_PKGNAMEPREFIX}cliff>=0:devel/py-cliff \
		${PYTHON_PKGNAMEPREFIX}keystoneauth1>=2.10.0:devel/py-keystoneauth1 \
		${PYTHON_PKGNAMEPREFIX}openstacksdk>=0.9.4:devel/py-openstacksdk \
		${PYTHON_PKGNAMEPREFIX}osc-lib>=1.0.2:devel/py-osc-lib \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=2.1.0:devel/py-oslo.i18n \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.16.0:devel/py-oslo.utils \
		${PYTHON_PKGNAMEPREFIX}glanceclient>=0:net/py-glanceclient \
		${PYTHON_PKGNAMEPREFIX}keystoneclient>=0:net/py-keystoneclient \
		${PYTHON_PKGNAMEPREFIX}novaclient>=0:net/py-novaclient \
		${PYTHON_PKGNAMEPREFIX}cinderclient>=0:net/py-cinderclient \
		${PYTHON_PKGNAMEPREFIX}neutronclient>=0:net/py-neutronclient

USES=		python
USE_PYTHON=	distutils autoplist noegginfo
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,install_requires.*,,' ${WRKSRC}/setup.py

.include <bsd.port.mk>
