# New ports collection makefile for:	sendmail
# Date created:				20 Apr 2000
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	sendmail
PORTVERSION=	8.11.3
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.sendmail.org/pub/sendmail/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	dirk.meyer@dinoex.sub.org

NO_PACKAGE=	"sendmail included in base system"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
WCONF=		${WRKSRC}/devtools/Site
PLIST=		${WRKDIR}/.PLIST.more

# Options to define Features:
#
# SENDMAIL_WITH_TLS=YES
# SENDMAIL_WITH_SASL=YES
# SENDMAIL_WITH_SFIO=YES
# SENDMAIL_WITH_MILTER=YES

.if defined(SENDMAIL_WITH_TLS)
USE_OPENSSL=	yes
.endif
.if defined(SENDMAIL_WITH_SASL)
BUILD_DEPENDS=	${LOCALBASE}/sbin/pwcheck:${PORTSDIR}/security/cyrus-sasl
.endif
.if defined(SENDMAIL_WITH_SFIO)
BUILD_DEPENDS=	${LOCALBASE}/lib/libsfio.a:${PORTSDIR}/devel/sfio
.endif

.if exists(${DESTDIR}/etc/mail/mailer.conf)
pre-configure:
	${SED} -e "s=%%PREFIX%%=${PREFIX}=" \
		${FILESDIR}/site.config.m4 > ${WCONF}/site.config.m4
.if defined(SENDMAIL_WITH_TLS)
	${CAT} ${FILESDIR}/site.config.m4.tls >> ${WCONF}/site.config.m4
.endif
.if defined(SENDMAIL_WITH_SASL)
	${SED} -e "s=%%LOCALBASE%%=${LOCALBASE}=" \
		${FILESDIR}/site.config.m4.sasl >>${WCONF}/site.config.m4
.endif
.if defined(SENDMAIL_WITH_SFIO)
	${SED} -e "s=%%LOCALBASE%%=${LOCALBASE}=" \
		${FILESDIR}/site.config.m4.sfio >>${WCONF}/site.config.m4
.endif
.else
pre-configure:
	${SED} -e "s=%%PREFIX%%=${PREFIX}=" \
		${FILESDIR}/site.config.m4.pre4 > ${WCONF}/site.config.m4
.if defined(SENDMAIL_WITH_TLS)
	${SED} -e "s=%%LOCALBASE%%=${LOCALBASE}=" \
		${FILESDIR}/site.config.m4.ssl >> ${WCONF}/site.config.m4
.endif
.if exists(${FILESDIR}/site.config.m4.local)
	${SED} -e "s=%%LOCALBASE%%=${LOCALBASE}=" \
		${FILESDIR}/site.config.m4.local >> ${WCONF}/site.config.m4
.endif

PREFIX?=	${DESTDIR}/usr
MANPREFIX?=	${DESTDIR}/usr/share
.endif

PLIST_SUB+=	PREFIX=${PREFIX:S=${PREFIX}/==}
SENDMAIL=	${PREFIX}/sbin/sendmail

MAN1=	mailq.1 newaliases.1 vacation.1
MAN5=	aliases.5
MAN8=	sendmail.8 mailstats.8 makemap.8 praliases.8 smrsh.8 \
	mail.local.8 rmail.8

pre-install:
	@${CAT} ${PKGDIR}/pkg-plist >${PLIST}
.if defined(SENDMAIL_WITH_MILTER)
	@${CAT} ${FILESDIR}/pkg-milter >>${PLIST}
.endif
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC} && find cf -type f | \
	${AWK} '{print "share/sendmail/" $$1}' >>${PLIST}
	@cd ${WRKSRC} && find -d cf -type d | \
	${AWK} '{print "@dirrm share/sendmail/" $$1}' >>${PLIST}
	@${ECHO} "@dirrm share/sendmail" >>${PLIST}
.endif

.if defined(SENDMAIL_WITH_MILTER)
post-configure:
	${CAT} ${FILESDIR}/site.config.m4.milter >>${WCONF}/site.config.m4

post-build:
	( cd ${WRKSRC}/libmilter && ${MAKE} )
.endif

# We want mail.local and rmail for our system.
# the build install catmans only, we have to fix this.
post-install:
	( cd ${WRKSRC}/mail.local && ${MAKE} force-install )
	( cd ${WRKSRC}/rmail && ${MAKE} force-install )
.if defined(SENDMAIL_WITH_MILTER)
	${MKDIR} ${PREFIX}/include/libmilter
	${INSTALL_DATA} ${WRKSRC}/include/libmilter/mfapi.h \
		${PREFIX}/include/libmilter/
	${INSTALL_DATA} \
	 ${WRKSRC}/obj.`${WRKSRC}/devtools/bin/Build -A`/libmilter/libmilter.a \
	 ${PREFIX}/lib/
	${INSTALL_DATA} \
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
	${MKDIR} ${PREFIX}/share/sendmail
	@cd ${WRKSRC}; ${TAR} cf - cf |\
		(cd ${PREFIX}/share/sendmail; ${TAR} xf -)
.endif
.if exists(${DESTDIR}/etc/mail/mailer.conf)
	@${SED} s!%%PREFIX%%!${PREFIX}!g ${PKGMESSAGE}

mailer.conf:
	@${SED} \
	-e "s=^sendmail[ 	]*/.*$$=sendmail	${SENDMAIL}=" \
	-e "s=^send-mail[ 	]*/.*$$=send-mail	${SENDMAIL}=" \
	-e "s=^mailq[ 	]*/.*$$=mailq		${SENDMAIL}=" \
	-e "s=^newaliases[ 	]*/.*$$=newaliases	${SENDMAIL}=" \
	 ${DESTDIR}/etc/mail/mailer.conf > ${DESTDIR}/etc/mail/mailer.conf.new
	${MV} ${DESTDIR}/etc/mail/mailer.conf.new ${DESTDIR}/etc/mail/mailer.conf
.endif

.if defined(SENDMAIL_WITH_MILTER)
post-configure:
	${CAT} ${FILESDIR}/site.config.m4.milter >>${WCONF}/site.config.m4

post-build:
	( cd ${WRKSRC}/libmilter && ${MAKE} )
.endif

.include <bsd.port.mk>
