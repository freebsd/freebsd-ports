# New ports collection makefile for:	grepmail
# Date created:				20 November 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

PORTNAME=	grepmail
PORTVERSION= 	4.31
CATEGORIES=	mail
MASTER_SITES=	http://download.sourceforge.net/grepmail/

MAINTAINER=	jedgar@FreeBSD.org

USE_PERL5=	yes
NO_BUILD=	yes
POD2MAN?=	/usr/bin/pod2man

MAN1=		grepmail.1

do-configure:
		@${PERL} -pi.orig -e 's|_PERL_|${PERL}|' ${WRKSRC}/grepmail.DP
		@cd ${WRKSRC} && ${CP} grepmail.DP grepmail
		@cd ${WRKSRC} && ${POD2MAN} grepmail > grepmail.1

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/grepmail ${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/grepmail.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
