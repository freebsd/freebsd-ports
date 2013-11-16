# $FreeBSD$

PORTNAME=	sendmail
PORTVERSION=	8.14.7
PORTREVISION=	1
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.sendmail.org/pub/sendmail/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/mail/sendmail/&,}
PKGNAMESUFFIX?=	${TLS_SUFFIX}${SASL_SUFFIX}${LDAP_SUFFIX}${BDB_SUFFIX}${PKGNAMESUFFIX2}
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Reliable, highly configurable mail transfer agent with utilities

CONFLICTS?=	courier-0.* postfix-1.* postfix-2.* smail-3.* zmailer-2.* opensmtpd-*
NO_STAGE=	yes

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
MILTER_SOVER?=	6

OPTIONS_DEFINE?=	SHMEM SEM LA NIS IPV6 TLS SASL SASLAUTHD LDAP BDB SOCKETMAP CYRUSLOOKUP PICKY_HELO_CHECK MILTER MILTER_SHARED MILTER_POOL
OPTIONS_DEFAULT?=	SHMEM SEM LA NIS IPV6 PICKY_HELO_CHECK MILTER MILTER_SHARED MILTER_POOL
NO_OPTIONS_SORT=yes
SHMEM_DESC=		System V shared memory support
LA_DESC=		load averages support
TLS_DESC=		SMTP-TLS and SMTPS support
SASLAUTHD_DESC=		SASLAUTHD support
BDB_DESC=		Berkeley DB version 4 support
SOCKETMAP_DESC=		Enable socketmap feature
CYRUSLOOKUP_DESC=	Enable cyruslookup feature
PICKY_HELO_CHECK_DESC=	Enable picky HELO check
MILTER_DESC=		Build libmilter
MILTER_SHARED_DESC=	Build shared libmilter
MILTER_POOL_DESC=	Enable milter thread pools

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSHMEM} && !defined(BUILDING_INDEX)
IPCCHECK!=	ipcrm -q 0 2>&1 || true
.if ${IPCCHECK:Mimplemented}
IGNORE=		your system does not support sysvipc
.endif
.endif

.if ${PORT_OPTIONS:MBDB}
USE_BDB=	yes
BDB_SUFFIX=	+${BDB_INCLUDE_DIR:S,^${LOCALBASE}/include/,,}
CONFLICTS+=	sendmail-ldap-8.* sendmail-sasl-8.* sendmail-sasl2-8.* sendmail-tls-8.*
.endif
.if ${PORT_OPTIONS:MLDAP}
LDAP_SUFFIX?=	+ldap
CONFLICTS+=	sendmail-sasl-8.* sendmail-sasl2-8.* sendmail-tls-8.*
USE_OPENLDAP=	yes
.endif
.if ${PORT_OPTIONS:MSASL}
SASL_SUFFIX?=	+sasl2
CONFLICTS+=	sendmail-ldap-8.* sendmail-sasl-8.* sendmail-tls-8.*
LIB_DEPENDS+=	sasl2:${PORTSDIR}/security/cyrus-sasl2
.if ${PORT_OPTIONS:MSASLAUTHD}
RUN_DEPENDS+=	${LOCALBASE}/sbin/saslauthd:${PORTSDIR}/security/cyrus-sasl2-saslauthd
.endif
.endif
.if ${PORT_OPTIONS:MCYRUSLOOKUP}
.if ! ${PORT_OPTIONS:MSOCKETMAP}
IGNORE=		option CYRUSLOOKUP requires option SOCKETMAP
.else
EXTRA_PATCHES+=	${FILESDIR}/cyruslookup.patch
.endif
.endif
.if ${PORT_OPTIONS:MTLS}
TLS_SUFFIX?=	+tls
CONFLICTS+=	sendmail-ldap-8.* sendmail-sasl-8.* sendmail-sasl2-8.*
.endif

MAKE_PKGNAMES=	for i in "" +tls; do \
	for j in "" +sasl +sasl1 +sasl2; do \
	for k in "" +ldap; do \
	for l in "" +db2 +db3 +db4 +db41 +db42 +db43 +db44 +db45 +db46 +db47 +db48 +db49; do \
	echo "sendmail$${i}$${j}$${k}$${l}-8.*" ;\
	done done done done

ALL_PKGNAMES!=	${MAKE_PKGNAMES}
CONFLICTS2!=	${MAKE_PKGNAMES} | grep -v "${PORTNAME}${PKGNAMESUFFIX}-8."
CONFLICTS+=	${CONFLICTS2}

# Build site.config.m4
.if exists(${DESTDIR}/etc/mail/mailer.conf)
SITE+=	${FILESDIR}/site.config.m4
.endif
.if ${PORT_OPTIONS:MIPV6}
SITE+=	${FILESDIR}/site.config.m4.ipv6
.endif
.if ${PORT_OPTIONS:MSASL}
SITE+=	${FILESDIR}/site.config.m4.sasl2
.endif
.if ${PORT_OPTIONS:MLDAP}
SITE+=	${FILESDIR}/site.config.m4.ldap
.endif
.if ${PORT_OPTIONS:MMILTER}
SITE+=	${FILESDIR}/site.config.m4.milter
.endif
.if ${PORT_OPTIONS:MTLS}
USE_OPENSSL=	yes
.endif

# install directly if no mailwrapper support
.if ! exists(${DESTDIR}/etc/mail/mailer.conf)
PREFIX?=	/usr
MANPREFIX?=	/usr/share
.endif

.if ${PORT_OPTIONS:MMILTER}
.if ${PORT_OPTIONS:MMILTER_SHARED}
PLIST_SUB+=	MILTER_SHARED=""
PLIST_SUB+=	MILTER_SOVER=${MILTER_SOVER}
MAKE_ENV+=	MILTER_SOVER=${MILTER_SOVER}
.else
PLIST_SUB+=	MILTER_SHARED="@comment "
.endif
.endif

SED_SCRIPT=	-e "s|\`-pthread\'|\`${PTHREAD_LIBS}\'|" \
		-e "s|\`-O\'|\`${CFLAGS}\'|" \
		-e 's|%%CC%%|${CC}|' -e 's|%%LD%%|${LD}|'

.if ! ${PORT_OPTIONS:MNIS}
SED_SCRIPT+=	-e "s;-DNIS ;;"
.endif

post-patch:
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=g" \
		-e "s=%%LOCALBASE%%=${LOCALBASE}=g" \
		-e "s=%%PORTSDIR%%=${PORTSDIR}=g" \
		${PKGDIR}/pkg-message > ${WRKSRC}/pkg-message
.if ${PORT_OPTIONS:MMILTER} && ${PORT_OPTIONS:MMILTER_SHARED}
	@${CP} -pR ${WRKSRC}/libmilter ${WRKSRC}/libsharedmilter
	${CP} ${FILESDIR}/sharedlibrary.m4 \
		${WRKSRC}/devtools/M4/UNIX/sharedlibrary.m4
	${REINPLACE_CMD} -e 's=`library=`sharedlibrary=' \
		${WRKSRC}/libsharedmilter/Makefile.m4
.endif

do-configure:
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
.if ${PORT_OPTIONS:MMILTER} && ${PORT_OPTIONS:MMILTER_POOL} 
	${ECHO_CMD} \
	 'APPENDDEF(`conf_libmilter_ENVDEF'\'', `-DSM_CONF_POLL=1'\'')' \
		>> ${WCONF}/site.config.m4
	${ECHO_CMD} \
	 'APPENDDEF(`conf_libmilter_ENVDEF'\'', `-D_FFR_WORKERS_POOL=1'\'')' \
		>> ${WCONF}/site.config.m4
.endif

post-build:
	( cd ${WRKSRC}/doc/op && ${MAKE} op.txt )
.if ${PORT_OPTIONS:MMILTER}
	@(cd ${BUILD_WRKSRC}/libmilter; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.if ${PORT_OPTIONS:MMILTER_SHARED}
	@(cd ${BUILD_WRKSRC}/libsharedmilter; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.endif
.endif

pre-install:
	@${CAT} ${PKGDIR}/pkg-plist >${PLIST}
.if ${PORT_OPTIONS:MMILTER}
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
.if ${PORT_OPTIONS:MDOCS}
.for i in ${DOCS}
	@${ECHO_CMD} `${BASENAME} ${i}` | \
	${AWK} '{print "%%DOCSDIR%%/" $$1}' >>${PLIST}
.endfor
.if ${PORT_OPTIONS:MCYRUSLOOKUP}
	@${ECHO_CMD} "share/doc/sendmail/CYRUS_LOOKUP" >>${PLIST}
.endif
	@${ECHO_CMD} "@dirrm %%DOCSDIR%%" >>${PLIST}
.endif

# We want mail.local and rmail for our system.
# the build install catmans only, we have to fix this.
post-install:
	( cd ${WRKSRC}/mail.local && ${MAKE} force-install )
	( cd ${WRKSRC}/rmail && ${MAKE} force-install )
.if ${PORT_OPTIONS:MMILTER}
	${MKDIR} ${PREFIX}/include/libmilter
	${INSTALL_DATA} ${WRKSRC}/include/libmilter/mfapi.h \
		${WRKSRC}/include/libmilter/mfdef.h \
		${PREFIX}/include/libmilter/
	${INSTALL_DATA} \
	 ${WRKSRC}/obj.`${WRKSRC}/devtools/bin/Build -A`/libmilter/libmilter.a \
	 ${PREFIX}/lib/
.if ${PORT_OPTIONS:MMILTER_SHARED}
	${INSTALL_SCRIPT} \
	 ${WRKSRC}/obj.`${WRKSRC}/devtools/bin/Build -A`/libsharedmilter/libmilter.so \
	 ${PREFIX}/lib/libmilter.so.${MILTER_SOVER}
	${LN} -sf libmilter.so.${MILTER_SOVER} ${PREFIX}/lib/libmilter.so
.endif
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
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/op/op.ps ${DOCSDIR}/op.ps
	${INSTALL_DATA} ${WRKSRC}/doc/op/op.txt ${DOCSDIR}/op.txt
	${INSTALL_DATA} ${WRKSRC}/devtools/README ${DOCSDIR}/DEVTOOLS
	${INSTALL_DATA} ${WRKSRC}/sendmail/README ${DOCSDIR}/SENDMAIL
	${INSTALL_DATA} ${WRKSRC}/mail.local/README ${DOCSDIR}/MAIL.LOCAL
	${INSTALL_DATA} ${WRKSRC}/smrsh/README ${DOCSDIR}/SMRSH
.if ${PORT_OPTIONS:MMILTER}
	${INSTALL_DATA} ${WRKSRC}/libmilter/README ${DOCSDIR}/MILTER
	${MKDIR} ${DOCSDIR}/libmilter
	@${TAR} -C ${WRKSRC}/libmilter/docs -cf - . | \
		${TAR} -C ${DOCSDIR}/libmilter -xf -
.endif
.if ${PORT_OPTIONS:MCYRUSLOOKUP}
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

.if ${PORT_OPTIONS:MTLS}
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
