# ex:ts=8
# Ports collection makefile for:	clarence
# Date created:			Jan 30, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	clarence
PORTVERSION=	0.4.4
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	http://clay.ll.pl/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programmer's calculator

BROKEN=		"Broken dependency after python 2.4 update"

USE_GNOME=	pygtk2
USE_REINPLACE=	yes
USE_PYTHON=	yes
PYTHON_VERSION=	python2.3
NO_BUILD=	yes
MAN1=		clarence.1
PLIST_FILES=	bin/clarence

post-patch:
	@${REINPLACE_CMD} -e "s,#!/usr/bin/python,#!/usr/bin/env python,g" ${WRKSRC}/clarence.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/clarence.py ${PREFIX}/bin/clarence
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
