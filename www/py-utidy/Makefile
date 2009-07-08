# New ports collection makefile for:	utidy
# Date created:				Wed Aug 29 21:37:35 CEST 2007
# Whom:					Stefan Esser <se@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	utidy
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	utidylib
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	uTidylib-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python interface to tidy-lib

# XXX Better depend on tidy or tidy-devel???
LIB_DEPENDS=	tidy-0.99.0:${PORTSDIR}/www/tidy-lib

USE_ZIP=	yes
USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	uTidylib

.include <bsd.port.mk>
