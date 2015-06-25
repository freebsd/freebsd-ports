# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dpaste
PORTVERSION=	2.8
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}django-

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Django based pastebin

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:${PORTSDIR}/www/py-django16 \
		${PYTHON_PKGNAMEPREFIX}django-mptt>=0.6.0:${PORTSDIR}/www/py-django-mptt \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.6:${PORTSDIR}/textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0.0:${PORTSDIR}/www/py-requests

OPTIONS_DEFINE=		MIGRATIONS

MIGRATIONS_DESC=	Schema and data migration support (via south)

MIGRATIONS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}south>=0.8.2:${PORTSDIR}/databases/py-south

USES=		python
USE_PYTHON=	autoplist distutils

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} runtests.py

.include <bsd.port.mk>
