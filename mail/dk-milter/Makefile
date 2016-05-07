# Created by: ache
# $FreeBSD$

PORTNAME=	dk-milter
PORTVERSION=	1.0.2
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/DomainKeys%20Milter/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Domainkeys milter for Sendmail

USE_RC_SUBR=	milter-dk
USE_OPENSSL=	yes

.if !defined(BUILDING_INDEX)
IPCCHECK!=	ipcrm -q 0 2>&1 || true
.if ${IPCCHECK:Mimplemented}
IGNORE=		your system does not support sysvipc
.endif
.endif

.if defined(WITH_POSTFIX_MILTER) || defined(WITH_POSTFIX) || defined(WITH_POSTFIX_CURRENT)
WITH_SENDMAIL_BASE=	yes
PKGMESSAGE=	pkg-message.postfix

.if defined(WITH_POSTFIX_CURRENT)
RUN_DEPENDS+=	${LOCALBASE}/libexec/postfix/smtpd:mail/postfix-current
.else
RUN_DEPENDS+=	${LOCALBASE}/libexec/postfix/smtpd:mail/postfix
.endif
.endif

WCONF=		${WRKSRC}/devtools/Site
DOCSFILES=	FEATURES INSTALL KNOWNBUGS LICENSE README RELEASE_NOTES \
		rfc4870.txt dk-filter/autorespond.csh

SITE+=		${FILESDIR}/site.config.m4
SITE_SUB+=	-e "s|%%PREFIX%%|${PREFIX}|g" \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g"

OPTIONS_DEFINE=	DOCS

.if defined(WITH_POPAUTH)
. if defined(WITH_BDB_BASE)
IGNORE=		does not work with base bdb
SITE_SUB+=	-e 's|%%BDB%%|dnl |g'
. else
USE_BDB=	41+
INVALID_BDB_VER=	2 40
SITE_SUB+=	-e 's|%%BDB%%||g' \
		-e "s|%%BDB_LIB_DIR%%|${BDB_LIB_DIR}|g" \
		-e "s|%%BDB_INCLUDE_DIR%%|${BDB_INCLUDE_DIR}|g" \
		-e "s|%%BDB_LIB_NAME%%|${BDB_LIB_NAME}|g"
. endif
.else
SITE_SUB+=	-e 's|%%BDB%%|dnl |g'
.endif

.include <bsd.port.pre.mk>

WITHOUT_MILTER_CFLAGS=	yes
.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

SITE+=		${WRKSRC}/site.config.m4.dist
.if defined(WITH_SENDMAIL_PORT)
SITE+=		${FILESDIR}/site.config.m4.milter
.endif

.if defined(WITH_SENDMAIL_STATIC_MILTER)
SITE_SUB+=	-e '\|-static|s|%%STATIC%%||g'
.else
SITE_SUB+=	-e '\|-static|s|%%STATIC%%|dnl |g'
.endif

SUB_LIST=	"RC_SCRIPT=${PREFIX}/etc/rc.d/${USE_RC_SUBR}"

.if defined(WITH_DEBUG)
SITE_SUB+=	-e '\|confOPTIMIZE.*-g|s/^dnl //g'
.endif
.if !defined(WITHOUT_ARLIB)
SITE_SUB+=	-e '\|bld_USE_ARLIB|s/^dnl //g'
.endif
.if defined(WITH_POPAUTH) && !defined(WITHOUT_POPAUTH)
SITE_SUB+=	-e '/-DPOPAUTH/s/^dnl //g'
.endif

.if defined(WITH_OPENSSL_BASE)
SITE_SUB+=	-e 's|%%OPENSSL%%|dnl |g'
.else
SITE_SUB+=	-e 's|%%OPENSSL%%||g' \
		-e "s|%%OPENSSLINC%%|${OPENSSLINC}|g" \
		-e "s|%%OPENSSLLIB%%|${OPENSSLLIB}|g"
.endif

.include	"${.CURDIR}/Makefile.features"
pre-configure:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		-e "s|\`-O'|\`${CFLAGS}'|g" \
		${WRKSRC}/devtools/OS/FreeBSD
	${SED} ${SITE_SUB} -e '\|^dnl |d' -e '/^dnl$$/d' \
		${SITE} > ${WCONF}/site.config.m4

post-install:
	${CHMOD} u+w ${STAGEDIR}${PREFIX}/libexec/dk-filter
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/dk-filter
	${CHMOD} u-w ${STAGEDIR}${PREFIX}/libexec/dk-filter
	${INSTALL_SCRIPT} ${WRKSRC}/dk-filter/gentxt.csh \
		${STAGEDIR}${PREFIX}/sbin/gentxt-dk
.for i in dk-filter.8
	@${RM} -f ${STAGEDIR}${PREFIX}/man/cat8/${i} \
		${STAGEDIR}${PREFIX}/man/cat8/${i}.gz
	${INSTALL_MAN} ${WRKSRC}/*/${i} ${STAGEDIR}${PREFIX}/man/man8/
.endfor

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCSFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.post.mk>
