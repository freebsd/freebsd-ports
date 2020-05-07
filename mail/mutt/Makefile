# Created by: Udo Schweigert
# $FreeBSD$

PORTNAME=	mutt
DISTVERSION=	1.14.0
CATEGORIES+=	mail
MASTER_SITES=	ftp://ftp.mutt.org/pub/mutt/ \
		ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/ \
		https://bitbucket.org/mutt/mutt/downloads/ \
		ftp://ftp.demon.co.uk/pub/mirrors/mutt/ \
		http://www.mutt.org.ua/download/mutt-${VVV_PATCH_VERSION}/:vvv \
		http://www2.mutt.org.ua/download/mutt-${VVV_PATCH_VERSION}/:vvv
DIST_SUBDIR=	mutt
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES+=	http://www.mutt.org.ua/download/mutt-${VVV_PATCH_VERSION}/:vvv \
		http://www2.mutt.org.ua/download/mutt-${VVV_PATCH_VERSION}/:vvv \
		http://vc.org.ua/mutt/:vc
PATCH_DIST_STRIP=	-p1

MAINTAINER=	dereks@lifeofadishwasher.com
COMMENT=	Small but powerful text based program for read/writing e-mail

LICENSE=	GPLv2+

RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:misc/mime-support

USES=		cpe shebangfix ssl

CONFLICTS=	ja-mutt-[0-9]* ja-mutt-devel-[0-9]* mutt-1.4* mutt-devel-lite-[0-9]* mutt-lite-[0-9]* zh-mutt-devel-[0-9]*

CONFIGURE_ARGS=	--disable-fcntl --with-ssl=${OPENSSLBASE} \
		--with-docdir=${DOCSDIR} --sysconfdir=${PREFIX}/etc \
		--enable-external-dotlock --enable-pop --enable-imap \
		--enable-compressed --enable-sidebar

INFO=	${PORTNAME}

SHEBANG_FILES=	doc/gen-map-doc smime_keys.pl contrib/smime_keys_test.pl

.if defined(MUTT_CONFIGURE_ARGS)
CONFIGURE_ARGS+=	${MUTT_CONFIGURE_ARGS}
.endif

GNU_CONFIGURE=	yes

OPTIONS_SUB=	yes

OPTIONS_DEFINE=	AUTOCRYPT DEBUG DOCS EXAMPLES FLOCK FORCEBASE64 GPGME \
		GREETING_PATCH HTML ICONV IDN IFDEF_PATCH LOCALES_FIX \
		MAILBOX_MANPAGES MAILDIR_MTIME_PATCH NLS QUOTE_PATCH \
		REVERSE_REPLY_PATCH SASL SMART_DATE SMTP URLVIEW

OPTIONS_SINGLE=	GSSAPI HCACHE SCREEN
OPTIONS_RADIO=	SPELL
OPTIONS_RADIO_SPELL=	ASPELL ISPELL
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE
OPTIONS_SINGLE_HCACHE=	HCACHE_BDB HCACHE_TOKYOCABINET HCACHE_KYOTOCABINET HCACHE_NONE
OPTIONS_SINGLE_SCREEN=	NCURSES SLANG

AUTOCRYPT_DESC=	Convenient End-to-End Encryption
DEBUG_DESC=	Debugging capabilities
FLOCK_DESC=	flock() usage
FORCEBASE64_DESC=	Option to force base64 encoding for compose
GPGME_DESC=	Gpgme interface
GREETING_PATCH_DESC=	Greeting support
HCACHE_BDB_DESC=	Use Berkeley DB (BDB)
HCACHE_DESC=	Header Cache support
HCACHE_KYOTOCABINET_DESC=	Use Kyoto Cabinet
HCACHE_NONE_DESC=	Disable Header Cache
HCACHE_TOKYOCABINET_DESC=	Use Tokyo Cabinet
HTML_DESC=	HTML documentation
IDN_DESC=	International Domain Names (implies ICONV)
IFDEF_PATCH_DESC=	ifdef feature
LOCALES_FIX_DESC=	Locales fix
MAILBOX_MANPAGES_DESC=	Install mbox.5/mmdf.5 manpages
MAILDIR_MTIME_PATCH_DESC=	Maildir mtime patch
NCURSES_DESC=	Ncurses support
NLS_DESC=	Native language support (implies ICONV)
QUOTE_PATCH_DESC=	Extended quoting
REVERSE_REPLY_PATCH_DESC=	Reverse_reply
SASL_DESC=	SASL authentication
SLANG_DESC=	SLANG support
SMART_DATE_DESC=	Dynamic date formatting with "%@"
SMTP_DESC=	SMTP relay support
URLVIEW_DESC=	Use urlview for the URL selector menu

OPTIONS_DEFAULT=	AUTOCRYPT DEBUG GPGME GSSAPI_NONE HCACHE_BDB HTML ICONV IDN \
		IFDEF_PATCH LOCALES_FIX MAILBOX_MANPAGES MAILDIR_MTIME_PATCH NCURSES \
		NLS QUOTE_PATCH REVERSE_REPLY_PATCH SASL SMART_DATE SMTP URLVIEW

.ifmake makesum # for optional distfiles patchfiles
OPTIONS_OVERRIDE=	${OPTIONS_DEFINE} ${OPTIONS_DEFAULT}
.MAKEOVERRIDES+=	OPTIONS_OVERRIDE
.endif

AUTOCRYPT_CONFIGURE_ENABLE=	autocrypt
AUTOCRYPT_IMPLIES=		GPGME IDN
AUTOCRYPT_USES=			sqlite:3
AUTOCRYPT_CONFIGURE_WITH=	sqlite3=${LOCALBASE}
AUTOCRYPT_DEPENDS=		gnupg>=2.1:security/gnupg \
				gpgme>=1.8:security/gpgme
AUTOCRYPT_BUILD_DEPENDS=	${AUTOCRYPT_DEPENDS}
AUTOCRYPT_RUN_DEPENDS=		${AUTOCRYPT_DEPENDS}

ASPELL_BUILD_DEPENDS=	aspell:textproc/aspell
ASPELL_RUN_DEPENDS=	aspell:textproc/aspell
ISPELL_BUILD_DEPENDS=	ispell:textproc/aspell-ispell
ISPELL_RUN_DEPENDS=	ispell:textproc/aspell-ispell
URLVIEW_RUN_DEPENDS=	urlview:textproc/urlview

DEBUG_CONFIGURE_ON=	--enable-debug

# Handle ncurses/ncurses-port/slang
SLANG_CONFIGURE_ON=	--with-slang=${LOCALBASE}
SLANG_LIB_DEPENDS=	libslang.so:devel/libslang2
SLANG_VARS=	PKGMESSAGE=${FILESDIR}/pkg-message.slang

NCURSES_USES=	ncurses

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_IMPLIES=	ICONV

# Handle GSSAPI from various places
GSSAPI_BASE_USES=	gssapi
GSSAPI_BASE_CONFIGURE_ON=	--with-gss=${GSSAPIBASEDIR} ${GSSAPI_CONFIGURE_ARGS}
GSSAPI_HEIMDAL_USES=	gssapi:heimdal
GSSAPI_HEIMDAL_CONFIGURE_ON=	--with-gss=${GSSAPIBASEDIR} ${GSSAPI_CONFIGURE_ARGS}
GSSAPI_MIT_USES=	gssapi:mit
GSSAPI_MIT_CONFIGURE_ON=	--with-gss=${GSSAPIBASEDIR} ${GSSAPI_CONFIGURE_ARGS}
GSSAPI_NONE_CONFIGURE_ON=	--without-gss

HCACHE_NONE_CONFIGURE_ON=	--disable-hcache
HCACHE_NONE_CONFIGURE_OFF=	--enable-hcache --without-qdbm --without-gdbm
HCACHE_NONE_USES_OFF=		perl5
HCACHE_NONE_VARS_OFF=		USE_PERL5=build

HCACHE_BDB_CONFIGURE_WITH=	bdb=${LOCALBASE}
HCACHE_BDB_USES=	bdb:42+

HCACHE_TOKYOCABINET_CONFIGURE_WITH=	tokyocabinet=${LOCALBASE}
HCACHE_TOKYOCABINET_LIB_DEPENDS=	libtokyocabinet.so:databases/tokyocabinet

HCACHE_KYOTOCABINET_CONFIGURE_WITH=	kyotocabinet=${LOCALBASE}
HCACHE_KYOTOCABINET_LIB_DEPENDS=	libkyotocabinet.so:databases/kyotocabinet

ICONV_USES=	iconv:translit
ICONV_CONFIGURE_ON=	${ICONV_CONFIGURE_ARG}
ICONV_CONFIGURE_OFF=	--disable-iconv

REVERSE_REPLY_PATCH_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-reverse_reply

SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_CONFIGURE_ON=	--with-sasl=${LOCALBASE}

SMART_DATE_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-smartdate

FLOCK_CONFIGURE_ENABLE=	flock

LOCALES_FIX_CONFIGURE_ON=	--enable-locales-fix

IDN_LIB_DEPENDS=	libidn2.so:dns/libidn2 \
			libunistring.so:devel/libunistring
IDN_CONFIGURE_WITH=	idn2=${LOCALBASE}
IDN_IMPLIES=	ICONV

IFDEF_PATCH_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-ifdef

GPGME_LIB_DEPENDS+=	libgpgme.so:security/gpgme
GPGME_LIB_DEPENDS+=	libgpg-error.so:security/libgpg-error
GPGME_LIB_DEPENDS+=	libassuan.so:security/libassuan
GPGME_CONFIGURE_ENABLE=	gpgme

SMTP_CONFIGURE_ENABLE=	smtp

FORCEBASE64_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-forcebase64

MAILDIR_MTIME_PATCH_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-maildir-mtime

GREETING_PATCH_PATCHFILES=	mutt-${GREETING_PATCH_VERSION}.vc.greeting:vc

QUOTE_PATCH_PATCHFILES=	patch-${VVV_PATCH_VERSION}.vvv.initials.xz:vvv \
	patch-${VVV_PATCH_VERSION}.vvv.quote.xz:vvv

DOCS_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-doc-ref

.include <bsd.port.options.mk>

# un/comment as each VERSION is created for PORTVERSION
VVV_PATCH_VERSION=	1.13.0
GREETING_PATCH_VERSION=	1.14.0

post-install:
	${INSTALL_MAN} ${FILESDIR}/mailcap.5 ${STAGEDIR}${MANPREFIX}/man/man5

pre-configure::
	@${REINPLACE_CMD} -e 's,?eimdal\*),?eimdal*|\"FreeBSD heimdal\"*),' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's,pgp6,pgp,g' \
		${WRKSRC}/contrib/pgp6.rc
	@${REINPLACE_CMD} -E -e 's#(/samples|samples/)#share/examples/mutt#g' \
		${WRKSRC}/doc/reference.html \
		${WRKSRC}/doc/manual.html \
		${WRKSRC}/doc/manual.txt \
		${WRKSRC}/doc/Muttrc \
		${WRKSRC}/INSTALL \
		${WRKSRC}/init.h
	@${REINPLACE_CMD} -e 's#$$(docdir)/samples#${EXAMPLESDIR}#g' \
		${WRKSRC}/contrib/Makefile.in

pre-configure-ASPELL-on:
	@${REINPLACE_CMD} -e '/^# append-hook/p' \
		-e 's/^# append-hook.*$$/set ispell="aspell --mode=email check"/' \
	${WRKSRC}/doc/Muttrc.head

pre-configure-HCACHE_BDB-on:
	@${REINPLACE_CMD} -E -e 's/BDB_VERSIONS="/&${BDB_LIB_NAME} db${BDB_VER} /' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

pre-build::
	@${REINPLACE_CMD} -e '/^BUILD_DOC_TARGETS/s/=.*/=/' ${WRKSRC}/doc/Makefile

.include <bsd.port.mk>
