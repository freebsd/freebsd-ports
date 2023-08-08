PORTNAME=	django-reversion-compare
PORTVERSION=	0.14.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gettoknowmi@yahoo.com
COMMENT=	Extension to django-reversion that provides a history compare view
WWW=		https://github.com/jedie/django-reversion-compare

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}diff-match-patch>0:textproc/py-diff-match-patch@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
