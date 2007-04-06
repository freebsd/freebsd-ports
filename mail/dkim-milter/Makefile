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
PORTVERSION=	0.6.3
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	umq@ueo.co.jp
COMMENT=	Domainkeys Identified Mail (DKIM) milter

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
PLIST_FILES=	libexec/dkim-filter sbin/gentxt-dkim
PORTDOCS=	FEATURES INSTALL KNOWNBUGS LICENSE README RELEASE_NOTES \
		autorespond.csh

SITE+=		${FILESDIR}/site.config.m4
.if !defined(SENDMAIL_MILTER_IN_BASE)
SITE+=		${FILESDIR}/site.config.m4.milter
.endif

.include <bsd.port.pre.mk>

SUB_LIST=	"RC_SCRIPT=${PREFIX}/etc/rc.d/${USE_RC_SUBR:S/.sh$//}${RC_SUBR_SUFFIX}"

.if defined(WITH_VERIFY_DOMAINKEYS) && !defined(WITHOUT_VERIFY_DOMAINKEYS)
BROKEN=		dkim-milter does not verify DomainKeys correctly
LIBDK_PORT=	mail/dk-milter
BUILD_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/${LIBDK_PORT}:patch
DKMILTER_DISTNAME!=	cd ${PORTSDIR}/${LIBDK_PORT} && ${MAKE} -V DISTNAME
LIBDK_PATH=	${PORTSDIR}/${LIBDK_PORT}/work/${DKMILTER_DISTNAME}/libdk
.endif

pre-fetch:
.if defined(SENDMAIL_WITHOUT_MILTER)
	@${ECHO_MSG}
	@${ECHO_MSG} You must unset variable SENDMAIL_WITHOUT_MILTER,
	@${ECHO_MSG} and rebuild sendmail in the ports
	@${FALSE}
.endif
	@${ECHO_MSG}
	@${ECHO_MSG} "dkim-milter has the following tunable option(s):"
#	@${ECHO_MSG} " WITH_VERIFY_DOMAINKEYS=yes	Verify DomainKeys using dk-milter's libdk"
	@${ECHO_MSG} " SENDMAIL_MILTER_IN_BASE=yes	Build to run with base sendmail"
	@${ECHO_MSG} " WITH_POSTFIX=yes		Build to run with postfix port"
	@${ECHO_MSG}
	@sleep 5

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

.if defined(WITH_VERIFY_DOMAINKEYS) && !defined(WITHOUT_VERIFY_DOMAINKEYS)
	@${REINPLACE_CMD} -e "/bldPUSH_SMLIB(\`dk')/s|^dnl ||" \
		-e "/-I\.\.\/libdk\//s|^dnl ||" \
		-e '/-DVERIFY_DOMAINKEYS/s|^dnl ||' \
		${WRKSRC}/dkim-filter/Makefile.m4
	${LN} -s ${LIBDK_PATH} ${WRKSRC}/
.endif

post-install:
	@${STRIP_CMD} ${PREFIX}/libexec/dkim-filter
	${INSTALL_SCRIPT} ${WRKSRC}/dkim-filter/gentxt.csh \
		${PREFIX}/sbin/gentxt-dkim
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
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
