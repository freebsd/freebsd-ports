# Created by: Johannes Jost Meixner <johannes@FreeBSD.org>
# $FreeBSD$

PORTNAME=	msrestazure
DISTVERSION=	0.6.2
CATEGORIES=	net-mgmt python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Azure-specific AutoRest swagger generator Python client runtime

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msrest>0.6.0:net-mgmt/py-msrest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}adal>0.6.0:net-mgmt/py-adal@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
