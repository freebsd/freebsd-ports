PORTNAME=	django-csp
PORTVERSION=	3.8
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_csp-${PORTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Adds Content-Security-Policy headers to Django
WWW=		https://github.com/mozilla/django-csp

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django32>=3.2:www/py-django32@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	JINJA2
OPTIONS_DEFAULT=	JINJA2

JINJA2_DESC=	Support for Django templates via Jinja2
JINJA2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.9.6:devel/py-Jinja2@${PY_FLAVOR}

.include <bsd.port.mk>
