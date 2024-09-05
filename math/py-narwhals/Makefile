PORTNAME=	narwhals
PORTVERSION=	1.4.2
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extremely lightweight compatibility layer between dataframe libraries
WWW=		https://narwhals-dev.github.io/narwhals/ \
		https://github.com/narwhals-dev/narwhals

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
