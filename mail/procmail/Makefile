# New ports collection makefile for:	procmail
# Version required:	3.10
# Date created:		24 September 1994
# Whom:			adam
#
# $Id: Makefile,v 1.8 1994/11/19 12:29:15 ats Exp $
#

DISTNAME=       procmail-3.10
MASTER_SITES=	ftp://ftp.informatik.rwth-aachen.de/pub/packages/procmail/
IS_INTERACTIVE=	yes

install:
	@echo "===>  Installing for ${DISTNAME}"
	@cd ${WRKSRC}; ${MAKE} install-suid install.man

.include <bsd.port.mk>
