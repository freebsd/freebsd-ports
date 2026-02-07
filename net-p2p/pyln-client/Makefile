PORTNAME=	pyln-client
PORTVERSION=	23.11
CATEGORIES=	net-p2p python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	vd@FreeBSD.org
COMMENT=	Python client library for lightningd (net-p2p/c-lightning)
WWW=		https://github.com/ElementsProject/lightning/tree/master/contrib/pyln-client

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=0:devel/py-poetry-core@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist pep517
SHEBANG_FILES=	pyln/client/gossmap.py

NO_ARCH=	yes

.include <bsd.port.mk>
