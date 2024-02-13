PORTNAME=	pyln-bolt7
PORTVERSION=	1.0.246
CATEGORIES=	net-p2p python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Lightning Network BOLT7 implementation
WWW=		https://github.com/ElementsProject/lightning/tree/master/contrib/pyln-spec/bolt7

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=0:devel/py-poetry-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
