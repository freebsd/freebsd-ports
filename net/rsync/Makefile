# New ports collection makefile for:    rsync
# Version required:     1.6.2
# Date created:         Sat Aug 3, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.8 1997/10/06 03:46:50 obrien Exp $
#

DISTNAME=	rsync-1.6.3
CATEGORIES=	net
MASTER_SITES=	ftp://samba.anu.edu.au/pub/rsync/  \
		ftp://sunsite.auc.dk/pub/unix/rsync/

MAINTAINER=     obrien@FreeBSD.org

GNU_CONFIGURE=	yes
MAN1=		rsync.1

post-patch:
	@${CP} ${FILESDIR}/clientserver.c ${WRKSRC}
	@${CP} ${FILESDIR}/README.daemon ${WRKSRC}
	@${CP} ${FILESDIR}/rsyncd_trees.eg ${WRKSRC}

post-install:
	@strip ${PREFIX}/bin/rsync
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/rsync
	${INSTALL_DATA} ${WRKSRC}/tech_report.ps ${PREFIX}/share/doc/rsync
	${INSTALL_DATA} ${FILESDIR}/README.daemon ${PREFIX}/share/doc/rsync
	${INSTALL_DATA} ${FILESDIR}/rsyncd_trees.eg ${PREFIX}/share/doc/rsync
.endif

.include <bsd.port.mk>
