# ex:ts=8
# Ports collection makefile for:  mutt development
# Date created:			  6 Jun 2001
# Whom:				  Udo Schweigert
#
# $FreeBSD$
#

PORTNAME=	mutt-devel
PORTVERSION=	1.3.20
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.demon.co.uk/pub/mirrors/mutt/devel/ \
		ftp://ftp.parodius.com/pub/mutt/devel/
DISTNAME=	mutt-${PORTVERSION}i
#DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ust@cert.siemens.de

DIST_SUBDIR=    mutt
GNU_CONFIGURE=  yes
CONFIGURE_ARGS=	--enable-flock --disable-fcntl \
		--with-sharedir=${PREFIX}/share/mutt \
		--with-docdir=${PREFIX}/share/doc/mutt \
		--sysconfdir=${PREFIX}/etc \
		--with-libiconv-prefix=${PREFIX}

.include <bsd.port.pre.mk>

USE_GMAKE=	yes
USE_AUTOMAKE=	yes

.if defined(WITH_MUTT_COMPRESSED_FOLDERS) || defined(WITH_MUTT_NNTP) || \
		defined(WITH_MUTT_RU_PATCH) || defined(WITH_MUTT_QUOTE_PATCH)
PATCH_SITES+=	http://mutt.org.ua/download/mutt-${PATCH_VERSION}/ \
		ftp://mutt.org.ua/mutt/mutt-${PATCH_VERSION}/
.endif

.if !defined(PATCH_VERSION)
PATCH_VERSION=	${PORTVERSION}
.endif

.if defined(PACKAGE_BUILDING)
WITH_MUTT_SLANG=	yes
BUILD_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell \
		urlview:${PORTSDIR}/textproc/urlview
.if ${MACHINE_ARCH} != "alpha"
#  coredump in sgmls
WITH_MUTT_HTML=	yes
.endif
.endif

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext \
		giconv.2:${PORTSDIR}/converters/libiconv

.if defined(WITH_MUTT_SLANG)
LIB_DEPENDS+=	slang.1:${PORTSDIR}/devel/libslang
.elif defined(WITH_MUTT_NCURSES_PORT)
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
CFLAGS+=	-I${PREFIX}/include/ncurses -I${PREFIX}/include
.endif
.if defined(WITH_MUTT_SSL)
USE_OPENSSL=	yes
.endif
.if defined(WITH_MUTT_HTML)
BUILD_DEPENDS+=	sgmlfmt:${PORTSDIR}/textproc/sgmlformat
.endif

.if defined(WITH_MUTT_LOCALES_FIX)
CONFIGURE_ARGS+=	--enable-locales-fix
.endif
.if defined(WITH_MUTT_SLANG)
CONFIGURE_ARGS+=	--with-slang=${PREFIX}
.elif defined(WITH_MUTT_NCURSES_PORT)
CONFIGURE_ARGS+=	--with-curses=${PREFIX}
.endif
.if defined(WITH_MUTT_SSL)
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}
.endif
.if defined(WITH_MUTT_POP)
CONFIGURE_ARGS+=	--enable-pop
.endif
.if defined(WITH_MUTT_IMAP)
CONFIGURE_ARGS+=	--enable-imap
.endif
.if defined(WITH_MUTT_POP_IMAP)
CONFIGURE_ARGS+=	--enable-pop --enable-imap
.endif

PATCH_DIST_STRIP=	-p1

.if defined(WITH_MUTT_COMPRESSED_FOLDERS)
PATCHFILES+=	patch-${PATCH_VERSION}.rr.compressed.gz
CONFIGURE_ARGS+=	--enable-compressed
.endif
.if defined(WITH_MUTT_NNTP)
PATCHFILES+=	patch-${PATCH_VERSION}.vvv.nntp.gz
CONFIGURE_ARGS+=	--enable-nntp
.endif
.if defined(WITH_MUTT_QUOTE_PATCH)
PATCHFILES+=	patch-${PATCH_VERSION}.vvv.initials.gz \
		patch-${PATCH_VERSION}.vvv.quote.gz
.endif
.if defined(WITH_MUTT_RU_PATCH)
PATCHFILES+=	patch-${PATCH_VERSION}.vvv.ru.gz
.endif

WRKSRC=		${WRKDIR}/${DISTNAME:S/i$//}
MAN1=		flea.1 mutt.1 mutt_dotlock.1 muttbug.1
MAN5=		muttrc.5 mbox.5

pre-configure:
	(cd ${WRKSRC}; aclocal -I m4)

.if !defined(NOPORTDOCS)
PLIST_SUB+=	SUB_DOCS=""
post-build:
	${TOUCH} ${WRKSRC}/doc/mutt.man ${WRKSRC}/doc/manual.sgml
	${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-doc-ref
	printf ",s|\$${PREFIX}|%s|g\nw\nq\n" ${PREFIX} | \
		ed -s ${WRKSRC}/doc/mutt.man
.if defined(WITH_MUTT_HTML)
PLIST_SUB+=	SUB_HTML=""
.if defined(WITH_MUTT_COMPRESSED_FOLDERS) && defined(WITH_MUTT_NNTP) && \
	defined(WITH_MUTT_RU_PATCH) && defined(WITH_MUTT_QUOTE_PATCH)
PLIST_SUB+=	SUB_ADD_G=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
.elif defined(WITH_MUTT_COMPRESSED_FOLDERS) && defined(WITH_MUTT_NNTP) && \
	defined(WITH_MUTT_RU_PATCH) && !defined(WITH_MUTT_QUOTE_PATCH)
PLIST_SUB+=	SUB_ADD_F=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
.elif defined(WITH_MUTT_COMPRESSED_FOLDERS) && defined(WITH_MUTT_NNTP) && \
	!defined(WITH_MUTT_RU_PATCH) && defined(WITH_MUTT_QUOTE_PATCH)
PLIST_SUB+=	SUB_ADD_G=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
.elif defined(WITH_MUTT_COMPRESSED_FOLDERS) && defined(WITH_MUTT_NNTP) && \
	!defined(WITH_MUTT_RU_PATCH) && !defined(WITH_MUTT_QUOTE_PATCH)
PLIST_SUB+=	SUB_ADD_F=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
.elif defined(WITH_MUTT_COMPRESSED_FOLDERS) && !defined(WITH_MUTT_NNTP) && \
	defined(WITH_MUTT_RU_PATCH) && defined(WITH_MUTT_QUOTE_PATCH)
PLIST_SUB+=	SUB_ADD_C=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
.elif defined(WITH_MUTT_COMPRESSED_FOLDERS) && !defined(WITH_MUTT_NNTP) && \
	defined(WITH_MUTT_RU_PATCH) && !defined(WITH_MUTT_QUOTE_PATCH)
PLIST_SUB+=	SUB_ADD_B=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
.elif defined(WITH_MUTT_COMPRESSED_FOLDERS) && !defined(WITH_MUTT_NNTP) && \
	!defined(WITH_MUTT_RU_PATCH) && defined(WITH_MUTT_QUOTE_PATCH)
PLIST_SUB+=	SUB_ADD_C=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
.elif defined(WITH_MUTT_COMPRESSED_FOLDERS) && !defined(WITH_MUTT_NNTP) && \
	!defined(WITH_MUTT_RU_PATCH) && !defined(WITH_MUTT_QUOTE_PATCH)
PLIST_SUB+=	SUB_ADD_B=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
.elif !defined(WITH_MUTT_COMPRESSED_FOLDERS) && defined(WITH_MUTT_NNTP) && \
	defined(WITH_MUTT_RU_PATCH) && defined(WITH_MUTT_QUOTE_PATCH)
PLIST_SUB+=	SUB_ADD_E=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
.elif !defined(WITH_MUTT_COMPRESSED_FOLDERS) && defined(WITH_MUTT_NNTP) && \
	defined(WITH_MUTT_RU_PATCH) && !defined(WITH_MUTT_QUOTE_PATCH)
PLIST_SUB+=	SUB_ADD_D=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
.elif !defined(WITH_MUTT_COMPRESSED_FOLDERS) && defined(WITH_MUTT_NNTP) && \
	!defined(WITH_MUTT_RU_PATCH) && defined(WITH_MUTT_QUOTE_PATCH)
PLIST_SUB+=	SUB_ADD_E=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
.elif !defined(WITH_MUTT_COMPRESSED_FOLDERS) && defined(WITH_MUTT_NNTP) && \
	!defined(WITH_MUTT_RU_PATCH) && !defined(WITH_MUTT_QUOTE_PATCH)
PLIST_SUB+=	SUB_ADD_D=""
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
.elif !defined(WITH_MUTT_COMPRESSED_FOLDERS) && !defined(WITH_MUTT_NNTP) && \
	defined(WITH_MUTT_RU_PATCH) && defined(WITH_MUTT_QUOTE_PATCH)
PLIST_SUB+=	SUB_ADD_A=""
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
.elif !defined(WITH_MUTT_COMPRESSED_FOLDERS) && !defined(WITH_MUTT_NNTP) && \
	defined(WITH_MUTT_RU_PATCH) && !defined(WITH_MUTT_QUOTE_PATCH)
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
.elif !defined(WITH_MUTT_COMPRESSED_FOLDERS) && !defined(WITH_MUTT_NNTP) && \
	!defined(WITH_MUTT_RU_PATCH) && defined(WITH_MUTT_QUOTE_PATCH)
PLIST_SUB+=	SUB_ADD_A=""
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
.elif !defined(WITH_MUTT_COMPRESSED_FOLDERS) && !defined(WITH_MUTT_NNTP) && \
	!defined(WITH_MUTT_RU_PATCH) && !defined(WITH_MUTT_QUOTE_PATCH)
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
.else # patches
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
.endif
.else # HTML
PLIST_SUB+=	SUB_HTML="@comment "
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
.endif
.else 	# NOPORTDOCS
PLIST_SUB+=	SUB_DOCS="@comment "
PLIST_SUB+=	SUB_HTML="@comment "
PLIST_SUB+=	SUB_ADD_A="@comment "
PLIST_SUB+=	SUB_ADD_B="@comment "
PLIST_SUB+=	SUB_ADD_C="@comment "
PLIST_SUB+=	SUB_ADD_D="@comment "
PLIST_SUB+=	SUB_ADD_E="@comment "
PLIST_SUB+=	SUB_ADD_F="@comment "
PLIST_SUB+=	SUB_ADD_G="@comment "
post-patch:
	${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-nodoc
	${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-nodoc-contrib
.endif

post-install:
	@strip ${PREFIX}/bin/mutt
.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing Mutt documentation"
	@${MKDIR} ${PREFIX}/share/doc/mutt && \
		${CHMOD} a+rx ${PREFIX}/share/doc/mutt
	@cd ${WRKSRC}/doc ; ${INSTALL_MAN} manual.txt PGP-Notes.txt \
		${PREFIX}/share/doc/mutt
.if defined(WITH_MUTT_HTML)
	@${MKDIR} ${PREFIX}/share/doc/mutt/html && \
		${CHMOD} a+rx ${PREFIX}/share/doc/mutt/html
	${INSTALL_MAN} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/mutt/html
	${INSTALL_MAN} ${WRKSRC}/doc/*.latin1 ${PREFIX}/share/doc/mutt
.endif
.endif

.include <bsd.port.post.mk>
