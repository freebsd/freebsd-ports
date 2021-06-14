# Created by: Udo Schweigert

PORTNAME=	mutt
DISTVERSION=	2.1.0
CATEGORIES+=	mail
MASTER_SITES=	ftp://ftp.mutt.org/pub/mutt/ \
		https://bitbucket.org/mutt/mutt/downloads/ \
		http://www.mutt.org.ua/download/mutt-${VVV_PATCH_VERSION}/:vvv \
		http://www2.mutt.org.ua/download/mutt-${VVV_PATCH_VERSION}/:vvv
DIST_SUBDIR=	mutt
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES+=		http://www.mutt.org.ua/download/mutt-${VVV_PATCH_VERSION}/:vvv \
			http://www2.mutt.org.ua/download/mutt-${VVV_PATCH_VERSION}/:vvv \
			http://vc.org.ua/mutt/:vc
PATCH_DIST_STRIP=	-p1

MAINTAINER=	dereks@lifeofadishwasher.com
COMMENT=	Small but powerful text based program for read/writing e-mail

LICENSE=	GPLv2+

RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:misc/mime-support

USES=		cpe perl5 shebangfix ssl
USE_PERL5=	build

SHEBANG_FILES=	contrib/smime_keys_test.pl doc/gen-map-doc smime_keys.pl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-fcntl \
		--enable-compressed \
		--enable-external-dotlock \
		--enable-imap \
		--enable-pop \
		--enable-sidebar \
		--sysconfdir=${PREFIX}/etc \
		--with-docdir=${DOCSDIR} \
		--with-ssl=${OPENSSLBASE}

.if defined(MUTT_CONFIGURE_ARGS)
CONFIGURE_ARGS+=	${MUTT_CONFIGURE_ARGS}
.endif

CONFLICTS=	ja-mutt-[0-9]* ja-mutt-devel-[0-9]* mutt-1.4* \
		mutt-devel-lite-[0-9]* mutt-lite-[0-9]* zh-mutt-devel-[0-9]*

INFO=		${PORTNAME}

OPTIONS_SUB=	yes

OPTIONS_DEFINE=	AUTOCRYPT DEBUG_LOGS DOCS EXAMPLES FLOCK GPGME GREETING_PATCH \
		HTML ICONV IDN IFDEF_PATCH LOCALES_FIX MAILBOX_MANPAGES \
		MAILDIR_MTIME_PATCH NLS QUOTE_PATCH REVERSE_REPLY_PATCH SASL \
		SMART_DATE SMIME SMTP URLVIEW

OPTIONS_SINGLE=		GSSAPI HCACHE SCREEN
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE
OPTIONS_SINGLE_HCACHE=	HCACHE_BDB HCACHE_KYOTOCABINET HCACHE_NONE \
			HCACHE_TOKYOCABINET
OPTIONS_SINGLE_SCREEN=	NCURSES SLANG

AUTOCRYPT_DESC=			Convenient End-to-End Encryption
DEBUG_LOGS_DESC=		Debugging capabilities
FLOCK_DESC=			flock() usage
GPGME_DESC=			Gpgme interface
GREETING_PATCH_DESC=		Greeting support
HCACHE_BDB_DESC=		Use Berkeley DB (BDB)
HCACHE_DESC=			Header Cache support
HCACHE_KYOTOCABINET_DESC=	Use Kyoto Cabinet
HCACHE_NONE_DESC=		Disable Header Cache
HCACHE_TOKYOCABINET_DESC=	Use Tokyo Cabinet
HTML_DESC=			HTML documentation
IDN_DESC=			International Domain Names (implies ICONV)
IFDEF_PATCH_DESC=		ifdef feature
LOCALES_FIX_DESC=		Locales fix
MAILBOX_MANPAGES_DESC=		Install mbox.5/mmdf.5 manpages
MAILDIR_MTIME_PATCH_DESC=	Maildir mtime patch
NCURSES_DESC=			Ncurses support
NLS_DESC=			Native language support (implies ICONV)
QUOTE_PATCH_DESC=		Extended quoting
REVERSE_REPLY_PATCH_DESC=	Reverse_reply
SASL_DESC=			SASL authentication
SMIME_DESC=			SMIME email check option patch
SLANG_DESC=			SLANG support
SMART_DATE_DESC=		Dynamic date formatting with "%@"
SMTP_DESC=			SMTP relay support
URLVIEW_DESC=			Use urlview for the URL selector menu

OPTIONS_DEFAULT=	AUTOCRYPT DEBUG_LOGS GPGME GSSAPI_NONE HCACHE_BDB HTML \
			ICONV IDN IFDEF_PATCH LOCALES_FIX MAILBOX_MANPAGES \
			MAILDIR_MTIME_PATCH NCURSES NLS QUOTE_PATCH \
			REVERSE_REPLY_PATCH SASL SMART_DATE SMIME SMTP URLVIEW

.ifmake makesum # for optional distfiles patchfiles
OPTIONS_OVERRIDE=	${OPTIONS_DEFAULT} ${OPTIONS_DEFINE}
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

URLVIEW_RUN_DEPENDS=	urlview:textproc/urlview

DEBUG_LOGS_CONFIGURE_ON=	--enable-debug

DOCS_CONFIGURE_OFF=	--disable-doc
DOCS_BUILD_DEPENDS=	lynx:www/lynx

# Handle ncurses/ncurses-port/slang
SLANG_CONFIGURE_ON=	--with-slang=${LOCALBASE}
SLANG_LIB_DEPENDS=	libslang.so:devel/libslang2
SLANG_VARS=		PKGMESSAGE=${FILESDIR}/pkg-message.slang

NCURSES_USES=	ncurses

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_IMPLIES=		ICONV

# Handle GSSAPI from various places
GSSAPI_BASE_USES=		gssapi
GSSAPI_BASE_CONFIGURE_ON=	${GSSAPI_CONFIGURE_ARGS} \
				--with-gss=${GSSAPIBASEDIR}
GSSAPI_HEIMDAL_USES=		gssapi:heimdal
GSSAPI_HEIMDAL_CONFIGURE_ON=	${GSSAPI_CONFIGURE_ARGS} \
				--with-gss=${GSSAPIBASEDIR}
GSSAPI_MIT_USES=		gssapi:mit
GSSAPI_MIT_CONFIGURE_ON=	${GSSAPI_CONFIGURE_ARGS} \
				--with-gss=${GSSAPIBASEDIR}
GSSAPI_NONE_CONFIGURE_ON=	--without-gss

HCACHE_NONE_CONFIGURE_ON=	--disable-hcache
HCACHE_NONE_CONFIGURE_OFF=	--enable-hcache

HCACHE_BDB_CONFIGURE_WITH=	bdb=${LOCALBASE}
HCACHE_BDB_USES=		bdb:42+
HCACHE_BDB_VARS=		CFLAGS+=-I${BDB_INCLUDE_DIR} \
				LDFLAGS+=-L${BDB_LIB_DIR}

HCACHE_TOKYOCABINET_CONFIGURE_WITH=	tokyocabinet=${LOCALBASE}
HCACHE_TOKYOCABINET_LIB_DEPENDS=	libtokyocabinet.so:databases/tokyocabinet

HCACHE_KYOTOCABINET_CONFIGURE_WITH=	kyotocabinet=${LOCALBASE}
HCACHE_KYOTOCABINET_LIB_DEPENDS=	libkyotocabinet.so:databases/kyotocabinet

ICONV_USES=		iconv:translit
ICONV_CONFIGURE_ON=	${ICONV_CONFIGURE_ARG}
ICONV_CONFIGURE_OFF=	--disable-iconv

REVERSE_REPLY_PATCH_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-reverse_reply

SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_CONFIGURE_ON=	--with-sasl=${LOCALBASE}

SMIME_EXTRA_PATCHES=	${PATCHDIR}/extra-smime-sender

SMART_DATE_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-smartdate

FLOCK_CONFIGURE_ENABLE=	flock

LOCALES_FIX_CONFIGURE_ON=	--enable-locales-fix

IDN_LIB_DEPENDS=	libidn2.so:dns/libidn2 \
			libunistring.so:devel/libunistring
IDN_CONFIGURE_WITH=	idn2=${LOCALBASE}
IDN_IMPLIES=		ICONV

IFDEF_PATCH_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-ifdef

GPGME_LIB_DEPENDS+=	libassuan.so:security/libassuan \
			libgpg-error.so:security/libgpg-error \
			libgpgme.so:security/gpgme
GPGME_CONFIGURE_ENABLE=	gpgme

SMTP_CONFIGURE_ENABLE=	smtp

MAILDIR_MTIME_PATCH_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-maildir-mtime

GREETING_PATCH_PATCHFILES=	mutt-${GREETING_PATCH_VERSION}.vc.greeting:vc

QUOTE_PATCH_PATCHFILES=	patch-${VVV_PATCH_VERSION}.vvv.initials.xz:vvv \
			mutt-${GREETING_PATCH_VERSION}.vvv.quote:vc

.include <bsd.port.options.mk>

VVV_PATCH_VERSION=	1.13.0
GREETING_PATCH_VERSION=	2.0.6

post-install:
	${INSTALL_MAN} ${FILESDIR}/mailcap.5 ${STAGEDIR}${MANPREFIX}/man/man5

pre-configure::
# Stop make from setgid mutt_dotlock
	@${REINPLACE_CMD} \
		-e '/if test.*mutt_dotlock.*DOTLOCK_GROUP/s/if/if ${FALSE} \&\&/' \
		${WRKSRC}/Makefile.in
# Base FreeBSD krb5-config --version returns "FreeBSD heimdal"
	@${REINPLACE_CMD} -e 's,?eimdal\*),?eimdal*|\"FreeBSD heimdal\"*),' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
# Install contrib samples to ${EXAMPLESDIR}
	@${REINPLACE_CMD} -e 's#$$(docdir)/samples#${EXAMPLESDIR}#g' \
		${WRKSRC}/contrib/Makefile.in

# Undo some dist. installed files
post-stage::
	@${MV} ${STAGEDIR}/${LOCALBASE}/etc/Muttrc.dist \
	    	${STAGEDIR}/${LOCALBASE}/etc/Muttrc.sample
	@${RM} ${STAGEDIR}/${LOCALBASE}/etc/mime.types*

.include <bsd.port.mk>
