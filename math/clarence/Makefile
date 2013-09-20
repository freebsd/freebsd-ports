# Created by: ijliao
# $FreeBSD$

PORTNAME=	clarence
PORTVERSION=	0.4.4
PORTREVISION=	8
CATEGORIES=	math python
MASTER_SITES=	http://www.sourcefiles.org/Productivity_Tools/Calculators/ \
		ftp://ftp.tu-chemnitz.de/.SAN0/pub/linux/sunsite.unc-mirror/distributions/sourcemage/grimoire/fallback/fallback/

MAINTAINER=	psh@iki.fi
COMMENT=	Programmer's calculator

USE_GNOME=	pygtk2
USE_PYTHON=	yes
NO_BUILD=	yes
MAN1=		clarence.1
PLIST_FILES=	bin/clarence

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s,#!/usr/bin/python,#!/usr/bin/env python,g" ${WRKSRC}/clarence.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/clarence.py ${PREFIX}/bin/clarence
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
