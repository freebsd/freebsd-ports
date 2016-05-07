# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dpaste
PORTVERSION=	2.9
PORTREVISION=	1
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}django-

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Django based pastebin

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:www/py-django18 \
		${PYTHON_PKGNAMEPREFIX}django-mptt>=0.7.4:www/py-django-mptt \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.6:textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0.0:www/py-requests

OPTIONS_DEFINE=		MIGRATIONS

MIGRATIONS_DESC=	Schema and data migration support (via south)

MIGRATIONS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}south>=0.8.2:databases/py-south

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

GH_ACCOUNT=	bartTC

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} runtests.py

.include <bsd.port.mk>
