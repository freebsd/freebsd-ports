# ex:ts=8
# New ports collection makefile for:    mutt
# Version required:     0.xy
# Date created:         Thur July 25, 1996
# Whom:                 David O'Brien (obrien@NUXI.com)
#
# $Id: Makefile,v 1.36 1997/07/24 20:59:00 obrien Exp $

DISTNAME=	${PKGNAME}e
PKGNAME=	mutt-0.81
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cs.hmc.edu/pub/me/mutt/  \
		ftp://ftp.ibp.fr/pub/unix/mail/mutt/  \
		ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/  \
		ftp://ftp.teuto.de/pub/user/lmb/  \
		ftp://ftp.funet.fi/pub/unix/mail/mutt/

PATCH_SITES=	ftp://ftp.nuxi.com/pub/mutt/${PKGNAME:S/^mutt-//}/  \
		http://www.frmug.org/mutt/mutt/${PKGNAME:S/^mutt-//}/  \
		http://www.math.fu-berlin.de/~leitner/mutt/${PKGNAME:S/^mutt-//}/  \
		http://www.efrei.fr/~parmelan/mutt/${PKGNAME:S/^mutt-//}/  \
		ftp://www.frmug.org/pub/mutt/mutt/${PKGNAME:S/^mutt-//}/
PATCHFILES=

MAINTAINER=     obrien@FreeBSD.org

DIST_SUBDIR=	mutt
WRKSRC=		${WRKDIR}/${PKGNAME}
PATCH_DIST_STRIP=	-p1
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --enable-dsn --enable-pop --enable-8bitmime --enable-flock \
		--disable-fcntl --enable-hidden-host
MAN1=		mutt.1


post-install:
	@strip ${PREFIX}/bin/mutt
.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing Mutt documentation"
	@${MKDIR} ${PREFIX}/share/doc/mutt && chmod a+rx ${PREFIX}/share/doc/mutt
	@${INSTALL_MAN} ${WRKSRC}/doc/*.latin1 ${WRKSRC}/doc/*.html  \
		${PREFIX}/share/doc/mutt
	@(cd ${WRKSRC} ; ${INSTALL_DATA} sample.muttrc Mush.rc Pine.rc  \
		${PREFIX}/share/doc/mutt)
.endif

.include <bsd.port.mk>
