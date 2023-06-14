PORTNAME=	pyramid_rpc
PORTVERSION=	0.8
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	RPC support for the Pyramid web framework
WWW=		https://pypi.org/project/pyramid_rpc/

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyramid>=0:www/py-pyramid@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
