# ex:ts=8
# New ports collection makefile for:    mutt
# Version required:     0.xy
# Date created:         Thur July 25, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.20 1997/02/20 09:53:22 obrien Exp $

DISTNAME=	${PKGNAME}e
PKGNAME=	mutt-0.64
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
PATCHFILES=	03.rd_count.PATCH  \
		04.cfg-files.PATCH.EXP  \
		05.search-color.PATCH.EXP  \
		06.env_info.PATCH.EXP  \
		18.envstr.PATCH  \
		07.thread_chars.PATCH  \
		08.parse_set.PATCH  \
		09.quote_sig.PATCH.EXP  \
		11.synch.PATCH  \
		12.edit_cc.PATCH  \
		13.postponed-delete.PATCH  \
		20.cmd-complete.PATCH  \
		21.cmd_line.PATCH  \
		22.body_search.PATCH  \
		23.display_types.PATCH  \
		25.messageid.PATCH  \
		27.parse_rc.PATCH
# these either don't apply cleanly, or to FreeBSD, or are too specialized
#		02.status.PATCH  \
#		10.warnings.PATCH  \
#		14.add_buffy.PATCH  \
#		15.ansihp.PATCH  \
#		16.pgp.PATCH.EXP  \
#		17.hdr_format.PATCH  \
#		19.buffy.PATCH  \
#		24.mx_lock.PATCH  \
#		26.abort-unmodified.PATCH

MAINTAINER=     obrien@FreeBSD.org

DIST_SUBDIR=	mutt
WRKSRC=		${WRKDIR}/${PKGNAME}
#PATCH_DIST_STRIP=	-p2
PATCH_DIST_STRIP=	-p1
#PATCH_DIST_STRIP=	
GNU_CONFIGURE=	yes
MAN1=		mutt.1


post-install:
	@####   don't strip until out of beta peroid
	@#strip ${PREFIX}/bin/mutt
.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing Mutt documentation"
	@${MKDIR} ${PREFIX}/share/doc/mutt && chmod a+rx ${PREFIX}/share/doc/mutt
	@${INSTALL_MAN} ${WRKSRC}/doc/*.latin1 ${WRKSRC}/doc/*.html  \
		${PREFIX}/share/doc/mutt
	@(cd ${WRKSRC} ; ${INSTALL_DATA} sample.muttrc Mush.rc Pine.rc  \
		${PREFIX}/share/doc/mutt)
.endif

.include <bsd.port.mk>
