# ex:ts=8
# Ports collection makefile for:  mutt development
# Date created:			  6 Jun 2001
# Whom:				  Udo Schweigert
#
# $FreeBSD$
#

PORTNAME=	mutt-devel
PORTVERSION=	1.3.19
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.demon.co.uk/pub/mirrors/mutt/devel/ \
		ftp://ftp.parodius.com/pub/mutt/devel/
DISTNAME=	mutt-${PORTVERSION}i
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ust@cert.siemens.de

USE_GMAKE=	yes
USE_AUTOMAKE=	yes

.if !defined(PATCH_VERSION)
PATCH_VERSION=	${PORTVERSION}
.endif

.if defined(PACKAGE_BUILDING)
WITH_SLANG=	yes
BUILD_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell \
		urlview:${PORTSDIR}/textproc/urlview
.if ${MACHINE_ARCH} != "alpha"
#  coredump in sgmls
WITH_DOCS=	yes
.endif
.endif

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext \
		giconv.2:${PORTSDIR}/converters/libiconv

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
CONFIGURE_TARGET=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CC="${CC} -I${LOCALBASE}/include" LDFLAGS=-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-pop --enable-imap --enable-flock --disable-fcntl \
		--with-sharedir=${PREFIX}/share/mutt \
		--with-docdir=${PREFIX}/share/doc/mutt \
		--sysconfdir=${PREFIX}/etc \
		--with-iconv=${PREFIX}

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

.if defined(WITH_COMPRESSED_FOLDERS)
PATCHFILES=	patch-${PATCH_VERSION}.rr.compressed.1.gz
PATCH_DIST_STRIP=	-p1
PATCH_SITES=	http://www.spinnaker.de/mutt/compressed/
CONFIGURE_ARGS+=	--enable-compressed
.endif

.if defined(WITH_VVV_PATCHES)
PATCHFILES=	patch-${PATCH_VERSION}.rr.compressed.gz \
		patch-${PATCH_VERSION}.vvv.nntp.gz \
		patch-${PATCH_VERSION}.vvv.initials.gz \
		patch-${PATCH_VERSION}.vvv.quote.gz \
		patch-${PATCH_VERSION}.vvv.ru.gz
PATCH_DIST_STRIP=	-p1
PATCH_SITES=	http://mutt.org.ua/download/mutt-${PATCH_VERSION}/ \
		ftp://mutt.org.ua/mutt/mutt-${PATCH_VERSION}/
CONFIGURE_ARGS+=	--enable-nntp --with-regex --enable-compressed
.endif

WRKSRC=		${WRKDIR}/${DISTNAME:S/i$//}
MAN1=		flea.1 mutt.1 mutt_dotlock.1 muttbug.1
MAN5=		muttrc.5 mbox.5

pre-configure:
	(cd ${WRKSRC}; aclocal -I m4)

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
	${SETENV} MANMODE=0755 ${INSTALL_MAN} -d ${PREFIX}/share/doc/mutt/html
	${INSTALL_MAN} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/mutt/html
	${INSTALL_MAN} ${WRKSRC}/doc/*.latin1 ${PREFIX}/share/doc/mutt
.endif
.endif

.include <bsd.port.mk>
