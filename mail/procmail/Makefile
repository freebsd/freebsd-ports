# New ports collection makefile for:	procmail
# Version required:	3.10
# Date created:		24 September 1994
# Whom:			adam
#
# $Id: Makefile,v 1.5 1994/10/08 15:31:10 ache Exp $
#

DISTNAME=       procmail-3.10pre5
MASTER_SITES=	ftp://ftp.informatik.rwth-aachen.de/pub/packages/procmail/

install:
	@echo "===>  Installing for ${DISTNAME}"
	@cd ${WRKSRC}; ${MAKE} MANCOMPRESS=gzip MAN1SUFFIX=1.gz MAN5SUFFIX=5.gz install-suid install.man

.include <bsd.port.mk>
