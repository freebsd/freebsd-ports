# New ports collection makefile for:	cyrus-sasl
# Date created:				Nov 1 1999
# Whom:					hetzels@westbend.net
#
# $FreeBSD$
#

PORTNAME=	cyrus-sasl
PORTVERSION=	1.5.27
PORTREVISION=	7
CATEGORIES=	security ipv6
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/%SUBDIR%/ \
		http://www.surf.org.uk/downloads/ \
		ftp://ftp.westbend.net/pub/cyrus-mail/%SUBDIR%/ \
		${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.hanse.de/sites/transit/mirror/ftp.andrew.cmu.edu/pub/cyrus-mail/
MASTER_SITE_SUBDIR=	. OLD-VERSIONS/sasl cyrus-utils

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		sasl-${PORTVERSION}-ldap-ssl-filter-mysql-patch4.tgz

PATCH_SITES=	ftp://ftp.westbend.net/pub/cyrus-mail/contrib/ \
		http://www.imasy.or.jp/~ume/ipv6/
PATCHFILES=	sasl_apop_patch.gz \
		${DISTNAME}-ipv6-${IPV6_VER}.diff.gz

MAINTAINER=	hetzels@westbend.net

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

USE_AUTOMAKE_VER=14
USE_LIBTOOL=	YES
AUTOMAKE_ARGS=	--add-missing --include-deps

CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc \
		--with-plugindir=${PREFIX}/lib/sasl \
		--with-dbpath=${PREFIX}/etc/sasldb \
		--includedir=${PREFIX}/include/sasl1 \
		--enable-static \
		--enable-login \
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

DOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README TODO

PLIST_SUB=	PREFIX=${PREFIX} \
		GSSAPI=${GSSAPI} \
		EBONES=${EBONES} \
		DOCSDIR=${DOCSDIR:S/^${PREFIX}\///} \
		EXAMPLESDIR=${EXAMPLESDIR:S/^${PREFIX}\///}

LDAP_MYSQL_PATCH=	ldap-mysql_sasl-${PORTVERSION}/sasl-ldap+mysql.patch

PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGINSTALL=	${WRKDIR}/pkg-install
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 450000
FMT=    /usr/bin/fmt
.else
FMT=    /usr/bin/fmt -w 67
.endif

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.sasl

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

post-extract:
	@${CP} ${FILESDIR}/pwcheck_pam.c ${WRKSRC}/pwcheck

pre-patch:
	@(cd ${WRKSRC} && ${PATCH} -p1 < ${WRKDIR}/${LDAP_MYSQL_PATCH})

# Fix pkg-{install/deinstall/messages}
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
		mv ${PREFIX}/sbin/saslauthd ${PREFIX}/sbin/saslauthd2; \
		if [ -f ${PREFIX}/man/man8/saslauthd.8 ]; then \
			mv ${PREFIX}/man/man8/saslauthd.8 \
			   ${PREFIX}/man/man8/saslauthd2.8; \
		elif [ -f ${PREFIX}/man/man8/saslauthd.8.gz ]; then \
			mv ${PREFIX}/man/man8/saslauthd.8.gz \
			   ${PREFIX}/man/man8/saslauthd2.8.gz; \
		fi; \
	fi

post-install:
	@${SED} -e "s;%%PREFIX%%;${PREFIX};g" ${PWCHECK_SUB} \
		${FILESDIR}/pwcheck.sh > ${PREFIX}/etc/rc.d/pwcheck.sh
	@${MKDIR} ${EXAMPLESDIR}
	@${SED} -e 's;%%PREFIX%%;${PREFIX};g' \
		${FILESDIR}/cyrus.pam > ${EXAMPLESDIR}/cyrus.pam
	@${CHMOD} 755 ${PREFIX}/etc/rc.d/pwcheck.sh
	${INSTALL} -d -m 770 -o cyrus -g cyrus /var/pwcheck
	@${SED} -e "s;%%PREFIX%%;${PREFIX};g" ${SASLAUTHD_SUB} \
		${FILESDIR}/saslauthd.sh > ${PREFIX}/etc/rc.d/saslauthd1.sh
	@${CHMOD} 755 ${PREFIX}/etc/rc.d/saslauthd1.sh
	${INSTALL} -d -m 770 -o cyrus -g cyrus /var/state/saslauthd1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	(cd ${WRKSRC}/doc ; \
	for file in `make -V EXTRA_DIST` ; do \
		${INSTALL_DATA} ${WRKSRC}/doc/$${file} ${DOCSDIR} ; \
	done)
	@${INSTALL_DATA} ${WRKSRC}/java/doc/draft-weltman-java-sasl-02.txt ${DOCSDIR}
	@${INSTALL_DATA} ${FILESDIR}/Sendmail.README ${DOCSDIR}
.endif
	@mv ${PREFIX}/sbin/saslauthd ${PREFIX}/sbin/saslauthd1
	@mv ${PREFIX}/man/man8/saslauthd.8 ${PREFIX}/man/man8/saslauthd1.8
	@if [ -f ${PREFIX}/sbin/saslauthd2 ]; then \
		mv ${PREFIX}/sbin/saslauthd2 ${PREFIX}/sbin/saslauthd; \
		if [ -f ${PREFIX}/man/man8/saslauthd2.8 ]; then \
			mv ${PREFIX}/man/man8/saslauthd2.8 \
			   ${PREFIX}/man/man8/saslauthd.8; \
		elif [ -f ${PREFIX}/man/man8/saslauthd2.8.gz ]; then \
			mv ${PREFIX}/man/man8/saslauthd2.8.gz \
			   ${PREFIX}/man/man8/saslauthd.8.gz; \
		fi; \
	fi
	@PKG_PREFIX=${PREFIX} BATCH=${BATCH} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

#if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
#include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
#endif

.include <bsd.port.post.mk>
