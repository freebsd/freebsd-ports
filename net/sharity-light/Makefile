# New ports collection makefile for:	rumba
# Version required:	0.6
# Date created:		14 June 1997
# Whom:			Dmitrij Tejblum <dima@tejblum.dnttm.rssi.ru>
#
# $Id: Makefile,v 1.3 1998/06/04 04:18:39 vanilla Exp $
#

DISTNAME=	rumba.0.6a.s
PKGNAME=	rumba-0.6a
CATEGORIES=	net
MASTER_SITES=	ftp://hal.kph.tuwien.ac.at/pub/NeXT/tools/rumba/ \
		ftp://ftp.obdev.at/pub/Products/rumba/
EXTRACT_SUFX=	.gnutar.gz

MAINTAINER=	dt@FreeBSD.ORG

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
	${MKDIR} ${PREFIX}/share/doc/rumba
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/rumba/README
	${INSTALL_DATA} ${WRKSRC}/FAQ.txt ${PREFIX}/share/doc/rumba/FAQ
.endif
	${INSTALL_MAN} ${WRKSRC}/smbmount.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
