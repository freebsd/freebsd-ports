PORTNAME=	zope.proxy
DISTVERSION=	5.2
CATEGORIES=	net python zope
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Generic Transparent Proxies
WWW=		https://pypi.org/project/zope.proxy/

LICENSE=	ZPL21

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=3.3.0:devel/py-zope.interface@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

CFLAGS+=	-Wno-error=incompatible-function-pointer-types

.include <bsd.port.mk>
