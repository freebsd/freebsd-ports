# New ports collection makefile for:	glimpse
# Version required:     4.*
# Date created:		25 August 1996
# Whom:			chuckr@freebsd.org
#
# $Id: Makefile,v 1.14 1998/10/13 23:37:06 jseger Exp $
#

DISTNAME=       glimpse-4.1.src
PKGNAME=        glimpse-4.1
CATEGORIES=	textproc databases
MASTER_SITES=   ftp://ftp.cs.arizona.edu/glimpse/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	chuckr@freebsd.org

WRKSRC=         ${WRKDIR}/glimpse-4.1
USE_GMAKE=	yes
NO_CDROM=	"Restrictive copyright (don't sell for profit)"
GNU_CONFIGURE=	yes
CONFIGURE_ENV=  CFLAGS="${CFLAGS} -DISO_CHAR_SET=1"
MAN1=		glimpse.1 glimpseindex.1 glimpseserver.1 agrep.1

pre-configure:
	chmod ugo+x ${WRKSRC}/configure

post-install:
	${MKDIR} ${PREFIX}/share/doc/glimpse
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/glimpse
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/glimpse
	${INSTALL_PROGRAM} ${WRKSRC}/index/wgconvert ${PREFIX}/bin

.include <bsd.port.mk>
