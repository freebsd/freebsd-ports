# ex:ts=8
# Ports collection makefile for:  mutt development
# Date created:			  6 Jun 2001
# Whom:				  Udo Schweigert
#
# $FreeBSD$
#
# There are several knobs which are used to define additions to the core
# mutt functionality.
#
# As all of the knobs have a unique name which should not interfere with
# other ports you can add them to /etc/make.conf, e.g. a line like
# "WITH_MUTT_NNTP=yes" will enable mutt's nntp facilities.
#
# In addition to the knobs listed below you can enable other configuration
# options of mutt by adding them to the MUTT_CONFIGURE_ARGS variable. For
# example you could say "MUTT_CONFIGURE_ARGS=--with-homespool=MyMail" to
# configure a different file for mutt's homespool.
#
# The two most important knobs are:
#
# In general you can choose between using the SLANG port (WITH_MUTT_SLANG)
# and ncurses (WITH_MUTT_NCURSES) which is the default. Note that you may
# have to set the variables COLORTERM=yes and COLORFGBG=color,color in your
# environment to get slang function properly.
#
# If you want to install the mutt documentation in html and ps format define:
#  WITH_MUTT_HTML
#  This is a default knob and can be disabled by WITHOUT_MUTT_HTML
#
# If you do not want that the documentation is rebuilt using sgmlformat
# define:
#  WITHOUT_MUTT_SGMLFORMAT
#    (this can only be stated if WITHOUT_MUTT_HTML is defined)
#
# If you want to access compressed email folders define:
#  WITH_MUTT_COMPRESSED_FOLDERS
#  This is a default knob and can be disabled by WITHOUT_MUTT_COMPRESSED_FOLDERS
#
# If you do not want mutt to use the iconv library define:
#  WITHOUT_MUTT_ICONV
#
# If you want to enable extended quoting functions define:
#  WITH_MUTT_QUOTE_PATCH
#  This is a default knob and can be disabled by WITHOUT_MUTT_QUOTE_PATCH
#
# If you want to have the IMAP header cache define:
#  WITH_MUTT_IMAP_HEADER_CACHE
#
# If you want to have the Maildir header cache define:
#  WITH_MUTT_MAILDIR_HEADER_CACHE
#
# If you want to make SMIME outlook compatible define:
#  WITH_MUTT_SMIME_OUTLOOK_COMPAT
#  This is a default knob and can be disabled by
#    WITHOUT_MUTT_SMIME_OUTLOOK_COMPAT
#
# If you want to use enhanced pgp features define:
#  WITH_MUTT_PGP_PATCH
#  This is a default knob and can be disabled by WITHOUT_MUTT_PGP_PATCH
#
# If you want to read and post news with mutt define:
#  WITH_MUTT_NNTP
#
# If you want to use the SASL authentication features with your email server
# define
#  WITH_MUTT_CYRUS_SASL
#
# If you want to use the rethreading functions define:
#  WITH_MUTT_EDIT_THREADS
#
# If you want to use the signature menu define:
#  WITH_MUTT_SIGNATURE_MENU
#
# If you want to use the printf-like enhancement to the mbox-hook command
# define:
#  WITH_MUTT_MBOX_HOOK_PATCH
#
# If you want to use the ifdef feature define:
#  WITH_MUTT_IFDEF_PATCH
#
# If you want to have the Maildir mtime patch define:
#  WITH_MUTT_MAILDIR_MTIME_PATCH

PORTNAME=	mutt-devel
PORTVERSION=	1.5.6
PORTREVISION=	7
CATEGORIES+=	mail ipv6
.if defined(WITH_MUTT_NNTP)
CATEGORIES+=	news
.endif
MASTER_SITES=	ftp://ftp.mutt.org/mutt/devel/ \
		ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/devel/ \
		ftp://ftp.demon.co.uk/pub/mirrors/mutt/devel/ \
		ftp://ftp.parodius.com/pub/mutt/devel/
DISTNAME=	mutt-${PORTVERSION}i

PATCH_SITES+=	http://www.mutt.org.ua/download/mutt-${VVV_PATCH_VERSION}/:vvv \
		http://www2.mutt.org.ua/download/mutt-${VVV_PATCH_VERSION}/:vvv \
		http://www3.mutt.org.ua/download/mutt-${VVV_PATCH_VERSION}/:vvv \
		ftp://ftp.mutt.org.ua/pub/mutt/mutt-${VVV_PATCH_VERSION}/:vvv \
		ftp://ftp3.mutt.org.ua/pub/mutt/mutt-${VVV_PATCH_VERSION}/:vvv \
		http://cedricduval.free.fr/mutt/patches/download/:cd \
		http://home.woolridge.ca/mutt/patches/:dw

MAINTAINER?=	udo.schweigert@siemens.com
COMMENT?=	The Mongrel of Mail User Agents (part Elm, Pine, Mush, mh, etc.)

CONFLICTS=	mutt-[0-9]*

DIST_SUBDIR=	mutt
DOCSDIR?=	${PREFIX}/share/doc/mutt
EXAMPLESDIR?=	${PREFIX}/share/examples/mutt
DATADIR?=	${PREFIX}/share/mutt

LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CC="${CC} -I${LOCALBASE}/include" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-flock --disable-fcntl --with-ssl=${OPENSSLBASE} \
		--with-sharedir=${PREFIX}/share/mutt --with-docdir=${DOCSDIR} \
		--sysconfdir=${PREFIX}/etc --enable-external-dotlock \
		--enable-pop --enable-imap
.if defined(MUTT_CONFIGURE_ARGS)
CONFIGURE_ARGS+=	${MUTT_CONFIGURE_ARGS}
.endif

USE_REINPLACE=	yes
USE_AUTOMAKE_VER=	18
USE_AUTOCONF_VER=	259
USE_OPENSSL=	yes

PLIST=		${WRKDIR}/PLIST
PKGMESSAGE=	${WRKDIR}/pkg-message
SCRIPTS_ENV=	WRKDIR="${WRKDIR}"

.include <bsd.port.pre.mk>

CD_PATCH_VERSION=	1.5.5.1
CD_IFDEF_PATCH_VERSION=	1.5.4
.if !defined(VVV_PATCH_VERSION)
VVV_PATCH_VERSION=	${PORTVERSION}
.endif
.if !defined(CD_PATCH_VERSION)
CD_PATCH_VERSION=	${PORTVERSION}
.endif
.if !defined(CD_IFDEF_PATCH_VERSION)
CD_IFDEF_PATCH_VERSION=	${CD_PATCH_VERSION}
.endif
.if !defined(DW_PATCH_VERSION)
DW_PATCH_VERSION=	${PORTVERSION}
.endif
.if !defined(DW_MBOX_PATCH_VERSION)
DW_MBOX_PATCH_VERSION=	${DW_PATCH_VERSION}
.endif

# XXX
# this should be done automagically by aclocal but ....
# for now, this will have to do
pre-build:
	@${REINPLACE_CMD} -E -e "s|^(ACLOCAL = ).+|\1${ACLOCAL}|" \
			-e "s|^(AUTOCONF = ).+|\1${AUTOCONF}|" \
			-e "s|^(AUTOMAKE = ).+|\1${AUTOMAKE}|" \
			-e "s|^(AUTOHEADER = ).+|\1${AUTOHEADER}|" \
		${BUILD_WRKSRC}/Makefile

.if defined(PACKAGE_BUILDING)
BUILD_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell \
		urlview:${PORTSDIR}/textproc/urlview
.endif

.if defined(WITH_MUTT_NCURSES_PORT)
WITH_MUTT_NCURSES=	yes
.endif
.if defined(WITH_MUTT_NCURSES)
MUTT_USES_NCURSES=	yes
.endif
.if defined(WITH_MUTT_SLANG) && !defined(MUTT_USES_NCURSES)
MUTT_USES_SLANG=	yes
.endif
.if !defined(MUTT_USES_NCURSES) && !defined(WITHOUT_MUTT_NCURSES) && !defined(MUTT_USES_SLANG)
MUTT_USES_NCURSES=	yes
.endif
.if defined(WITHOUT_MUTT_SGMLFORMAT)
SGML_USED=	no
.endif
.if !defined(SGML_USED)
SGML_USED=	no
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
.endif
.if !defined(WITHOUT_MUTT_ICONV)
USE_ICONV=	yes
.endif

.if defined(NOPORTDOCS)
SGML_USED=	no
.endif
.if defined(MUTT_USES_NCURSES) && ${OSVERSION} < 400000
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
CFLAGS+=	-I${PREFIX}/include/ncurses -I${PREFIX}/include
.elif defined(MUTT_USES_SLANG)
LIB_DEPENDS+=	slang.1:${PORTSDIR}/devel/libslang
.endif
.if defined(WITH_MUTT_CYRUS_SASL)
BROKEN=		"mutt-devel's SASL code appears to be broken"
LIB_DEPENDS+=	sasl.8:${PORTSDIR}/security/cyrus-sasl
.endif
.if defined(WITH_MUTT_MAILDIR_HEADER_CACHE)
LIB_DEPENDS+=	db-4.2.2:${PORTSDIR}/databases/db42
CFLAGS+=	-I${PREFIX}/include/db42
.endif
.if ! defined(WITHOUT_MUTT_SMIME_OUTLOOK_COMPAT)
pre-configure::
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-smime-outlook
.endif
.if defined(WITH_MUTT_IMAP_HEADER_CACHE)
pre-configure::
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-imap-header-cache
.endif
.if defined(WITH_MUTT_MAILDIR_HEADER_CACHE)
pre-configure::
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-maildir-header-cache
.endif
.if defined(WITH_MUTT_MAILDIR_MTIME_PATCH)
pre-configure::
.if defined(WITH_MUTT_NNTP)
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-maildir-mtime-nntp
.else
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-maildir-mtime
.endif
.endif
.if defined(WITH_MUTT_NNTP)
pre-configure::
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-nntp.c
.endif

.if ! defined(WITHOUT_MUTT_PGP_PATCH)
SGML_NEEDED=	yes
pre-configure::
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-pgp-dw
.endif

.if defined(WITH_MUTT_EDIT_THREADS)
pre-configure::
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-edit-threads
.endif

.if defined(WITH_MUTT_LOCALES_FIX)
CONFIGURE_ARGS+=	--enable-locales-fix
.endif
.if defined(MUTT_USES_NCURSES) && ${OSVERSION} < 400000
CONFIGURE_ARGS+=	--with-curses=${PREFIX}
.elif defined(MUTT_USES_SLANG)
CONFIGURE_ARGS+=	--with-slang=${PREFIX}
PATCHFILES+=	patch-${VVV_PATCH_VERSION}.vvv.slang.gz:vvv
.endif
.if defined(WITH_MUTT_CYRUS_SASL)
CONFIGURE_ARGS+=	--with-sasl=${LOCALBASE}
.endif
.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
.endif
.if defined(WITHOUT_MUTT_ICONV)
CONFIGURE_ARGS+=	--disable-iconv
.else
CONFIGURE_ARGS+=	--with-libiconv-prefix=${PREFIX}
.endif

PATCH_DIST_STRIP=	-p1

.if ! defined (WITHOUT_MUTT_COMPRESSED_FOLDERS)
PATCHFILES+=	patch-${VVV_PATCH_VERSION}.rr.compressed.gz:vvv
CONFIGURE_ARGS+=	--enable-compressed
SGML_NEEDED=	yes
.endif
.if defined(WITH_MUTT_NNTP)
PATCHFILES+=	patch-${VVV_PATCH_VERSION}.vvv.nntp.gz:vvv
CONFIGURE_ARGS+=	--enable-nntp
SGML_NEEDED=	yes
.endif
.if ! defined(WITHOUT_MUTT_QUOTE_PATCH)
PATCHFILES+=	patch-${VVV_PATCH_VERSION}.vvv.initials.gz:vvv \
		patch-${VVV_PATCH_VERSION}.vvv.quote.gz:vvv
SGML_NEEDED=	yes
.endif
.if defined(WITH_MUTT_EDIT_THREADS)
CONFIGURE_ARGS+=	--enable-imap-edit-threads
SGML_NEEDED=	yes
.endif
.if defined(WITH_MUTT_SIGNATURE_MENU)
PATCHFILES+=	patch-${CD_PATCH_VERSION}.cd.signatures_menu.2.1:cd
SGML_NEEDED=	yes
.endif
.if defined(WITH_MUTT_IFDEF_PATCH)
PATCHFILES+=	patch-${CD_IFDEF_PATCH_VERSION}.cd.ifdef.1:cd
SGML_NEEDED=	yes
.endif
.if defined(WITH_MUTT_MBOX_HOOK_PATCH)
PATCHFILES+=	p0-patch-${DW_MBOX_PATCH_VERSION}.dw.mbox-hook.1:dw
.endif

WRKSRC=		${WRKDIR}/${DISTNAME:S/i$//}
MAN1=		flea.1 mutt.1 mutt_dotlock.1 muttbug.1
MAN5=		muttrc.5 mbox.5

post-patch::
	@${REINPLACE_CMD} -e 's,/usr/bin/gpg,${LOCALBASE}/bin/gpg,g' \
		${WRKSRC}/contrib/gpg.rc
	@${REINPLACE_CMD} -E -e 's|@samplesdir@|${EXAMPLESDIR}|g' \
		${WRKSRC}/contrib/Makefile.in

pre-configure::
	@(cd ${WRKSRC}; ${SETENV} ${AUTOMAKE_ENV} ${ACLOCAL} -I m4)

.if defined(WITH_MUTT_NNTP)
SCRIPTS_ENV+=	MUTT_NNTP="yes"
.endif
.if ! defined (WITHOUT_MUTT_COMPRESSED_FOLDERS)
SCRIPTS_ENV+=	MUTT_COMPRESSED_FOLDERS="yes"
.endif
.if ! defined(WITHOUT_MUTT_QUOTE_PATCH)
SCRIPTS_ENV+=	MUTT_QUOTE_PATCH="yes"
.endif
.if defined(WITH_MUTT_IMAP_HEADER_CACHE)
SCRIPTS_ENV+=	MUTT_IMAP_HEADER_CACHE="yes"
.endif
.if defined(WITH_MUTT_MAILDIR_HEADER_CACHE)
SCRIPTS_ENV+=	MUTT_MAILDIR_HEADER_CACHE="yes"
CONFIGURE_ARGS+=	--enable-hcache
.endif
.if defined(WITH_MUTT_EDIT_THREADS)
SCRIPTS_ENV+=	MUTT_EDIT_THREADS="yes"
.endif
.if defined(WITH_MUTT_SIGNATURE_MENU)
SCRIPTS_ENV+=	MUTT_SIGNATURE_MENU="yes"
.endif
.if defined(WITH_MUTT_IFDEF_PATCH)
SCRIPTS_ENV+=	MUTT_IFDEF_PATCH="yes"
.endif
.if ! defined(WITHOUT_MUTT_PGP_PATCH)
SCRIPTS_ENV+=	MUTT_PGP_PATCH="yes"
.endif
.if ! defined(WITHOUT_MUTT_HTML)
SCRIPTS_ENV+=	MUTT_HTML="yes"
.endif
.if !defined(WITHOUT_NLS)
SCRIPTS_ENV+=	MUTT_NLS="yes"
.endif

.if !defined(NOPORTDOCS)
SCRIPTS_ENV+=	MUTT_PORTDOCS="yes"
post-build:
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-doc-ref
	@${REINPLACE_CMD} -E -e 's|\$$\{PREFIX\}|${PREFIX}|g' \
		-e 's|\$$\{DOCSDIR\}|${DOCSDIR}|g' \
		-e 's|\$$\{EXAMPLESDIR\}|${EXAMPLESDIR}|g' \
		${WRKSRC}/doc/mutt.man
	@${REINPLACE_CMD} -E -e 's|\$$\{PREFIX\}|${PREFIX}|g' \
		-e 's|\$$\{DOCSDIR\}|${DOCSDIR}|g' \
		-e 's|\$$\{EXAMPLESDIR\}|${EXAMPLESDIR}|g' \
		${WRKSRC}/doc/muttrc.man
.if ! defined(WITHOUT_MUTT_HTML)
SGML_USED=	yes
.endif
.if defined(SGML_NEEDED) && !defined(WITHOUT_MUTT_SGMLFORMAT)
SGML_USED=	yes
.endif
.else 	# ! NOPORTDOCS
post-patch::
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-nodoc-contrib
.endif # ! NOPORTDOCS

.if ${SGML_USED} == yes
SCRIPTS_ENV+=	MUTT_SGML="yes"
BUILD_DEPENDS+=	sgmlfmt:${PORTSDIR}/textproc/sgmlformat
post-patch::
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-sgmlformat
.endif

pre-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/generate-plist > ${PLIST}

post-install:
	@${ECHO} > ${PKGMESSAGE}
	${INSTALL_DATA} ${WRKSRC}/Muttrc ${PREFIX}/etc/Muttrc.dist
	${INSTALL_DATA} ${WRKSRC}/mime.types ${PREFIX}/etc/mime.types.dist
.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing Mutt documentation"
	@${MKDIR} ${DOCSDIR} && ${CHMOD} a+rx ${DOCSDIR}
	@cd ${WRKSRC}/doc ; ${INSTALL_MAN} manual.txt PGP-Notes.txt \
		../ABOUT-NLS ../contrib/language*  ${DOCSDIR}
.if ${SGML_USED} == yes
	@cd ${WRKSRC}/doc ; ${INSTALL_MAN} manual.latin1 manual.ps ${DOCSDIR}
.endif
.if defined(WITH_MUTT_NNTP)
	@cd ${WRKSRC} ; ${INSTALL_MAN} ChangeLog.nntp ${DOCSDIR}
.endif
.if ! defined(WITHOUT_MUTT_HTML)
	@${MKDIR} ${DOCSDIR}/html && ${CHMOD} a+rx ${DOCSDIR}/html
	${INSTALL_MAN} ${WRKSRC}/doc/*.html ${DOCSDIR}/html
.endif
.endif
.if defined(MUTT_USES_SLANG)
	@${ECHO} "====================================================" >> ${PKGMESSAGE}
	@${ECHO} "You have installed ${PORTNAME} with SLANG support." >> ${PKGMESSAGE}
	@${ECHO} "This may work for a color terminal only when defining" >> ${PKGMESSAGE}
	@${ECHO} "COLORTERM=yes and COLORFGBG=color,color in your" >> ${PKGMESSAGE}
	@${ECHO} "environment." >> ${PKGMESSAGE}
	@${ECHO} "====================================================" >> ${PKGMESSAGE}
.endif
.if defined(WITH_MUTT_IMAP_HEADER_CACHE)
	@${ECHO} "====================================================" >> ${PKGMESSAGE}
	@${ECHO} "You have installed ${PORTNAME} with the IMAP header cache enabled." >> ${PKGMESSAGE}
	@${ECHO} "Please be aware that this - at the moment - could result in" >> ${PKGMESSAGE}
	@${ECHO} "incorrect display of message flags if there is another client" >> ${PKGMESSAGE}
	@${ECHO} "simultaneously using the same mailbox." >> ${PKGMESSAGE}
	@${ECHO} "====================================================" >> ${PKGMESSAGE}
.endif
.if defined(WITH_MUTT_MAILDIR_HEADER_CACHE) && defined(WITH_MUTT_MAILDIR_MTIME_PATCH)
	@${ECHO} "====================================================" >> ${PKGMESSAGE}
	@${ECHO} "You have installed ${PORTNAME} with the Maildir header" >> ${PKGMESSAGE}
	@${ECHO} "cache and the MAILDIR_MTIME_PATCH enabled." >> ${PKGMESSAGE}
	@${ECHO}  >> ${PKGMESSAGE}
	@${ECHO} "For this to work you may have to delete your old" >> ${PKGMESSAGE}
	@${ECHO} "Maildir header cache or otherwise you may face" >> ${PKGMESSAGE}
	@${ECHO} "an \"Out of memory\" error." >> ${PKGMESSAGE}
	@${ECHO} "====================================================" >> ${PKGMESSAGE}
.endif
.if !defined(BATCH)
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
.endif
.include <bsd.port.post.mk>
