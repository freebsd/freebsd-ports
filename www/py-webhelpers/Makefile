# New ports collection makefile for:	py-webhelpers
# Date created:		Thu Jun 21 12:44:46 MSD 2007
# Whom:			Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	webhelpers
PORTVERSION=	1.2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	WebHelpers-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python helper functions for writing templates in web applications

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}routes>=1.1:${PORTSDIR}/www/py-routes \
		${PYTHON_PKGNAMEPREFIX}simplejson>=1.4:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}MarkupSafe>=0.11:${PORTSDIR}/textproc/py-MarkupSafe

USE_PYTHON=		2.5+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	WebHelpers

.include <bsd.port.mk>
