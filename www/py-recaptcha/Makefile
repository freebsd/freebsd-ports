# New ports collection makefile for:	py-recaptcha
# Date created:				20 Mar 2009
# Whom:					Philip Paeps <philip@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	recaptcha
PORTVERSION=	1.0.5
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITE_CHEESESHOP}
MASTER_SITE_SUBDIR=	source/r/recaptcha-client
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-client-${PORTVERSION}

MAINTAINER=	philip@FreeBSD.org
COMMENT=	A plugin for reCAPTCHA and reCAPTCHA Mailhide

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	recaptcha_client
PYDISTUTILS_NOEGGINFO=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/${PYDISTUTILS_PKGNAME}-${PORTVERSION}-py${PYTHON_VER}.egg

.include <bsd.port.mk>
