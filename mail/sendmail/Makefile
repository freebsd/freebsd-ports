# $FreeBSD$

PORTNAME=	sendmail
PORTVERSION=	8.15.2
PORTREVISION=	14
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.sendmail.org/pub/sendmail/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Reliable, highly configurable mail transfer agent with utilities

LICENSE=	Sendmail
LICENSE_NAME=	Sendmail License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

CONFLICTS?=	courier-0.* postfix-1.* postfix-2.* smail-3.* zmailer-2.* opensmtpd-*

USERS=		smmsp
GROUPS=		smmsp

USES=		cpe uidfix groff
MAKE_ARGS=	UBINOWN=${UID} UBINGRP=${GID} \
		SBINOWN=${UID} SBINGRP=${GID} \
		GBINOWN=${UID} GBINGRP=${GID} \
		MANOWN=${UID} MANGRP=${GID} \
		LIBMODE=0644 UBINMODE=0755 GBINMODE=2755
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
DOCS=		KNOWNBUGS LICENSE PGPKEYS README RELEASE_NOTES \
		sendmail/TRACEFLAGS sendmail/SECURITY sendmail/TUNING
PLIST_SUB+=	PREFIX=${PREFIX:S=${PREFIX}/==} \
		MANPREFIX=${MANPREFIX:S=$=/=:S=${PREFIX}==:S=^/==}
PKGMESSAGE=	${WRKSRC}/pkg-message

WCONF=		${WRKSRC}/devtools/Site
SITE=		${FILESDIR}/site.config.m4.pre4
PLIST=		${WRKDIR}/.PLIST.more
LMAN1=		mailq.1 newaliases.1 vacation.1
LMAN5=		aliases.5
LMAN8=		sendmail.8 mailstats.8 makemap.8 praliases.8 smrsh.8 \
		mail.local.8 rmail.8 editmap.8
SENDMAIL=	${PREFIX}/sbin/sendmail
BASEMAIL=	/usr/libexec/sendmail/sendmail
MILTER_SOVER?=	6

OPTIONS_DEFINE?=	SHMEM SEM LA NIS IPV6 TLS SASL SASLAUTHD LDAP BDB \
			GDBM SOCKETMAP CYRUSLOOKUP BLACKLISTD SMTPUTF8 \
			PICKY_HELO_CHECK MILTER DOCS
OPTIONS_DEFAULT?=	SHMEM SEM LA NIS TLS SASL SASLAUTHD BDB1 \
			BLACKLISTD PICKY_HELO_CHECK MILTER
NO_OPTIONS_SORT=yes
SHMEM_DESC=		System V shared memory support
LA_DESC=		load averages support
TLS_DESC=		SMTP-TLS and SMTPS support
SASLAUTHD_DESC=		SASLAUTHD support
BDB_DESC=		Berkeley DB version 4+ support
GDBM_DESC=		GNU dbm library support (option COMPAT needed)
SOCKETMAP_DESC=		Enable socketmap feature
BLACKLISTD_DESC=	Enable blacklistd support
CYRUSLOOKUP_DESC=	Enable cyruslookup feature
PICKY_HELO_CHECK_DESC=	Enable picky HELO check
MILTER_DESC=		Enable milter support
SMTPUTF8_DESC=		Enable unicode address support

TLS_USES=	ssl
SASL_LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2
SASLAUTHD_RUN_DEPENDS=	${LOCALBASE}/sbin/saslauthd:security/cyrus-sasl2-saslauthd
LDAP_USE=	OPENLDAP=yes
BDB_USES=	bdb
GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
GDBM_CONFIGURE_WITH=	compat
SMTPUTF8_LIB_DEPENDS=	libidn2.so:dns/libidn2 libicui18n.so:devel/icu

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1200000
PKGNAMESUFFIX?=	${TLS_SUFFIX}${SASL_SUFFIX}${LDAP_SUFFIX}${BDB_SUFFIX}${PKGNAMESUFFIX2}
.endif

.if ${PORT_OPTIONS:MSHMEM} && !defined(BUILDING_INDEX)
IPCCHECK!=	ipcrm -q 0 2>&1 || true
.if ${IPCCHECK:Mimplemented}
IGNORE=		your system does not support sysvipc
.endif
.endif

.if ${PORT_OPTIONS:MBDB}
BDB_SUFFIX=	+${BDB_INCLUDE_DIR:S,^${LOCALBASE}/include/,,}
CONFLICTS+=	sendmail-ldap-8.* sendmail-sasl2-8.* sendmail-tls-8.*
.endif
.if ${PORT_OPTIONS:MLDAP}
LDAP_SUFFIX?=	+ldap
CONFLICTS+=	sendmail-sasl2-8.* sendmail-tls-8.*
.endif
.if ${PORT_OPTIONS:MSASL}
SASL_SUFFIX?=	+sasl2
CONFLICTS+=	sendmail-ldap-8.* sendmail-tls-8.*
.endif
.if ${PORT_OPTIONS:MCYRUSLOOKUP}
.if ! ${PORT_OPTIONS:MSOCKETMAP}
IGNORE=		option CYRUSLOOKUP requires option SOCKETMAP
.else
EXTRA_PATCHES+=	${FILESDIR}/cyruslookup.patch
.endif
.endif
.if ${PORT_OPTIONS:MSMTPUTF8}
EXTRA_PATCHES+=	${FILESDIR}/smtputf8.patch
.endif
.if ${PORT_OPTIONS:MTLS}
TLS_SUFFIX?=	+tls
CONFLICTS+=	sendmail-ldap-8.* sendmail-sasl2-8.*
.endif

MAKE_PKGNAMES=	for i in "" +tls; do \
	for j in "" +sasl2; do \
	for k in "" +ldap; do \
	for l in "" +db48 +db5 +db6; do \
	echo "sendmail$${i}$${j}$${k}$${l}-8.*" ;\
	done done done done

ALL_PKGNAMES!=	${MAKE_PKGNAMES}
CONFLICTS2!=	${MAKE_PKGNAMES} | ${GREP} -v "${PORTNAME}${PKGNAMESUFFIX:S|${PKGNAMESUFFIX2}||}-8."
CONFLICTS+=	${CONFLICTS2}

# Build site.config.m4
SITE+=	${FILESDIR}/site.config.m4
.if ${PORT_OPTIONS:MIPV6}
SITE+=	${FILESDIR}/site.config.m4.ipv6
.endif
.if ${PORT_OPTIONS:MSASL}
SITE+=	${FILESDIR}/site.config.m4.sasl2
.endif
.if ${PORT_OPTIONS:MLDAP}
SITE+=	${FILESDIR}/site.config.m4.ldap
.endif
.if ${PORT_OPTIONS:MBLACKLISTD}
SITE+=	${FILESDIR}/site.config.m4.blacklistd
.endif
.if ${PORT_OPTIONS:MSMTPUTF8}
SITE+=	${FILESDIR}/site.config.m4.smtputf8
.endif
.if ${PORT_OPTIONS:MMILTER}
SITE+=	${FILESDIR}/site.config.m4.milter
.endif
.if ${PORT_OPTIONS:MGDBM}
NO_PACKAGE=	GPLv3 license conflict
SITE+=	${FILESDIR}/site.config.m4.gdbm
.endif

SED_SCRIPT=	-e "s|\`-O'|\`${CFLAGS}'|" \
		-e 's|%%CC%%|${CC}|' -e 's|%%LD%%|${LD}|'

.if ! ${PORT_OPTIONS:MNIS}
SED_SCRIPT+=	-e "s;-DNIS ;;"
.endif

post-patch:
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=g" \
		-e "s=%%LOCALBASE%%=${LOCALBASE}=g" \
		-e "s=%%PORTSDIR%%=${PORTSDIR}=g" \
		${PKGDIR}/pkg-message > ${WRKSRC}/pkg-message

do-configure:
.if ${PORT_OPTIONS:MGDBM}
	@(if [ ! -e "${LOCALBASE}/lib/libgdbm_compat.so" ] ; then \
	  ${ECHO_MSG} "===> option COMPAT is missing in databases/gdbm."; \
	  ${FALSE}; \
	  fi)
.endif
.if ${PORT_OPTIONS:MBLACKLISTD}
	@(if [ ! -e "${DESTDIR}/usr/lib/libblacklist.so" ] ; then \
	  ${ECHO_MSG} "===> libblacklist.so not found. Please update to FreeBSD 11"; \
	  ${FALSE}; \
	  fi)
.endif
	${REINPLACE_CMD} ${SED_SCRIPT} ${WRKSRC}/devtools/OS/FreeBSD
	${SED} -e "s=%%PREFIX%%=${PREFIX}=g" \
		-e "s=%%LOCALBASE%%=${LOCALBASE}=g" \
		${SITE} > ${WCONF}/site.config.m4
.if ${PORT_OPTIONS:MBDB}
	${ECHO_CMD} \
	 'APPENDDEF(`confENVDEF'\'', `-I${BDB_INCLUDE_DIR}'\'')' \
		>> ${WCONF}/site.config.m4
	${ECHO_CMD} \
	 'APPENDDEF(`confLIBDIRS'\'', `-L${LOCALBASE}/lib'\'')' \
		>> ${WCONF}/site.config.m4
.for i in sendmail editmap makemap praliases vacation
	${ECHO_CMD} \
	 'APPENDDEF(`conf_${i}_LIBS'\'', `-l${BDB_LIB_NAME}'\'')' \
		>> ${WCONF}/site.config.m4
.endfor
.endif
.if ${PORT_OPTIONS:MSOCKETMAP}
	${ECHO_CMD} \
	 'APPENDDEF(`conf_sendmail_ENVDEF'\'', `-DSOCKETMAP'\'')' \
		>> ${WCONF}/site.config.m4
.endif
.if ${PORT_OPTIONS:MPICKY_HELO_CHECK}
	${ECHO_CMD} \
	 'APPENDDEF(`conf_sendmail_ENVDEF'\'', `-DPICKY_HELO_CHECK'\'')' \
		>> ${WCONF}/site.config.m4
.endif
.if ! ${PORT_OPTIONS:MSHMEM}
	${ECHO_CMD} \
	 'APPENDDEF(`confENVDEF'\'', `-DSM_CONF_SHM=0'\'')' \
		>> ${WCONF}/site.config.m4
.endif
.if ! ${PORT_OPTIONS:MSEM}
	${ECHO_CMD} \
	'APPENDDEF(`confENVDEF'\'', `-DSM_CONF_SEM=0'\'')' \
		>> ${WCONF}/site.config.m4
.endif
.if ! ${PORT_OPTIONS:MLA}
	${ECHO_CMD} \
	'APPENDDEF(`confENVDEF'\'', `-DLA_TYPE=LA_ZERO'\'')' \
		>> ${WCONF}/site.config.m4
.endif

post-build:
	(cd ${WRKSRC}/doc/op && \
	 ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} op.txt)

pre-install:
	${MKDIR} ${STAGEDIR}/etc/mail
	@${CAT} ${PKGDIR}/pkg-plist >${PLIST}
	@cd ${WRKSRC} && ${FIND} cf -type f | \
	${AWK} '{print "share/sendmail/" $$1}' >>${PLIST}
.if ${PORT_OPTIONS:MDOCS}
.for i in ${DOCS}
	@${ECHO_CMD} `${BASENAME} ${i}` | \
	${AWK} '{print "%%DOCSDIR%%/" $$1}' >>${PLIST}
.endfor
.if ${PORT_OPTIONS:MCYRUSLOOKUP}
	@${ECHO_CMD} "share/doc/sendmail/CYRUS_LOOKUP" >>${PLIST}
.endif
.endif

# We want mail.local and rmail for our system.
# the build install catmans only, we have to fix this.
post-install:
	(cd ${WRKSRC}/mail.local && \
	 ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} force-install)
	(cd ${WRKSRC}/rmail && \
	 ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} force-install)
.for i in ${LMAN8}
	${INSTALL_MAN} ${WRKSRC}/*/${i} ${STAGEDIR}${MANPREFIX}/man/man8/
.endfor
.for i in ${LMAN5}
	${INSTALL_MAN} ${WRKSRC}/*/${i} ${STAGEDIR}${MANPREFIX}/man/man5/
.endfor
.for i in ${LMAN1}
	${INSTALL_MAN} ${WRKSRC}/*/${i} ${STAGEDIR}${MANPREFIX}/man/man1/
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/share/sendmail
	${TAR} -C ${WRKSRC} -cf - cf | \
		${TAR} -C ${STAGEDIR}${PREFIX}/share/sendmail -xf -
	${RM} ${STAGEDIR}${PREFIX}/man/cat*/*
# final perm of sendmail is 2555 (see plist), needed for strip cmd
	${CHMOD} 755 ${STAGEDIR}${PREFIX}/sbin/sendmail

	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/vacation
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rmail
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/*

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/op/op.ps ${STAGEDIR}${DOCSDIR}/op.ps
	${INSTALL_DATA} ${WRKSRC}/doc/op/op.txt ${STAGEDIR}${DOCSDIR}/op.txt
	${INSTALL_DATA} ${WRKSRC}/devtools/README ${STAGEDIR}${DOCSDIR}/DEVTOOLS
	${INSTALL_DATA} ${WRKSRC}/sendmail/README ${STAGEDIR}${DOCSDIR}/SENDMAIL
	${INSTALL_DATA} ${WRKSRC}/mail.local/README ${STAGEDIR}${DOCSDIR}/MAIL.LOCAL
	${INSTALL_DATA} ${WRKSRC}/smrsh/README ${STAGEDIR}${DOCSDIR}/SMRSH
.if ${PORT_OPTIONS:MCYRUSLOOKUP}
	${INSTALL_DATA} ${FILESDIR}/CYRUS_LOOKUP ${STAGEDIR}${DOCSDIR}/CYRUS_LOOKUP
.endif

mailer.base:
	@${SED} \
	-e "s=^sendmail[ 	]*/.*$$=sendmail	${BASEMAIL}=" \
	-e "s=^send-mail[ 	]*/.*$$=send-mail	${BASEMAIL}=" \
	-e "s=^mailq[ 	]*/.*$$=mailq		${BASEMAIL}=" \
	-e "s=^newaliases[ 	]*/.*$$=newaliases	${BASEMAIL}=" \
	-e "s=^hoststat[ 	]*/.*$$=hoststat	${BASEMAIL}=" \
	-e "s=^purgestat[ 	]*/.*$$=purgestat	${BASEMAIL}=" \
	 ${DESTDIR}/etc/mail/mailer.conf > ${DESTDIR}/etc/mail/mailer.conf.new
	${MV} ${DESTDIR}/etc/mail/mailer.conf.new \
		${DESTDIR}/etc/mail/mailer.conf

mailer.conf:
	@${SED} \
	-e "s=^sendmail[ 	]*/.*$$=sendmail	${SENDMAIL}=" \
	-e "s=^send-mail[ 	]*/.*$$=send-mail	${SENDMAIL}=" \
	-e "s=^mailq[ 	]*/.*$$=mailq		${SENDMAIL}=" \
	-e "s=^newaliases[ 	]*/.*$$=newaliases	${SENDMAIL}=" \
	-e "s=^hoststat[ 	]*/.*$$=hoststat	${SENDMAIL}=" \
	-e "s=^purgestat[ 	]*/.*$$=purgestat	${SENDMAIL}=" \
	 ${DESTDIR}/etc/mail/mailer.conf > ${DESTDIR}/etc/mail/mailer.conf.new
	${MV} ${DESTDIR}/etc/mail/mailer.conf.new \
		${DESTDIR}/etc/mail/mailer.conf

# create sumbit.cf on older systems
#
submit.cf:	${DESTDIR}/etc/mail/submit.cf

${DESTDIR}/etc/mail/submit.mc:
	${INSTALL_DATA} ${PREFIX}/share/sendmail/cf/cf/submit.mc \
		${DESTDIR}/etc/mail/submit.mc

${DESTDIR}/etc/mail/submit.cf:	${DESTDIR}/etc/mail/submit.mc
	@( cd ${DESTDIR}/etc/mail && ${MAKE} \
		SENDMAIL_CF_DIR=${PREFIX}/share/sendmail/cf \
		SENDMAIL_MC=submit )

# create basics for smtp-auth
#
howto-sasldb:
	@${ECHO_CMD} "# Links:"
	@${ECHO_CMD} "#"
	@${ECHO_CMD} "# http://www.sendmail.org/~gshapiro/"
	@${ECHO_CMD} "# http://www.sendmail.org/~ca/email/auth.html"
	@${ECHO_CMD} "# http://www.bme.ogi.edu/~pchytil/linux/sendmail/"
	@${ECHO_CMD} "# http://blue-labs.org/software/sm-pgsql/"
	@${ECHO_CMD} "# http://www.falkotimme.com/howtos/sendmail_smtp_auth_tls/"
	@${ECHO_CMD} "#"

# create certificates for TLS/SSL
#
tls-install:
	${SETENV} DESTDIR=${DESTDIR} FILESDIR=${FILESDIR} \
		${SH} ${FILESDIR}/tls-install.sh

help:
	@${ECHO_CMD} "# additional targets:"
	@${ECHO_CMD} "#"
	@${ECHO_CMD} "# configure ${DESTDIR}/etc/mail/mailer.conf"
	@${ECHO_CMD} "# for sendmail from ports"
	@${ECHO_CMD} "make mailer.conf"
	@${ECHO_CMD} "# for sendmail in the base"
	@${ECHO_CMD} "make mailer.base"
	@${ECHO_CMD} "#"
	@${ECHO_CMD} "# show howto for configuring sasldb"
	@${ECHO_CMD} "make howto-sasldb"
	@${ECHO_CMD} "#"
	@${ECHO_CMD} "# create a self-signed certificate"
	@${ECHO_CMD} "make tls-install"
	@${ECHO_CMD} "#"

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTLS}
.if ${SSL_DEFAULT} != base
SITE+=	${FILESDIR}/site.config.m4.ssl
.endif
SITE+=	${FILESDIR}/site.config.m4.tls
.endif

.if exists(${FILESDIR}/site.config.m4.local)
SITE+=	${FILESDIR}/site.config.m4.local
.endif

.if ${PREFIX} == "/usr"
pre-everything::
	@${ECHO_CMD} "#"
	@${ECHO_CMD} "# You can't override the base sendmail this way."
	@${ECHO_CMD} "# your version FreeBSD use mailwrapper."
	@${ECHO_CMD} "#"
	@${ECHO_CMD} "# Please install with normal PREFIX"
	@${ECHO_CMD} "# and activate the port version with"
	@${ECHO_CMD} "# cd ${PORTSDIR}/mail/sendmail && make mailer.conf"
	@${ECHO_CMD} "#"
	@${FALSE}
.endif

.include <bsd.port.post.mk>
