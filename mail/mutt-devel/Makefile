# ex:ts=8
# New ports collection makefile for:    mutt w/pgp hooks
# Version required:     0.xy
# Date created:         Thur July 25, 1996
# Whom:                 David O'Brien (obrien@NUXI.com)
#
# $Id: Makefile,v 1.40 1998/01/28 00:11:59 obrien Exp $

DISTNAME=	${PKGNAME}i
PKGNAME=	mutt-0.89.1
CATEGORIES=	mail
MASTER_SITES=	ftp://riemann.iam.uni-bonn.de/pub/mutt/  \
		ftp://ftp.gbnet.net/pub/mutt-international/  \
		ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/mutt-international/ \
		ftp://ftp.gwdg.de/pub/unix/mail/mutt/international/  \
		ftp://ftp.iks-jena.de/pub/mitarb/lutz/crypt/software/pgp/mutt/

PATCH_SITES=	http://www.frmug.org/mutt/mutt/${PKGNAME:S/^mutt-//}/  \
		http://www.math.fu-berlin.de/~leitner/mutt/${PKGNAME:S/^mutt-//}/  \
		http://www.efrei.fr/~parmelan/mutt/${PKGNAME:S/^mutt-//}/  \
		ftp://www.frmug.org/pub/mutt/mutt/${PKGNAME:S/^mutt-//}/  \
		ftp://ftp.nuxi.com/pub/mutt/${PKGNAME:S/^mutt-//}/
PATCHFILES=

MAINTAINER=     obrien@FreeBSD.org

.if defined(BATCH)
RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell
.endif

DIST_SUBDIR=	mutt
PATCH_DIST_STRIP=	-p1
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --enable-dsn --enable-pop --enable-flock \
		--disable-fcntl --enable-hidden-host
MAN1=		mutt.1

post-install:
	@strip ${PREFIX}/bin/mutt
.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing Mutt documentation"
	@${MKDIR} ${PREFIX}/share/doc/mutt && chmod a+rx ${PREFIX}/share/doc/mutt
	@${INSTALL_MAN} ${WRKSRC}/doc/*.txt  \
		${PREFIX}/share/doc/mutt
	@(cd ${WRKSRC} ; ${INSTALL_DATA} sample.muttrc Mush.rc Pine.rc  \
		${PREFIX}/share/doc/mutt)
.endif

.include <bsd.port.mk>
