# ex:ts=8
# New ports collection makefile for:    rsync
# Version required:     1.6.2
# Date created:         Sat Aug 3, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

DISTNAME=	rsync-2.3.1
CATEGORIES=	net
MASTER_SITES=	ftp://samba.anu.edu.au/pub/rsync/  \
		ftp://sunsite.auc.dk/pub/unix/rsync/  \
		ftp://ftp.sunet.se/pub/unix/admin/rsync/  \
		ftp://ftp.fu-berlin.de/pub/unix/network/rsync/

MAINTAINER=     obrien@FreeBSD.org

Y2K=		http://rsync.samba.org/rsync/y2k.html

GNU_CONFIGURE=	yes
MAN1=		rsync.1
MAN5=		rsyncd.conf.5

pre-configure:
	@${PERL} -pi.orig -e 's:/etc/:${PREFIX}/etc/:g' ${WRKSRC}/rsync.1
	@${PERL} -pi.orig -e 's:/etc/:${PREFIX}/etc/:g' ${WRKSRC}/rsyncd.conf.5

post-install:
	@strip ${PREFIX}/bin/rsync
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/rsync
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/rsync
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/rsync
	${INSTALL_DATA} ${WRKSRC}/tech_report.tex ${PREFIX}/share/doc/rsync
.endif

.include <bsd.port.mk>
