# New ports collection makefile for:	sendmail
# Date created:				20 Apr 2000
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	sendmail
PORTVERSION=	8.14.3
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.sendmail.org/pub/sendmail/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/mail/sendmail/&,}
PKGNAMESUFFIX?=	${TLS_SUFFIX}${SASL_SUFFIX}${LDAP_SUFFIX}${BERKELEYDB_SUFFIX}${PKGNAMESUFFIX2}
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Reliable, highly configurable mail transfer agent with utilities

CONFLICTS?=	courier-0.* postfix-1.* postfix-2.* smail-3.* zmailer-2.*

.if !defined(SENDMAIL_WITHOUT_SHMEM) && !defined(BUILDING_INDEX)
IPCCHECK!=	ipcrm -q 0 2>&1 || true
.if ${IPCCHECK:Mimplemented}
IGNORE=		your system does not support sysvipc
.endif
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
WCONF=		${WRKSRC}/devtools/Site
SITE=		${FILESDIR}/site.config.m4.pre4
PLIST=		${WRKDIR}/.PLIST.more
DOCS=		KNOWNBUGS LICENSE PGPKEYS README RELEASE_NOTES \
		sendmail/TRACEFLAGS sendmail/SECURITY sendmail/TUNING
MAN1=		mailq.1 newaliases.1 vacation.1
MAN5=		aliases.5
MAN8=		sendmail.8 mailstats.8 makemap.8 praliases.8 smrsh.8 \
		mail.local.8 rmail.8 editmap.8
SENDMAIL=	${PREFIX}/sbin/sendmail
BASEMAIL=	/usr/libexec/sendmail/sendmail
PLIST_SUB+=	PREFIX=${PREFIX:S=${PREFIX}/==}
PKGMESSAGE=	${WRKSRC}/pkg-message
MILTER_SOVER?=	4

# Options to define Features:
# SENDMAIL_WITHOUT_IPV6=yes
# SENDMAIL_WITHOUT_MILTER=yes
# SENDMAIL_WITHOUT_NIS=yes
# SENDMAIL_WITHOUT_SHMEM=yes
# SENDMAIL_WITHOUT_SEM=yes
# SENDMAIL_WITHOUT_LA=yes
# SENDMAIL_WITHOUT_MILTER_POOL
# SENDMAIL_WITH_TLS=yes
# SENDMAIL_WITH_SMTPS=yes
# SENDMAIL_WITH_SASL=yes
# SENDMAIL_WITH_SASL2=yes
# SENDMAIL_WITH_LDAP=yes
# SENDMAIL_WITH_BERKELEYDB=yes
#   Set either WITH_BDB_VER or SENDMAIL_WITH_BDB_VER
#   to the version of Berkeley DB to use.
# SENDMAIL_WITH_SOCKETMAP=yes
# SENDMAIL_WITH_CYRUSLOOKUP=yes
# SENDMAIL_WITH_PICKY_HELO_CHECK=yes
# SENDMAIL_WITH_SHARED_MILTER=yes

.if defined(SENDMAIL_WITH_SMTPS) && !defined(SENDMAIL_WITH_TLS) && !defined(WITH_TLS)
SENDMAIL_WITH_TLS=yes
AUTO_ENABLED_TLS=yes
.endif
.if defined(SENDMAIL_WITH_CYRUSLOOKUP)  && !defined(SENDMAIL_WITH_SOCKETMAP)
SENDMAIL_WITH_SOCKETMAP=yes
AUTO_ENABLED_SOCKETMAP=yes
.endif

.if defined(SENDMAIL_WITH_BERKELEYDB_VER)
SENDMAIL_WITH_BERKELEYDB=	yes
OBSOLETE_BDB_VAR=	SENDMAIL_WITH_BERKELEYDB_VER BERKELEYDB_PORT \
	BERKELEYDB_LIB BERKELEYDB_INCLUDE
IGNORE=	use SENDMAIL_WITH_BERKELEYDB to select Berkeley DB
.endif

.if defined(SENDMAIL_WITH_BDB_VER)
SENDMAIL_WITH_BERKELEYDB=	yes
.endif

.if defined(SENDMAIL_WITH_BERKELEYDB)
USE_BDB=	yes
BERKELEYDB_SUFFIX=	+${BDB_INCLUDE_DIR:S,^${LOCALBASE}/include/,,}
CONFLICTS+=	sendmail-ldap-8.* sendmail-sasl-8.* sendmail-sasl2-8.* sendmail-tls-8.*
.endif
.if defined(SENDMAIL_WITH_LDAP)
LDAP_SUFFIX?=	+ldap
CONFLICTS+=	sendmail-sasl-8.* sendmail-sasl2-8.* sendmail-tls-8.*
USE_OPENLDAP=	yes
.endif
.if defined(SENDMAIL_WITH_SASL) && !defined(SENDMAIL_WITH_SASL2)
SENDMAIL_WITH_SASL2=	yes
.endif
.if defined(SENDMAIL_WITH_SASL2)
SASL_SUFFIX?=	+sasl2
CONFLICTS+=	sendmail-ldap-8.* sendmail-sasl-8.* sendmail-tls-8.*
LIB_DEPENDS+=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2
.if !defined(SENDMAIL_WITHOUT_SASLAUTHD)
RUN_DEPENDS+=	${LOCALBASE}/sbin/saslauthd:${PORTSDIR}/security/cyrus-sasl2-saslauthd
.endif
.endif
.if defined(SENDMAIL_WITH_CYRUSLOOKUP)
EXTRA_PATCHES+=	${FILESDIR}/cyruslookup.patch
.endif
.if defined(SENDMAIL_WITH_TLS) || defined(WITH_TLS)
TLS_SUFFIX?=	+tls
CONFLICTS+=	sendmail-ldap-8.* sendmail-sasl-8.* sendmail-sasl2-8.*
.endif

MAKE_PKGNAMES=	for i in "" +tls; do \
	for j in "" +sasl +sasl1 +sasl2; do \
	for k in "" +ldap; do \
	for l in "" +db2 +db3 +db4 +db41 +db42 +db43 +db44; do \
	echo "sendmail$${i}$${j}$${k}$${l}-8.*" ;\
	done done done done

ALL_PKGNAMES!=	${MAKE_PKGNAMES}
CONFLICTS2!=	${MAKE_PKGNAMES} | grep -v "${PORTNAME}${PKGNAMESUFFIX}-8."
CONFLICTS+=	${CONFLICTS2}

# Build site.config.m4
.if exists(${DESTDIR}/etc/mail/mailer.conf)
SITE+=	${FILESDIR}/site.config.m4
.endif
.if !defined(SENDMAIL_WITHOUT_IPV6)
SITE+=	${FILESDIR}/site.config.m4.ipv6
.endif
.if defined(SENDMAIL_WITH_SASL2)
SITE+=	${FILESDIR}/site.config.m4.sasl2
.endif
.if defined(SENDMAIL_WITH_LDAP)
SITE+=	${FILESDIR}/site.config.m4.ldap
.endif
.if !defined(SENDMAIL_WITHOUT_MILTER)
SITE+=	${FILESDIR}/site.config.m4.milter
.endif
.if defined(SENDMAIL_WITH_TLS) || defined(WITH_TLS)
USE_OPENSSL=	yes
.endif

# install directly if no mailwrapper support
.if ! exists(${DESTDIR}/etc/mail/mailer.conf)
PREFIX?=	/usr
MANPREFIX?=	/usr/share
PLIST_SUB+=	ETCPORT="@comment "
.else
PLIST_SUB+=	ETCPORT=""
.endif

.if !defined(SENDMAIL_WITHOUT_MILTER)
.if defined(SENDMAIL_WITH_SHARED_MILTER)
PLIST_SUB+=	MILTER_SHARED=""
PLIST_SUB+=	MILTER_SOVER=${MILTER_SOVER}
MAKE_ENV+=	MILTER_SOVER=${MILTER_SOVER}
.else
PLIST_SUB+=	MILTER_SHARED="@comment "
.endif
.endif

SED_SCRIPT=	-e "s;\`-pthread\';\`${PTHREAD_LIBS}\';" \
		-e "s;\`-O\';\`${CFLAGS}\';"

.if defined(SENDMAIL_WITHOUT_NIS)
SED_SCRIPT+=	-e "s;-DNIS ;;"
.endif

post-extract:
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=" ${FILESDIR}/sm-client.sh \
		> ${WRKSRC}/sm-client.sh
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=" ${FILESDIR}/sendmail.sh \
		> ${WRKSRC}/sendmail.sh
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=g" \
		-e "s=%%LOCALBASE%%=${LOCALBASE}=g" \
		-e "s=%%PORTSDIR%%=${PORTSDIR}=g" \
		${PKGDIR}/pkg-message > ${WRKSRC}/pkg-message
.if !defined(SENDMAIL_WITHOUT_MILTER) && defined(SENDMAIL_WITH_SHARED_MILTER)
	@${CP} -pR ${WRKSRC}/libmilter ${WRKSRC}/libsharedmilter
	${CP} ${FILESDIR}/sharedlibrary.m4 \
		${WRKSRC}/devtools/M4/UNIX/sharedlibrary.m4
	@${MV} ${WRKSRC}/libsharedmilter/Makefile.m4 \
		${WRKSRC}/libsharedmilter/Makefile.m4.sed
	@${SED} -e 's=`library=`sharedlibrary=' \
		${WRKSRC}/libsharedmilter/Makefile.m4.sed \
		> ${WRKSRC}/libsharedmilter/Makefile.m4
.endif

pre-configure:
.if defined(AUTO_ENABLED_TLS)
	@${ECHO_CMD} "DEPENDENCY NOTE: SENDMAIL_WITH_TLS will be enabled to support SENDMAIL_WITH_SMTPS"
.endif
.if defined(AUTO_ENABLED_SOCKETMAP)
	@${ECHO_CMD} "DEPENDENCY NOTE: SENDMAIL_WITH_SOCKETMAP will be enabled to support SENDMAIL_WITH_CYRUSLOOKUP"
.endif

do-configure:
	@${MV} ${WRKSRC}/devtools/OS/FreeBSD ${WRKSRC}/devtools/OS/FreeBSD.sed
	${SED} ${SED_SCRIPT} ${WRKSRC}/devtools/OS/FreeBSD.sed \
		> ${WRKSRC}/devtools/OS/FreeBSD
	${SED} -e "s=%%PREFIX%%=${PREFIX}=g" \
		-e "s=%%LOCALBASE%%=${LOCALBASE}=g" \
		${SITE} > ${WCONF}/site.config.m4
.if defined(SENDMAIL_WITH_BERKELEYDB)
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
.if defined(SENDMAIL_WITH_SOCKETMAP)
	${ECHO_CMD} \
	 'APPENDDEF(`conf_sendmail_ENVDEF'\'', `-DSOCKETMAP'\'')' \
		>> ${WCONF}/site.config.m4
.endif
.if defined(SENDMAIL_WITH_PICKY_HELO_CHECK)
	${ECHO_CMD} \
	 'APPENDDEF(`conf_sendmail_ENVDEF'\'', `-DPICKY_HELO_CHECK'\'')' \
		>> ${WCONF}/site.config.m4
.endif
.if defined(SENDMAIL_WITHOUT_SHMEM)
	${ECHO_CMD} \
	 'APPENDDEF(`confENVDEF'\'', `-DSM_CONF_SHM=0'\'')' \
		>> ${WCONF}/site.config.m4
.endif
.if defined(SENDMAIL_WITHOUT_SEM)
	${ECHO_CMD} \
	'APPENDDEF(`confENVDEF'\'', `-DSM_CONF_SEM=0'\'')' \
		>> ${WCONF}/site.config.m4
.endif
.if defined(SENDMAIL_WITHOUT_LA)
	${ECHO_CMD} \
	'APPENDDEF(`confENVDEF'\'', `-DLA_TYPE=LA_ZERO'\'')' \
		>> ${WCONF}/site.config.m4
.endif
.if !defined(SENDMAIL_WITHOUT_MILTER) && !defined(SENDMAIL_WITHOUT_MILTER_POOL)
	${ECHO_CMD} \
	 'APPENDDEF(`conf_libmilter_ENVDEF'\'', `-DSM_CONF_POLL=1'\'')' \
		>> ${WCONF}/site.config.m4
	${ECHO_CMD} \
	 'APPENDDEF(`conf_libmilter_ENVDEF'\'', `-D_FFR_WORKERS_POOL=1'\'')' \
		>> ${WCONF}/site.config.m4
.endif

post-build:
	( cd ${WRKSRC}/doc/op && ${MAKE} op.txt )
.if !defined(SENDMAIL_WITHOUT_MILTER)
	@(cd ${BUILD_WRKSRC}/libmilter; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.if defined(SENDMAIL_WITH_SHARED_MILTER)
	@(cd ${BUILD_WRKSRC}/libsharedmilter; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.endif
.endif

pre-install:
	@${CAT} ${PKGDIR}/pkg-plist >${PLIST}
.if !defined(SENDMAIL_WITHOUT_MILTER)
	@${CAT} ${FILESDIR}/pkg-milter >>${PLIST}
.endif
	if ! pw groupshow smmsp; then pw groupadd smmsp -g 25; fi
	if ! pw usershow smmsp; then pw useradd smmsp -g smmsp -u 25 \
		-h - -d /nonexistent -s /nonexistent -c "Sendmail Queue"; fi
	@cd ${WRKSRC} && ${FIND} cf -type f | \
	${AWK} '{print "share/sendmail/" $$1}' >>${PLIST}
	@cd ${WRKSRC} && ${FIND} -d cf -type d | \
	${AWK} '{print "@dirrm share/sendmail/" $$1}' >>${PLIST}
	@${ECHO_CMD} "@dirrm share/sendmail" >>${PLIST}
.if !defined(NOPORTDOCS)
.for i in ${DOCS}
	@${ECHO_CMD} `${BASENAME} ${i}` | \
	${AWK} '{print "%%DOCSDIR%%/" $$1}' >>${PLIST}
.endfor
.if defined(SENDMAIL_WITH_CYRUSLOOKUP)
	@${ECHO_CMD} "share/doc/sendmail/CYRUS_LOOKUP" >>${PLIST}
.endif
	@${ECHO_CMD} "@dirrm %%DOCSDIR%%" >>${PLIST}
.endif

# We want mail.local and rmail for our system.
# the build install catmans only, we have to fix this.
post-install:
	( cd ${WRKSRC}/mail.local && ${MAKE} force-install )
	( cd ${WRKSRC}/rmail && ${MAKE} force-install )
.if !defined(SENDMAIL_WITHOUT_MILTER)
	${MKDIR} ${PREFIX}/include/libmilter
	${INSTALL_DATA} ${WRKSRC}/include/libmilter/mfapi.h \
		${WRKSRC}/include/libmilter/mfdef.h \
		${PREFIX}/include/libmilter/
	${INSTALL_DATA} \
	 ${WRKSRC}/obj.`${WRKSRC}/devtools/bin/Build -A`/libmilter/libmilter.a \
	 ${PREFIX}/lib/
.if defined(SENDMAIL_WITH_SHARED_MILTER)
	${INSTALL_SCRIPT} \
	 ${WRKSRC}/obj.`${WRKSRC}/devtools/bin/Build -A`/libsharedmilter/libmilter.so \
	 ${PREFIX}/lib/libmilter.so.${MILTER_SOVER}
	${LN} -sf libmilter.so.${MILTER_SOVER} ${PREFIX}/lib/libmilter.so
.endif
.endif
.if exists(${DESTDIR}/etc/mail/mailer.conf)
	${INSTALL_SCRIPT} ${WRKSRC}/sm-client.sh \
		${LOCALBASE}/etc/rc.d/sm-client.sh.sample
	${INSTALL_SCRIPT} ${WRKSRC}/sendmail.sh \
		${LOCALBASE}/etc/rc.d/sendmail.sh.sample
.endif
	${CHOWN} smmsp:smmsp /var/spool/clientmqueue
	${CHMOD} 770 /var/spool/clientmqueue
.for i in ${MAN8}
	@${RM} -f ${MANPREFIX}/man/cat8/${i} ${MANPREFIX}/man/cat8/${i}.gz
	${INSTALL_MAN} ${WRKSRC}/*/${i} ${MANPREFIX}/man/man8
.endfor
.for i in ${MAN5}
	@${RM} -f ${MANPREFIX}/man/cat5/${i} ${MANPREFIX}/man/cat5/${i}.gz
	${INSTALL_MAN} ${WRKSRC}/*/${i} ${MANPREFIX}/man/man5
.endfor
.for i in ${MAN1}
	@${RM} -f ${MANPREFIX}/man/cat1/${i} ${MANPREFIX}/man/cat1/${i}.gz
	${INSTALL_MAN} ${WRKSRC}/*/${i} ${MANPREFIX}/man/man1
.endfor
	${MKDIR} ${PREFIX}/share/sendmail
	@${TAR} -C ${WRKSRC} -cf - cf | \
		${TAR} -C ${PREFIX}/share/sendmail -xf -
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/op/op.ps ${DOCSDIR}/op.ps
	${INSTALL_DATA} ${WRKSRC}/doc/op/op.txt ${DOCSDIR}/op.txt
	${INSTALL_DATA} ${WRKSRC}/devtools/README ${DOCSDIR}/DEVTOOLS
	${INSTALL_DATA} ${WRKSRC}/sendmail/README ${DOCSDIR}/SENDMAIL
	${INSTALL_DATA} ${WRKSRC}/mail.local/README ${DOCSDIR}/MAIL.LOCAL
	${INSTALL_DATA} ${WRKSRC}/smrsh/README ${DOCSDIR}/SMRSH
.if !defined(SENDMAIL_WITHOUT_MILTER)
	${INSTALL_DATA} ${WRKSRC}/libmilter/README ${DOCSDIR}/MILTER
	${MKDIR} ${DOCSDIR}/libmilter
	@${TAR} -C ${WRKSRC}/libmilter/docs -cf - . | \
		${TAR} -C ${DOCSDIR}/libmilter -xf -
.endif
.if defined(SENDMAIL_WITH_CYRUSLOOKUP)
	${INSTALL_DATA} ${FILESDIR}/CYRUS_LOOKUP ${DOCSDIR}/CYRUS_LOOKUP
.endif
.endif
.if exists(${DESTDIR}/etc/mail/mailer.conf)
	@${CAT} ${PKGMESSAGE}

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
.endif

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

.if defined(SENDMAIL_WITH_TLS) || defined(WITH_TLS)
.if !defined(WITH_OPENSSL_BASE)
SITE+=	${FILESDIR}/site.config.m4.ssl
.endif
SITE+=	${FILESDIR}/site.config.m4.tls
.endif

.if exists(${FILESDIR}/site.config.m4.local)
SITE+=	${FILESDIR}/site.config.m4.local
.endif

.if exists(${DESTDIR}/etc/mail/mailer.conf) && ${PREFIX} == "/usr"
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
