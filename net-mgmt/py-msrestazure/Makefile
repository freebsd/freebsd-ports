# Created by: Johannes Jost Meixner <johannes@FreeBSD.org>
# $FreeBSD$

PORTNAME=	msrestazure
PORTVERSION=	0.4.8
CATEGORIES=	net-mgmt python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xmj@FreeBSD.org
COMMENT=	Azure-specific AutoRest swagger generator Python client runtime

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}keyring>0:security/py-keyring@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msrest>0:net-mgmt/py-msrest@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}adal>0:net-mgmt/py-adal@${FLAVOR}

USES=		python zip
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
