# New ports collection makefile for:   slrn
# Version required:    0.9.4.2
# Date created:        28 March 1997
# Whom:                Carey Jones <mcj@acquiesce.org>
# 
# $Id: Makefile,v 1.4 1997/07/09 10:21:56 max Exp $
#

DISTNAME=	slrn0.9.4.3
PKGNAME=	slrn-0.9.4.3
CATEGORIES=	news
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slrn/ \
		ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/ \
		ftp://ftp.prz.tu-berlin.de/pub/unix/news/reader/slrn/

MAINTAINER=	mcj@acquiesce.org

LIB_DEPENDS=	slang\\.0\\.99[0-9][0-9]:${PORTSDIR}/devel/libslang

WRKSRC=		${WRKDIR}/slrn
GNU_CONFIGURE=	yes
MAN1=		slrn.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/objs/slrn ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/examples/slrn
	${INSTALL_DATA} ${WRKSRC}/doc/slrn.rc ${PREFIX}/share/examples/slrn
	${INSTALL_MAN} ${WRKSRC}/doc/slrn.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
