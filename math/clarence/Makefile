# ex:ts=8
# Ports collection makefile for:	clarence
# Date created:			Jan 30, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	clarence
PORTVERSION=	0.2.0
CATEGORIES=	math python
MASTER_SITES=	http://clay.ll.pl/clarence/

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-1.2/GDK.py:${PORTSDIR}/x11-toolkits/py-gtk

USE_REINPLACE=	yes
USE_PYTHON=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
MAN1=	clarence.1

post-patch:
	@${REINPLACE_CMD} -e "s,#!/usr/bin/python,#!/usr/bin/env python,g" ${WRKSRC}/clarence.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/clarence.py ${PREFIX}/bin/clarence
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
