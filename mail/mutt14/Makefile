# ex:ts=8
# New ports collection makefile for:    mutt
# Version required:     0.xy
# Date created:         Thur July 25, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.6 1996/11/26 06:54:15 asami Exp $

DISTNAME=	${PKGNAME}-export
PKGNAME=	mutt-0.53
CATEGORIES=	mail
MASTER_SITES=	ftp://cs.hmc.edu/pub/me/mutt/  \
		ftp://ftp.ibp.fr/pub/unix/mail/mutt/  \
		ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/  \
		ftp://ftp.teuto.de/pub/user/lmb/  \
		ftp://ftp.funet.fi/pub/unix/mail/mutt/

PATCH_SITES=	ftp://nuxi.cs.ucdavis.edu/pub/mutt/${PKGNAME:S/^mutt-//}/  \
		http://www.frmug.org/mutt/mutt/${PKGNAME:S/^mutt-//}/  \
		http://www.math.fu-berlin.fr/~leitner/mutt/${PKGNAME:S/^mutt-//}/  \
		http://www.efrei.fr/~parmelan/mutt/${PKGNAME:S/^mutt-//}/  \
		ftp://www.frmug.org/pub/mutt/mutt/${PKGNAME:S/^mutt-//}/
PATCHFILES=

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
