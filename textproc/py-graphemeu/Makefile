PORTNAME=	graphemeu
PORTVERSION=	0.9.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI \
		https://github.com/timendum/grapheme/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Unicode grapheme helpers
WWW=		https://graphemeu.readthedocs.io/en/latest/ \
		https://github.com/timendum/grapheme

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
