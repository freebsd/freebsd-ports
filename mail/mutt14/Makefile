# ex:ts=8
# New ports collection makefile for:    mutt w/pgp hooks
# Version required:     0.xy
# Date created:         Thur July 25, 1996
# Whom:                 David O'Brien (obrien@NUXI.com)
#
# $Id: Makefile,v 1.45 1998/07/17 18:52:17 obrien Exp $

DISTNAME=	mutt-0.93.1i
PKGNAME=	mutt-0.93.1
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
		ftp://ftp.nuxi.com/pub/mutt/${PKGNAME:S/^mutt-//}/  \
		ftp://riemann.iam.uni-bonn.de/pub/mutt/
PATCHFILES=

MAINTAINER=     obrien@FreeBSD.org

.if defined(BATCH)
LIB_DEPENDS=	slang\\.1\\.:${PORTSDIR}/devel/libslang
BUILD_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell
RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell
.elif defined(USE_NCURSES_PORT)
LIB_DEPENDS=	ncurses\\.4\\.:${PORTSDIR}/devel/ncurses
.elif defined(USE_SLANG)
LIB_DEPENDS=	slang\\.1\\.:${PORTSDIR}/devel/libslang
.endif

DIST_SUBDIR=	mutt
PATCH_DIST_STRIP=	-p1
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --enable-dsn --enable-pop --enable-imap --enable-flock \
		--disable-fcntl --enable-hidden-host \
		--with-sharedir=${PREFIX}/share/misc \
		--with-docdir=${PREFIX}/share/doc/mutt
.if defined(BATCH) || defined(USE_SLANG)
CONFIGURE_ARGS+=	--with-slang=${PREFIX}
.elif defined(USE_NCURSES_PORT)
CONFIGURE_ARGS+=	--with-curses=${PREFIX}
.endif
MAN1=		mutt.1

post-patch:
	@touch ${WRKSRC}/doc/mutt.man ${WRKSRC}/doc/manual.txt

pre-configure:
	@${MKDIR} ${PREFIX}/share/misc

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
