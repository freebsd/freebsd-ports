# ex:ts=8
# New ports collection makefile for:    mutt
# Version required:     0.xy
# Date created:         Thur July 25, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.16 1997/01/19 02:11:50 obrien Exp $

DISTNAME=	${PKGNAME}e
PKGNAME=	mutt-0.58
CATEGORIES=	mail
MASTER_SITES=	ftp://cs.hmc.edu/pub/me/mutt/  \
		ftp://ftp.ibp.fr/pub/unix/mail/mutt/  \
		ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/  \
		ftp://ftp.teuto.de/pub/user/lmb/  \
		ftp://ftp.funet.fi/pub/unix/mail/mutt/

PATCH_SITES=	http://www.frmug.org/mutt/mutt/${PKGNAME:S/^mutt-//}/  \
		ftp://ftp.nuxi.com/pub/mutt/${PKGNAME:S/^mutt-//}/  \
		http://www.math.fu-berlin.de/~leitner/mutt/${PKGNAME:S/^mutt-//}/  \
		http://www.efrei.fr/~parmelan/mutt/${PKGNAME:S/^mutt-//}/  \
		ftp://www.frmug.org/pub/mutt/mutt/${PKGNAME:S/^mutt-//}/
PATCHFILES=	05.save_redraw.PATCH  \
		06.limit_redraw.PATCH  \
		08.newline.PATCH  \
		09.remove_xrefs.PATCH  \
		11.toggle-quoted.PATCH  \
		12.print-message.PATCH  \
		13.consistency+others.PATCH  \
		14.next-undeleted.PATCH  \
		15.keypad.PATCH  \
#	these don't patch cleanly and are experimental:
#		10.list_attrib.PATCH  \
#		07.pipe-message.PATCH  \

MAINTAINER=     obrien@FreeBSD.org

DIST_SUBDIR=	mutt
WRKSRC=		${WRKDIR}/${PKGNAME}
PATCH_DIST_STRIP=	-p2
#PATCH_DIST_STRIP=	-p1
#PATCH_DIST_STRIP=	
GNU_CONFIGURE=	yes
MAN1=		mutt.1


post-install:
	@####   don't strip until out of beta peroid
	@#strip ${PREFIX}/bin/mutt
.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing Mutt documentation"
	@${MKDIR} ${PREFIX}/share/doc/mutt && chmod a+rx ${PREFIX}/share/doc/mutt
	@${INSTALL_DATA} ${WRKSRC}/doc/*.latin1 ${WRKSRC}/doc/*.html  \
		${PREFIX}/share/doc/mutt
.endif

.include <bsd.port.mk>
