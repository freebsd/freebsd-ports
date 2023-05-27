PORTNAME=	diff-match-patch
PORTVERSION=	20230430
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Algorithms for converting plain text
WWW=		https://github.com/diff-match-patch-python/diff-match-patch

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.8<4:devel/py-flit-core@${PY_FLAVOR}

USES=		python:3.6+ shebangfix
USE_PYTHON=	autoplist concurrent pep517 unittest

NO_ARCH=	yes

python_OLD_CMD=	/usr/bin/python[0-9\.]*
SHEBANG_GLOB=	*.py

.include <bsd.port.mk>
