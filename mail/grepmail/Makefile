# New ports collection makefile for:	grepmail
# Version required:			4.1
# Date created:				20 November 1999
# Whom:					Chris D. Faulhaber <jedgar@fxp.org>
#
# $FreeBSD$
#

DISTNAME=	grepmail-4.1
CATEGORIES=	mail
MASTER_SITES=	http://www.cs.virginia.edu/~dwc3q/code/

MAINTAINER=	jedgar@fxp.org

NO_BUILD=	yes

do-configure:
		@cd ${WRKSRC} && ${CP} grepmail.DP grepmail

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/grepmail ${PREFIX}/bin

.include <bsd.port.mk>
