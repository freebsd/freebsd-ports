# New ports collection makefile for:	py-djblets
# Date created:		2011-02-26
# Whom:			Li-Wen Hsu <lwhsu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	djblets
PORTVERSION=	0.6.7
CATEGORIES=	www python
MASTER_SITES=	http://downloads.reviewboard.org/releases/Djblets/${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Djblets-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	A collection of useful classes and functions for Django

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>=1.1.1:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}imaging>0:${PORTSDIR}/graphics/py-imaging

LICENSE=	MIT

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Djblets

.include <bsd.port.mk>
