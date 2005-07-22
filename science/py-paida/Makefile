# New ports collection makefile for:	paida
# Date created:		2005-07-17
# Whom:			Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	paida
PORTVERSION=	3.2.1.2.8
CATEGORIES=	science python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	paida
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-3.2.1_2.8

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Pure Python scientific analysis package

.if !defined(NO_GUI)
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter
.endif

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
