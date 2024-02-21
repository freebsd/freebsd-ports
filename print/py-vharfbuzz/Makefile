PORTNAME=	vharfbuzz
PORTVERSION=	0.3.0
CATEGORIES=	print python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	User-friendlier way to use Harfbuzz in Python
WWW=		https://github.com/simoncozens/vharfbuzz

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uharfbuzz>=0.34.0:print/py-uharfbuzz@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
