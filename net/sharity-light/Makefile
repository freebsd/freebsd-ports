# New ports collection makefile for:	rumba
# Version required:	0.6
# Date created:		14 June 1997
# Whom:			Dmitrij Tejblum <dima@tejblum.dnttm.rssi.ru>
#
# $Id: Makefile,v 1.2 1997/07/21 19:28:46 max Exp $
#

DISTNAME=	rumba.0.6.s
PKGNAME=	rumba-0.6
CATEGORIES=	net
MASTER_SITES=	ftp://hal.kph.tuwien.ac.at/pub/NeXT/tools/rumba/ \
		ftp://ftp.obdev.at/pub/Products/rumba/
EXTRACT_SUFX=	.gnutar.gz

MAINTAINER=	dima@tejblum.dnttm.rssi.ru

USE_GMAKE=	yes
MAKE_ENV=	PWD=${WRKSRC}
MAN8=		smbmount.8

post-extract:
	@${MKDIR} work/unrumba
	@${CP} ${FILESDIR}/unrumba.c ${WRKDIR}/unrumba
	@${CP} files/Makefile.unrumba ${WRKDIR}/unrumba/Makefile

post-build:
	cd ${WRKDIR}/unrumba && make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rumba ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKDIR}/unrumba/unrumba ${PREFIX}/sbin
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/README.rumba
.endif
	${INSTALL_MAN} ${WRKSRC}/smbmount.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
