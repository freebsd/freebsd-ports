# New ports collection makefile for:    psutils
# Version required:     1.13
# Date created:         21 September 1994
# Whom:                 jmz
#
# $Id$
#

DISTNAME=	psutils-1.13
CATEGORIES+=	printing
MASTER_SITES=	ftp://ftp.sunet.se/pub/text-processing/postscript/utilities/psutils/

MAINTAINER=	jmz@FreeBSD.org

WRKSRC=		$(WRKDIR)/src-1.3

pre-install:
	@mkdir -p ${PREFIX}/share/psutils
	@mkdir -p ${PREFIX}/man/man1
	@mkdir -p ${PREFIX}/bin

.include <bsd.port.mk>
