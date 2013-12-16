# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dpaste
PORTVERSION=	2.1
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}django-

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Pastebin Django application that powers dpaste.de

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>=1.4:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}django-mptt>=0.6.0:${PORTSDIR}/www/py-django-mptt \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.6:${PORTSDIR}/textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}requests>=1.0.0:${PORTSDIR}/www/py-requests

OPTIONS_DEFINE=	MIGRATIONS

MIGRATIONS_DESC=	Schema and data migration support (via south)
MIGRATIONS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}south>=0.8.2:${PORTSDIR}/databases/py-south

USE_GITHUB=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

GH_ACCOUNT=	bartTC
GH_COMMIT=	4ffd0ed

.include <bsd.port.mk>
