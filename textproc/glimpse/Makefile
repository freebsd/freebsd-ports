# New ports collection makefile for:	glimpse
# Version required:	3.6
# Date created:		25 August 1996
# Whom:			chuckr@freebsd.org
#
# $Id: Makefile,v 1.7 1996/11/17 09:05:49 obrien Exp $
#

DISTNAME=       glimpse-3.6.src
PKGNAME=	glimpse-3.6
CATEGORIES=	misc
MASTER_SITES=   ftp://ftp.cs.arizona.edu/glimpse/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	chuckr@freebsd.org

NO_CDROM=	"Restrictive copyright (don't sell for profit)"
GNU_CONFIGURE=	yes
MAN1=		glimpse.1 glimpseindex.1 glimpseserver.1 agrep.1

pre-configure:
	chmod ugo+x ${WRKSRC}/configure

post-install:
	${MKDIR} ${PREFIX}/share/doc/glimpse
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/glimpse
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/glimpse

.include <bsd.port.mk>
