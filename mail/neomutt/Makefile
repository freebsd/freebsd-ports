# $FreeBSD$

PORTNAME=	neomutt
PORTVERSION=	20170907
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	mail

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Bringing together all the Mutt Code

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:misc/mime-support \
		urlview:textproc/urlview

USES=		autoreconf iconv:translit localbase shebangfix ssl

USE_GITHUB=	yes

GNU_CONFIGURE=	yes

OPTIONS_SUB=	yes
SHEBANG_FILES=	contrib/smime_keys

OPTIONS_DEFINE=	NLS DOCS SASL IDN FLOCK GPGME NOTMUCH
OPTIONS_DEFAULT=SASL TOKYOCABINET NOTMUCH GPGME LMDB NCURSES
OPTIONS_MULTI=	HCACHE
OPTIONS_MULTI_HCACHE=	BDB GDBM KYOTOCABINET LMDB QDBM TOKYOCABINET
OPTIONS_SINGLE=	SCREEN
OPTIONS_SINGLE_SCREEN=	NCURSES SLANG

FLOCK_DESC=	Use flock() to lock files
GPGME_DESC=	Use gpgme to handle pgp
NOTMUCH_DESC=	Use notmuch for tagging and searching
HCACHE_DESC=	Header-cache backend
KYOTOCABINET_DESC=	Kyoto Cabinet support
LMDB_DESC=		Lightning Memory-Mapped Database support
QDBM_DESC=		Quick DataBase Manager support
TOKYOCABINET_DESC=	Tokyo Cabinet support
SCREEN_DESC=	Screen options

CONFIGURE_ARGS=	--disable-dependency-tracking \
		--with-docdir="${DOCSDIR}" \
		--with-ssl="${OPENSSLBASE}" \
		--disable-fcntl \
		--enable-locales-fix \
		${ICONV_CONFIGURE_ARGS}

# Header cache
BDB_CONFIGURE_WITH=		bdb
BDB_USES=			bdb
GDBM_CONFIGURE_WITH=		gdbm
GDBM_LIB_DEPENDS=		libgdbm.so:databases/gdbm
KYOTOCABINET_CONFIGURE_WITH=	kyotocabinet
KYOTOCABINET_LIB_DEPENDS=	libkyotocabinet.so:databases/kyotocabinet
LMDB_CONFIGURE_WITH=		lmdb
LMDB_LIB_DEPENDS=		liblmdb.so:databases/lmdb
QDBM_CONFIGURE_WITH=		qdbm
QDBM_LIB_DEPENDS=		libqdbm.so:databases/qdbm
TOKYOCABINET_CONFIGURE_WITH=	tokyocabinet
TOKYOCABINET_LIB_DEPENDS=	libtokyocabinet.so:databases/tokyocabinet

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext
NLS_USES_OFF=		gettext-runtime:build gettext-tools:build

IDN_LIB_DEPENDS=	libidn.so:dns/libidn
IDN_CONFIGURE_WITH=	idn

FLOCK_CONFIGURE_ENABLE=	flock

SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_CONFIGURE_ON=	--with-sasl

GPGME_LIB_DEPENDS=	libgpgme.so:security/gpgme \
			libassuan.so:security/libassuan \
			libgpg-error.so:security/libgpg-error
GPGME_CONFIGURE_ENABLE=	gpgme

NOTMUCH_LIB_DEPENDS=	libnotmuch.so:mail/notmuch
NOTMUCH_CONFIGURE_ENABLE=	notmuch

SLANG_CONFIGURE_ON=	--with-slang=${LOCALBASE}
SLANG_LIB_DEPENDS=	libslang.so:devel/libslang2
SLANG_VARS=	PKGMESSAGE=${FILESDIR}/pkg-message.slang

NCURSES_USES=	ncurses

DOCS_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
			${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
			lynx:www/lynx

post-patch:
	@${REINPLACE_CMD} '/LIBS=$$/d' ${WRKSRC}/configure.ac

post-install:
	${RM} ${STAGEDIR}${PREFIX}/etc/mime*

.include <bsd.port.mk>
