# $FreeBSD$

PORTNAME=	neomutt
PORTVERSION=	20161028
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	mail

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Bringing together all the Mutt Code

LICENSE=	GPLv1
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USE_GITHUB=	yes

USES=		autoreconf localbase ncurses shebangfix ssl
GNU_CONFIGURE=	yes

BUILD_DEPENDS=	gdate:sysutils/coreutils
RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:misc/mime-support \
		urlview:textproc/urlview

OPTIONS_SUB=	yes
SHEBANG_FILES=	smime_keys.pl

OPTIONS_DEFINE=	NLS DOCS SASL ICONV IDN FLOCK GPGME NOTMUCH
OPTIONS_DEFAULT=SASL TOKYOCABINET NOTMUCH
OPTIONS_RADIO=	HCACHE
OPTIONS_RADIO_HCACHE=	TOKYOCABINET LMDB

FLOCK_DESC=	Use flock() to lock files
GPGME_DESC=	Use gpgme to handle pgp
NOTMUCH_DESC=	Use notmuch for tagging and searching
TOKYOCABINET_DESC=	Use TokyoCabinet as header-cache backend
LMDB_DESC=		Use LMDB as header-cache backend

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
		--without-qdbm \
		--disable-fcntl \
		--enable-external-dotlock

TOKYOCABINET_CONFIGURE_WITH=	tokyocabinet
TOKYOCABINET_LIB_DEPENDS=	libtokyocabinet.so:databases/tokyocabinet

LMDB_CONFIGURE_WITH=	lmdb
LMDB_LIB_DEPENDS=	liblmdb.so:databases/lmdb

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
	@${REINPLACE_CMD} -e "s/\`date/\`gdate/" ${WRKSRC}/Makefile.am ${WRKSRC}/doc/Makefile.am
	@${REINPLACE_CMD} '/LIBS=$$/d' ${WRKSRC}/configure.ac

post-install:
	${RM} ${STAGEDIR}${PREFIX}/etc/mime*

.include <bsd.port.mk>
