# New ports collection makefile for:    rpcalc
# Date created:                         31 January 2010
# Whom:                                 Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	rpcalc
PORTVERSION=	0.6.0
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	BERLIOS

MAINTAINER=	edwin@mavetju.org
COMMENT=	Simple RPN calculator

RUN_DEPENDS=	${PYTHON_SITELIBDIR}//PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui

WRKSRC=		${WRKDIR}/rpCalc

NO_BUILD=	yes
USE_PYTHON=	yes

do-install:
	cd ${WRKSRC} && ${PYTHON_CMD} install.py

.include <bsd.port.mk>
