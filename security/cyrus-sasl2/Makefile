# New ports collection makefile for:	cyrus-sasl2
# Date created:				Nov 1 1999
# Whom:					hetzels@westbend.net
#
# $FreeBSD$
#

PORTNAME=	cyrus-sasl
PORTVERSION=	2.1.23
#PORTREVISION=	0
CATEGORIES=	security ipv6
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/%SUBDIR%/ \
		ftp://ftp.westbend.net/pub/cyrus-mail/%SUBDIR%/ \
		http://www.transit.hanse.de/mirror/ftp.andrew.cmu.edu/pub/cyrus-mail/%SUBDIR%/
MASTER_SITE_SUBDIR=	. OLD-VERSIONS/sasl

MAINTAINER=	ume@FreeBSD.org
COMMENT=	RFC 2222 SASL (Simple Authentication and Security Layer)

LATEST_LINK=	${PORTNAME}2

USE_AUTOTOOLS=	libtool:15
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
		--includedir=${PREFIX}/include \
		--enable-static \
		--enable-auth-sasldb \
		--with-rc4=openssl \
		--with-saslauthd=${SASLAUTHD_RUNPATH}

OPTIONS=	BDB		"Use Berkeley DB"			off \
		MYSQL		"Use MySQL"				off \
		PGSQL		"Use PostgreSQL"			off \
		SQLITE		"Use SQLite"				off \
		DEV_URANDOM	"Use /dev/urandom"			off \
		ALWAYSTRUE	"Enable the alwaystrue password verifier" off \
		KEEP_DB_OPEN	"Keep handle to Berkeley DB open"	off \
		AUTHDAEMOND	"Enable use of authdaemon"		on \
		LOGIN		"Enable LOGIN authentication"		on \
		PLAIN		"Enable PLAIN authentication"		on \
		CRAM		"Enable CRAM-MD5 authentication"	on \
		DIGEST		"Enable DIGEST-MD5 authentication"	on \
		OTP		"Enable OTP authentication"		on \
		NTLM		"Enable NTLM authentication"		on

.include <bsd.port.pre.mk>

.if defined(WITH_BDB)
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

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-mysql=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-mysql
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=--with-pgsql=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-pgsql
.endif

.if defined(WITH_SQLITE)
USE_SQLITE=	2
CONFIGURE_ARGS+=--with-sqlite=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-sqlite
.endif

.if defined(WITH_MYSQL) || defined(WITH_PGSQL) || defined(WITH_SQLITE)
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

.if defined(WITH_KEEP_DB_OPEN)
CONFIGURE_ARGS+=--enable-keep-db-open
.endif

.if defined(WITHOUT_AUTHDAEMOND)
CONFIGURE_ARGS+=--with-authdaemond=no
.else
CONFIGURE_ARGS+=--with-authdaemond=/var/run/authdaemond/socket
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

.if ${ARCH} == "amd64"
CPPFLAGS+=	-fPIC
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
.endif
.if !defined(WITHOUT_GSSAPI) && defined(KRB5_HOME) && exists(${KRB5_HOME}/lib/libgssapi_krb5.so)
CONFIGURE_ARGS+=--enable-gssapi=${KRB5_HOME} --with-gss_impl=mit
.elif !defined(WITHOUT_GSSAPI) && defined(HEIMDAL_HOME) && exists(${HEIMDAL_HOME}/lib/libgssapi.a)
CONFIGURE_ARGS+=--enable-gssapi=${HEIMDAL_HOME} --with-gss_impl=heimdal
.elif !defined(WITHOUT_GSSAPI) && exists(/usr/lib/libkrb5.a)
CONFIGURE_ARGS+=--enable-gssapi
.else
CONFIGURE_ARGS+=--disable-gssapi
GSSAPI=	"@comment "
.endif

# KERBEROS 4 was removed in FreeBSD 5.0-CURRENT
.if defined(WITH_KERBEROS4)
LIB_DEPENDS+=	krb.2:${PORTSDIR}/security/krb4
CONFIGURE_ARGS+=--enable-krb4=${LOCALBASE}/krb4
.else
CONFIGURE_ARGS+=--disable-krb4
EBONES=	"@comment "
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
.if !defined(NOPORTDOCS)
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
