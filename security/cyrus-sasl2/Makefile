# New ports collection makefile for:	cyrus-sasl2
# Date created:				Nov 1 1999
# Whom:					hetzels@westbend.net
#
# $FreeBSD$
#

PORTNAME=	cyrus-sasl
PORTVERSION=	2.1.17
PORTREVISION=	1
CATEGORIES=	security ipv6
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/%SUBDIR%/ \
		ftp://ftp.westbend.net/pub/cyrus-mail/%SUBDIR%/ \
		ftp://ftp.hanse.de/sites/transit/mirror/ftp.andrew.cmu.edu/pub/cyrus-mail/%SUBDIR%/
MASTER_SITE_SUBDIR=	. OLD-VERSIONS/sasl

MAINTAINER=	ume@FreeBSD.org
COMMENT=	RFC 2222 SASL (Simple Authentication and Security Layer)

LATEST_LINK=	${PORTNAME}2

INSTALLS_SHLIB=	yes

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}2

MAN3=		sasl.3 sasl_authorize_t.3 sasl_auxprop.3 \
		sasl_auxprop_getctx.3 sasl_auxprop_request.3 \
		sasl_callbacks.3 sasl_canon_user_t.3 \
		sasl_chalprompt_t.3 sasl_checkapop.3 sasl_checkpass.3 \
		sasl_client_init.3 sasl_client_new.3 sasl_client_start.3 \
		sasl_client_step.3 sasl_decode.3 sasl_dispose.3 sasl_done.3 \
		sasl_encode.3 sasl_encodev.3 sasl_errdetail.3 sasl_errors.3 \
		sasl_errstring.3 sasl_getopt_t.3 sasl_getpath_t.3 \
		sasl_getprop.3 sasl_getrealm_t.3 sasl_getsecret_t.3 \
		sasl_getsimple_t.3 sasl_global_listmech.3 \
		sasl_idle.3 sasl_listmech.3 sasl_log_t.3 \
		sasl_server_init.3 sasl_server_new.3 sasl_server_start.3 \
		sasl_server_step.3 sasl_server_userdb_checkpass_t.3 \
		sasl_server_userdb_setpass_t.3 sasl_setpass.3 sasl_setprop.3 \
		sasl_user_exists.3 sasl_verifyfile_t.3
MAN8=		sasldblistusers2.8 saslpasswd2.8

USE_OPENSSL=	yes
GNU_CONFIGURE=	YES

CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc \
		--with-plugindir=${PREFIX}/lib/sasl2 \
		--with-dbpath=${PREFIX}/etc/sasldb2 \
		--includedir=${PREFIX}/include \
		--mandir=${MANPREFIX}/man \
		--enable-static \
		--enable-auth-sasldb \
		--with-openssl=${OPENSSLBASE} \
		--with-rc4=openssl \
		--with-saslauthd

.if defined(WITH_BDB_VER)
.if ${WITH_BDB_VER} == 3
LIB_DEPENDS+=	db3.3:${PORTSDIR}/databases/db3
CONFIGURE_ARGS+=--with-bdb-incdir=${LOCALBASE}/include/db3 --with-bdb=db3
.elif ${WITH_BDB_VER} == 4
LIB_DEPENDS+=	db4.0:${PORTSDIR}/databases/db4
CONFIGURE_ARGS+=--with-bdb-incdir=${LOCALBASE}/include/db4 --with-bdb=db4
.elif ${WITH_BDB_VER} == 41
LIB_DEPENDS+=	db41.1:${PORTSDIR}/databases/db41
CONFIGURE_ARGS+=--with-bdb-incdir=${LOCALBASE}/include/db41 --with-bdb=db41
.elif ${WITH_BDB_VER} == 42
LIB_DEPENDS+=	db-4.2.2:${PORTSDIR}/databases/db42
CONFIGURE_ARGS+=--with-bdb-incdir=${LOCALBASE}/include/db42 --with-bdb=db-4.2
.else
BROKEN=		"WITH_BDB_VER must be 3, 4, 41 or 42"
.endif
CONFIGURE_ARGS+=--with-dblib=berkeley --with-bdb-libdir=${PREFIX}/lib
SASLDB_NAME=	sasldb2
.else
CONFIGURE_ARGS+=--with-dblib=ndbm
SASLDB_NAME=	sasldb2.db
.endif

.if defined(WITH_MYSQL_VER)
WITH_MYSQL=	YES
.if ${WITH_MYSQL_VER} == 3
WANT_MYSQL_VER=	323
.endif
.endif
.if defined(WITH_MYSQL)
USE_MYSQL=	YES
CONFIGURE_ARGS+=--with-mysql=${PREFIX}
.endif

.if defined(WITH_PGSQL)
POSTGRESQL_PORT?=	databases/postgresql-client
LIB_DEPENDS+=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
CONFIGURE_ARGS+=--with-pgsql=${PREFIX}
.endif

.if defined(WITH_MYSQL) || defined(WITH_PGSQL)
CONFIGURE_ARGS+=--enable-sql
.else
SQL=	"@comment "
.endif

.if defined(WITH_DEV_URANDOM)
CONFIGURE_ARGS+=--with-devrandom=/dev/urandom
.endif

.if defined(WITH_ALWAYSTRUE)
CONFIGURE_ARGS+=--enable-alwaystrue
.endif

.if defined(WITHOUT_LOGIN)
LOGIN=	"@comment "
.else
CONFIGURE_ARGS+=--enable-login
.endif

.if defined(WITHOUT_PLAIN)
CONFIGURE_ARGS+=--disable-plain
PLAIN= "@comment "
.endif

.if defined(WITHOUT_OTP)
CONFIGURE_ARGS+=--disable-otp
OTP=	"@comment "
.endif

.if defined(WITHOUT_CRAM)
CONFIGURE_ARGS+=--disable-cram
CRAM=	"@comment "
.endif

.if defined(WITHOUT_DIGEST)
CONFIGURE_ARGS+=--disable-digest
DIGEST=	"@comment "
.endif

.if defined(WITHOUT_NTLM)
CONFIGURE_ARGS+=--disable-ntlm
NTLM=	"@comment "
.else
CONFIGURE_ARGS+=--enable-ntlm
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GSSAPI) && defined(KRB5_HOME) && exists(${KRB5_HOME}/lib/libgssapi_krb5.a)
CONFIGURE_ARGS+=--enable-gssapi=${KRB5_HOME}
.elif !defined(WITHOUT_GSSAPI) && defined(HEIMDAL_HOME) && exists(${HEIMDAL_HOME}/lib/libgssapi.a)
CONFIGURE_ARGS+=--enable-gssapi=${HEIMDAL_HOME} --with-gss_impl=heimdal
.elif !defined(WITHOUT_GSSAPI) && ( defined(MAKE_KERBEROS5) || ${OSVERSION} > 500105 ) && exists(/usr/lib/libkrb5.a)
CONFIGURE_ARGS+=--enable-gssapi
.else
CONFIGURE_ARGS+=--disable-gssapi
GSSAPI=	"@comment "
.endif

# KERBEROS 4 was removed in FreeBSD 5.0-CURRENT
.if ${OSVERSION} > 500105
.if defined(WITH_KERBEROS4)
LIB_DEPENDS+=	krb.2:${PORTSDIR}/security/krb4
CONFIGURE_ARGS+=--enable-krb4=${LOCALBASE}/krb4
.else
CONFIGURE_ARGS+=--disable-krb4
EBONES=	"@comment "
.endif
.elif exists(/usr/lib/libkrb.a) && defined(MAKE_KERBEROS4) && !defined(WITHOUT_KERBEROS4)
CONFIGURE_ARGS+=--enable-krb4
.elif !exists(/usr/lib/libkrb.a) && defined(WITH_KERBEROS4)
LIB_DEPENDS+=	krb.2:${PORTSDIR}/security/krb4
CONFIGURE_ARGS+=--enable-krb4=${LOCALBASE}/krb4
.else
CONFIGURE_ARGS+=--disable-krb4
EBONES=	"@comment "
.endif

CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE} \
		OPENSSLINC=${OPENSSLINC} \
		OPENSSLLIB=${OPENSSLLIB} \
		LDFLAGS=${LDFLAGS}

CYRUS_USER?=	cyrus
CYRUS_GROUP?=	cyrus

DOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README

DOC2=	ONEWS TODO draft-burdis-cat-srp-sasl-08.txt \
	draft-ietf-cat-sasl-gssapi-05.txt draft-ietf-sasl-anon-02.txt \
	draft-ietf-sasl-crammd5-00.txt draft-ietf-sasl-plain-02.txt \
	draft-ietf-sasl-rfc2222bis-02.txt draft-ietf-sasl-rfc2831bis-02.txt \
	draft-ietf-sasl-saslprep-03.txt draft-murchison-sasl-login-00.txt \
	draft-newman-sasl-c-api-01.txt rfc1321.txt rfc1939.txt rfc2104.txt \
	rfc2195.txt rfc2222.txt rfc2243.txt rfc2245.txt rfc2289.txt \
	rfc2444.txt rfc2595.txt rfc2831.txt rfc2945.txt rfc3174.txt \
	server-plugin-flow.fig testing.txt

HTDOCS=	advanced appconvert gssapi index install macosx mechanisms \
	options plugprog programming readme sysadmin upgrading windows

PLIST_SUB=	PREFIX=${PREFIX} \
		LOGIN=${LOGIN} \
		PLAIN=${PLAIN} \
		OTP=${OTP} \
		CRAM=${CRAM} \
		DIGEST=${DIGEST} \
		NTLM=${NTLM} \
		GSSAPI=${GSSAPI} \
		EBONES=${EBONES} \
		SQL=${SQL} \
		DOCSDIR=${DOCSDIR:S/^${PREFIX}\///}

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGINSTALL=	${WRKDIR}/pkg-install
PKGMESSAGE=	${WRKDIR}/pkg-message

# Fix sasldb name in pkg-install/deinstall scripts
post-patch:
	@${SED} -e "s;%%SASLDB%%;${SASLDB_NAME};g" \
		-e "s;%%CYRUS_USER%%;${CYRUS_USER};g" \
		-e "s;%%CYRUS_GROUP%%;${CYRUS_GROUP};g" \
		${.CURDIR}/pkg-install > ${PKGINSTALL}
	@${SED} -e "s;%%SASLDB%%;${SASLDB_NAME};g" \
		-e "s;%%CYRUS_USER%%;${CYRUS_USER};g" \
		-e "s;%%CYRUS_GROUP%%;${CYRUS_GROUP};g" \
		${.CURDIR}/pkg-deinstall > ${PKGDEINSTALL}
	@${SED} -e "s;%%PREFIX%%;${PREFIX};g" \
		${.CURDIR}/pkg-message > ${PKGMESSAGE}

# Create Cyrus user and group
pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_MAN} ${WRKSRC}/utils/saslpasswd2.8 \
		${MAN8PREFIX}/man/man8/saslpasswd2.8
	${INSTALL_MAN} ${WRKSRC}/utils/sasldblistusers2.8 \
		${MAN8PREFIX}/man/man8/sasldblistusers2.8
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/html
.for file in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.for file in ${DOC2}
	@${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.for file in ${HTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${file}.html ${DOCSDIR}/html
.endfor
	@${INSTALL_DATA} ${FILESDIR}/Sendmail.README ${DOCSDIR}
.endif
	@PKG_PREFIX=${PREFIX} BATCH=${BATCH} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
