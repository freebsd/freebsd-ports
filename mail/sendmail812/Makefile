# New ports collection makefile for:	sendmail
# Date created:				20 Apr 2000
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	sendmail
PORTVERSION=	8.12.11
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.sendmail.org/pub/sendmail/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/mail/sendmail/&,}
PKGNAMESUFFIX?=	${TLS_SUFFIX}${SASL_SUFFIX}${LDAP_SUFFIX}${PKGNAMESUFFIX2}
DISTNAME=	${PORTNAME}.${PORTVERSION}

.if defined(SENDMAIL_WITH_CONNECTION_RATE)
PATCH_SITES=	http://j-chkmail.ensmp.fr/sm/
PATCHFILES=	ratectrl.src-v2.patch ratectrl.cf.patch
.endif

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Reliable, highly configurable mail transfer agent with utilities

CONFLICTS?=	courier-0.* postfix-1.* postfix-2.* smail-3.* zmailer-2.*
CONFLICTS+=	sendmail-8.11.* sendmail-*-8.11.* sendmail+*-8.11.*
CONFLICTS+=	sendmail-8.13.* sendmail-*-8.13.* sendmail+*-8.13.*

NO_LATEST_LINK=	yes
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
LDAP_PORT?=	net/openldap21-client
PKGMESSAGE=	${WRKSRC}/pkg-message

# Options to define Features:
# SENDMAIL_WITHOUT_IPV6=yes
# SENDMAIL_WITHOUT_MILTER=yes
# SENDMAIL_WITHOUT_SHMEM=yes
# SENDMAIL_WITH_TLS=yes
# SENDMAIL_WITH_SMTPS=yes
# SENDMAIL_WITH_SASL=yes
# SENDMAIL_WITH_SASL2=yes
# SENDMAIL_WITH_LDAP=yes
# SENDMAIL_WITH_SOCKETMAP=yes
# SENDMAIL_WITH_CYRUSLOOKUP=yes
# SENDMAIL_WITH_PICKY_HELO_CHECK=yes
# SENDMAIL_WITH_CONNECTION_RATE=yes

.if defined(SENDMAIL_WITH_SMTPS) && !defined(SENDMAIL_WITH_TLS) && !defined(WITH_TLS)
SENDMAIL_WITH_TLS=yes
AUTO_ENABLED_TLS=yes
.endif
.if defined(SENDMAIL_WITH_CYRUSLOOKUP)  && !defined(SENDMAIL_WITH_SOCKETMAP)
SENDMAIL_WITH_SOCKETMAP=yes
AUTO_ENABLED_SOCKETMAP=yes
.endif

.if defined(SENDMAIL_WITH_LDAP)
LDAP_SUFFIX?=	+ldap
CONFLICTS+=	sendmail+tls-8.* \
		sendmail+tls+sasl1-8.* \
		sendmail+tls+sasl2-8.* \
		sendmail+sasl1-8.* \
		sendmail+sasl2-8.*
CONFLICTS+=	sendmail-sasl-8.* sendmail-sasl2-8.* sendmail-tls-8.*
LIB_DEPENDS+=	ldap.2:${PORTSDIR}/${LDAP_PORT}
LIB_DEPENDS+=	lber.2:${PORTSDIR}/${LDAP_PORT}
.else
CONFLICTS+=	sendmail*+ldap*-8.*
.endif
.if defined(SENDMAIL_WITH_SASL) && !defined(SENDMAIL_WITH_SASL2)
SASL_SUFFIX?=	+sasl1
CONFLICTS+=	sendmail+tls-8.* \
		sendmail+tls+ldap-8.* \
		sendmail+tls+sasl2-8.* \
		sendmail+tls+sasl2+ldap-8.* \
		sendmail+sasl2-8.* \
		sendmail+sasl2+ldap-8.* \
		sendmail+ldap-8.*
CONFLICTS+=	sendmail-ldap-8.* sendmail-sasl2-8.* sendmail-tls-8.*
LIB_DEPENDS+=	sasl.8:${PORTSDIR}/security/cyrus-sasl
.else
CONFLICTS+=	sendmail*+sasl1*-8.*
.endif
.if defined(SENDMAIL_WITH_SASL2)
SASL_SUFFIX?=	+sasl2
CONFLICTS+=	sendmail+tls-8.* \
		sendmail+tls+ldap-8.* \
		sendmail+tls+sasl-8.* \
		sendmail+tls+sasl+ldap-8.* \
		sendmail+sasl-8.* \
		sendmail+sasl+ldap-8.* \
		sendmail+ldap-8.*
CONFLICTS+=	sendmail-ldap-8.* sendmail-sasl-8.* sendmail-tls-8.*
LIB_DEPENDS+=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2
.if !defined(SENDMAIL_WITHOUT_SASLAUTHD)
RUN_DEPENDS+=	${LOCALBASE}/sbin/saslauthd:${PORTSDIR}/security/cyrus-sasl2-saslauthd
.endif
.else
CONFLICTS+=	sendmail*+sasl2*-8.*
.endif
.if defined(SENDMAIL_WITH_SOCKETMAP)
EXTRA_PATCHES+=	${FILESDIR}/socketmap.patch
.endif
.if defined(SENDMAIL_WITH_CYRUSLOOKUP)
EXTRA_PATCHES+=	${FILESDIR}/cyruslookup.patch
.endif
.if defined(SENDMAIL_WITH_TLS) || defined(WITH_TLS)
TLS_SUFFIX?=	+tls
CONFLICTS+=	sendmail+sasl-8.* \
		sendmail+sasl+ldap-8.* \
		sendmail+sasl2-8.* \
		sendmail+sasl2+ldap-8.* \
		sendmail+ldap-8.*
CONFLICTS+=	sendmail-ldap-8.* sendmail-sasl-8.* sendmail-sasl2-8.*
.else
CONFLICTS+=	sendmail*+tls*-8.*
.endif

# Build site.config.m4
.if exists(${DESTDIR}/etc/mail/mailer.conf)
SITE+=	${FILESDIR}/site.config.m4
.if ! defined(SENDMAIL_WITHOUT_IPV6)
SITE+=	${FILESDIR}/site.config.m4.ipv6
.endif
.endif
.if defined(SENDMAIL_WITH_SASL)
SITE+=	${FILESDIR}/site.config.m4.sasl
.endif
.if defined(SENDMAIL_WITH_SASL2)
SITE+=	${FILESDIR}/site.config.m4.sasl2
.endif
.if defined(SENDMAIL_WITH_LDAP)
SITE+=	${FILESDIR}/site.config.m4.ldap
.endif
.if ! defined(SENDMAIL_WITHOUT_MILTER)
SITE+=	${FILESDIR}/site.config.m4.milter
.endif
.if defined(SENDMAIL_WITH_TLS) || defined(WITH_TLS)
USE_OPENSSL=	yes
.endif

# install directly if no mailwrapper support
.if ! exists(${DESTDIR}/etc/mail/mailer.conf)
PREFIX?=	${DESTDIR}/usr
MANPREFIX?=	${DESTDIR}/usr/share
PLIST_SUB+=	ETCPORT="@comment "
.else
PLIST_SUB+=	ETCPORT=""
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

pre-configure:
.if defined(AUTO_ENABLED_TLS)
	@${ECHO_CMD} "DEPENDENCY NOTE: SENDMAIL_WITH_TLS will be enabled to support SENDMAIL_WITH_SMTPS"
.endif
.if defined(AUTO_ENABLED_SOCKETMAP)
	@${ECHO_CMD} "DEPENDENCY NOTE: SENDMAIL_WITH_SOCKETMAP will be enabled to support SENDMAIL_WITH_CYRUSLOOKUP"
.endif

do-configure:
	@${MV} ${WRKSRC}/devtools/OS/FreeBSD ${WRKSRC}/devtools/OS/FreeBSD.sed
	${SED} -e "s;\`-pthread\';\`${PTHREAD_LIBS}\';" \
		-e "s;\`-O\';\`${CFLAGS}\';" \
		${WRKSRC}/devtools/OS/FreeBSD.sed \
		> ${WRKSRC}/devtools/OS/FreeBSD
	${SED} -e "s=%%PREFIX%%=${PREFIX}=g" \
		-e "s=%%LOCALBASE%%=${LOCALBASE}=g" \
		${SITE} > ${WCONF}/site.config.m4
.if defined(SENDMAIL_WITH_SMTPS)
	${ECHO_CMD} \
	 'APPENDDEF(`conf_sendmail_ENVDEF'\'', `-D_FFR_SMTP_SSL'\'')' \
		>> ${WCONF}/site.config.m4
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
.if defined(SENDMAIL_WITH_CONNECTION_RATE)
	${ECHO_CMD} \
	 'APPENDDEF(`conf_sendmail_ENVDEF'\'', `-D_FFR_CONNECTION_RATE_CONTROL'\'')' \
		>> ${WCONF}/site.config.m4
.endif
.if defined(SENDMAIL_WITHOUT_SHMEM)
	${ECHO_CMD} \
	 'APPENDDEF(`confENVDEF'\'', `-DSM_CONF_SHM=0'\'')' \
		>> ${WCONF}/site.config.m4
.endif

post-build:
	( cd ${WRKSRC}/doc/op && ${MAKE} op.txt )
.if ! defined(SENDMAIL_WITHOUT_MILTER)
	( cd ${WRKSRC}/libmilter && ${MAKE} )
.endif

pre-install:
	@${CAT} ${PKGDIR}/pkg-plist >${PLIST}
.if ! defined(SENDMAIL_WITHOUT_MILTER)
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
.if defined(SENDMAIL_WITH_CONNECTION_RATE)
	@${ECHO_CMD} "share/doc/sendmail/CONNECTION_RATE_CONTROL" >>${PLIST}
.endif
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
.if ! defined(SENDMAIL_WITHOUT_MILTER)
	${MKDIR} ${PREFIX}/include/libmilter
	${INSTALL_DATA} ${WRKSRC}/include/libmilter/mfapi.h \
		${WRKSRC}/include/libmilter/mfdef.h \
		${PREFIX}/include/libmilter/
	${INSTALL_DATA} \
	 ${WRKSRC}/obj.`${WRKSRC}/devtools/bin/Build -A`/libmilter/libmilter.a \
	 ${PREFIX}/lib/
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
.if ! defined(SENDMAIL_WITHOUT_MILTER)
	${INSTALL_DATA} ${WRKSRC}/libmilter/README ${DOCSDIR}/MILTER
	${MKDIR} ${DOCSDIR}/libmilter
	@${TAR} -C ${WRKSRC}/libmilter/docs -cf - . | \
		${TAR} -C ${DOCSDIR}/libmilter -xf -
.endif
.if defined(SENDMAIL_WITH_CONNECTION_RATE)
	${INSTALL_DATA} ${FILESDIR}/CONNECTION_RATE_CONTROL \
		 ${DOCSDIR}/CONNECTION_RATE_CONTROL
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
	@${ECHO_CMD} "# http://www.asp.ogi.edu/people/paja/linux/sendmail/"
	@${ECHO_CMD} "# http://blue-labs.org/clue/sendmail.php"
	@${ECHO_CMD} "# http://www.digitalanswers.org/sendmail/"
	@${ECHO_CMD} "#"

# create certificates for TLS/SSL
#
tls-install:
	${SETENV} DESTDIR=${DESTDIR} FILESDIR=${FILESDIR} \
		${SH} ${FILESDIR}/tls-install.sh

.include <bsd.port.pre.mk>

.if defined(SENDMAIL_WITH_TLS) || defined(WITH_TLS)
.if ! defined(WITH_OPENSSL_BASE)
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
