PORTNAME=	django-htmlmin
PORTVERSION=	0.9.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	HTML minifier for Python

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/bs4/element.py:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/html5lib/html5parser.py:www/py-html5lib@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
