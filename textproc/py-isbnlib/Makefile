PORTNAME=	isbnlib
PORTVERSION=	3.10.14
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extract, clean, transform, hyphenate and metadata for ISBNs
WWW=		https://github.com/xlcnd/isbnlib

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE-LGPL-3.0.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
