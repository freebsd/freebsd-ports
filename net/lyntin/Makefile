# New ports collection makefile for:	lyntin
# Date created:				Dec 09 2004
# Whom:					ste
#
# $FreeBSD$
#

PORTNAME=	lyntin
PORTVERSION=	4.1.1
CATEGORIES=	net games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	stefan@aeschbacher.ch
COMMENT=	A highly configurable client program to help playing muds

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
