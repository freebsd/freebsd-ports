# ex:ts=8
# New ports collection makefile for:    mutt
# Version required:     0.xy
# Date created:         Thur July 25, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.10 1996/12/05 09:52:00 obrien Exp $

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
		http://www.math.fu-berlin.de/~leitner/mutt/${PKGNAME:S/^mutt-//}/  \
		http://www.efrei.fr/~parmelan/mutt/${PKGNAME:S/^mutt-//}/  \
		ftp://www.frmug.org/pub/mutt/mutt/${PKGNAME:S/^mutt-//}/
PATCHFILES=	02.keys.PATCH  \
		03.configure.PATCH  \
		04.mbox-hook.PATCH  \
		05.bind.PATCH  \
		08.undisclosed.PATCH  \
		09.attach.PATCH  \
		10.noop.PATCH  \
		11.external.PATCH  \
		12.tagged.PATCH  \
		13.random.PATCH  \
		15.mallocline.PATCH  \
		16.defaultcolor.PATCH  \
		17.variables.PATCH  \
		19.fdleak.PATCH
#		don't apply cleanly:
#		06.setgid.PATCH  \
#		07.configure.in.PATCH  \
#		14.mallocline.PATCH  \
#		18.buffy.PATCH  \

MAINTAINER=     obrien@cs.ucdavis.edu

DIST_SUBDIR=	mutt
WRKSRC=		${WRKDIR}/${PKGNAME}
#PATCH_DIST_STRIP=	-p2
PATCH_DIST_STRIP=	
GNU_CONFIGURE=	yes
MAN1=		mutt.1


#	distpatches weren't made relative to ${WRKSRC}
pre-patch:
	@ln ${WRKSRC}/doc/manual.sgml ${WRKSRC}

post-patch:
	@${CP} ${WRKSRC}/manual.sgml ${WRKSRC}/doc


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
