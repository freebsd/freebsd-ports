# New ports collection makefile for:	procmail
# Version required:	3.10
# Date created:		24 September 1994
# Whom:			adam
#
# $Id$
#

DISTNAME=	procmail-3.10pre3
MASTER_SITES=	ftp://ftp.informatik.rwth-aachen.de/pub/packages/procmail/

install:
	@echo "===>  Installing for ${DISTNAME}"
	@cd ${WRKSRC}; ${MAKE} install-suid

.include <bsd.port.mk>
