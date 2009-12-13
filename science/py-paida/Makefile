# New ports collection makefile for:	paida
# Date created:		2005-07-17
# Whom:			Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	paida
PORTVERSION=	3.2.1.2.10
CATEGORIES=	science python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-3.2.1_2.10.1
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-3.2.1_2.10.1

MAINTAINER=	wenheping@gmail.com
COMMENT=	Pure Python scientific analysis package

.if !defined(NO_GUI)
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter
.endif

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGVERSION=	3.2.1_2.10.1

.include <bsd.port.mk>
