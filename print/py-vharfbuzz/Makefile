PORTNAME=	vharfbuzz
PORTVERSION=	0.1.4
CATEGORIES=	print python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	User-friendlier way to use Harfbuzz in Python
WWW=		https://github.com/simoncozens/vharfbuzz

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools>=0:print/py-fonttools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uharfbuzz>=0:print/py-uharfbuzz@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
