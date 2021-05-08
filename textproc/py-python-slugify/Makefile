PORTNAME=	python-slugify
PORTVERSION=	5.0.2
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Slugify application that handles unicode

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}text-unidecode>=1.3:converters/py-text-unidecode@${PY_FLAVOR}

### Can alternatively require:
### 	${PYTHON_PKGNAMEPREFIX}unidecode>=1.1.1:converters/py-unidecode@${PY_FLAVOR}
### but text-unidecode is preferred upstream.

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
