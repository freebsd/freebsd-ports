# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	novaclient
PORTVERSION=	3.2.0	
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Client for the OpenStack Nova API

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.6:${PORTSDIR}/devel/py-pbr
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argparse>=0:${PORTSDIR}/devel/py-argparse \
		${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.9:${PORTSDIR}/devel/py-iso8601 \
		${PYTHON_PKGNAMEPREFIX}keystoneauth1>=2.1.0:${PORTSDIR}/devel/py-keystoneauth1 \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=1.5.0:${PORTSDIR}/devel/py-oslo.i18n \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=1.10.0:${PORTSDIR}/devel/py-oslo.serialization \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.2.0:${PORTSDIR}/devel/py-oslo.utils \
		${PYTHON_PKGNAMEPREFIX}prettytable>=0:${PORTSDIR}/devel/py-prettytable \
		${PYTHON_PKGNAMEPREFIX}requests>=2.8.1:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.2.0:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:${PORTSDIR}/devel/py-six

USES=		python
USE_PYTHON=	distutils autoplist noegginfo

post-patch:
	@${REINPLACE_CMD} -e 's,install_requires.*,,' ${WRKSRC}/setup.py

.include <bsd.port.mk>
