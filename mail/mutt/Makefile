# ex:ts=8
# Ports collection makefile for:  mutt w/pgp hooks
# Date created:			  Thur July 25, 1996
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	mutt
PORTVERSION=	1.4
PORTREVISION=	0
CATEGORIES+=	mail
MASTER_SITES=	ftp://ftp.mutt.org/mutt/ \
		ftp://ftp.gbnet.net/pub/mutt-international/ \
		ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/ \
		ftp://ftp.demon.co.uk/pub/mirrors/mutt/ \
		ftp://ftp.parodius.com/pub/mutt/ \
		ftp://pgp.rasip.fer.hr/pub/mutt/international/
DISTFILES=	${DISTNAME}i${EXTRACT_SUFX}

PATCH_SITES=	http://www.mutt.org.ua/download/${PKGNAME}/ \
		http://www.spinnaker.de/mutt/compressed/ \
		http://www.frmug.org/mutt/mutt/${PKGNAME:S/^mutt-//}/ \
		http://www.math.fu-berlin.de/~leitner/mutt/${PKGNAME:S/^mutt-//}/ \
		http://www.efrei.fr/~parmelan/mutt/${PKGNAME:S/^mutt-//}/ \
		ftp://www.frmug.org/pub/mutt/mutt/${PKGNAME:S/^mutt-//}/ \
		ftp://riemann.iam.uni-bonn.de/pub/mutt/
PATCHFILES=	patch-${PORTVERSION}.rr.compressed.1.gz \
		patch-${PORTVERSION}.vvv.initials.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER?=	udo.schweigert@siemens.com

.if defined(PACKAGE_BUILDING)
WITH_SLANG=	yes
BUILD_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell
RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell \
		urlview:${PORTSDIR}/textproc/urlview
.endif
.if ${MACHINE_ARCH} != "alpha"
#  coredump in sgmls
WITH_SGML_DOCS?=yes
.endif

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext
.if defined(WITH_SLANG)
LIB_DEPENDS+=	slang.1:${PORTSDIR}/devel/libslang
.elif defined(WITH_NCURSES_PORT)
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
.endif
.if defined(WITH_MUTT_CYRUS_SASL)
LIB_DEPENDS+=	sasl.8:${PORTSDIR}/security/cyrus-sasl
.endif
.if defined(WITH_SGML_DOCS) && ${WITH_SGML_DOCS} != "no"
BUILD_DEPENDS+=	sgmlfmt:${PORTSDIR}/textproc/sgmlformat
.endif

DIST_SUBDIR=	mutt
WRKSRC=		${WRKDIR}/${DISTNAME:S/i$//}
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_AUTOMAKE=	yes	# configure.in is patched by <PATCHFILES>
USE_REINPLACE=	yes
CONFIGURE_TARGET=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CC="${CC} -I${LOCALBASE}/include" LDFLAGS=-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-pop --enable-imap --enable-flock --disable-fcntl \
		--with-ssl=${OPENSSLBASE} --sysconfdir=${PREFIX}/etc \
		--with-sharedir=${PREFIX}/share/mutt \
		--with-docdir=${PREFIX}/share/doc/mutt --with-charmaps \
		--with-libiconv-prefix=${PREFIX} \
		--enable-compressed
.if defined(WITH_LOCALES_FIX)
CONFIGURE_ARGS+=	--enable-locales-fix
.endif
.if defined(WITH_SLANG)
CONFIGURE_ARGS+=	--with-slang=${PREFIX}
.elif defined(WITH_NCURSES_PORT)
CONFIGURE_ARGS+=	--with-curses=${PREFIX}
CFLAGS+=	-I${PREFIX}/include/ncurses -I${PREFIX}/include
.endif
.if defined(WITH_MUTT_CYRUS_SASL)
CONFIGURE_ARGS+=	--with-sasl=${LOCALBASE}
.endif
MAN1=		flea.1 mutt.1 mutt_dotlock.1 muttbug.1
MAN5=		mbox.5 muttrc.5

# XXX
# this should be done automagically by aclocal but ....
# for now, this will have to do
pre-build:
	${REINPLACE_CMD} -E -e "s|^(ACLOCAL = ).+|\1${ACLOCAL}|" \
			-e "s|^(AUTOCONF = ).+|\1${AUTOCONF}|" \
			-e "s|^(AUTOMAKE = ).+|\1${AUTOMAKE}|" \
			-e "s|^(AUTOHEADER = ).+|\1${AUTOHEADER}|" \
		${BUILD_WRKSRC}/Makefile

.if !defined(NOPORTDOCS)
post-build:
	${TOUCH} ${WRKSRC}/doc/mutt.man ${WRKSRC}/doc/manual.sgml
	${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-doc-ref
	printf ",s|\$${PREFIX}|%s|g\nw\nq\n" ${PREFIX} | \
		ed -s ${WRKSRC}/doc/mutt.man
.if defined(WITH_SGML_DOCS) && ${WITH_SGML_DOCS} != "no"
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
.if defined(WITH_SGML_DOCS) && ${WITH_SGML_DOCS} != "no"
	${INSTALL} ${COPY} -o ${MANOWN} -g ${MANGRP} -m 0755 \
	    -d ${PREFIX}/share/doc/mutt/html
	${INSTALL_MAN} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/mutt/html
	${INSTALL_MAN} ${WRKSRC}/doc/*.latin1 ${PREFIX}/share/doc/mutt
.endif
.endif

.include <bsd.port.mk>
