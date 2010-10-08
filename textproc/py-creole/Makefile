# New ports collection makefile for:	py-creole
# Date created:			May 27 2009
# Whom:				Stanislav Svirid <count@211.ru>
#
# $FreeBSD$
#

PORTNAME=	creole
PORTVERSION=	0.2.8
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	count@211.ru
COMMENT=	Python lib for creole markup

LICENSE=	GPLv3

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	python_creole

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
