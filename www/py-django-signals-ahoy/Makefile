# New ports collection makefile for:	py-django-signals-ahoy
# Date created:				8 December 2009
# Whom:					Kevin Golding <ports@caomhin.org>
#
# $FreeBSD$
#

PORTNAME=	django-signals-ahoy
PORTVERSION=	0.1.0
CATEGORIES=	www python
MASTER_SITES=	http://cdn.bitbucket.org/bkroeze/django-signals-ahoy/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION:C/([[:digit:]]\.[[:digit:]])\./\1-/g}

MAINTAINER=	ports@caomhin.org
COMMENT=	An extended set of signals for use by Django apps.

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:${PORTSDIR}/www/py-django

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_NOEGGINFO=	yes
PYEASYINSTALL_EGG=	${PYDISTUTILS_PKGNAME:C/[^A-Za-z0-9.]+/_/g}-${PORTVERSION:C/([[:digit:]]\.[[:digit:]])\./\1_/g}-${PYTHON_VERSION:S/thon//}${PYEASYINSTALL_OSARCH}.egg
PYEASYINSTALL_UNINSTALLARGS=	-q -m -S ${PYTHON_SITELIBDIR} \
			${PYDISTUTILS_PKGNAME}==${PYDISTUTILS_PKGVERSION:C/([[:digit:]]\.[[:digit:]])\./\1_/g}

.include <bsd.port.mk>
