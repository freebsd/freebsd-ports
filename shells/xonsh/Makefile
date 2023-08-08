PORTNAME=	xonsh
PORTVERSION=	0.11.0
CATEGORIES=	shells python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	roberfern@gmail.com
COMMENT=	Python-ish BASH-wards shell
WWW=		https://xon.sh

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/license

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}amalgamate>=0:devel/py-amalgamate@${PY_FLAVOR}

NO_ARCH=	yes

USES=		python
USE_PYTHON=	distutils autoplist concurrent

.include <bsd.port.mk>
