# New ports collection makefile for:    vscan
# Version required:     1.0.2
# Date created:         Thur Sept 25, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.6 1997/10/10 06:53:45 obrien Exp $
#

DISTNAME=	vfrb101e
PKGNAME=	vscan-1.0.2
CATEGORIES=	security
MASTER_SITES=   ftp://ftp.mcafee.com/pub/antivirus/unix/freebsd/
EXTRACT_SUFX=	.taz

MAINTAINER=     obrien@FreeBSD.org

BROKEN=		distfile no longer available

NO_WRKSUBDIR=	yes
RESTRICTED=	"Commercial software"

LIBDIR=	${PREFIX}/lib/mcafee
MAN1=	uvscan.1

pre-fetch:
.if defined(PREFIX) && ${PREFIX} != "/usr/local"
	@${ECHO} ""
	@${ECHO} "This software has /usr/local hardcoded into it."
	@${ECHO} "Sorry, but with PREFIX = ${PREFIX}, vscan will not work correctly."
	@${ECHO} ""
	@false
.endif

do-build::

# The binary executable file will be left unstripped as stripping the
# file will cause attempt to validate this file to fail.
do-install:
	(cd ${WRKSRC}; ./Install-vscan)

post-install:
	@/usr/sbin/chown ${BINOWN}.${BINGRP} ${PREFIX}/bin/uvscan
	@/usr/sbin/chown -R ${SHAREOWN}.${SHAREGRP} ${LIBDIR}
	@/usr/sbin/chown ${MANOWN}.${MANGRP} ${PREFIX}/man/man1/uvscan.1	
.if !defined(NOPORTDOCS)
	${MKDIR} -p ${PREFIX}/share/doc/vscan
	${INSTALL_DATA} ${WRKSRC}/Whatsnew.txt ${PREFIX}/share/doc/vscan
	${INSTALL_DATA} ${WRKSRC}/README.1ST ${PREFIX}/share/doc/vscan/vscan.LICENCE
.endif
	@${ECHO} ""
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
