# New ports collection makefile for:    rsync
# Version required:     1.6.2
# Date created:         Sat Aug 3, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.6 1997/09/28 04:49:41 peter Exp $
#

DISTNAME=	rsync-1.6.2
CATEGORIES=	net
MASTER_SITES=	ftp://samba.anu.edu.au/pub/rsync/  \
		ftp://sunsite.auc.dk/pub/unix/rsync/

MAINTAINER=     obrien@cs.ucdavis.edu

GNU_CONFIGURE=	yes
MAN1=		rsync.1

post-patch:
	cp ${FILESDIR}/clientserver.c ${WRKSRC}
	cp ${FILESDIR}/README.daemon ${WRKSRC}
	cp ${FILESDIR}/rsyncd_trees.eg ${WRKSRC}

post-install:
	@strip ${PREFIX}/bin/rsync
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/rsync
	${INSTALL_DATA} ${WRKSRC}/tech_report.ps ${PREFIX}/share/doc/rsync
	${INSTALL_DATA} ${FILESDIR}/README.daemon ${PREFIX}/share/doc/rsync
	${INSTALL_DATA} ${FILESDIR}/rsyncd_trees.eg ${PREFIX}/share/doc/rsync
.endif

.include <bsd.port.mk>
