# New ports collection makefile for:	dk-milter
# Date created:				22 May 2005
# Whom:					ache
#
# $FreeBSD$
#

PORTNAME=	dk-milter
PORTVERSION=	0.6.0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dk-milter

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Domainkeys milter for Sendmail

USE_RC_SUBR=	milter-dk.sh
USE_OPENSSL=	yes

IPCCHECK!=	ipcrm -q 0 2>&1 || true
.if ${IPCCHECK:Mimplemented}
IGNORE=		your system does not support sysvipc
.endif

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

.if defined(WITH_SENDMAIL_STATIC_MILTER) || !defined(SENDMAIL_WITH_SHARED_MILTER)
SITE+=		-e '\|-static|s|%%STATIC%%||g'
.else
SITE+=		-e '\|-static|s|%%STATIC%%|dnl |g'
.endif

SENDMAIL_MILTER_PORT?=	sendmail
WCONF=		${WRKSRC}/devtools/Site
MAN8=		dk-filter.8
DOCSFILES=	FEATURES INSTALL KNOWNBUGS LICENSE README RELEASE_NOTES \
		rfc4870.txt dk-filter/autorespond.csh

SITE+=		${FILESDIR}/site.config.m4
.if !defined(SENDMAIL_MILTER_IN_BASE)
SITE+=		${FILESDIR}/site.config.m4.milter
.endif
SITE+=		${WRKSRC}/site.config.m4.dist
SITE_SUB+=	-e "s|%%PREFIX%%|${PREFIX}|g" \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g"

.include <bsd.port.pre.mk>

SUB_LIST=	"RC_SCRIPT=${PREFIX}/etc/rc.d/${USE_RC_SUBR:S/.sh$//}${RC_SUBR_SUFFIX}"

.if defined(WITH_DEBUG)
SITE_SUB+=	-e '\|confOPTIMIZE.*-g|s/^dnl //g'
.endif
.if !defined(WITHOUT_ARLIB)
SITE_SUB+=	-e '\|bld_USE_ARLIB|s/^dnl //g'
.endif
.if defined(WITH_POPAUTH) && !defined(WITHOUT_POPAUTH)
SITE_SUB+=	-e '/-DPOPAUTH/s/^dnl //g'
.endif

.if defined(WITH_POPAUTH)
USE_BDB=	41+
INVALID_BDB_VER=	2 3 40
SITE_SUB+=	-e 's|%%BDB%%||g' \
		-e "s|%%BDB_LIB_DIR%%|${BDB_LIB_DIR}|g" \
		-e "s|%%BDB_INCLUDE_DIR%%|${BDB_INCLUDE_DIR}|g" \
		-e "s|%%BDB_LIB_NAME%%|${BDB_LIB_NAME}|g"
.else
SITE_SUB+=	-e 's|%%BDB%%|dnl |g'
.endif
.if defined(WITH_OPENSSL_BASE) || defined(OPENSSL_OVERWRITE_BASE)
SITE_SUB+=	-e 's|%%OPENSSL%%|dnl |g'
.else
SITE_SUB+=	-e 's|%%OPENSSL%%||g' \
		-e "s|%%OPENSSLINC%%|${OPENSSLINC}|g" \
		-e "s|%%OPENSSLLIB%%|${OPENSSLLIB}|g"
.endif

.if defined(SENDMAIL_WITHOUT_MILTER)
pre-fetch:
	@${ECHO_MSG}
	@${ECHO_MSG} You must unset variable SENDMAIL_WITHOUT_MILTER,
	@${ECHO_MSG} and rebuild sendmail in the ports
	@${FALSE}
.endif

.include	"${.CURDIR}/Makefile.features"
pre-configure:
	${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|' \
		-e 's|-D_THREAD_SAFE|${PTHREAD_CFLAGS}|' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		-e "s|\`-O'|\`${CFLAGS}'|g" \
		${WRKSRC}/devtools/OS/FreeBSD
	${SED} ${SITE_SUB} -e '\|^dnl |d' -e '/^dnl$$/d' \
		${SITE} > ${WCONF}/site.config.m4

post-install:
.if !defined(WITH_DEBUG)
	-${STRIP_CMD} ${PREFIX}/libexec/dk-filter
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/dk-filter/gentxt.csh \
		${PREFIX}/sbin/gentxt-dk
.for i in ${MAN8}
	@${RM} -f ${MANPREFIX}/man/cat8/${i} ${MANPREFIX}/man/cat8/${i}.gz
	${INSTALL_MAN} ${WRKSRC}/*/${i} ${MANPREFIX}/man/man8/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCSFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
