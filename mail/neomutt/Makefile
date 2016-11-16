# $FreeBSD$

PORTNAME=	neomutt
PORTVERSION=	20161104
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	2
CATEGORIES=	mail

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Bringing together all the Mutt Code

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:misc/mime-support \
		urlview:textproc/urlview

USE_GITHUB=	yes

USES=		autoreconf localbase ncurses shebangfix ssl
GNU_CONFIGURE=	yes

OPTIONS_SUB=	yes
SHEBANG_FILES=	smime_keys.pl

OPTIONS_DEFINE=	NLS DOCS SASL ICONV IDN FLOCK GPGME NOTMUCH
OPTIONS_DEFAULT=SASL TOKYOCABINET NOTMUCH GPGME
OPTIONS_RADIO=	HCACHE
OPTIONS_RADIO_HCACHE=	BDB GDBM KYOTOCABINET LMDB QDBM TOKYOCABINET

FLOCK_DESC=	Use flock() to lock files
GPGME_DESC=	Use gpgme to handle pgp
NOTMUCH_DESC=	Use notmuch for tagging and searching
HCACHE_DESC=	Header-cache backend
KYOTOCABINET_DESC=	Kyoto Cabinet support
LMDB_DESC=		Lightning Memory-Mapped Database support
QDBM_DESC=		Quick DataBase Manager support
TOKYOCABINET_DESC=	Tokyo Cabinet support

CONFIGURE_ARGS=	--disable-dependency-tracking \
		--with-docdir="${DOCSDIR}" \
		--with-ssl="${OPENSSLBASE}" \
		--enable-imap \
		--enable-smtp \
		--enable-pop \
		--enable-nntp \
		--enable-compressed \
		--enable-hcache \
		--enable-sidebar \
		--disable-fcntl \
		--enable-external-dotlock

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
NLS_USES=	gettext
NLS_IMPLIES=	ICONV

IDN_LIB_DEPENDS=	libidn.so:dns/libidn
IDN_IMPLIES=	ICONV
IDN_CONFIGURE_WITH=	idn

ICONV_USES=	iconv:translit
ICONV_CONFIGURE_ON=	${ICONV_CONFIGURE_ARGS}
ICONV_CONFIGURE_OFF=	--disable-iconv

FLOCK_CONFIGURE_ENABLE=	flock

SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_CONFIGURE_ON=	--with-sasl

GPGME_LIB_DEPENDS=	libgpgme.so:security/gpgme
GPGME_CONFIGURE_ENABLE=	gpgme

NOTMUCH_LIB_DEPENDS=	libnotmuch.so:mail/notmuch
NOTMUCH_CONFIGURE_ENABLE=	notmuch

DOCS_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
			${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
			lynx:www/lynx

post-patch:
	@${REINPLACE_CMD} '/LIBS=$$/d' ${WRKSRC}/configure.ac

post-install:
	${RM} ${STAGEDIR}${PREFIX}/etc/mime*

.include <bsd.port.mk>
