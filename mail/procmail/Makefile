# New ports collection makefile for:	procmail
# Version required:	3.10
# Date created:		24 September 1994
# Whom:			adam
#
# $Id: Makefile,v 1.3 1994/10/07 01:01:27 ache Exp $
#

DISTNAME=       procmail-3.10pre4
MASTER_SITES=	ftp://ftp.informatik.rwth-aachen.de/pub/packages/procmail/

install:
	@echo "===>  Installing for ${DISTNAME}"
	@cd ${WRKSRC}; ${MAKE} MANCOMPRESS=gzip COMPSUFFIX=.gz install-suid install.man

.include <bsd.port.mk>
