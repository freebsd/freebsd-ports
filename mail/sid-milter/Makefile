# New ports collection makefile for:	sid-milter
# Date created:				18. Dec 2004
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	sid-milter
PORTVERSION=	0.2.5
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sid-milter

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	An sid and spf milter for Sendmail

.if !defined(SENDMAIL_MILTER_IN_BASE)
.if defined(SENDMAIL_WITH_SHARED_MILTER)
LIB_DEPENDS+=	milter.3:${PORTSDIR}/mail/${SENDMAIL_MILTER_PORT}
.else
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmilter.a:${PORTSDIR}/mail/${SENDMAIL_MILTER_PORT}
.endif
.endif

RESTRICTED=	may incorporate intellectual property, possible patent issues

SENDMAIL_MILTER_PORT?=	sendmail
USE_REINPLACE=	yes
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"
WCONF=		${WRKSRC}/devtools/Site
MAN3=		ar.3
MAN8=		sid-filter.8
INCFILES=	libar/ar.h
DOCSFILES=	INSTALL KNOWNBUGS LICENSE README README-SenderID RELEASE_NOTES

SITE+=		${FILESDIR}/site.config.m4
.if !defined(SENDMAIL_MILTER_IN_BASE)
SITE+=		${FILESDIR}/site.config.m4.milter
.endif

.include <bsd.port.pre.mk>

.if defined(SENDMAIL_WITHOUT_MILTER)
pre-fetch:
	@${ECHO_MSG}
	@${ECHO_MSG} You must unset variable SENDMAIL_WITHOUT_MILTER,
	@${ECHO_MSG} and rebuild sendmail in the ports
	@${FALSE}
.endif

pre-configure:
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=" ${FILESDIR}/milter-sid.sh \
		> ${WRKSRC}/milter-sid.sh
	${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/devtools/OS/FreeBSD
	${SED} -e "s|%%PREFIX%%|${PREFIX}|g" \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${SITE} > ${WCONF}/site.config.m4

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/milter-sid.sh \
		${PREFIX}/etc/rc.d/milter-sid.sh.sample
.for i in ${MAN3}
	@${RM} -f ${MANPREFIX}/man/cat3/${i} ${MANPREFIX}/man/cat3/${i}.gz
	${INSTALL_MAN} ${WRKSRC}/*/${i} ${MANPREFIX}/man/man3/
.endfor
.for i in ${MAN8}
	@${RM} -f ${MANPREFIX}/man/cat8/${i} ${MANPREFIX}/man/cat8/${i}.gz
	${INSTALL_MAN} ${WRKSRC}/*/${i} ${MANPREFIX}/man/man8/
.endfor
.for i in ${INCFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/include/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCSFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
