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

USES=		perl5
USE_PERL5=	patch
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
NO_STAGE=	yes

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

NO_OPTIONS_SORT=	yes
OPTIONS_DEFINE=		ALWAYSTRUE AUTHDAEMOND KEEP_DB_OPEN \
			OBSOLETE_CRAM_ATTR BDB MYSQL PGSQL
OPTIONS_RADIO=		SQLITE
OPTIONS_RADIO_SQLITE=	SQLITE2 SQLITE3
OPTIONS_GROUP=		MECH
OPTIONS_GROUP_MECH=	CRAM DIGEST LOGIN NTLM OTP PLAIN SCRAM
OPTIONS_DEFAULT=	AUTHDAEMOND OBSOLETE_CRAM_ATTR CRAM DIGEST \
			LOGIN NTLM OTP PLAIN SCRAM
OPTIONS_SUB=		yes
ALWAYSTRUE_DESC=	the alwaystrue password verifier
ALWAYSTRUE_CONFIGURE_ENABLE=alwaystrue
AUTHDAEMOND_DESC=	use of authdaemon
AUTHDAEMOND_CONFIGURE_ON=--with-authdaemond=/var/run/authdaemond/socket
AUTHDAEMOND_CONFIGURE_OFF=--with-authdaemond=no
KEEP_DB_OPEN_DESC=	Keep handle to Berkeley DB open
KEEP_DB_OPEN_CONFIGURE_ENABLE=keep-db-open
OBSOLETE_CRAM_ATTR_DESC=cmusaslsecretCRAM-MD5 property
OBSOLETE_CRAM_ATTR_CONFIGURE_OFF=--enable-obsolete_cram_attr=no
BDB_CONFIGURE_ON=	--with-dblib=berkeley \
			--with-bdb-libdir=${BDB_LIB_DIR} \
			--with-bdb-incdir=${BDB_INCLUDE_DIR} \
			--with-bdb=${BDB_LIB_NAME}
BDB_CONFIGURE_OFF=	--with-dblib=ndbm
MYSQL_CONFIGURE_ON=	--with-mysql=${LOCALBASE}
MYSQL_CONFIGURE_OFF=	--without-mysql
PGSQL_CONFIGURE_ON=	--with-pgsql=${LOCALBASE}
PGSQL_CONFIGURE_OFF=	--without-pgsql
SQLITE2_DESC=		SQLite 2 database
SQLITE2_CONFIGURE_ON=	--with-sqlite=${LOCALBASE}
SQLITE2_CONFIGURE_OFF=	--without-sqlite
SQLITE3_CONFIGURE_ON=	--with-sqlite3=${LOCALBASE}
SQLITE3_CONFIGURE_OFF=	--without-sqlite3
CRAM_DESC=		CRAM-MD5 authentication
CRAM_CONFIGURE_ENABLE=	cram
DIGEST_DESC=		DIGEST-MD5 authentication
DIGEST_CONFIGURE_ENABLE=digest
LOGIN_DESC=		LOGIN authentication
LOGIN_CONFIGURE_ENABLE=	login
NTLM_DESC=		NTLM authentication
NTLM_CONFIGURE_ENABLE=	ntlm
OTP_DESC=		OTP authentication
OTP_CONFIGURE_ENABLE=	otp
PLAIN_DESC=		PLAIN authentication
PLAIN_CONFIGURE_ENABLE=	plain
SCRAM_DESC=		SCRAM authentication
SCRAM_CONFIGURE_ENABLE=	scram

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MBDB}
USE_BDB=	yes
INVALID_BDB_VER=2
SASLDB_NAME=	sasldb2
.else
SASLDB_NAME=	sasldb2.db
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
.endif

.if ${PORT_OPTIONS:MSQLITE2}
USE_SQLITE=	2
.endif

.if ${PORT_OPTIONS:MSQLITE3}
USE_SQLITE=	3
.endif

.if ${PORT_OPTIONS:MMYSQL} || ${PORT_OPTIONS:MPGSQL} || \
    ${PORT_OPTIONS:MSQLITE2} || ${PORT_OPTIONS:MSQLITE3}
CONFIGURE_ARGS+=--enable-sql
.else
SQL=	"@comment "
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

PLIST_SUB+=	PREFIX=${PREFIX} \
		GSSAPI=${GSSAPI} \
		EBONES=${EBONES} \
		SQL=${SQL} \
		DOCSDIR=${DOCSDIR:S/^${PREFIX}\///}

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGINSTALL=	${WRKDIR}/pkg-install
PKGMESSAGE=	${WRKDIR}/pkg-message

post-patch:
# Fix sasldb name in pkg-install/deinstall scripts
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
# Try to unbreak parallel (-jX) builds, part 1: make build commands atomic
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${PERL} -w0pi.bak \
		-e 's/(^\@am__fastdepCC_TRUE\@.*?) \
		\n\@am__fastdepCC_TRUE\@\s+(.*?)$$/$$1 && $$2/mgx'
# Part 2: prevent intermediate *.Tpo output files clash (use unique names)
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${PERL} -wpi.bak \
		-e 's/\$$\*\.Tpo/$$&.$$./g'

# Create Cyrus user and group
pre-su-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.if ${PORT_OPTIONS:MDOCS}
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
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
