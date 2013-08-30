# $FreeBSD$

PORTNAME=	cyrus-sasl
PORTVERSION=	2.1.26
PORTREVISION=	2
CATEGORIES=	security ipv6
MASTER_SITES=	ftp://ftp.cyrusimap.org/cyrus-sasl/ \
		http://cyrusimap.org/releases/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	RFC 2222 SASL (Simple Authentication and Security Layer)

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

LATEST_LINK=	${PORTNAME}2

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}2

MAN3=		sasl.3 sasl_authorize_t.3 sasl_auxprop.3 \
		sasl_auxprop_getctx.3 sasl_auxprop_request.3 \
		sasl_callbacks.3 sasl_canon_user_t.3 \
		sasl_chalprompt_t.3 sasl_checkapop.3 sasl_checkpass.3 \
		sasl_client_init.3 sasl_client_new.3 sasl_client_start.3 \
		sasl_client_step.3 sasl_decode.3 sasl_dispose.3 sasl_done.3 \
		sasl_encode.3 sasl_encodev.3 sasl_errdetail.3 sasl_errors.3 \
		sasl_errstring.3 sasl_getconfpath_t.3 sasl_getopt_t.3 \
		sasl_getpath_t.3 sasl_getprop.3 sasl_getrealm_t.3 \
		sasl_getsecret_t.3 sasl_getsimple_t.3 sasl_global_listmech.3 \
		sasl_idle.3 sasl_listmech.3 sasl_log_t.3 \
		sasl_server_init.3 sasl_server_new.3 sasl_server_start.3 \
		sasl_server_step.3 sasl_server_userdb_checkpass_t.3 \
		sasl_server_userdb_setpass_t.3 sasl_setpass.3 sasl_setprop.3 \
		sasl_user_exists.3 sasl_verifyfile_t.3
MAN8=		pluginviewer.8 sasldblistusers2.8 saslpasswd2.8

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc \
		--with-configdir=${PREFIX}/lib/sasl2:${PREFIX}/etc/sasl2 \
		--with-plugindir=${PREFIX}/lib/sasl2 \
		--with-dbpath=${PREFIX}/etc/sasldb2 \
		--with-lib-subdir=lib \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--includedir=${PREFIX}/include \
		--enable-static \
		--enable-auth-sasldb \
		--with-rc4=openssl \
		--with-saslauthd=${SASLAUTHD_RUNPATH} \
		--disable-krb4

MAKE_JOBS_UNSAFE=	yes

NO_OPTIONS_SORT=	yes
OPTIONS_DEFINE=		ALWAYSTRUE AUTHDAEMOND KEEP_DB_OPEN \
			OBSOLETE_CRAM_ATTR BDB MYSQL PGSQL
OPTIONS_RADIO=		SQLITE
OPTIONS_RADIO_SQLITE=	SQLITE2 SQLITE3
OPTIONS_GROUP=		MECH
OPTIONS_GROUP_MECH=	CRAM DIGEST LOGIN NTLM OTP PLAIN SCRAM
OPTIONS_DEFAULT=	AUTHDAEMOND OBSOLETE_CRAM_ATTR CRAM DIGEST LOGIN NTLM \
			OTP PLAIN SCRAM
ALWAYSTRUE_DESC=	the alwaystrue password verifier
AUTHDAEMOND_DESC=	use of authdaemon
KEEP_DB_OPEN_DESC=	Keep handle to Berkeley DB open
OBSOLETE_CRAM_ATTR_DESC=cmusaslsecretCRAM-MD5 property
SQLITE2_DESC=		SQLite 2 database
CRAM_DESC=		CRAM-MD5 authentication
DIGEST_DESC=		DIGEST-MD5 authentication
LOGIN_DESC=		LOGIN authentication
NTLM_DESC=		NTLM authentication
OTP_DESC=		OTP authentication
PLAIN_DESC=		PLAIN authentication
SCRAM_DESC=		SCRAM authentication

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MBDB}
USE_BDB=	yes
INVALID_BDB_VER=2
CONFIGURE_ARGS+=--with-dblib=berkeley \
		--with-bdb-libdir=${BDB_LIB_DIR} \
		--with-bdb-incdir=${BDB_INCLUDE_DIR} \
		--with-bdb=${BDB_LIB_NAME}
SASLDB_NAME=	sasldb2
.else
CONFIGURE_ARGS+=--with-dblib=ndbm
SASLDB_NAME=	sasldb2.db
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-mysql=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=--with-pgsql=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-pgsql
.endif

.if ${PORT_OPTIONS:MSQLITE2}
USE_SQLITE=	2
CONFIGURE_ARGS+=--with-sqlite=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-sqlite
.endif

.if ${PORT_OPTIONS:MSQLITE3}
USE_SQLITE=	3
CONFIGURE_ARGS+=--with-sqlite3=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-sqlite3
.endif

.if ${PORT_OPTIONS:MMYSQL} || ${PORT_OPTIONS:MPGSQL} || \
    ${PORT_OPTIONS:MSQLITE2} || ${PORT_OPTIONS:MSQLITE3}
CONFIGURE_ARGS+=--enable-sql
.else
SQL=	"@comment "
.endif

.if ${PORT_OPTIONS:MALWAYSTRUE}
CONFIGURE_ARGS+=--enable-alwaystrue
.endif

.if ${PORT_OPTIONS:MKEEP_DB_OPEN}
CONFIGURE_ARGS+=--enable-keep-db-open
.endif

.if !${PORT_OPTIONS:MOBSOLETE_CRAM_ATTR}
CONFIGURE_ARGS+=--enable-obsolete_cram_attr=no
.endif

.if ${PORT_OPTIONS:MAUTHDAEMOND}
CONFIGURE_ARGS+=--with-authdaemond=/var/run/authdaemond/socket
.else
CONFIGURE_ARGS+=--with-authdaemond=no
.endif

.if ${PORT_OPTIONS:MLOGIN}
CONFIGURE_ARGS+=--enable-login
.else
LOGIN=	"@comment "
.endif

.if !${PORT_OPTIONS:MPLAIN}
CONFIGURE_ARGS+=--disable-plain
PLAIN=	"@comment "
.endif

.if !${PORT_OPTIONS:MOTP}
CONFIGURE_ARGS+=--disable-otp
OTP=	"@comment "
.endif

.if !${PORT_OPTIONS:MCRAM}
CONFIGURE_ARGS+=--disable-cram
CRAM=	"@comment "
.endif

.if !${PORT_OPTIONS:MDIGEST}
CONFIGURE_ARGS+=--disable-digest
DIGEST=	"@comment "
.endif

.if ${PORT_OPTIONS:MNTLM}
CONFIGURE_ARGS+=--enable-ntlm
.else
CONFIGURE_ARGS+=--disable-ntlm
NTLM=	"@comment "
.endif

.if !${PORT_OPTIONS:MSCRAM}
CONFIGURE_ARGS+=--disable-scram
SCRAM=	"@comment "
.endif

.if ${ARCH} == "amd64"
CPPFLAGS+=	-fPIC
.endif
.if !defined(WITHOUT_GSSAPI) && defined(KRB5_HOME) && exists(${KRB5_HOME}/lib/libgssapi_krb5.so)
CONFIGURE_ARGS+=--enable-gssapi=${KRB5_HOME} --with-gss_impl=mit
LDFLAGS+=	"-R${KRB5_HOME}/lib"
.elif !defined(WITHOUT_GSSAPI) && defined(HEIMDAL_HOME) && exists(${HEIMDAL_HOME}/lib/libgssapi.a)
CONFIGURE_ARGS+=--enable-gssapi=${HEIMDAL_HOME} --with-gss_impl=heimdal
.elif !defined(WITHOUT_GSSAPI) && exists(/usr/lib/libkrb5.a)
CONFIGURE_ARGS+=--enable-gssapi
.else
CONFIGURE_ARGS+=--disable-gssapi
GSSAPI=	"@comment "
.endif

.if ${OPENSSLBASE} == /usr
CONFIGURE_ARGS+=--with-openssl=yes
.else
CONFIGURE_ARGS+=--with-openssl=${OPENSSLBASE}
.endif

SASLAUTHD_RUNPATH?=	/var/run/saslauthd

CYRUS_USER?=	cyrus
CYRUS_GROUP?=	cyrus

DOCS=	AUTHORS COPYING ChangeLog INSTALL INSTALL.TXT NEWS README

DOC2=	ONEWS TODO draft-burdis-cat-srp-sasl-xx.txt \
	draft-ietf-sasl-anon-xx.txt draft-ietf-sasl-crammd5-xx.txt \
	draft-ietf-sasl-gssapi-xx.txt draft-ietf-sasl-plain-xx.txt \
	draft-ietf-sasl-rfc2222bis-xx.txt draft-ietf-sasl-rfc2831bis-xx.txt \
	draft-ietf-sasl-saslprep-xx.txt draft-murchison-sasl-login-xx.txt \
	draft-newman-sasl-c-api-xx.txt rfc1321.txt rfc1939.txt rfc2104.txt \
	rfc2195.txt rfc2222.txt rfc2243.txt rfc2245.txt rfc2289.txt \
	rfc2444.txt rfc2595.txt rfc2831.txt rfc2945.txt rfc3174.txt \
	server-plugin-flow.fig testing.txt

HTDOCS=	advanced appconvert components gssapi index install macosx \
	mechanisms options plugprog programming readme sysadmin upgrading \
	windows

PLIST_SUB=	PREFIX=${PREFIX} \
		LOGIN=${LOGIN} \
		PLAIN=${PLAIN} \
		OTP=${OTP} \
		CRAM=${CRAM} \
		DIGEST=${DIGEST} \
		NTLM=${NTLM} \
		GSSAPI=${GSSAPI} \
		EBONES=${EBONES} \
		SCRAM=${SCRAM} \
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
pre-su-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/html
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.for f in ${DOC2}
	@${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.endfor
.for f in ${HTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${f}.html ${DOCSDIR}/html
.endfor
	@${INSTALL_DATA} ${FILESDIR}/Sendmail.README ${DOCSDIR}
.endif
	@PKG_PREFIX=${PREFIX} BATCH=${BATCH} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
