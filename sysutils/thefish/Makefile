# New ports collection makefile for:	thefish
# Date created:			Sat Mar 16 17:49:09 CET 2002
# Whom:				Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	thefish
PORTVERSION=	0.2.1
CATEGORIES=	sysutils
MASTER_SITES=	http://energyhq.homeip.net/files/

MAINTAINER=	flynn@energyhq.homeip.net

USE_X_PREFIX=	yes
USE_GTK=	yes

MAN1=		thefish.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/thefish ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/thefish.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
