# New ports collection makefile for:	grpn
# Date created:				25 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	grpn
PORTVERSION=	1.1.2
CATEGORIES=	math
MASTER_SITES=	http://lashwhip.com/grpn/

MAINTAINER=	jedgar@FreeBSD.org

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12

ALL_TARGET=

MAN1=		grpn.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/grpn ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/grpn.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
