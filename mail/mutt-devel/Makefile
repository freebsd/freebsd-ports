# ex:ts=8
# Ports collection makefile for:  mutt w/pgp hooks
# Date created:			  Thur July 25, 1996
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	mutt
PORTVERSION= 	1.0.1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.guug.de/pub/mutt/  \
		ftp://ftp.uib.no/pub/mutt/  \
		ftp://pgp.rasip.fer.hr/pub/mutt/international/  \
		ftp://ftp.gbnet.net/pub/mutt-international/  \
		ftp://riemann.iam.uni-bonn.de/pub/mutt/  \
		ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/mutt-international/ \
		ftp://ftp.gwdg.de/pub/unix/mail/mutt/international/  \
		ftp://ftp.iks-jena.de/pub/mitarb/lutz/crypt/software/pgp/mutt/
DISTNAME=	${PKGNAME}i

PATCH_SITES=	http://www.frmug.org/mutt/mutt/${PKGNAME:S/^mutt-//}/  \
		http://www.math.fu-berlin.de/~leitner/mutt/${PKGNAME:S/^mutt-//}/  \
		http://www.efrei.fr/~parmelan/mutt/${PKGNAME:S/^mutt-//}/  \
		ftp://www.frmug.org/pub/mutt/mutt/${PKGNAME:S/^mutt-//}/  \
		ftp://riemann.iam.uni-bonn.de/pub/mutt/
PATCHFILES=
PATCH_DIST_STRIP=	-p1

MAINTAINER=	obrien@FreeBSD.org

BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext
.if defined(BATCH)
LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang
BUILD_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell
.if ${MACHINE_ARCH} != "alpha"
#  coredump in sgmls
BUILD_DEPENDS+=	sgmlfmt:${PORTSDIR}/textproc/sgmlformat
.endif
RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell
.elif defined(WITH_NCURSES_PORT)
LIB_DEPENDS=	ncurses.4:${PORTSDIR}/devel/ncurses
.elif defined(WITH_SLANG)
LIB_DEPENDS=	slang.1:${PORTSDIR}/devel/libslang
.endif
.if defined(PACKAGE_BUILDING)
RUN_DEPENDS+=	urlview:${PORTSDIR}/textproc/urlview
.endif

DIST_SUBDIR=	mutt
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS= --enable-pop --enable-imap --enable-flock --disable-fcntl  \
		--with-sharedir=${PREFIX}/share/mutt \
		--with-docdir=${PREFIX}/share/doc/mutt
.if defined(BATCH) || defined(WITH_SLANG)
CONFIGURE_ARGS+=	--with-slang=${PREFIX}
.elif defined(WITH_NCURSES_PORT)
CONFIGURE_ARGS+=	--with-curses=${PREFIX}
.endif
WRKSRC=		${WRKDIR}/${DISTNAME:S/i$//}
MAN1=		mutt.1 mutt_dotlock.1

post-patch:
	uudecode -p ${FILESDIR}/ru.gmo.uu > ${WRKSRC}/po/ru.gmo

.if !defined(NOPORTDOCS)
post-build:
	${TOUCH} ${WRKSRC}/doc/mutt.man ${WRKSRC}/doc/manual.txt
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
	@${MKDIR} ${PREFIX}/share/doc/mutt && ${CHMOD} a+rx ${PREFIX}/share/doc/mutt
	@cd ${WRKSRC}/doc ; ${INSTALL_MAN} manual.txt PGP-Notes.txt \
		${PREFIX}/share/doc/mutt
.if defined(BATCH)
	${INSTALL_MAN} ${WRKSRC}/doc/*.latin1 ${PREFIX}/share/doc/mutt
	${INSTALL_MAN} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/mutt
.endif
	@cd ${WRKSRC}/contrib ; ${INSTALL_DATA} sample.muttrc Mush.rc Pine.rc \
		${PREFIX}/share/doc/mutt
.endif

.include <bsd.port.mk>
