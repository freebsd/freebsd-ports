# New ports collection makefile for:	procmail
# Version required:	3.10
# Date created:		24 September 1994
# Whom:			adam
#
# $Id: Makefile,v 1.10 1995/03/05 04:18:05 jkh Exp $
#

DISTNAME=	procmail-3.10
MASTER_SITES=	ftp://ftp.informatik.rwth-aachen.de/pub/packages/procmail/
CATEGORIES+=	mail
IS_INTERACTIVE=	yes

install:
.if !defined(BATCH)
	@echo "===>  Installing for ${DISTNAME}"
	@cd ${WRKSRC}; ${MAKE} install-suid install.man
.endif

.include <bsd.port.mk>
