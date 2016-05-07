# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	django-mezzanine
PORTVERSION=	3.1.10
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Mezzanine-${PORTVERSION}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Content management platform built using the Django framework

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:www/py-django16 \
		${PYTHON_PKGNAMEPREFIX}django-mezzanine-filebrowser>=0.3.4:www/py-django-mezzanine-filebrowser \
		${PYTHON_PKGNAMEPREFIX}django-mezzanine-grappelli>=0.3.12:www/py-django-mezzanine-grappelli \
		${PYTHON_PKGNAMEPREFIX}tzlocal>=1.0:devel/py-tzlocal \
		${PYTHON_PKGNAMEPREFIX}bleach>=1.4:www/py-bleach \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.1.3:www/py-beautifulsoup \
		${PYTHON_PKGNAMEPREFIX}requests>=2.1.0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>=0.4:www/py-requests-oauthlib \
		${PYTHON_PKGNAMEPREFIX}future>=0.9.0:devel/py-future \
		${PYTHON_PKGNAMEPREFIX}pillow>=1.3.1:graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}django-contrib-comments>0:www/py-django-contrib-comments \
		${PYTHON_PKGNAMEPREFIX}south>=0.7.3:databases/py-south \

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pep8>=1.4.1:devel/pep8 \
		${PYTHON_PKGNAMEPREFIX}pyflakes>=0.6.1:devel/py-pyflakes

USES=		gettext python
USE_PYTHON=	autoplist distutils

do-test:
	@cd ${WRKSRC} && ${SETENV} TZ=UTC LC_ALL=en_US.UTF-8 ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
