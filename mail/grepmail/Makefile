# New ports collection makefile for:	grepmail
# Date created:				20 November 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	grepmail
PORTVERSION= 	4.23
CATEGORIES=	mail
MASTER_SITES=	http://download.sourceforge.net/grepmail/

MAINTAINER=	jedgar@FreeBSD.org

NO_BUILD=	yes
POD2MAN?=	/usr/bin/pod2man

MAN1=		grepmail.1

do-configure:
		@cd ${WRKSRC} && ${CP} grepmail.DP grepmail
		@cd ${WRKSRC} && ${POD2MAN} grepmail > grepmail.1

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/grepmail ${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/grepmail.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
