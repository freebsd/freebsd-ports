# New ports collection makefile for:    rsync
# Version required:     0.37
# Date created:         Sat Aug 3, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.5 1995/04/24 03:38:04 asami Exp $
#

DISTNAME=	rsync-1.5.1
CATEGORIES+=	net
MASTER_SITES=	ftp://samba.anu.edu.au/pub/rsync/

MAINTAINER=     obrien@cs.ucdavis.edu

GNU_CONFIGURE=	yes

post-install:
	strip ${PREFIX}/bin/rsync
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/rsync.1
.endif
.if !defined(NOPORTDOCS)
	mkdir -p ${PREFIX}/share/doc/rsync
	${INSTALL_DATA} ${WRKSRC}/tech_report.ps ${PREFIX}/share/doc/rsync
.endif

.include <bsd.port.mk>
