# New ports collection makefile for:	sendmail
# Date created:				20 Apr 2000
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	sendmail
PORTVERSION=	8.11.1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.sendmail.org/pub/sendmail/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	dirk.meyer@dinoex.sub.org

NO_PACKAGE=	"sendmail included in base system"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PLIST=		${WRKDIR}/.PLIST.more

.if exists(/etc/mail/mailer.conf)
pre-configure:
	${SED} -e "s=%%PREFIX%%=${PREFIX}=" \
	${FILESDIR}/site.config.m4 >${WRKSRC}/devtools/Site/site.config.m4
.else
pre-configure:
	${SED} -e "s=%%PREFIX%%=${PREFIX}=" \
	${FILESDIR}/site.config.m4.pre4 >${WRKSRC}/devtools/Site/site.config.m4

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
	${CAT} ${PKGDIR}/pkg-plist >${PLIST}
.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && find cf -type f | \
	${AWK} '{print "share/sendmail/" $$1}' >>${PLIST}
	cd ${WRKSRC} && find -d cf -type d | \
	${AWK} '{print "@dirrm share/sendmail/" $$1}' >>${PLIST}
.endif

# We want mail.local and rmail for our system.
# the build install catmans only, we have to fix this.
post-install:
	( cd ${WRKSRC}/mail.local && ${MAKE} force-install )
	( cd ${WRKSRC}/rmail && ${MAKE} force-install )
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
	@${SED} s!%%PREFIX%%!${PREFIX}!g ${PKGDIR}/pkg-message

mailer.conf:
	${SED} \
	-e "s=^sendmail[ 	]*/.*$$=sendmail	${SENDMAIL}=" \
	-e "s=^send-mail[ 	]*/.*$$=send-mail	${SENDMAIL}=" \
	-e "s=^mailq[ 	]*/.*$$=mailq		${SENDMAIL}=" \
	-e "s=^newaliases[ 	]*/.*$$=newaliases	${SENDMAIL}=" \
	 ${DESTDIR}/etc/mail/mailer.conf > ${DESTDIR}/etc/mail/mailer.conf.new
	${MV} ${DESTDIR}/etc/mail/mailer.conf.new ${DESTDIR}/etc/mail/mailer.conf
.endif

.include <bsd.port.mk>
