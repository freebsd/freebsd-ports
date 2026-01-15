PORTNAME=	django-registration
PORTVERSION=	5.2.1
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	django_registration-${PORTVERSION}

MAINTAINER=	ports@caomhin.org
COMMENT=	User-registration application for Django
WWW=		https://github.com/ubernostrum/django-registration

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>0:devel/py-pdm-backend@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}confusable-homoglyphs>=3.0:devel/py-confusable-homoglyphs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django42>=4.2:www/py-django42@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}django-registration-redux

NO_ARCH=	yes

.include <bsd.port.mk>
