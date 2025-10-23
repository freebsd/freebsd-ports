PORTNAME=	msrestazure
DISTVERSION=	0.6.4
PORTREVISION=	1
CATEGORIES=	net-mgmt python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Azure-specific AutoRest swagger generator Python client runtime
WWW=		https://github.com/Azure/msrestazure-for-python

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msrest>=0.6.0<2.0.0:net-mgmt/py-msrest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}adal>=0.6.0<2.0.0:net-mgmt/py-adal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
