# New ports collection makefile for:	sendmail
# Date created:				20 Apr 2000
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	sendmail
PORTVERSION=	8.11.7
PORTREVISION=	1
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.sendmail.org/pub/sendmail/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/mail/sendmail/&,}
PKGNAMESUFFIX?=	${TLS_SUFFIX}${SFIO_SUFFIX}${SASL_SUFFIX}${LDAP_SUFFIX}${PKGNAMESUFFIX2}
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Reliable, highly configurable mail transfer agent with utilities

CONFLICTS?=	courier-0.* postfix-1.* postfix-2.* smail-3.* zmailer-2.*
CONFLICTS+=	sendmail-8.12.* sendmail-*-8.12.* sendmail+*-8.12.*
CONFLICTS+=	sendmail-8.13.* sendmail-*-8.13.* sendmail+*-8.13.*

NO_CDROM=	please update to a newer version
NO_LATEST_LINK=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
WCONF=		${WRKSRC}/devtools/Site
SITE=		${FILESDIR}/site.config.m4.pre4
PLIST=		${WRKDIR}/.PLIST.more
DOCS=		KNOWNBUGS LICENSE PGPKEYS README RELEASE_NOTES \
		sendmail/TRACEFLAGS
MAN1=		mailq.1 newaliases.1 vacation.1
MAN5=		aliases.5
MAN8=		sendmail.8 mailstats.8 makemap.8 praliases.8 smrsh.8 \
		mail.local.8 rmail.8

# Options to define Features:
# SENDMAIL_WITHOUT_IPV6=yes
# SENDMAIL_WITHOUT_MILTER=yes
# SENDMAIL_WITH_TLS=yes
# SENDMAIL_WITH_SASL=yes
# SENDMAIL_WITH_SFIO=yes
# SENDMAIL_WITH_LDAP=yes

.if defined(SENDMAIL_WITH_LDAP)
LDAP_SUFFIX?=	+ldap
CONFLICTS+=	sendmail+tls-8.* \
		sendmail+tls+sfio-8.* \
		sendmail+tls+sasl-8.* \
		sendmail+tls+sfio+sasl-8.* \
		sendmail+sfio-8.* \
		sendmail+sfio+sasl-8.* \
		sendmail+sasl-8.*
CONFLICTS+=	sendmail-sasl-8.* sendmail-tls-8.*
.if defined(LDAP_PORT)
OPENLDAP_LIB?=	libldap.so.2
BUILD_DEPENDS+=	${LOCALBASE}/lib/${OPENLDAP_LIB}:${PORTSDIR}/${LDAP_PORT}
RUN_DEPENDS+=	${LOCALBASE}/lib/${OPENLDAP_LIB}:${PORTSDIR}/${LDAP_PORT}
.else
USE_OPENLDAP_VER?=	22
.endif
.endif
.if defined(SENDMAIL_WITH_SASL)
SASL_SUFFIX?=	+sasl
CONFLICTS+=	sendmail+tls-8.* \
		sendmail+tls+sfio-8.* \
		sendmail+tls+sfio+ldap-8.* \
		sendmail+tls+ldap-8.* \
		sendmail+sfio-8.* \
		sendmail+sfio+ldap-8.* \
		sendmail+ldap-8.*
CONFLICTS+=	sendmail-ldap-8.* sendmail-tls-8.*
LIB_DEPENDS+=	sasl.8:${PORTSDIR}/security/cyrus-sasl
.endif
.if defined(SENDMAIL_WITH_TLS) || defined(WITH_TLS)
TLS_SUFFIX?=	+tls
CONFLICTS+=	sendmail+sfio-8.* \
		sendmail+sfio+sasl-8.* \
		sendmail+sfio+sasl+ldap-8.* \
		sendmail+sasl-8.* \
		sendmail+sasl+ldap-8.* \
		sendmail+ldap-8.*
CONFLICTS+=	sendmail-sasl-8.* sendmail-ldap-8.*
.endif
.if defined(SENDMAIL_WITH_SFIO)
SFIO_SUFFIX?=	+sfio
BUILD_DEPENDS+=	${LOCALBASE}/lib/libsfio.a:${PORTSDIR}/devel/sfio
.endif

# Build site.config.m4
.if exists(${DESTDIR}/etc/mail/mailer.conf)
SITE+=	${FILESDIR}/site.config.m4
.if ! defined(SENDMAIL_WITHOUT_IPV6)
SITE+=	${FILESDIR}/site.config.m4.ipv6
.endif
.endif
.if defined(SENDMAIL_WITH_SFIO)
SITE+=	${FILESDIR}/site.config.m4.sfio
.endif
.if defined(SENDMAIL_WITH_SASL)
SITE+=	${FILESDIR}/site.config.m4.sasl
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
.endif
PLIST_SUB+=	PREFIX=${PREFIX:S=${PREFIX}/==}
SENDMAIL=	${PREFIX}/sbin/sendmail

do-configure:
	@${MV} ${WRKSRC}/devtools/OS/FreeBSD ${WRKSRC}/devtools/OS/FreeBSD.sed
	${SED} -e "s;\`-pthread\';\`${PTHREAD_LIBS}\';" \
		-e "s;\`-O\';\`${CFLAGS}\';" \
		${WRKSRC}/devtools/OS/FreeBSD.sed \
		> ${WRKSRC}/devtools/OS/FreeBSD
	${SED} -e "s=%%PREFIX%%=${PREFIX}=g" \
		-e "s=%%LOCALBASE%%=${LOCALBASE}=g" \
		${SITE} > ${WCONF}/site.config.m4
.if defined(PARALLEL_PACKAGE_BUILD) || defined(BATCH)
	${ECHO_CMD} \
	 'define(`confNO_HELPFILE_INSTALL'\'',`True'\'')' \
		>> ${WCONF}/site.config.m4
.endif

.if ! defined(SENDMAIL_WITHOUT_MILTER)
post-build:
	( cd ${WRKSRC}/libmilter && ${MAKE} )
.endif

pre-install:
	@${CAT} ${PKGDIR}/pkg-plist >${PLIST}
.if ! defined(SENDMAIL_WITHOUT_MILTER)
	@${CAT} ${FILESDIR}/pkg-milter >>${PLIST}
.endif
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC} && ${FIND} cf -type f | \
	${AWK} '{print "share/sendmail/" $$1}' >>${PLIST}
	@cd ${WRKSRC} && ${FIND} -d cf -type d | \
	${AWK} '{print "@dirrm share/sendmail/" $$1}' >>${PLIST}
	@${ECHO_CMD} "@dirrm share/sendmail" >>${PLIST}
.for i in ${DOCS}
	@${ECHO_CMD} `${BASENAME} ${i}` | \
	${AWK} '{print "share/doc/sendmail/" $$1}' >>${PLIST}
.endfor
	@${ECHO_CMD} "@dirrm share/doc/sendmail" >>${PLIST}
.endif

# We want mail.local and rmail for our system.
# the build install catmans only, we have to fix this.
post-install:
	( cd ${WRKSRC}/mail.local && ${MAKE} force-install )
	( cd ${WRKSRC}/rmail && ${MAKE} force-install )
.if ! defined(SENDMAIL_WITHOUT_MILTER)
	${MKDIR} ${PREFIX}/include/libmilter
	${INSTALL_DATA} ${WRKSRC}/include/libmilter/mfapi.h \
		${PREFIX}/include/libmilter/
	${INSTALL_DATA} \
	 ${WRKSRC}/obj.`${WRKSRC}/devtools/bin/Build -A`/libmilter/libmilter.a \
	 ${WRKSRC}/obj.`${WRKSRC}/devtools/bin/Build -A`/libsmutil/libsmutil.a \
	 ${PREFIX}/lib/
.endif
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
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/sendmail ${DOCSDIR}
	@${TAR} -C ${WRKSRC} -cf - cf | \
		${TAR} -C ${PREFIX}/share/sendmail -xf -
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/devtools/README ${DOCSDIR}/DEVTOOLS
	${INSTALL_DATA} ${WRKSRC}/sendmail/README ${DOCSDIR}/SENDMAIL
	${INSTALL_DATA} ${WRKSRC}/mail.local/README ${DOCSDIR}/MAIL.LOCAL
	${INSTALL_DATA} ${WRKSRC}/smrsh/README ${DOCSDIR}/SMRSH
.if ! defined(SENDMAIL_WITHOUT_MILTER)
	${INSTALL_DATA} ${WRKSRC}/libmilter/README ${DOCSDIR}/MILTER
.endif
.endif
.if exists(${DESTDIR}/etc/mail/mailer.conf)
	@${SED} s!%%PREFIX%%!${PREFIX}!g ${PKGMESSAGE}

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
	@${ECHO_CMD} "# cd /usr/ports/mail/sendmail && make mailer.conf"
	@${ECHO_CMD} "#"
	@${FALSE}
.endif

.include <bsd.port.post.mk>
