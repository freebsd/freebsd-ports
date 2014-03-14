# Created by: Udo Schweigert
# $FreeBSD$

PORTNAME=	mutt
PORTVERSION=	1.5.23
CATEGORIES+=	mail ipv6
MASTER_SITES=	ftp://ftp.mutt.org/mutt/ \
		ftp://ftp.mutt.org/mutt/devel/ \
		ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/ \
		ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/devel/ \
		ftp://ftp.demon.co.uk/pub/mirrors/mutt/ \
		ftp://ftp.demon.co.uk/pub/mirrors/mutt/devel/ \
		http://www.mutt.org.ua/download/mutt-${VVV_PATCH_VERSION}/:vvv \
		http://www2.mutt.org.ua/download/mutt-${VVV_PATCH_VERSION}/:vvv \
		http://www3.mutt.org.ua/download/mutt-${VVV_PATCH_VERSION}/:vvv \
		ftp://ftp.mutt.org.ua/pub/mutt/mutt-${VVV_PATCH_VERSION}/:vvv \
		ftp://ftp3.mutt.org.ua/pub/mutt/mutt-${VVV_PATCH_VERSION}/:vvv \
		http://www.spinnaker.de/mutt/compressed/:rr \
		http://lunar-linux.org/~tchan/mutt/:tchan
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES+=	http://www.mutt.org.ua/download/mutt-${VVV_PATCH_VERSION}/:vvv \
		http://www2.mutt.org.ua/download/mutt-${VVV_PATCH_VERSION}/:vvv \
		http://www3.mutt.org.ua/download/mutt-${VVV_PATCH_VERSION}/:vvv \
		ftp://ftp.mutt.org.ua/pub/mutt/mutt-${VVV_PATCH_VERSION}/:vvv \
		ftp://ftp3.mutt.org.ua/pub/mutt/mutt-${VVV_PATCH_VERSION}/:vvv \
		http://home.woolridge.ca/mutt/patches/:dw \
		http://www.spinnaker.de/mutt/compressed/:rr \
		http://www.emaillab.org/mutt/${AC_PATCH_VERSION}/:jp

MAINTAINER?=	udo.schweigert@siemens.com
COMMENT?=	The Mongrel of Mail User Agents (development version)

CONFLICTS?=	ja-mutt-[0-9]* ja-mutt-devel-[0-9]* mutt-1.4* mutt-devel-lite-[0-9]* mutt-lite-[0-9]* zh-mutt-devel-[0-9]*

DIST_SUBDIR=	mutt
DOCSDIR?=	${PREFIX}/share/doc/mutt
EXAMPLESDIR?=	${PREFIX}/share/examples/mutt
DATADIR?=	${PREFIX}/share/mutt
CONFIGURE_ENV=	CC="${CC} -I${LOCALBASE}/include"
CONFIGURE_ARGS=	--disable-fcntl --with-ssl=${OPENSSLBASE} \
		--with-docdir=${DOCSDIR} --sysconfdir=${PREFIX}/etc \
		--enable-external-dotlock --enable-pop --enable-imap \
		--disable-warnings

USES+=		shebangfix
SHEBANG_FILES=	doc/gen-map-doc smime_keys.pl contrib/smime_keys_test.pl

.if defined(MUTT_CONFIGURE_ARGS)
CONFIGURE_ARGS+=	${MUTT_CONFIGURE_ARGS}
.endif

USE_AUTOTOOLS=	automake autoconf
AUTOMAKE_ARGS=	--add-missing
USE_OPENSSL=	yes

.if defined (MUTT_LITE)
LITE=	YES
.endif
.if !defined (LITE)
OPTIONS_DEFINE=	COMPRESSED_FOLDERS SASL DEBUG FLOCK \
		GPGME GREETING_PATCH GSSAPI HTML ICONV IDN IFDEF_PATCH \
		IMAP_HEADER_CACHE LOCALES_FIX MAILBOX_MANPAGES \
		MAILDIR_HEADER_CACHE MAILDIR_MTIME_PATCH \
		NNTP PARENT_CHILD_MATCH_PATCH \
		QUOTE_PATCH REVERSE_REPLY_PATCH SGMLFORMAT SIDEBAR_PATCH \
		SIGNATURE_MENU SMART_DATE SMIME_OUTLOOK_COMPAT SMTP \
		TOKYOCABINET TRASH_PATCH XML

OPTIONS_SINGLE=	SCREEN
OPTIONS_RADIO=	SPELL
OPTIONS_RADIO_SPELL=	ASPELL ISPELL
OPTIONS_SINGLE_SCREEN=	NCURSES SLANG

COMPRESSED_FOLDERS_DESC=	Compressed folders
SASL_DESC=	SASL authentication
DEBUG_DESC=	Debugging capabilities
FLOCK_DESC=	flock() usage
GPGME_DESC=	Gpgme interface
GREETING_PATCH_DESC=	Greeting support
GSSAPI_DESC=	Use the gss API
HTML_DESC=	HTML documentation
IFDEF_PATCH_DESC=	ifdef feature
IMAP_HEADER_CACHE_DESC=	IMAP header cache
LOCALES_FIX_DESC=	Locales fix
MAILBOX_MANPAGES_DESC=	Install mbox.5/mmdf.5 manpages
MAILDIR_HEADER_CACHE_DESC=	Maildir header cache
MAILDIR_MTIME_PATCH_DESC=	Maildir mtime patch
MBOX_HOOK_PATCH_DESC=	Enhanced mbox-hook
NCURSES_DESC=	Ncurses support
PARENT_CHILD_MATCH_PATCH_DESC=	Parent/child match
QUOTE_PATCH_DESC=	Extended quoting
REVERSE_REPLY_PATCH_DESC=	Reverse_reply
SGMLFORMAT_DESC=	SGML support
SIDEBAR_PATCH_DESC=	Sidebar support
SIGNATURE_MENU_DESC=	Signature menu
SLANG_DESC=	SLANG support
SMART_DATE_DESC=	Dynamic date formatting with "%@"
SMIME_OUTLOOK_COMPAT_DESC=	SMIME outlook compatibility
SMTP_DESC=	SMTP relay support
TOKYOCABINET_DESC=	Use tokyocabinet instead of Berkley DB
TRASH_PATCH_DESC=	Trash folder support
XML_DESC=	Use XML tools for building documentation

OPTIONS_DEFAULT=	COMPRESSED_FOLDERS HTML ICONV MAILBOX_MANPAGES \
		NCURSES QUOTE_PATCH SGMLFORMAT SMIME_OUTLOOK_COMPAT \
		NLS XML SMTP
.endif

.include <bsd.port.options.mk>

DW_PATCH_VERSION=	1.5.6
AC_PATCH_VERSION=	1.5.9
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

.if defined (LITE)
PKGNAMESUFFIX=	-lite
PLIST_SUB+=	MBOXMAN=""
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

.if !defined (LITE)
.if ${PORT_OPTIONS:MASPELL}
BUILD_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
RUN_DEPENDS+=	aspell:${PORTSDIR}/textproc/aspell
.elif ${PORT_OPTIONS:MISPELL}
BUILD_DEPENDS+=	ispell:${PORTSDIR}/textproc/aspell-ispell
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/aspell-ispell
.endif
.if defined(PACKAGE_BUILDING)
RUN_DEPENDS+=	urlview:${PORTSDIR}/textproc/urlview
.endif
.endif

# Handle ncurses/ncurses-port/slang
.if ${PORT_OPTIONS:MSLANG}
CONFIGURE_ARGS+=	--with-slang=${LOCALBASE}
LIB_DEPENDS+=	libslang.so:${PORTSDIR}/devel/libslang2
.endif

.if ${PORT_OPTIONS:MNCURSES}
USES+=		ncurses
.endif

.if ! ${PORT_OPTIONS:MSGMLFORMAT} || ! ${PORT_OPTIONS:MXML} || !defined(XML_USED) \
	|| ! ${PORT_OPTIONS:MDOCS}
XML_USED=	no
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MSASL}
LIB_DEPENDS+=	libsasl2.so:${PORTSDIR}/security/cyrus-sasl2
CONFIGURE_ARGS+=	--with-sasl=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MSMIME_OUTLOOK_COMPAT}
post-patch::
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-smime-outlook
.endif

.if ${PORT_OPTIONS:MSMART_DATE}
post-patch::
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-smartdate
.endif

.if ${PORT_OPTIONS:MSIGNATURE_MENU}
IGNORE=	the WITH_SIGNATURE_MENU does not work at the moment
XML_NEEDED=	yes
post-patch::
	@${PATCH} ${PATCH_ARGS} -p1 < ${PATCHDIR}/extra-patch-signature-menu
.endif

.if ${PORT_OPTIONS:MMAILDIR_MTIME_PATCH}
post-patch::
.if ${PORT_OPTIONS:MNNTP}
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-maildir-mtime-nntp
.else
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-maildir-mtime
.endif
.endif

.if ${PORT_OPTIONS:MASPELL}
post-patch::
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-aspell
.endif

.if ${PORT_OPTIONS:MREVERSE_REPLY_PATCH}
post-patch::
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-reverse_reply
.endif

.if ${PORT_OPTIONS:MPARENT_CHILD_MATCH_PATCH}
post-patch::
	@${PATCH} ${PATCH_ARGS} -p1 < ${PATCHDIR}/extra-patch-parent-child-match
.endif

.if ${PORT_OPTIONS:MFLOCK}
CONFIGURE_ARGS+=	--enable-flock
.else
CONFIGURE_ARGS+=	--disable-flock
.endif

.if ${PORT_OPTIONS:MLOCALES_FIX}
CONFIGURE_ARGS+=	--enable-locales-fix
.endif

.if ${PORT_OPTIONS:MICONV}
USES+=			iconv
CONFIGURE_ARGS+=	${ICONV_CONFIGURE_ARG}
.else
CONFIGURE_ARGS+=	--disable-iconv
.endif

.if ${PORT_OPTIONS:MIDN}
LIB_DEPENDS+=	libidn.so:${PORTSDIR}/dns/libidn
CONFIGURE_ARGS+=	--with-idn
.else
CONFIGURE_ARGS+=	--without-idn
.endif

.if ${PORT_OPTIONS:MGPGME}
LIB_DEPENDS+=	libgpgme.so:${PORTSDIR}/security/gpgme
CONFIGURE_ARGS+=	--enable-gpgme
.else
CONFIGURE_ARGS+=	--disable-gpgme
.endif
LDFLAGS=

.if ${PORT_OPTIONS:MGSSAPI}
.if exists(${LOCALBASE}/bin/krb5-config)
LIB_DEPENDS+=		libgssapi_krb5.so:${PORTSDIR}/security/krb5
CONFIGURE_ARGS+=	--with-gss=${LOCALBASE}
.elif exists(${KRB5_HOME}/bin/krb5-config)
LIB_DEPENDS+=		libgssapi_krb5.so:${PORTSDIR}/security/krb5
CONFIGURE_ARGS+=	--with-gss=${KRB5_HOME}
LDFLAGS+=		-L${KRB5_HOME}/lib -rpath=${KRB5_HOME}/lib -ltinfow
.elif exists(${HEIMDAL_HOME}/bin/krb5-config)
LIB_DEPENDS+=		libgssapi_krb5.so:${PORTSDIR}/security/krb5
CONFIGURE_ARGS+=	--with-gss=${HEIMDAL_HOME}
LDFLAGS+=		-L${HEIMDAL_HOME}/lib -rpath=${HEIMDAL_HOME}/lib -ltinfow
.elif (defined(MAKE_KERBEROS5)) || exists(/usr/lib/libkrb5.a)
CONFIGURE_ARGS+=	--with-gss
WITH_KRB5_SYS=YES
.endif
.endif

LDFLAGS+=		-L${LOCALBASE}/lib -rpath=${LOCALBASE}/lib:/usr/lib -ltinfow
CFLAGS+=		${CFLAGS_ADD}
LDFLAGS+=		${LDFLAGS_ADD}

.if ${PORT_OPTIONS:MSMTP}
CONFIGURE_ARGS+=	--enable-smtp
.else
CONFIGURE_ARGS+=	--disable-smtp
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.endif

PATCH_DIST_STRIP=	-p1

.if ${PORT_OPTIONS:MCOMPRESSED_FOLDERS}
DISTFILES+=	patch-${RR_PATCH_VERSION}.rr.compressed.gz:vvv
CONFIGURE_ARGS+=	--enable-compressed
XML_NEEDED=	yes
pre-patch::
	@${GUNZIP_CMD} -c ${DISTDIR}/${DIST_SUBDIR}/patch-${RR_PATCH_VERSION}.rr.compressed.gz > ${WRKDIR}/patch-compressed
	@${REINPLACE_CMD} -E '/^diff.*\/doc\/manual.txt$$/,/^diff/d' \
		 ${WRKDIR}/patch-compressed
	@${PATCH} ${PATCH_ARGS} -p1 < ${WRKDIR}/patch-compressed
.endif

.if ${PORT_OPTIONS:MNNTP}
DISTFILES+=	patch-${VVV_PATCH_VERSION}.vvv.nntp.gz:vvv
DISTFILES+=	patch-${VVV_PATCH_VERSION}.vvv.nntp_ru.gz:vvv
CONFIGURE_ARGS+=	--enable-nntp
XML_NEEDED=	yes
CATEGORIES+=	news
PLIST_SUB+=	NNTP=""
pre-patch::
	@${GUNZIP_CMD} -c ${DISTDIR}/${DIST_SUBDIR}/patch-${VVV_PATCH_VERSION}.vvv.nntp.gz > ${WRKDIR}/patch-nntp
	@${REINPLACE_CMD} -E '/^diff.*\/doc\/manual.txt$$/,/^diff/d' \
		${WRKDIR}/patch-nntp
	@${PATCH} ${PATCH_ARGS} -p1 < ${WRKDIR}/patch-nntp
post-install:
	${INSTALL_MAN} ${WRKSRC}/ChangeLog.nntp ${STAGEDIR}${DOCSDIR}
.else
PLIST_SUB+=	NNTP="@comment "
.endif

.if ${PORT_OPTIONS:MQUOTE_PATCH}
PATCHFILES+=	patch-${VVV_PATCH_VERSION}.vvv.initials.gz:vvv \
		patch-${VVV_PATCH_VERSION}.vvv.quote.gz:vvv
XML_NEEDED=	yes
.endif

.if ${PORT_OPTIONS:MIFDEF_PATCH}
post-patch::
	@${PATCH} ${PATCH_ARGS} -p1 < ${PATCHDIR}/extra-patch-ifdef
.endif

.if ${PORT_OPTIONS:MMBOX_HOOK_PATCH}
IGNORE=	the MBOX_HOOK_PATCH does not work at the moment
#PATCHFILES+=	p0-patch-${DW_MBOX_PATCH_VERSION}.dw.mbox-hook.1:dw
.endif

.if ${PORT_OPTIONS:MSIDEBAR_PATCH}
XML_NEEDED=	yes
.if ${PORT_OPTIONS:MNNTP}
post-patch::
	@${PATCH} ${PATCH_ARGS} -p1 < ${PATCHDIR}/extra-patch-sidebar-nntp
.else
post-patch::
	@${PATCH} ${PATCH_ARGS} -p1 < ${PATCHDIR}/extra-patch-sidebar
.endif
.endif

.if ${PORT_OPTIONS:MGREETING_PATCH}
post-patch::
	@${PATCH} ${PATCH_ARGS} -p1 < ${PATCHDIR}/extra-patch-greeting
.endif
.if ${PORT_OPTIONS:MTRASH_PATCH}
post-patch::
	@${PATCH} ${PATCH_ARGS} -p1 < ${PATCHDIR}/extra-patch-trash-purge
.endif

WRKSRC=		${WRKDIR}/${DISTNAME:S/i$//}

post-patch::
	@${REINPLACE_CMD} -e 's,/usr/bin/gpg,${LOCALBASE}/bin/gpg,g' \
		${WRKSRC}/contrib/gpg.rc
	@${REINPLACE_CMD} -e 's,pgp6,pgp,g' \
		${WRKSRC}/contrib/pgp6.rc
	@${REINPLACE_CMD} -E -e 's|@samplesdir@|${EXAMPLESDIR}|g' \
		${WRKSRC}/contrib/Makefile.am

pre-configure::
	@(cd ${WRKSRC}; ${SETENV} ${AUTOMAKE_ENV} ${ACLOCAL} -I m4)
.if defined(WITH_KRB5_SYS)
	@${ECHO_CMD} "#define HAVE_HEIMDAL" >> ${WRKSRC}/config.h.in
	@${REINPLACE_CMD} -e 's|<gssapi/gssapi\.h>|<gssapi.h>|' \
		${WRKSRC}/imap/auth_gss.c
.endif

.if ${PORT_OPTIONS:MCOMPRESSED_FOLDERS}
PLIST_SUB+=	COMPRESS=""
.else
PLIST_SUB+=	COMPRESS="@comment "
.endif

.if ${PORT_OPTIONS:MIMAP_HEADER_CACHE} || ${PORT_OPTIONS:MMAILDIR_HEADER_CACHE}
.if ${PORT_OPTIONS:MTOKYOCABINET}
CONFIGURE_ARGS+=	--enable-hcache --without-gdbm --without-bdb --with-tokyocabinet
LIB_DEPENDS+=		libtokyocabinet.so:${PORTSDIR}/databases/tokyocabinet
.else
USE_BDB=		42+
CONFIGURE_ARGS+=	--enable-hcache --without-gdbm --with-bdb
CONFIGURE_SED=	-e 's/BDB_VERSIONS="/&${BDB_LIB_NAME} db${BDB_VER} /'
pre-configure::
	@${REINPLACE_CMD} -E ${CONFIGURE_SED} ${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}.ac
.endif
.else
CONFIGURE_ARGS+=	--disable-hcache
.endif

.if ${PORT_OPTIONS:MMAILDIR_HEADER_CACHE}
CONFIGURE_ARGS+=	--without-qdbm
.endif

.if defined (XML_NEEDED) && ${PORT_OPTIONS:MXML}
XML_USED=	yes
.endif
.if ${PORT_OPTIONS:MHTML}
XML_USED=	yes
.endif

.if ${PORT_OPTIONS:MMAILBOX_MANPAGES}
PLIST_SUB+=	MBOXMAN=""
.else
PLIST_SUB+=	MBOXMAN="@comment "
.endif

.if ${PORT_OPTIONS:MHTML}
PLIST_SUB+=	HTML=""
.else
PLIST_SUB+=	HTML="@comment "
.endif
.if ${PORT_OPTIONS:MDOCS} || ${XML_USED} == yes
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
.endif

.if ${XML_USED} == yes
BUILD_DEPENDS+=	xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl \
		lynx:${PORTSDIR}/www/lynx
.endif

.if ${PORT_OPTIONS:MSLANG}
PKGMESSAGE=	${FILESDIR}/pkg-message.slang
.endif

.include <bsd.port.mk>
