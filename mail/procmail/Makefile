# New ports collection makefile for:	procmail
# Version required:	3.10
# Date created:		24 September 1994
# Whom:			adam
#
# $Id: Makefile,v 1.12 1995/04/11 20:28:28 asami Exp $
#

DISTNAME=	procmail-3.10
CATEGORIES+=	mail
MASTER_SITES=	ftp://ftp.informatik.rwth-aachen.de/pub/packages/procmail/

IS_INTERACTIVE=	yes

install: build
.if !defined(BATCH)
	@echo "===>  Installing for ${DISTNAME}"
	@cd ${WRKSRC}; ${MAKE} install-suid install.man
.endif

.include <bsd.port.mk>
