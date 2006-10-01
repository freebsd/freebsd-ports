# New ports collection makefile for:	dkim-milter
# Date created:				10 Jan 2006
# Whom:					Hirohisa Yamaguchi <umq@ueo.co.jp>
#
# $FreeBSD$
#
## There is a new option WITH_POSTFIX_MILTER
## to make this port work with mail/postfix port.

## WITH_POSTFIX_MILTER knob implicitly defines
## SENDMAIL_MILTER_IN_BASE, to build with libmilter*
## in base system.  If you have deleted sendamil in
## base system, building this port may fail.

PORTNAME=	dkim-milter
PORTVERSION=	0.5.2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	umq@ueo.co.jp
COMMENT=	Domainkeys milter for Sendmail

USE_RC_SUBR=	milter-dkim.sh

.if defined(WITH_POSTFIX_MILTER) || defined(WITH_POSTFIX) || defined(WITH_POSTFIX_CURRENT)
SENDMAIL_MILTER_IN_BASE=	yes
PKGMESSAGE=	pkg-message.postfix

.if defined(WITH_POSTFIX_CURRENT)
RUN_DEPENDS+=	${LOCALBASE}/libexec/postfix/smtpd:${PORTSDIR}/mail/postfix-current
.else
RUN_DEPENDS+=	${LOCALBASE}/libexec/postfix/smtpd:${PORTSDIR}/mail/postfix
.endif
.endif

.if !defined(SENDMAIL_MILTER_IN_BASE)
.if defined(SENDMAIL_WITH_SHARED_MILTER)
LIB_DEPENDS+=	milter.3:${PORTSDIR}/mail/${SENDMAIL_MILTER_PORT}
.else
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmilter.a:${PORTSDIR}/mail/${SENDMAIL_MILTER_PORT}
.endif
.endif

SENDMAIL_MILTER_PORT?=	sendmail
SUB_FILES=	milter-dkim.sh
WCONF=		${WRKSRC}/devtools/Site
MAN8=		dkim-filter.8
PLIST_FILES=	lib/libar.a libexec/dkim-filter sbin/gentxt
PORTDOCS=	FEATURES INSTALL KNOWNBUGS LICENSE README RELEASE_NOTES \
		autorespond.csh

SITE+=		${FILESDIR}/site.config.m4
.if !defined(SENDMAIL_MILTER_IN_BASE)
SITE+=		${FILESDIR}/site.config.m4.milter
.endif

.include <bsd.port.pre.mk>

# .sh suffix is stripped in recent releases.
.if (${OSVERSION} >= 700007 || ( ${OSVERSION} < 700000 && ${OSVERSION} >= 600101 ))
SUB_LIST=	"RC_SCRIPT=${PREFIX}/etc/rc.d/${USE_RC_SUBR:S/.sh$//}"
.else
SUB_LIST=	"RC_SCRIPT=${PREFIX}/etc/rc.d/${USE_RC_SUBR}"
.endif

.if defined(SENDMAIL_WITHOUT_MILTER)
pre-fetch:
	@${ECHO_MSG}
	@${ECHO_MSG} You must unset variable SENDMAIL_WITHOUT_MILTER,
	@${ECHO_MSG} and rebuild sendmail in the ports
	@${FALSE}
.endif

post-extract:
	@${CP} ${WRKSRC}/dkim-filter/autorespond.csh ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|' \
		-e 's|-D_THREAD_SAFE|${PTHREAD_CFLAGS}|' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		-e "s|\`-O'|\`${CFLAGS}'|g" \
		${WRKSRC}/devtools/OS/FreeBSD
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${SITE} > ${WCONF}/site.config.m4

post-install:
	@${STRIP_CMD} ${PREFIX}/libexec/dkim-filter
	${INSTALL_SCRIPT} ${WRKSRC}/dkim-filter/gentxt.csh \
		${PREFIX}/sbin/gentxt
.for i in ${MAN8}
	@${RM} -f ${MANPREFIX}/man/cat8/${i} ${MANPREFIX}/man/cat8/${i}.gz
	${INSTALL_MAN} ${WRKSRC}/*/${i} ${MANPREFIX}/man/man8/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
