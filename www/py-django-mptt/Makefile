# Created by: Carlo Strub
# $FreeBSD$

PORTNAME=	django-mptt
PORTVERSION=	0.5.4
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Utilities for implementing a pre-order traversal tree in django

LICENSE=	BSD

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:${PORTSDIR}/www/py-django
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:${PORTSDIR}/www/py-django

USE_GITHUB=	yes
GH_ACCOUNT=	django-mptt
GH_COMMIT=	4310e7e
GH_TAGNAME=	${PORTVERSION}

USES=		gettext
USE_PYDISTUTILS=yes
USE_PYTHON=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
