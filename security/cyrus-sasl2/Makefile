# New ports collection makefile for:	cyrus-sasl2
# Date created:				Nov 1 1999
# Whom:					hetzels@westbend.net
#
# $FreeBSD$
#

PORTNAME=	cyrus-sasl
PORTVERSION=	2.1.10
#PORTREVISION=	0
CATEGORIES=	security ipv6
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		ftp://ftp.westbend.net/pub/cyrus-mail/ \
		ftp://ftp.hanse.de/sites/transit/mirror/ftp.andrew.cmu.edu/pub/cyrus-mail/

MAINTAINER=	ume@FreeBSD.org

USE_SUBMAKE=	yes
USE_OPENSSL=	yes

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
MAN8=		saslauthd.8 sasldblistusers2.8 saslpasswd2.8

GNU_CONFIGURE=	YES

CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc \
		--with-plugindir=${PREFIX}/lib/sasl2 \
		--with-dbpath=${PREFIX}/etc/sasldb2 \
		--includedir=${PREFIX}/include \
		--enable-static \
		--enable-login \
		--with-saslauthd \
		--enable-auth-sasldb \
		--with-rc4=openssl

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		PREFIX="${PREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}" \
		REALCURDIR="${.CURDIR}" \
		WITH_DB3="${WITH_DB3}" \
		WITH_MYSQL="${WITH_MYSQL}" \
		WITH_LDAP="${WITH_LDAP}"

.if defined(WITHOUT_OTP)
CONFIGURE_ARGS+=	--disable-otp
OTP=	"@comment "
.endif

.if defined(WITHOUT_CRAM)
CONFIGURE_ARGS+=	--disable-cram
CRAM=	"@comment "
.endif

.if defined(WITHOUT_DIGEST)
CONFIGURE_ARGS+=	--disable-digest
DIGEST=	"@comment "
.endif

.if defined(KRB5_HOME) && exists(${KRB5_HOME})
CONFIGURE_ARGS+=	--enable-gssapi=${KRB5_HOME}
.elif defined(HEIMDAL_HOME) && exists(${HEIMDAL_HOME})
CONFIGURE_ARGS+=	--enable-gssapi=${HEIMDAL_HOME}
.else
CONFIGURE_ARGS+=	--disable-gssapi
GSSAPI=	"@comment "
.endif

.if exists(/usr/lib/libkrb.a)
CONFIGURE_ARGS+=	--enable-krb4
.else
CONFIGURE_ARGS+=	--disable-krb4
EBONES=	"@comment "
.endif

CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE} \
		OPENSSLINC=${OPENSSLINC} \
		OPENSSLLIB=${OPENSSLLIB}

DOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README

DOC2=	ONEWS TODO draft-burdis-cat-srp-sasl-06.txt \
	draft-ietf-cat-sasl-gssapi-05.txt draft-melnikov-rfc2831bis-02.txt \
	draft-myers-saslrev-02.txt draft-nerenberg-sasl-crammd5-03.txt \
	draft-newman-sasl-c-api-00.txt draft-sasl-login.txt \
	draft-zeilenga-sasl-anon-01.txt draft-zeilenga-sasl-plain-01.txt \
	rfc1321.txt rfc1939.txt rfc2104.txt rfc2195.txt rfc2222.txt \
	rfc2243.txt rfc2245.txt rfc2289.txt rfc2444.txt rfc2595.txt \
	rfc2831.txt rfc2945.txt rfc3174.txt server-plugin-flow.fig \
	testing.txt

SASLAUTHD_DOCS=	AUTHORS COPYING ChangeLog INSTALL LDAP_SASLAUTHD NEWS README

HTDOCS=	advanced appconvert gssapi index install macosx mechanisms \
	options plugprog programming readme sysadmin upgrading

PLIST_SUB=	PREFIX=${PREFIX} \
		OTP=${OTP} \
		CRAM=${CRAM} \
		DIGEST=${DIGEST} \
		GSSAPI=${GSSAPI} \
		EBONES=${EBONES} \
		MYSQL=${MYSQL} \
		DOCSDIR=${DOCSDIR:S/^${PREFIX}\///} \

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGINSTALL=	${WRKDIR}/pkg-install
PKGMESSAGE=	${WRKDIR}/pkg-message

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.sasl

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

# Fix sasldb name in pkg-install/deinstall scripts
post-patch:
	@${SED} -e "s;%%SASLDB%%;${SASLDB_NAME};g" \
		-e "s;%%PWCHECK_METHOD%%;${PWCHECK_METHOD};g" \
		${.CURDIR}/pkg-install > ${PKGINSTALL}
	@${SED} -e "s;%%SASLDB%%;${SASLDB_NAME};g" \
		-e "s;%%PWCHECK_METHOD%%;${PWCHECK_METHOD};g" \
		${.CURDIR}/pkg-deinstall > ${PKGDEINSTALL}
	@${SED} -e "s;%%PWCHECK_METHOD%%;${PWCHECK_METHOD};g" \
		-e "s;%%PREFIX%%;${PREFIX};g" \
		${.CURDIR}/pkg-message > ${PKGMESSAGE}

# Create Cyrus user and group
pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_MAN} ${WRKSRC}/utils/saslpasswd2.8 \
		${MAN8PREFIX}/man/man8/saslpasswd2.8
	${INSTALL_MAN} ${WRKSRC}/utils/sasldblistusers2.8 \
		${MAN8PREFIX}/man/man8/sasldblistusers2.8
	${INSTALL_MAN} ${WRKSRC}/saslauthd/saslauthd.mdoc \
		${MAN8PREFIX}/man/man8/saslauthd.8
	@${SED} -e "s;%%PREFIX%%;${PREFIX};g" ${PWCHECK_SUB} \
		${FILESDIR}/saslauthd.sh > ${PREFIX}/etc/rc.d/saslauthd.sh
	@${CHMOD} 755 ${PREFIX}/etc/rc.d/saslauthd.sh
	${MKDIR} -m 770 /var/state/saslauthd
	${CHOWN} cyrus:cyrus /var/state/saslauthd
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/html
	@${MKDIR} ${DOCSDIR}/saslauthd
.for file in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.for file in ${DOC2}
	@${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.for file in ${HTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${file}.html ${DOCSDIR}/html
.endfor
.for file in ${SASLAUTHD_DOCS}
	@${INSTALL_DATA} ${WRKSRC}/saslauthd/${file} ${DOCSDIR}/saslauthd
.endfor
	@${INSTALL_DATA} ${FILESDIR}/Sendmail.README ${DOCSDIR}
.endif
	@PKG_PREFIX=${PREFIX} BATCH=${BATCH} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.mk>
