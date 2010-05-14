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
# In general you can choose between using ncurses (WITH_MUTT_NCURSES)
# and SLANG (WITH_MUTT_SLANG). Note that you may have to set the variables
# COLORTERM=yes and COLORFGBG="color1;color2" in your environment to get slang
# function properly.
# The default version for ncurses is that which comes with the operating
# system. If you want to use the ncurses supplied by the ports-system define
# WITH_MUTT_NCURSES_PORT.
#
# If you want to install the mutt documentation in html and ps format define:
#  WITH_MUTT_HTML
#  This is a default knob and can be disabled by WITHOUT_MUTT_HTML
#
# If you do not want that the documentation is rebuilt using the xml tools
# define:
#  WITHOUT_MUTT_XML
#    (this can only be stated if WITHOUT_MUTT_HTML is defined)
#
# If you want to access compressed email folders define:
#  WITH_MUTT_COMPRESSED_FOLDERS
#  This is a default knob and can be disabled by WITHOUT_MUTT_COMPRESSED_FOLDERS
#
# If you do not want mutt to use the iconv library define:
#  WITHOUT_MUTT_ICONV
#
# If you want mutt to use the idn library define:
#  WITH_MUTT_IDN
#
# If you want to make use of the gpgme interface define:
#  WITH_MUTT_GPGME
#
# If you want to enable extended quoting functions define:
#  WITH_MUTT_QUOTE_PATCH
#  This is a default knob and can be disabled by WITHOUT_MUTT_QUOTE_PATCH
#
# If you want to have the IMAP header cache define:
#  WITH_MUTT_IMAP_HEADER_CACHE
#
# If you want to have the Maildir and the IMAP header cache define:
#  WITH_MUTT_MAILDIR_HEADER_CACHE
#
# If you want to make SMIME outlook compatible define:
#  WITH_MUTT_SMIME_OUTLOOK_COMPAT
#  This is a default knob and can be disabled by
#    WITHOUT_MUTT_SMIME_OUTLOOK_COMPAT
#
# If you want to read and post news with mutt define:
#  WITH_MUTT_NNTP
#
# If you want to use the SASL2 authentication features with your email server
# define
#  WITH_MUTT_CYRUS_SASL2
#
# If you want mutt to use the GNU aspell spelling checker define:
#  WITH_MUTT_ASPELL
#
# If you want mutt to use the ispell spelling checker define:
#  WITH_MUTT_ISPELL
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
#
# If you want to have the Mailbox Sidebar patch define:
#  WITH_MUTT_SIDEBAR_PATCH
#
# If you do not want mutt to use the flock() function define:
#  WITHOUT_MUTT_FLOCK
#
# If you want to enable the reverse_reply option define:
#  WITH_MUTT_REVERSE_REPLY_PATCH
#
# If you want to enable the `greeting' option define:
#  WITH_MUTT_GREETING_PATCH
#
# If you want to enable the parent/child match support define:
#  WITH_MUTT_PARENT_CHILD_MATCH_PATCH
#
# If you want to enable the internal SMTP relay support define:
#  WITH_MUTT_SMTP
#
# If you want to enable debugging capabilities define:
#  WITH_MUTT_DEBUG
#
# If you do not want to install the manpages mbox.5 and mdf.8 (because that
# conflicts with other ports which installed these:
#  WITHOUT_MUTT_MAILBOX_MANPAGES
#

PORTNAME=	mutt-devel
PORTVERSION=	1.5.20
PORTREVISION?=	4
CATEGORIES+=	mail ipv6
.if defined(WITH_MUTT_NNTP)
CATEGORIES+=	news
.endif
MASTER_SITES=	ftp://ftp.mutt.org/mutt/devel/ \
		ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/devel/ \
		ftp://ftp.demon.co.uk/pub/mirrors/mutt/devel/ \
		ftp://ftp.parodius.com/pub/mutt/devel/ \
		http://www.mutt.org.ua/download/mutt-${VVV_PATCH_VERSION}/:vvv \
		http://www2.mutt.org.ua/download/mutt-${VVV_PATCH_VERSION}/:vvv \
		http://www3.mutt.org.ua/download/mutt-${VVV_PATCH_VERSION}/:vvv \
		ftp://ftp.mutt.org.ua/pub/mutt/mutt-${VVV_PATCH_VERSION}/:vvv \
		ftp://ftp3.mutt.org.ua/pub/mutt/mutt-${VVV_PATCH_VERSION}/:vvv \
		http://www.spinnaker.de/mutt/compressed/:rr \
		http://lunar-linux.org/~tchan/mutt/:tchan
DISTNAME=	mutt-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES+=	http://www.mutt.org.ua/download/mutt-${VVV_PATCH_VERSION}/:vvv \
		http://www2.mutt.org.ua/download/mutt-${VVV_PATCH_VERSION}/:vvv \
		http://www3.mutt.org.ua/download/mutt-${VVV_PATCH_VERSION}/:vvv \
		ftp://ftp.mutt.org.ua/pub/mutt/mutt-${VVV_PATCH_VERSION}/:vvv \
		ftp://ftp3.mutt.org.ua/pub/mutt/mutt-${VVV_PATCH_VERSION}/:vvv \
		http://home.woolridge.ca/mutt/patches/:dw \
		http://www.spinnaker.de/mutt/compressed/:rr \
		http://www.emaillab.org/mutt/${AC_PATCH_VERSION}/:jp \
		http://vc.org.ua/mutt/:vc \
		http://yz.kiev.ua/mutt/:vc

MAINTAINER?=	udo.schweigert@siemens.com
COMMENT?=	The Mongrel of Mail User Agents (development version)

CONFLICTS=	mutt-[0-9]*
DIST_SUBDIR=	mutt
DOCSDIR?=	${PREFIX}/share/doc/mutt
EXAMPLESDIR?=	${PREFIX}/share/examples/mutt
DATADIR?=	${PREFIX}/share/mutt
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CC="${CC} -I${LOCALBASE}/include" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-fcntl --with-ssl=${OPENSSLBASE} \
		--with-docdir=${DOCSDIR} --sysconfdir=${PREFIX}/etc \
		--enable-external-dotlock --enable-pop --enable-imap \
		--disable-warnings
.if defined(MUTT_CONFIGURE_ARGS)
CONFIGURE_ARGS+=	${MUTT_CONFIGURE_ARGS}
.endif

USE_AUTOTOOLS=	automake:110 autoconf:262
USE_OPENSSL=	yes

PLIST=		${WRKDIR}/PLIST
PKGMESSAGE=	${WRKDIR}/pkg-message
SCRIPTS_ENV=	WRKDIR="${WRKDIR}"

.include <bsd.port.pre.mk>

DW_PATCH_VERSION=	1.5.6
AC_PATCH_VERSION=	1.5.9
VC_PATCH_VERSION=	1.5.16
DW_MBOX_PATCH_VERSION=	1.5.18
.if !defined(VVV_PATCH_VERSION)
VVV_PATCH_VERSION=	${PORTVERSION}
.endif
.if !defined(RR_PATCH_VERSION)
RR_PATCH_VERSION=	${PORTVERSION}
.endif
.if !defined(DW_PATCH_VERSION)
DW_PATCH_VERSION=	${PORTVERSION}
.endif
.if !defined(DW_MBOX_PATCH_VERSION)
DW_MBOX_PATCH_VERSION=	${DW_PATCH_VERSION}
.endif
.if !defined(AC_PATCH_VERSION)
AC_PATCH_VERSION=	${PORTVERSION}
.endif
.if !defined(VC_PATCH_VERSION)
VC_PATCH_VERSION=	${PORTVERSION}
.endif
.if defined(WITH_MUTT_MAILDIR_HEADER_CACHE)
WITH_MUTT_IMAP_HEADER_CACHE=	yes
.endif
.if ${OSVERSION} >= 700033 || (${OSVERSION} < 700000 && ${OSVERSION} >= 602107)
NCURSES_IS_DEFAULT=	yes
.else
SLANG_IS_DEFAULT=	yes
.endif

.if defined (MUTT_LITE)
WITHOUT_MUTT_XML=			yes
WITHOUT_MUTT_COMPRESSED_FOLDERS=	yes
WITHOUT_MUTT_QUOTE_PATCH=		yes
WITHOUT_MUTT_HTML=			yes
WITH_MUTT_NCURSES=			yes
PKGNAMESUFFIX=	-lite
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

RUN_DEPENDS+=	${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support
.if !defined (MUTT_LITE)
.if exists(${LOCALBASE}/bin/aspell) && !defined(WITH_MUTT_ISPELL)
WITH_MUTT_ASPELL=	yes
.elif exists(${LOCALBASE}/bin/ispell) && !defined(WITH_MUTT_ASPELL)
WITH_MUTT_ISPELL=	yes
.endif
.if defined(PACKAGE_BUILDING) && !defined(WITH_MUTT_ASPELL) && \
	!defined(WITH_MUTT_ISPELL)
WITH_MUTT_ASPELL=	yes
.endif
.if defined(WITH_MUTT_ASPELL)
BUILD_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
RUN_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
.elif defined(WITH_MUTT_ISPELL)
BUILD_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
.endif
.if defined(PACKAGE_BUILDING)
RUN_DEPENDS+=	urlview:${PORTSDIR}/textproc/urlview
.endif
.endif

.if defined(WITH_MUTT_NCURSES_PORT)
WITH_MUTT_NCURSES=	yes
.endif
.if defined(WITH_MUTT_SLANG) || defined(WITH_SLANG)
MUTT_USES_SLANG=	yes
.endif
.if defined(WITH_MUTT_NCURSES) && !defined(MUTT_USES_SLANG)
MUTT_USES_NCURSES=	yes
.endif
.if !defined(MUTT_USES_SLANG) && !defined(WITHOUT_MUTT_SLANG) && !defined(MUTT_USES_NCURSES)
.if defined(SLANG_IS_DEFAULT)
MUTT_USES_SLANG=	yes
.elif defined(NCURSES_IS_DEFAULT)
MUTT_USES_NCURSES=	yes
.endif
.endif
.if defined(WITHOUT_MUTT_SGMLFORMAT)
XML_USED=	no
.endif
.if defined(WITHOUT_MUTT_XML)
XML_USED=	no
.endif
.if !defined(XML_USED)
XML_USED=	no
.endif
.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
.endif
.if !defined(WITHOUT_MUTT_ICONV)
USE_ICONV=	yes
.endif
.if defined(NOPORTDOCS)
XML_USED=	no
.endif
.if defined(MUTT_USES_NCURSES)
.if defined(WITH_MUTT_NCURSES_PORT) || exists(${LOCALBASE}/lib/libncurses.a)
MUTT_USES_NCURSES_PORT=	yes
.endif
.endif
.if defined(MUTT_USES_NCURSES_PORT)
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
CFLAGS+=	-I${LOCALBASE}/include/ncurses -I${LOCALBASE}/include
.elif defined(MUTT_USES_SLANG)
LIB_DEPENDS+=	slang.2:${PORTSDIR}/devel/libslang2
.endif
.if defined(WITH_MUTT_CYRUS_SASL2)
LIB_DEPENDS+=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2
.endif
.if exists(${LOCALBASE}/lib/libidn.so) && !defined(WITHOUT_MUTT_IDN)
WITH_MUTT_IDN=	yes
.endif
.if defined(WITH_MUTT_IDN)
LIB_DEPENDS+=	idn:${PORTSDIR}/dns/libidn
.endif
.if defined(WITH_MUTT_GPGME)
LIB_DEPENDS+=	gpgme:${PORTSDIR}/security/gpgme
.endif
.if ! defined(WITHOUT_MUTT_SMIME_OUTLOOK_COMPAT)
post-patch::
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-smime-outlook
.endif
.if defined(WITH_MUTT_SIGNATURE_MENU)
IGNORE=	The WITH_MUTT_SIGNATURE_MENU does not work at the moment
XML_NEEDED=	yes
post-patch::
	@${PATCH} ${PATCH_ARGS} -p1 < ${PATCHDIR}/extra-patch-signature-menu
.endif
.if defined(WITH_MUTT_MAILDIR_MTIME_PATCH)
post-patch::
.if defined(WITH_MUTT_NNTP)
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-maildir-mtime-nntp
.else
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-maildir-mtime
.endif
.endif

.if defined(WITH_MUTT_ASPELL)
post-patch::
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-aspell
.endif

.if defined(WITH_MUTT_REVERSE_REPLY_PATCH)
post-patch::
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-reverse_reply
.endif

.if defined(WITH_MUTT_PARENT_CHILD_MATCH_PATCH)
post-patch::
	@${PATCH} ${PATCH_ARGS} -p1 < ${PATCHDIR}/extra-patch-parent-child-match
.endif

.if defined(WITHOUT_MUTT_FLOCK)
CONFIGURE_ARGS+=	--disable-flock
.else
CONFIGURE_ARGS+=	--enable-flock
.endif
.if defined(WITH_MUTT_LOCALES_FIX)
CONFIGURE_ARGS+=	--enable-locales-fix
.endif
.if defined(MUTT_USES_NCURSES_PORT)
CONFIGURE_ARGS+=	--with-curses=${LOCALBASE}
.elif defined(MUTT_USES_SLANG)
CONFIGURE_ARGS+=	--with-slang=${LOCALBASE}
.endif
.if defined(WITH_MUTT_CYRUS_SASL2)
CONFIGURE_ARGS+=	--with-sasl=${LOCALBASE}
.endif
.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
.endif
.if defined(WITHOUT_MUTT_ICONV)
CONFIGURE_ARGS+=	--disable-iconv
.else
CONFIGURE_ARGS+=	--with-libiconv-prefix=${LOCALBASE}
.endif
.if defined(WITH_MUTT_IDN)
CONFIGURE_ARGS+=	--with-idn
.else
CONFIGURE_ARGS+=	--without-idn
.endif
.if defined(WITH_MUTT_GPGME)
CONFIGURE_ARGS+=	--enable-gpgme
.else
CONFIGURE_ARGS+=	--disable-gpgme
.endif
.if !defined(WITHOUT_GSSAPI)
.if exists(${LOCALBASE}/bin/krb5-config)
LIB_DEPENDS+=		gssapi_krb5:${PORTSDIR}/security/krb5
CONFIGURE_ARGS+=	--with-gss=${LOCALBASE}
.elif (defined(MAKE_KERBEROS5)) || exists(/usr/lib/libkrb5.a)
CONFIGURE_ARGS+=	--with-gss
USE_KRB5_SYS=YES
.endif
.endif
.if defined(WITH_MUTT_SMTP)
CONFIGURE_ARGS+=	--enable-smtp
.else
CONFIGURE_ARGS+=	--disable-smtp
.endif
.if defined(WITH_MUTT_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

PATCH_DIST_STRIP=	-p1

.if ! defined (WITHOUT_MUTT_COMPRESSED_FOLDERS)
DISTFILES+=	patch-${RR_PATCH_VERSION}.rr.compressed.gz:vvv
CONFIGURE_ARGS+=	--enable-compressed
XML_NEEDED=	yes
pre-patch::
	@${GUNZIP_CMD} -c ${DISTDIR}/${DIST_SUBDIR}/patch-${RR_PATCH_VERSION}.rr.compressed.gz > ${WRKDIR}/patch-compressed
	@${REINPLACE_CMD} -E '/^diff.*\/doc\/manual.txt$$/,/^diff/d' \
		 ${WRKDIR}/patch-compressed
	@${PATCH} ${PATCH_ARGS} -p1 < ${WRKDIR}/patch-compressed
.endif
.if defined(WITH_MUTT_NNTP)
DISTFILES+=	patch-${VVV_PATCH_VERSION}.vvv.nntp.gz:vvv
CONFIGURE_ARGS+=	--enable-nntp
XML_NEEDED=	yes
pre-patch::
	@${GUNZIP_CMD} -c ${DISTDIR}/${DIST_SUBDIR}/patch-${VVV_PATCH_VERSION}.vvv.nntp.gz > ${WRKDIR}/patch-nntp
	@${REINPLACE_CMD} -E '/^diff.*\/doc\/manual.txt$$/,/^diff/d' \
		${WRKDIR}/patch-nntp
	@${PATCH} ${PATCH_ARGS} -p1 < ${WRKDIR}/patch-nntp
.endif
.if ! defined(WITHOUT_MUTT_QUOTE_PATCH)
PATCHFILES+=	patch-${VVV_PATCH_VERSION}.vvv.initials.gz:vvv \
		patch-${VVV_PATCH_VERSION}.vvv.quote.gz:vvv
XML_NEEDED=	yes
.endif
.if defined(WITH_MUTT_IFDEF_PATCH)
post-patch::
	@${PATCH} ${PATCH_ARGS} -p1 < ${PATCHDIR}/extra-patch-ifdef
.endif
.if defined(WITH_MUTT_MBOX_HOOK_PATCH)
IGNORE=	The WITH_MUTT_MBOX_HOOK_PATCH does not work at the moment
#PATCHFILES+=	p0-patch-${DW_MBOX_PATCH_VERSION}.dw.mbox-hook.1:dw
.endif
.if defined(WITH_MUTT_SIDEBAR_PATCH)
XML_NEEDED=	yes
.if defined(WITH_MUTT_NNTP)
post-patch::
	@${PATCH} ${PATCH_ARGS} -p1 < ${PATCHDIR}/extra-patch-sidebar-nntp
.else
post-patch::
	@${PATCH} ${PATCH_ARGS} -p1 < ${PATCHDIR}/extra-patch-sidebar
.endif
.endif
.if defined(WITH_MUTT_GREETING_PATCH)
PATCHFILES+=	mutt-${VC_PATCH_VERSION}.vc.greeting:vc
.endif
.if defined(WITH_MUTT_TRASH_PATCH)
post-patch::
	@${PATCH} ${PATCH_ARGS} -p1 < ${PATCHDIR}/extra-patch-trash-purge
.endif

WRKSRC=		${WRKDIR}/${DISTNAME:S/i$//}
MAN1=		mutt.1 mutt_dotlock.1 flea.1 muttbug.1
MAN5=		muttrc.5
.if !defined(WITHOUT_MUTT_MAILBOX_MANPAGES)
MAN5+=		mbox.5 mmdf.5
.endif

post-patch::
	@${REINPLACE_CMD} -e 's,/usr/bin/gpg,${LOCALBASE}/bin/gpg,g' \
		${WRKSRC}/contrib/gpg.rc
	@${REINPLACE_CMD} -e 's,pgp6,pgp,g' \
		${WRKSRC}/contrib/pgp6.rc
	@${REINPLACE_CMD} -E -e 's|@samplesdir@|${EXAMPLESDIR}|g' \
		${WRKSRC}/contrib/Makefile.am
.if defined(WITHOUT_MUTT_MAILBOX_MANPAGES)
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-no-mbox-manpage
.endif

pre-configure::
	@(cd ${WRKSRC}; ${SETENV} ${AUTOMAKE_ENV} ${ACLOCAL} -I m4)
.if defined(USE_KRB5_SYS)
	@${ECHO_CMD} "#define HAVE_HEIMDAL" >> ${WRKSRC}/config.h.in
	@${REINPLACE_CMD} -e 's|<gssapi/gssapi\.h>|<gssapi.h>|' \
		${WRKSRC}/imap/auth_gss.c
.endif

.if defined(MUTT_SLAVE_HTML_PAGES)
SCRIPTS_ENV+=	MUTT_SLAVE_HTML_PAGES="${MUTT_SLAVE_HTML_PAGES}"
.endif
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
.if defined(WITH_TOKYOCABINET)
CONFIGURE_ARGS+=	--enable-hcache --without-gdbm --without-bdb --with-tokyocabinet
LIB_DEPENDS+=		tokyocabinet.9:${PORTSDIR}/databases/tokyocabinet
.else
USE_BDB=		42+
CONFIGURE_ARGS+=	--enable-hcache --without-gdbm --with-bdb
.endif
.else
CONFIGURE_ARGS+=	--disable-hcache
.endif
.if defined(WITH_MUTT_MAILDIR_HEADER_CACHE)
CONFIGURE_ARGS+=	--without-qdbm
.endif
.if defined(WITH_MUTT_SIDEBAR_PATCH)
SCRIPTS_ENV+=	MUTT_SIDEBAR_PATCH="yes"
.endif
.if defined(WITH_MUTT_SIGNATURE_MENU)
SCRIPTS_ENV+=	MUTT_SIGNATURE_MENU="yes"
.endif
.if defined(WITH_MUTT_IFDEF_PATCH)
SCRIPTS_ENV+=	MUTT_IFDEF_PATCH="yes"
.endif
.if ! defined(WITHOUT_MUTT_HTML)
SCRIPTS_ENV+=	MUTT_HTML="yes"
.endif
.if !defined(WITHOUT_NLS)
SCRIPTS_ENV+=	MUTT_NLS="yes"
.endif
.if defined(WITH_MUTT_REVERSE_REPLY_PATCH)
SCRIPTS_ENV+=	MUTT_REVERSE_REPLY_PATCH="yes"
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
XML_USED=	yes
.endif
.if defined(XML_NEEDED) && !defined(WITHOUT_MUTT_XML)
XML_USED=	yes
.endif
.else 	# ! NOPORTDOCS
post-patch::
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-nodoc-contrib
.endif # ! NOPORTDOCS

.if ${XML_USED} == yes
BUILD_DEPENDS+=	xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl \
		lynx:${PORTSDIR}/www/lynx
post-patch::
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-doc-xml
.endif

pre-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/generate-plist > ${PLIST}

post-install:
	@${ECHO} > ${PKGMESSAGE}
	${INSTALL_DATA} ${WRKSRC}/doc/Muttrc ${PREFIX}/etc/Muttrc.dist
.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing Mutt documentation"
	@${MKDIR} ${DOCSDIR} && ${CHMOD} a+rx ${DOCSDIR}
	@cd ${WRKSRC}/doc ; ${INSTALL_MAN} manual.txt PGP-Notes.txt \
		../ABOUT-NLS ../contrib/language*  ${DOCSDIR}
.if defined(WITH_MUTT_NNTP)
	@cd ${WRKSRC} ; ${INSTALL_MAN} ChangeLog.nntp ${DOCSDIR}
.endif
.if ! defined(WITHOUT_MUTT_HTML)
	@${MKDIR} ${DOCSDIR}/html && ${CHMOD} a+rx ${DOCSDIR}/html
	${INSTALL_MAN} ${WRKSRC}/doc/*.html ${DOCSDIR}/html
.endif
.endif
.if defined(MUTT_USES_SLANG)
	@${ECHO} "=====================================================" >> ${PKGMESSAGE}
	@${ECHO} "You have installed ${PORTNAME} with SLANG support." >> ${PKGMESSAGE}
	@${ECHO} "This may work for a color terminal only when defining" >> ${PKGMESSAGE}
	@${ECHO} "COLORTERM=yes and COLORFGBG=\"color1;color2\" in your" >> ${PKGMESSAGE}
	@${ECHO} "environment." >> ${PKGMESSAGE}
	@${ECHO} "=====================================================" >> ${PKGMESSAGE}
.endif
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
.endif
.include <bsd.port.post.mk>
