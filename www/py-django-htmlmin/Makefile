PORTNAME=	django-htmlmin
PORTVERSION=	0.9.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	HTML minifier for Python
WWW=		https://pypi.org/project/django-htmlmin/

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/bs4/element.py:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_SITELIBDIR}/html5lib/html5parser.py:www/py-html5lib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
