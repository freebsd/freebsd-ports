# Created by: Johannes Jost Meixner <johannes@FreeBSD.org>

PORTNAME=	msrestazure
DISTVERSION=	0.6.4
CATEGORIES=	net-mgmt python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Azure-specific AutoRest swagger generator Python client runtime

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msrest>=0.6.0<2.0.0:net-mgmt/py-msrest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}adal>=0.6.0<2.0.0:net-mgmt/py-adal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
