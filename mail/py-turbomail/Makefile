# New ports collection makefile for:	py-turbomail
# Date created:		2007-01-24
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	turbomail
PORTVERSION=	3.0.3
PORTREVISION=	2
CATEGORIES=	mail www python
MASTER_SITES=	CHEESESHOP \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TurboMail-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Multi-threaded mail queue manager for TurboGears applications

BUILD_DEPENDS=	tg-admin:${PORTSDIR}/www/py-turbogears
RUN_DEPENDS=	${BUILD_DEPENDS}

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TurboMail

.include <bsd.port.mk>
