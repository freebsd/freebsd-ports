# New ports collection makefile for:	py-django-appconf
# Date created:				13 April 2012
# Whom:					Ruslan Mahmatkhanov <rm@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	django-appconf
PORTVERSION=	0.5
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	A helper class for handling configuration defaults gracefully

LICENSE=	BSD

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	${PORTNAME:S/-/_/}

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
