# New ports collection makefile for:	procmail
# Version required:     3.11pre3
# Date created:		24 September 1994
# Whom:			adam
#
# $Id: Makefile,v 1.16 1995/04/22 12:35:37 asami Exp $
#

DISTNAME=       procmail-3.11pre3
PKGNAME=        procmail-3.11.3
CATEGORIES+=	mail
MASTER_SITES=	ftp://ftp.informatik.rwth-aachen.de/pub/packages/procmail/

MAINTAINER=     ache@FreeBSD.ORG

IS_INTERACTIVE=	yes

do-install:
	@cd ${WRKSRC}; ${MAKE} install-suid install.man

.include <bsd.port.mk>
