PORTNAME=	python-slugify
PORTVERSION=	9.2.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Slugify application that handles unicode
WWW=		https://github.com/un33k/python-slugify

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}text-unidecode>=1.3:converters/py-text-unidecode@${PY_FLAVOR}

### Can optionally require:
### 	${PYTHON_PKGNAMEPREFIX}unidecode>=1.1.1:converters/py-unidecode@${PY_FLAVOR}
###     ${PYTHON_PKGNAMEPREFIX}anyascii>=0.3.2:textproc/py-anyascii@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
