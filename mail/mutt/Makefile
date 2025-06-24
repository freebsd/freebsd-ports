PORTNAME=	mutt
DISTVERSION=	2.2.14
PORTREVISION=	1
CATEGORIES+=	mail
MASTER_SITES=	ftp://ftp.mutt.org/pub/mutt/ \
		https://bitbucket.org/mutt/mutt/downloads/
DIST_SUBDIR=	mutt
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	dereks@lifeofadishwasher.com
COMMENT=	Small but powerful text based program for read/writing e-mail
WWW=		http://www.mutt.org/

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

CONFLICTS=	ja-mutt ja-mutt-devel mutt-1.4* mutt-devel-lite mutt-lite \
		zh-mutt-devel

INFO=		${PORTNAME}

OPTIONS_DEFINE=		AUTOCRYPT DEBUG_LOGS DOCS EXAMPLES FLOCK GPGME HTML \
			ICONV IDN LOCALES_FIX MAILBOX_MANPAGES NLS SMTP URLVIEW
OPTIONS_DEFAULT=	AUTOCRYPT DEBUG_LOGS GPGME GSSAPI_NONE HCACHE_LMDB HTML \
			ICONV IDN LOCALES_FIX MAILBOX_MANPAGES NCURSES NLS \
			SASL_CYRUS SMTP URLVIEW

OPTIONS_SINGLE=		GSSAPI HCACHE SASL SCREEN
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE
OPTIONS_SINGLE_HCACHE=	HCACHE_BDB HCACHE_GDBM HCACHE_KYOTOCABINET HCACHE_LMDB \
			HCACHE_NONE HCACHE_QDBM HCACHE_TOKYOCABINET
OPTIONS_SINGLE_SASL=	SASL_CYRUS SASL_GSASL SASL_NONE
OPTIONS_SINGLE_SCREEN=	NCURSES SLANG
OPTIONS_SUB=		yes

AUTOCRYPT_DESC=			Convenient End-to-End Encryption
DEBUG_LOGS_DESC=		Debugging capabilities
FLOCK_DESC=			flock() usage
GPGME_DESC=			Gpgme interface
HCACHE_BDB_DESC=		Use Berkeley DB (BDB) (AGPLv3)
HCACHE_DESC=			Header Cache support
HCACHE_GDBM_DESC=		Use GDBM
HCACHE_KYOTOCABINET_DESC=	Use Kyoto Cabinet
HCACHE_LMDB_DESC=		Use LMDB
HCACHE_NONE_DESC=		Disable Header Cache
HCACHE_QDBM_DESC=		Use QDBM
HCACHE_TOKYOCABINET_DESC=	Use Tokyo Cabinet
HTML_DESC=			HTML documentation
IDN_DESC=			International Domain Names (implies ICONV)
LOCALES_FIX_DESC=		Locales fix
MAILBOX_MANPAGES_DESC=		Install mbox.5/mmdf.5 manpages
NCURSES_DESC=			Ncurses support
NLS_DESC=			Native language support (implies ICONV)
SASL_CYRUS_DESC=		Cyrus SASL Authentication
SASL_GSASL_DESC=		GNU SASL Authentication
SASL_NONE_DESC=			Disable SASL Authentication
SLANG_DESC=			SLANG support
SMTP_DESC=			SMTP relay support
URLVIEW_DESC=			Use urlview for the URL selector menu

AUTOCRYPT_IMPLIES=		GPGME IDN
AUTOCRYPT_BUILD_DEPENDS=	${AUTOCRYPT_DEPENDS}
AUTOCRYPT_RUN_DEPENDS=		${AUTOCRYPT_DEPENDS}
AUTOCRYPT_USES=			sqlite:3
AUTOCRYPT_CONFIGURE_ENABLE=	autocrypt
AUTOCRYPT_CONFIGURE_WITH=	sqlite3=${LOCALBASE}
AUTOCRYPT_DEPENDS=		gnupg>=2.1:security/gnupg \
				gpgme>=1.8:security/gpgme

DEBUG_LOGS_CONFIGURE_ON=	--enable-debug

DOCS_BUILD_DEPENDS=	lynx:www/lynx
DOCS_CONFIGURE_OFF=	--disable-doc

FLOCK_CONFIGURE_ENABLE=	flock

GPGME_LIB_DEPENDS+=	libassuan.so:security/libassuan \
			libgpg-error.so:security/libgpg-error \
			libgpgme.so:security/gpgme

GPGME_CONFIGURE_ENABLE=	gpgme

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

HCACHE_BDB_USES=			bdb:18
HCACHE_BDB_CONFIGURE_WITH=		bdb=${LOCALBASE}
HCACHE_BDB_VARS=			CFLAGS+=-I${BDB_INCLUDE_DIR} \
					LDFLAGS+=-L${BDB_LIB_DIR} \
					LICENSE=AGPLv3
HCACHE_GDBM_LIB_DEPENDS=		libgdbm.so:databases/gdbm
HCACHE_GDBM_CONFIGURE_WITH=		gdbm=${LOCALBASE}
HCACHE_KYOTOCABINET_LIB_DEPENDS=	libkyotocabinet.so:databases/kyotocabinet
HCACHE_KYOTOCABINET_CONFIGURE_WITH=	kyotocabinet=${LOCALBASE}
HCACHE_LMDB_LIB_DEPENDS=		liblmdb.so:databases/lmdb
HCACHE_LMDB_CONFIGURE_WITH=		lmdb=${LOCALBASE}
HCACHE_NONE_CONFIGURE_ON=		--disable-hcache
HCACHE_NONE_CONFIGURE_OFF=		--enable-hcache
HCACHE_QDBM_LIB_DEPENDS=		libqdbm.so:databases/qdbm
HCACHE_QDBM_CONFIGURE_WITH=		qdbm=${LOCALBASE}
HCACHE_TOKYOCABINET_LIB_DEPENDS=	libtokyocabinet.so:databases/tokyocabinet
HCACHE_TOKYOCABINET_CONFIGURE_WITH=	tokyocabinet=${LOCALBASE}

ICONV_USES=		iconv:translit
ICONV_CONFIGURE_ON=	${ICONV_CONFIGURE_ARG}
ICONV_CONFIGURE_OFF=	--disable-iconv

IDN_IMPLIES=		ICONV
IDN_LIB_DEPENDS=	libidn2.so:dns/libidn2 \
			libunistring.so:devel/libunistring
IDN_CONFIGURE_WITH=	idn2=${LOCALBASE}

LOCALES_FIX_CONFIGURE_ON=	--enable-locales-fix

NCURSES_USES=	ncurses

NLS_IMPLIES=		ICONV
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

SASL_CYRUS_LIB_DEPENDS=		libsasl2.so:security/cyrus-sasl2
SASL_CYRUS_CONFIGURE_WITH=	sasl=${LOCALBASE}
SASL_GSASL_LIB_DEPENDS=		libgsasl.so:security/libgsasl
SASL_GSASL_CONFIGURE_WITH=	gsasl=${LOCALBASE}
SASL_NONE_CONFIGURE_ON=		--with-sasl=no
SASL_NONE_CONFIGURE_OFF=

# Handle ncurses/ncurses-port/slang
SLANG_LIB_DEPENDS=	libslang.so:devel/libslang2
SLANG_CONFIGURE_ON=	--with-slang=${LOCALBASE}
SLANG_VARS=		PKGMESSAGE+=${FILESDIR}/pkg-message.slang

SMTP_CONFIGURE_ENABLE=	smtp

URLVIEW_RUN_DEPENDS=	urlview:textproc/urlview

pre-configure:
# Stop make from setgid mutt_dotlock
	@${REINPLACE_CMD} \
		-e '/if test.*mutt_dotlock.*DOTLOCK_GROUP/s/if/if ${FALSE} \&\&/' \
		${WRKSRC}/Makefile.in
# Base FreeBSD krb5-config --version returns "FreeBSD heimdal"
	@${REINPLACE_CMD} -e 's,?eimdal\*),?eimdal*|\"FreeBSD heimdal\"*),' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
# Install contrib samples to ${EXAMPLESDIR}
	@${REINPLACE_CMD} -e 's,$$(docdir)/samples,${EXAMPLESDIR},g' \
		${WRKSRC}/contrib/Makefile.in

post-install:
	${INSTALL_MAN} ${FILESDIR}/mailcap.5 ${STAGEDIR}${PREFIX}/share/man/man5

# Undo some dist. installed files
post-stage:
	@${MV} ${STAGEDIR}/${LOCALBASE}/etc/Muttrc.dist \
		${STAGEDIR}/${LOCALBASE}/etc/Muttrc.sample
	@${RM} ${STAGEDIR}/${LOCALBASE}/etc/mime.types*

.include <bsd.port.mk>
