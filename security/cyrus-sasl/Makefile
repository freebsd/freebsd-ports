# New ports collection makefile for:	cyrus-sasl
# Date created:				Nov 1 1999
# Whom:					hetzels@westbend.net
#
# $FreeBSD$
#

PORTNAME=	cyrus-sasl
PORTVERSION=	1.5.28
PORTREVISION=	4
CATEGORIES=	security ipv6

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RFC 2222 SASL (Simple Authentication and Security Layer)

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		sasl-${PORTVERSION}-ldap-ssl-filter-mysql-patch.tgz:ldap_mysql

MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/%SUBDIR%/ \
		ftp://ftp.westbend.net/pub/cyrus-mail/%SUBDIR%/ \
		ftp://ftp.hanse.de/sites/transit/mirror/ftp.andrew.cmu.edu/pub/cyrus-mail/ \
		http://www.surf.org.uk/downloads/:ldap_mysql \
		ftp://ftp.westbend.net/pub/cyrus-mail/%SUBDIR%/:ldap_mysql \
		${MASTER_SITE_SOURCEFORGE:S/$/:ldap_mysql/} \
MASTER_SITE_SUBDIR=	. OLD-VERSIONS/sasl cyrus-utils:ldap_mysql
PATCHFILES=	sasl_apop_patch.gz:apop \
		${DISTNAME}-ipv6-${IPV6_VER}.diff.gz
PATCH_SITES=	ftp://ftp.westbend.net/pub/cyrus-mail/contrib/:apop \
		http://www.imasy.or.jp/~ume/ipv6/

USE_SUBMAKE=	yes
USE_OPENSSL=	yes

INSTALLS_SHLIB=	yes

# IPv6 Patch provided by Hajimu UMEMOTO <ume@mahoroba.org>
IPV6_VER=	20020106

MAN3=		sasl.3 sasl_authorize_t.3 sasl_callbacks.3 sasl_checkpass.3 \
		sasl_client_init.3 sasl_client_new.3 sasl_client_start.3 \
		sasl_client_step.3 sasl_decode.3 sasl_done.3 sasl_encode.3 \
		sasl_errstring.3 sasl_getopt_t.3 sasl_getpath_t.3 \
		sasl_getprop.3 sasl_getsecret_t.3 sasl_getsimple_t.3 \
		sasl_listmech.3 sasl_log_t.3 sasl_server_init.3 \
		sasl_server_new.3 sasl_server_start.3 sasl_server_step.3 \
		sasl_setprop.3 sasl_usererr.3
MAN8=		sasldblistusers.8 saslpasswd.8 saslauthd1.8

USE_RC_SUBR=	YES

USE_AUTOMAKE_VER=14
USE_AUTOCONF_VER=213
USE_INC_LIBTOOL_VER=13
AUTOMAKE_ARGS=	--add-missing --include-deps

CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc \
		--with-plugindir=${PREFIX}/lib/sasl \
		--with-dbpath=${PREFIX}/etc/sasldb \
		--includedir=${PREFIX}/include/sasl1 \
		--enable-static \
		--with-saslauthd=/var/state/saslauthd1 \
		--enable-auth-sasldb \
		--with-pwcheck=/var/pwcheck \
		--with-rc4=openssl

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		PREFIX="${PREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}" \
		REALCURDIR="${.CURDIR}" \
		WITH_DB3="${WITH_DB3}" \
		WITH_JAVA="${WITH_JAVA}" \
		WITH_MYSQL="${WITH_MYSQL}" \
		WITH_LDAP1="${WITH_LDAP1}" \
		WITH_LDAP2="${WITH_LDAP2}"

JAVADIR?=	jdk1.3.1
JAVALIBDIR?=	${PREFIX}/${JAVADIR}/lib/i386/green_threads/

.if defined(WITHOUT_ANONYMOUS)
CONFIGURE_ARGS+=	--disable-anon
ANON=			"@comment "
.endif

.if defined(WITHOUT_CRAM)
CONFIGURE_ARGS+=	--disable-cram
CRAM=			"@comment "
.endif

.if defined(WITHOUT_DIGEST)
CONFIGURE_ARGS+=	--disable-digest
DIGEST=			"@comment "
.endif

# Outlook and Outlook Express requires the LOGIN mech
.if defined(WITHOUT_LOGIN)
CONFIGURE_ARGS+=	--disable-login
LOGIN=			"@comment "
.else
CONFIGURE_ARGS+=	--enable-login
.endif

.if defined(WITHOUT_OTP)
CONFIGURE_ARGS+=	--disable-otp
OTP=			"@comment "
.endif

# Netscape requires the PLAIN mech
.if defined(WITHOUT_PLAIN)
CONFIGURE_ARGS+=	--disable-plain
PLAIN=			"@comment "
.endif

.if !defined(WITHOUT_GSSAPI) && defined(KRB5_HOME) && exists(${KRB5_HOME}/lib/libgssapi_krb5.a)
CONFIGURE_ARGS+=	--enable-gssapi=${KRB5_HOME}
.elif !defined(WITHOUT_GSSAPI) && defined(HEIMDAL_HOME) && exists(${HEIMDAL_HOME}/lib/libgssapi.a)
CONFIGURE_ARGS+=	--enable-gssapi=${HEIMDAL_HOME}
.elif !defined(WITHOUT_GSSAPI) && defined(MAKE_KERBEROS5) && exists(/usr/lib/libkrb5.a)
CONFIGURE_ARGS+=	--enable-gssapi
.else
CONFIGURE_ARGS+=	--disable-gssapi
GSSAPI=	"@comment "
.endif

.include <bsd.port.pre.mk>

# KERBEROS 4 was removed in FreeBSD 5.0-CURRENT
.if ${OSVERSION} > 500105
.if defined(WITH_KERBEROS4)
LIB_DEPENDS+=	krb.2:${PORTSDIR}/security/krb4
CONFIGURE_ARGS+=	--enable-krb4=${LOCALBASE}/krb4
.else
CONFIGURE_ARGS+=	--disable-krb4
EBONES=	"@comment "
.endif
.elif exists(/usr/lib/libkrb.a) && defined(MAKE_KERBEROS4) && !defined(WITHOUT_KERBEROS4)
CONFIGURE_ARGS+=	--enable-krb4
.elif !exists(/usr/lib/libkrb.a) && defined(WITH_KERBEROS4)
LIB_DEPENDS+=	krb.2:${PORTSDIR}/security/krb4
CONFIGURE_ARGS+=	--enable-krb4=${LOCALBASE}/krb4
.else
CONFIGURE_ARGS+=	--disable-krb4
EBONES=	"@comment "
.endif

CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE} \
		OPENSSLINC=${OPENSSLINC} \
		OPENSSLLIB=${OPENSSLLIB}

CYRUS_USER?=	cyrus
CYRUS_GROUP?=	cyrus

DOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README TODO

PLIST_SUB=	PREFIX=${PREFIX} \
		ANON=${ANON} \
		OTP=${OTP} \
		CRAM=${CRAM} \
		DIGEST=${DIGEST} \
		LOGIN=${LOGIN} \
		PLAIN=${PLAIN} \
		GSSAPI=${GSSAPI} \
		EBONES=${EBONES} \
		DOCSDIR=${DOCSDIR:S/^${PREFIX}\///} \
		EXAMPLESDIR=${EXAMPLESDIR:S/^${PREFIX}\///}

LDAP_MYSQL_PATCH=	ldap-mysql_sasl-${PORTVERSION}/sasl-ldap+mysql.patch

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGINSTALL=	${WRKDIR}/pkg-install
PKGMESSAGE=	${WRKDIR}/pkg-message

.if ${OSVERSION} < 450000
FMT=	/usr/bin/fmt
.else
FMT=	/usr/bin/fmt -w 67
.endif

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.sasl

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

RC_SCRIPTS_SUB=	PREFIX=${PREFIX} \
		RC_SUBR=${RC_SUBR} \
		PWCHECK=${PWCHECK} \
		ENABLE_PWCHECK=${ENABLE_PWCHECK} \
		ENABLE_SASLAUTHD=${ENABLE_SASLAUTHD} \
		MYSQL_REQ=${MYSQL_REQ}

PKG_SCRIPTS_SUB=	PREFIX=${PREFIX} \
		CYRUS_USER=${CYRUS_USER} \
		CYRUS_GROUP=${CYRUS_GROUP} \
		ENABLE_PWCHECK=${ENABLE_PWCHECK} \
		ENABLE_SASLAUTHD=${ENABLE_SASLAUTHD} \
		PWCHECK=${PWCHECK} \
		PWCHECK_METHOD=${PWCHECK_METHOD} \
		SASLDB=${SASLDB_NAME}

post-extract:
	@${CP} ${FILESDIR}/pwcheck_pam.c ${WRKSRC}/pwcheck

pre-patch:
	@(cd ${WRKSRC} && ${PATCH} -p1 < ${WRKDIR}/${LDAP_MYSQL_PATCH})

# Fix pkg-{install/deinstall/messages}
post-patch:
	@${SED} ${PKG_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${.CURDIR}/pkg-install > ${PKGINSTALL}
	@${SED} ${PKG_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${.CURDIR}/pkg-deinstall > ${PKGDEINSTALL}
	@${SED} -e "s;%%PWCHECK_METHOD%%;${PWCHECK_METHOD};g" \
		-e "s;%%PREFIX%%;${PREFIX};g" \
		${.CURDIR}/pkg-message > ${PKGMESSAGE}
.ifdef LDAP_MYSQL_MSG
	@${ECHO_CMD} ${LDAP_MYSQL_MSG} | ${FMT} >> ${PKGMESSAGE}
	@${ECHO_CMD} >> ${PKGMESSAGE}
.endif

pre-configure:
	@(cd ${WRKSRC} && ${AUTOHEADER})

# Create Cyrus user and group
pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@if [ -f ${PREFIX}/sbin/saslauthd ]; then \
		${MV} ${PREFIX}/sbin/saslauthd ${PREFIX}/sbin/saslauthd2; \
		if [ -f ${PREFIX}/man/man8/saslauthd.8 ]; then \
			${MV} ${PREFIX}/man/man8/saslauthd.8 \
			   ${PREFIX}/man/man8/saslauthd2.8; \
		elif [ -f ${PREFIX}/man/man8/saslauthd.8.gz ]; then \
			${MV} ${PREFIX}/man/man8/saslauthd.8.gz \
			   ${PREFIX}/man/man8/saslauthd2.8.gz; \
		fi; \
	fi

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${SED} -e 's;%%PREFIX%%;${PREFIX};g' \
		${FILESDIR}/cyrus.pam > ${EXAMPLESDIR}/cyrus.pam
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/pwcheck.sh > ${PREFIX}/etc/rc.d/cyrus_pwcheck.sh
	@${CHMOD} 755 ${PREFIX}/etc/rc.d/cyrus_pwcheck.sh
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/saslauthd.sh > ${PREFIX}/etc/rc.d/saslauthd1.sh
	@${CHMOD} 755 ${PREFIX}/etc/rc.d/saslauthd1.sh
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/cyrus_sasl1 > ${PREFIX}/etc/rc.d/cyrus_sasl1
	@${CHMOD} 755 ${PREFIX}/etc/rc.d/cyrus_sasl1
	${INSTALL} -d -m 770 -o ${CYRUS_USER} -g ${CYRUS_GROUP} /var/pwcheck
	${INSTALL} -d -m 770 -o ${CYRUS_USER} -g ${CYRUS_GROUP} /var/state/saslauthd1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
	(cd ${WRKSRC}/doc ; \
	for extrafile in `make -V EXTRA_DIST` ; do \
		${INSTALL_DATA} ${WRKSRC}/doc/$${extrafile} ${DOCSDIR} ; \
	done)
	@${INSTALL_DATA} ${WRKSRC}/java/doc/draft-weltman-java-sasl-02.txt ${DOCSDIR}
	@${INSTALL_DATA} ${FILESDIR}/Sendmail.README ${DOCSDIR}
.endif
	@${MV} ${PREFIX}/sbin/saslauthd ${PREFIX}/sbin/saslauthd1
	@${MV} ${PREFIX}/man/man8/saslauthd.8 ${PREFIX}/man/man8/saslauthd1.8
	@if [ -f ${PREFIX}/sbin/saslauthd2 ]; then \
		${MV} ${PREFIX}/sbin/saslauthd2 ${PREFIX}/sbin/saslauthd; \
		if [ -f ${PREFIX}/man/man8/saslauthd2.8 ]; then \
			${MV} ${PREFIX}/man/man8/saslauthd2.8 \
			   ${PREFIX}/man/man8/saslauthd.8; \
		elif [ -f ${PREFIX}/man/man8/saslauthd2.8.gz ]; then \
			${MV} ${PREFIX}/man/man8/saslauthd2.8.gz \
			   ${PREFIX}/man/man8/saslauthd.8.gz; \
		fi; \
	fi
	@PKG_PREFIX=${PREFIX} BATCH=${BATCH} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.include <bsd.port.post.mk>
