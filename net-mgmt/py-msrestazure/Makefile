# Created by: Johannes Jost Meixner <johannes@FreeBSD.org>
# $FreeBSD$

PORTNAME=	msrestazure
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
CATEGORIES=	net-mgmt python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Azure-specific AutoRest swagger generator Python client runtime

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msrest>0:net-mgmt/py-msrest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}adal>0:net-mgmt/py-adal@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes
GH_ACCOUNT=	Azure
GH_PROJECT=	msrestazure-for-python

.include <bsd.port.mk>
