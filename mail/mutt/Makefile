# ex:ts=8
# New ports collection makefile for:    mutt w/pgp hooks
# Version required:     0.xy
# Date created:         Thur July 25, 1996
# Whom:                 David O'Brien (obrien@NUXI.com)
#
# $Id: Makefile,v 1.55 1999/01/07 18:43:20 obrien Exp $

DISTNAME=	mutt-0.95.3i
PKGNAME=	mutt-0.95.3
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.guug.de/pub/mutt/  \
		ftp://ftp.uib.no/pub/mutt/  \
		ftp://pgp.rasip.fer.hr/pub/mutt/international/  \
		ftp://ftp.gbnet.net/pub/mutt-international/  \
		ftp://riemann.iam.uni-bonn.de/pub/mutt/  \
		ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/mutt-international/ \
		ftp://ftp.gwdg.de/pub/unix/mail/mutt/international/  \
		ftp://ftp.iks-jena.de/pub/mitarb/lutz/crypt/software/pgp/mutt/

PATCH_SITES=	http://www.frmug.org/mutt/mutt/${PKGNAME:S/^mutt-//}/  \
		http://www.math.fu-berlin.de/~leitner/mutt/${PKGNAME:S/^mutt-//}/  \
		http://www.efrei.fr/~parmelan/mutt/${PKGNAME:S/^mutt-//}/  \
		ftp://www.frmug.org/pub/mutt/mutt/${PKGNAME:S/^mutt-//}/  \
		ftp://ftp.nuxi.com/pub/mutt/${PKGNAME:S/^mutt-//}/  \
		ftp://riemann.iam.uni-bonn.de/pub/mutt/
PATCHFILES=

MAINTAINER=     obrien@FreeBSD.org

.if defined(BATCH)
LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang
BUILD_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell \
		sgmlfmt:${PORTSDIR}/textproc/sgmlformat
RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell
.elif defined(USE_NCURSES_PORT)
LIB_DEPENDS=	ncurses.4:${PORTSDIR}/devel/ncurses
.elif defined(USE_SLANG)
LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang
.endif

DIST_SUBDIR=	mutt
PATCH_DIST_STRIP=	-p1
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --enable-pop --enable-imap --enable-flock --disable-fcntl  \
		--with-sharedir=${PREFIX}/share/mutt \
		--with-docdir=${PREFIX}/share/doc/mutt
.if defined(BATCH) || defined(USE_SLANG)
CONFIGURE_ARGS+=	--with-slang=${PREFIX}
.elif defined(USE_NCURSES_PORT)
CONFIGURE_ARGS+=	--with-curses=${PREFIX}
.endif
WRKSRC=		${WRKDIR}/${PKGNAME}
MAN1=		mutt.1 mutt_dotlock.1


.if !defined(NOPORTDOCS)
post-build:
	touch ${WRKSRC}/doc/mutt.man ${WRKSRC}/doc/manual.txt
	${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-doc-ref
	printf ",s|\$${PREFIX}|%s|g\nw\nq\n" ${PREFIX} | \
		ed -s ${WRKSRC}/doc/mutt.man
.if defined(BATCH)
PLIST:=		${WRKDIR}/PLIST
pre-install:
	@${CAT} ${PKGDIR}/PLIST.htmlfiles >> ${PLIST}
	@${CAT} ${PKGDIR}/PLIST >> ${PLIST}
.endif
.endif

post-install:
	@strip ${PREFIX}/bin/mutt
.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing Mutt documentation"
	@${MKDIR} ${PREFIX}/share/doc/mutt && chmod a+rx ${PREFIX}/share/doc/mutt
	@cd ${WRKSRC}/doc ; ${INSTALL_MAN} manual.txt PGP-Notes.txt \
		${PREFIX}/share/doc/mutt
.if defined(BATCH)
	${INSTALL_MAN} ${WRKSRC}/doc/*.latin1 ${PREFIX}/share/doc/mutt
	${INSTALL_MAN} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/mutt
.endif
	@(cd ${WRKSRC}/contrib ; ${INSTALL_DATA} sample.muttrc Mush.rc Pine.rc \
		${PREFIX}/share/doc/mutt)
.endif

.include <bsd.port.mk>
