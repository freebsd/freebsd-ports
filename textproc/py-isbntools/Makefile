PORTNAME=	isbntools
PORTVERSION=	4.3.29
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	App and framework for all things about ISBN
WWW=		https://github.com/xlcnd/isbntools

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE-LGPL-3.0.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}isbnlib>=3.10.9<3.11.0:textproc/py-isbnlib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
