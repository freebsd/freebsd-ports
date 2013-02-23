# Created by: John Hixson <john@ixsystems.com>
# $FreeBSD$

PORTNAME=	djangotoolbox
PORTVERSION=	0.9.2
CATEGORIES=	www python
MASTER_SITES=	https://github.com/django-nonrel/djangotoolbox/archive/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	develop

MAINTAINER=	john@ixsystems.com
COMMENT=	A common API for running Django on non-relational/NoSQL databases

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:${PORTSDIR}/www/py-django

USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

FETCH_ARGS=	-Fpr

WRKSRC=	${WRKDIR}/djangotoolbox-develop

.include <bsd.port.mk>
