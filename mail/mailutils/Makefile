# Created by: Attila Nagy <bra@fsn.hu>
# $FreeBSD$

PORTNAME=	mailutils
PORTVERSION=	3.1.1
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	GNU

MAINTAINER=	zeus@gnu.org.ua
COMMENT=	Utilities and daemons for processing e-mail

LICENSE=	GPLv3+

LIB_DEPENDS=	libltdl.so:devel/libltdl

USES=		gmake iconv libtool makeinfo readline tar:xz
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

INFO=		${PORTNAME}

OPTIONS_DEFINE=		GNUTLS GSSAPI GUILE MH NNTP NLS PAM PYTHON
OPTIONS_DEFAULT=	BDB GNUTLS PAM
OPTIONS_MULTI=		DB
OPTIONS_MULTI_DB=	BDB GDBM KYOTOCABINET LDAP MYSQL PGSQL TOKYOCABINET
OPTIONS_SUB=		yes

BDB_DESC=		Berkeley DB v4.8 support (last working one)
DB_DESC=		Database configuration
KYOTOCABINET_DESC=	Kyoto Cabinet database support
MH_DESC=		MH (Message Handling) system support
TOKYOCABINET_DESC=	Tokyo Cabinet database support

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_WITH=	gnutls

GSSAPI_RUN_DEPENDS=	cyrus-sasl-gssapi>0:security/cyrus-sasl2-gssapi
GSSAPI_CONFIGURE_WITH=	gssapi

GUILE_LIB_DEPENDS=	libguile.so:lang/guile
GUILE_CONFIGURE_WITH=	guile
GUILE_BROKEN=		does not build: ERROR: invalid arglist syntax: (hash paren_open SCM mbox paren_close)

MH_CONFIGURE_ENABLE=	mh

NNTP_CONFIGURE_ENABLE=	nntp

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

PAM_CONFIGURE_ENABLE=	pam

PYTHON_BUILD_DEPENDS=	python-config:lang/python
PYTHON_USES=		python
PYTHON_CONFIGURE_ENABLE=python

BDB_USES=		bdb:48
BDB_CONFIGURE_WITH=	berkeley-db
BDB_CPPFLAGS=		-I${BDB_INCLUDE_DIR}
BDB_LDFLAGS=		-L${BDB_LIB_DIR}
INVALID_BDB_VER=	5+

GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
GDBM_CONFIGURE_WITH=	gdbm

KYOTOCABINET_LIB_DEPENDS=	libkyotocabinet.so:databases/kyotocabinet
KYOTOCABINET_CONFIGURE_WITH=	kyotocabinet

LDAP_USE=		OPENLDAP=yes
LDAP_CONFIGURE_WITH=	ldap

MYSQL_USES=		mysql
MYSQL_CONFIGURE_WITH=	mysql

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_WITH=	postgres

TOKYOCABINET_LIB_DEPENDS=	libtokyocabinet.so:databases/tokyocabinet
TOKYOCABINET_CONFIGURE_WITH=	tokyocabinet

post-patch:
	@${REINPLACE_CMD} -e '/need_charset_alias=/s|true|false|' \
		${WRKSRC}/lib/gnu/Makefile.in
	@${REINPLACE_CMD} -e '/chown/,+1s|ch|#&|' \
		${WRKSRC}/dotlock/Makefile.in \
		${WRKSRC}/maidag/Makefile.in

.include <bsd.port.mk>
