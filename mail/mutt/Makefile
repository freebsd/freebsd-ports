# ex:ts=8
# New ports collection makefile for:    mutt
# Version required:     0.xy
# Date created:         Thur July 25, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.11 1996/12/08 06:33:38 obrien Exp $

DISTNAME=	${PKGNAME}-export
PKGNAME=	mutt-0.54
CATEGORIES=	mail
MASTER_SITES=	ftp://cs.hmc.edu/pub/me/mutt/  \
		ftp://ftp.ibp.fr/pub/unix/mail/mutt/  \
		ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/  \
		ftp://ftp.teuto.de/pub/user/lmb/  \
		ftp://ftp.funet.fi/pub/unix/mail/mutt/

PATCH_SITES=	ftp://nuxi.cs.ucdavis.edu/pub/mutt/${PKGNAME:S/^mutt-//}/  \
		http://www.frmug.org/mutt/mutt/${PKGNAME:S/^mutt-//}/  \
		http://www.math.fu-berlin.de/~leitner/mutt/${PKGNAME:S/^mutt-//}/  \
		http://www.efrei.fr/~parmelan/mutt/${PKGNAME:S/^mutt-//}/  \
		ftp://www.frmug.org/pub/mutt/mutt/${PKGNAME:S/^mutt-//}/
PATCHFILES=	02.control.PATCH  \
		03.fileio.PATCH  \
		04.parse.PATCH  \
		05.url.PATCH  \
		06.init.PATCH  \
		08.dirlist.PATCH  \
		09.complete.PATCH  \
		10.prefix.PATCH  \
		11.batchmode.PATCH  \
		12.folderrecog.PATCH  \
		14.savename.PATCH  \
		15.postponed.PATCH
#		don't apply cleanly:
#		13.pagercontext.PATCH  \

MAINTAINER=     obrien@cs.ucdavis.edu

DIST_SUBDIR=	mutt
WRKSRC=		${WRKDIR}/${PKGNAME}
#PATCH_DIST_STRIP=	-p2
PATCH_DIST_STRIP=	
GNU_CONFIGURE=	yes
MAN1=		mutt.1


post-install:
	@####   don't strip until out of beta peroid
	@#strip ${PREFIX}/bin/mutt
.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing Mutt documentation"
	@${MKDIR} ${PREFIX}/share/doc/mutt && chmod a+rx ${PREFIX}/share/doc/mutt
	@${INSTALL_DATA} ${WRKSRC}/doc/*  \
		${PREFIX}/share/doc/mutt
.endif

.include <bsd.port.mk>
