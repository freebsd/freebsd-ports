# New ports collection makefile for:	procmail
# Version required:	3.10
# Date created:		24 September 1994
# Whom:			adam
#
# $Id: Makefile,v 1.2 1994/10/07 00:51:13 ache Exp $
#

DISTNAME=       procmail-3.10pre4
MASTER_SITES=	ftp://ftp.informatik.rwth-aachen.de/pub/packages/procmail/

install:
	@echo "===>  Installing for ${DISTNAME}"
	@cd ${WRKSRC}; ${MAKE} install-suid install.man

.include <bsd.port.mk>
