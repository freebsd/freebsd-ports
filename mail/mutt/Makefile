# ex:ts=8
# Ports collection makefile for:  mutt w/pgp hooks
# Date created:			  Thur July 25, 1996
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	mutt
PORTVERSION=	1.2.5.1
CATEGORIES+=	mail
MASTER_SITES=	ftp://ftp.mutt.org/pub/mutt/ \
		ftp://ftp.uib.no/pub/mutt/ \
		ftp://pgp.rasip.fer.hr/pub/mutt/international/ \
		ftp://ftp.gbnet.net/pub/mutt-international/ \
		ftp://riemann.iam.uni-bonn.de/pub/mutt/ \
		ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/mutt-international/ \
		ftp://ftp.gwdg.de/pub/unix/mail/mutt/international/ \
		ftp://ftp.iks-jena.de/pub/mitarb/lutz/crypt/software/pgp/mutt/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} charmaps-0.0.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	http://www.spinnaker.de/mutt/compressed/ \
		http://www.frmug.org/mutt/mutt/${PKGNAME:S/^mutt-//}/ \
		http://www.math.fu-berlin.de/~leitner/mutt/${PKGNAME:S/^mutt-//}/ \
		http://www.efrei.fr/~parmelan/mutt/${PKGNAME:S/^mutt-//}/ \
		ftp://www.frmug.org/pub/mutt/mutt/${PKGNAME:S/^mutt-//}/ \
		ftp://riemann.iam.uni-bonn.de/pub/mutt/
PATCHFILES=	patch-${PORTVERSION}.rr.compressed.1.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER?=	obrien@FreeBSD.org

.if defined(PACKAGE_BUILDING)
WITH_SLANG=	yes
BUILD_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell
RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell \
		urlview:${PORTSDIR}/textproc/urlview
.if ${MACHINE_ARCH} != "alpha"
#  coredump in sgmls
WITH_DOCS=	yes
.endif
.endif

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext
.if defined(WITH_SLANG)
LIB_DEPENDS+=	slang.1:${PORTSDIR}/devel/libslang
.elif defined(WITH_NCURSES_PORT)
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
CFLAGS+=	-I${PREFIX}/include/ncurses -I${PREFIX}/include
.endif
.if defined(WITH_SSL)
USE_OPENSSL=	yes
.endif
.if defined(WITH_DOCS)
BUILD_DEPENDS+=	sgmlfmt:${PORTSDIR}/textproc/sgmlformat
.endif

DIST_SUBDIR=	mutt
GNU_CONFIGURE=	yes
USE_AUTOMAKE=	yes	# configure.in is patched by <PATCHFILES>
AUTOMAKE_ARGS=	--include-deps
CONFIGURE_TARGET=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CC="${CC} -I${LOCALBASE}/include" LDFLAGS=-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-pop --enable-imap --enable-flock --disable-fcntl \
		--with-sharedir=${PREFIX}/share/mutt \
		--with-docdir=${PREFIX}/share/doc/mutt --with-charmaps \
		--enable-compressed
.if defined(WITH_LOCALES_FIX)
CONFIGURE_ARGS+=	--enable-locales-fix
.endif
.if defined(WITH_SLANG)
CONFIGURE_ARGS+=	--with-slang=${PREFIX}
.elif defined(WITH_NCURSES_PORT)
CONFIGURE_ARGS+=	--with-curses=${PREFIX}
.endif
.if defined(WITH_SSL)
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}
.endif
WRKSRC=		${WRKDIR}/${DISTNAME:S/i$//}
MAN1=		mutt.1 mutt_dotlock.1
MAN5=		muttrc.5

pre-patch:
	(cd ${WRKSRC}; ${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/charmaps-0.0.tar.gz)

pre-configure:
	cd ${WRKSRC}/charmaps/maps; ${LN} CP1251 WINDOWS-1251
	cd ${WRKSRC}/charmaps/maps; ${RM} -f *.orig

pre-build:
	cd ${WRKSRC} && ${MAKE} keymap_defs.h

.if !defined(NOPORTDOCS)
post-build:
	${TOUCH} ${WRKSRC}/doc/mutt.man ${WRKSRC}/doc/manual.sgml
	${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-doc-ref
	printf ",s|\$${PREFIX}|%s|g\nw\nq\n" ${PREFIX} | \
		ed -s ${WRKSRC}/doc/mutt.man
.if defined(WITH_DOCS)
PLIST:=		${WRKDIR}/PLIST
pre-install:
	@${CAT} ${PKGDIR}/pkg-plist.htmlfiles >> ${PLIST}
	@${CAT} ${PKGDIR}/pkg-plist >> ${PLIST}
.endif
.endif

post-install:
	@strip ${PREFIX}/bin/mutt
.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing Mutt documentation"
	@${MKDIR} ${PREFIX}/share/doc/mutt && ${CHMOD} a+rx ${PREFIX}/share/doc/mutt
	@cd ${WRKSRC}/doc ; ${INSTALL_MAN} manual.txt PGP-Notes.txt \
		${PREFIX}/share/doc/mutt
.if defined(WITH_DOCS)
	${INSTALL} ${COPY} -o ${MANOWN} -g ${MANGRP} -m 0755 \
	    -d ${PREFIX}/share/doc/mutt/html
	${INSTALL_MAN} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/mutt/html
	${INSTALL_MAN} ${WRKSRC}/doc/*.latin1 ${PREFIX}/share/doc/mutt
.endif
.endif

.include <bsd.port.mk>
