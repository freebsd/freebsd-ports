PORTNAME=	neomutt
PORTVERSION=	20250905
CATEGORIES=	mail

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Bringing together all the Mutt Code
WWW=		https://neomutt.org

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${LOCALBASE}/etc/mime.types:misc/mime-support \
		urlview:textproc/urlview
LIB_DEPENDS=	libpcre2-8.so:devel/pcre2

USES=		cpe iconv:translit localbase ncurses perl5 pkgconfig python:env shebangfix ssl

USE_GITHUB=	yes
USE_PERL5=	build
MAKE_JOBS_UNSAFE=	yes

HAS_CONFIGURE=	yes

OPTIONS_SUB=	yes
SHEBANG_FILES=	contrib/smime_keys \
		contrib/oauth2/mutt_oauth2.py \
		data/account-command/macos-keychain/keychain.py

OPTIONS_DEFINE=	NLS DOCS SASL IDN FLOCK GPGME NOTMUCH
OPTIONS_DEFAULT=SASL TOKYOCABINET NOTMUCH GPGME LMDB GSSAPI_BASE
OPTIONS_MULTI=	HCACHE
OPTIONS_MULTI_HCACHE=	BDB GDBM KYOTOCABINET LMDB QDBM TOKYOCABINET
OPTIONS_SINGLE=	GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_NONE GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT

FLOCK_DESC=	Use flock() to lock files
GPGME_DESC=	Use gpgme to handle pgp
NOTMUCH_DESC=	Use notmuch for tagging and searching
HCACHE_DESC=	Header-cache backend
KYOTOCABINET_DESC=	Kyoto Cabinet support
LMDB_DESC=		Lightning Memory-Mapped Database support
QDBM_DESC=		Quick DataBase Manager support
TOKYOCABINET_DESC=	Tokyo Cabinet support

CONFIGURE_ARGS=	--with-ssl="${OPENSSLBASE}" \
		--locales-fix \
		--fmemopen \
		--pcre2 \
		--disable-idn \
		--prefix=${PREFIX} \
		${ICONV_CONFIGURE_ARGS}
CONFIGURE_ENV=	CC_FOR_BUILD="${CC}"

# Header cache
BDB_CONFIGURE_ON=		--bdb
BDB_USES=			bdb
GDBM_CONFIGURE_ON=		--gdbm
GDBM_LIB_DEPENDS=		libgdbm.so:databases/gdbm
KYOTOCABINET_CONFIGURE_ON=	--kyotocabinet
KYOTOCABINET_LIB_DEPENDS=	libkyotocabinet.so:databases/kyotocabinet
LMDB_CONFIGURE_ON=		--lmdb
LMDB_LIB_DEPENDS=		liblmdb.so:databases/lmdb
QDBM_CONFIGURE_ON=		--qdbm
QDBM_LIB_DEPENDS=		libqdbm.so:databases/qdbm
TOKYOCABINET_CONFIGURE_ON=	--tokyocabinet
TOKYOCABINET_LIB_DEPENDS=	libtokyocabinet.so:databases/tokyocabinet

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

IDN_LIB_DEPENDS=	libidn2.so:dns/libidn2
IDN_CONFIGURE_OFF=	--disable-idn2

FLOCK_CONFIGURE_ON=	--with-lock=flock

SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASL_CONFIGURE_ON=	--sasl

GPGME_LIB_DEPENDS=	libgpgme.so:security/gpgme \
			libgpg-error.so:security/libgpg-error
GPGME_CONFIGURE_ENABLE=	gpgme

NOTMUCH_LIB_DEPENDS=	libnotmuch.so:mail/notmuch
NOTMUCH_CONFIGURE_ENABLE=	notmuch

# GSSAPI
GSSAPI_BASE_USES=		gssapi
GSSAPI_BASE_CONFIGURE_ON=	--gss
GSSAPI_HEIMDAL_USES=		gssapi:heimdal
GSSAPI_HEIMDAL_CONFIGURE_ON=	--with-gss=${LOCALBASE}
GSSAPI_MIT_USES=		gssapi:mit
GSSAPI_MIT_CONFIGURE_ON=	--with-gss=${LOCALBASE}
GSSAPI_NONE_CONFIGURE_ON=	--disable-gss

DOCS_CONFIGURE_OFF=	--disable-doc
DOCS_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
			${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
			lynx:www/lynx

post-install:
	${RM} ${STAGEDIR}${PREFIX}/etc/mime*
	${MV} ${STAGEDIR}${PREFIX}/etc/neomuttrc ${STAGEDIR}${PREFIX}/etc/neomuttrc.dist
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/neomutt \
		${STAGEDIR}${PREFIX}/libexec/neomutt/pgpewrap

.include <bsd.port.mk>
