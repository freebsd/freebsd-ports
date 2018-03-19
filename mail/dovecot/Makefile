# Created by: Nagy, Attila <bra@fsn.hu>
# $FreeBSD$

######################################################################
# Anytime PORTVERSION changes please bump PORTREVISION of            #
# mail/dovecot-pigeonhole. See ports/146029 for an explanation.      #
#                                                                    #
# Please be careful when updating this port as changes to this port  #
# can break mail/dovecot-pigeonhole. In order to ensure the least    #
# amount of breakage possible please consult the maintainer of that  #
# port before updating this one.                                     #
######################################################################

PORTNAME=	dovecot
PORTVERSION=	2.2.35
CATEGORIES=	mail ipv6
MASTER_SITES=	https://www.dovecot.org/releases/2.2/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Secure, fast and powerful IMAP and POP3 server

LICENSE=	LGPL21 MIT
LICENSE_COMB=	dual
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LGPL
LICENSE_FILE_MIT=	${WRKSRC}/COPYING.MIT

USES=		cpe iconv libtool ssl
USE_RC_SUBR=	dovecot

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var \
		--with-statedir=/var/db/dovecot \
		--without-shadow \
		--with-ssl=openssl \
		--with-docs

USE_LDCONFIG=	${PREFIX}/lib/dovecot
INSTALL_TARGET=	install-strip

USERS=		dovecot dovenull
GROUPS=		${USERS}

OPTIONS_DEFINE=	LIBWRAP LZ4 VPOPMAIL DOCS EXAMPLES
OPTIONS_DEFAULT=GSSAPI_NONE LIBWRAP
OPTIONS_SUB=	yes

OPTIONS_GROUP=		DB FTS
OPTIONS_GROUP_DB=	CDB LDAP MYSQL PGSQL SQLITE
OPTIONS_GROUP_FTS=	ICU LUCENE SOLR TEXTCAT

OPTIONS_SINGLE=		GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_NONE GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT

LZ4_DESC=	LZ4 compression support
VPOPMAIL_DESC=	vpopmail support

DB_DESC=	Database support
CDB_DESC=	CDB database support

FTS_DESC=	Full text search plugins
ICU_DESC=	Use libicu for FTS unicode normalization
LUCENE_DESC=	CLucene FTS support
SOLR_DESC=	Solr FTS support
TEXTCAT_DESC=	Libtextcat FTS support

GSSAPI_NONE_DESC=	Build without GSSAPI support
GSSAPI_BASE_DESC=	Use GSSAPI from base
GSSAPI_HEIMDAL_DESC=	Use Heimdal GSSAPI from security/heimdal
GSSAPI_MIT_DESC=	Use MIT GSSAPI from security/krb5

# General options
LIBWRAP_CONFIGURE_WITH=	libwrap

LZ4_CONFIGURE_WITH=	lz4
LZ4_LIB_DEPENDS=	liblz4.so:archivers/liblz4

VPOPMAIL_BUILD_DEPENDS=	vpopmail>=0:mail/vpopmail
VPOPMAIL_CONFIGURE_WITH=vpopmail

# Databases
CDB_CONFIGURE_WITH=	cdb
CDB_LIB_DEPENDS=	libcdb.so:databases/tinycdb

LDAP_USE=		OPENLDAP=yes
LDAP_CONFIGURE_WITH=	ldap

MYSQL_USES=		mysql
MYSQL_CONFIGURE_WITH=	mysql

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_WITH=	pgsql

SQLITE_USES=		sqlite
SQLITE_CONFIGURE_WITH=	sqlite

# FTS
ICU_CONFIGURE_WITH=	icu
ICU_LIB_DEPENDS=	libicui18n.so:devel/icu
ICU_USES=		pkgconfig

LUCENE_CONFIGURE_WITH=	lucene
LUCENE_LIB_DEPENDS=	libclucene-core.so:textproc/clucene

SOLR_CONFIGURE_WITH=	solr
SOLR_LIB_DEPENDS=	libcurl.so:ftp/curl \
			libexpat.so:textproc/expat2

TEXTCAT_CONFIGURE_WITH=	textcat
TEXTCAT_LIB_DEPENDS=	libtextcat.so:textproc/libtextcat

# GSSAPI
GSSAPI_NONE_CONFIGURE_ON=	--without-gssapi
GSSAPI_NONE_CONFIGURE_OFF=	--with-gssapi ${GSSAPI_CONFIGURE_ARGS}
GSSAPI_BASE_USES=		gssapi
GSSAPI_HEIMDAL_USES=		gssapi:heimdal
GSSAPI_MIT_USES=		gssapi:mit

DOCS=		AUTHORS COPYING INSTALL NEWS TODO README
PORTDOCS=	*
PORTEXAMPLES=	*

# Default requirement for dovecot rc script
_REQUIRE=	LOGIN

LDAP_VARS=	_REQUIRE+=slapd
MYSQL_VARS=	_REQUIRE+=mysql
PGSQL_VARS=	_REQUIRE+=postgresql

SUB_LIST+=	REQUIRE="${_REQUIRE}"
SUB_FILES+=	pkg-message

CPPFLAGS+=	-I${LOCALBASE}/include -I${OPENSSLINC}
LDFLAGS+=	-L${LOCALBASE}/lib -L${OPENSSLLIB}

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/dovecot,${PREFIX}/etc/dovecot,g; \
		s,sysconfdir=/etc,sysconfdir=${PREFIX}/etc,g' \
		${WRKSRC}/doc/example-config/*.conf ${WRKSRC}/doc/example-config/conf.d/*
	@${REINPLACE_CMD} -e '/^LIBS =/s/$$/ @LTLIBICONV@/' \
		${WRKSRC}/src/lib-mail/Makefile.in
# Install the sample config files into ETCDIR/example-config/
	@${REINPLACE_CMD} -e '/^exampledir =/s|\$$(docdir)|${ETCDIR}|' \
		${WRKSRC}/doc/example-config/Makefile.in \
		${WRKSRC}/doc/example-config/conf.d/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/bin|${LOCALBASE}/bin|' \
		${WRKSRC}/src/plugins/fts/decode2text.sh

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${MV} ${STAGEDIR}${DOCSDIR}/dovecot-openssl.cnf ${STAGEDIR}${EXAMPLESDIR}
	${MV} ${STAGEDIR}${DOCSDIR}/mkcert.sh ${STAGEDIR}${EXAMPLESDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
