# New ports collection makefile for:	grpn
# Date created:				25 October 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	grpn
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://lashwhip.com/grpn/

MAINTAINER=	jedgar@FreeBSD.org
COMMENT=	GTK+-based reverse polish notation (RPN) calculator

USE_X_PREFIX=	yes
USE_GNOME=	gtk12

ALL_TARGET=

MAN1=		grpn.1
PLIST_FILES=	bin/grpn

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/grpn ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/grpn.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
