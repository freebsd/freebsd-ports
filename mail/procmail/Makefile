# New ports collection makefile for:	procmail
# Version required:     3.11pre1
# Date created:		24 September 1994
# Whom:			adam
#
# $Id: Makefile,v 1.14 1995/04/16 13:49:07 ache Exp $
#

DISTNAME=       procmail-3.11pre1
PKGNAME=        procmail-3.11.1
CATEGORIES+=	mail
MASTER_SITES=	ftp://ftp.informatik.rwth-aachen.de/pub/packages/procmail/

MAINTAINER=     ache@FreeBSD.ORG

IS_INTERACTIVE=	yes

install: build
.if !defined(BATCH)
	@echo "===>  Installing for ${DISTNAME}"
	@cd ${WRKSRC}; ${MAKE} install-suid install.man
.endif

.include <bsd.port.mk>
