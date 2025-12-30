PORTNAME=	django-tagging
PORTVERSION=	0.5.0
PORTREVISION=	4
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Generic tagging application for Django
WWW=		https://github.com/Fantomas42/django-tagging

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Upstream inactive since 5+ years, not compatible with Django 5+. Please use www/py-django-taggit instead
EXPIRATION_DATE=2026-03-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=0:www/py-django42@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
