# New ports collection makefile for:	spamilter
# Date created:				21. Apr 2004
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	spamilter
PORTVERSION=	0.60
CATEGORIES=	mail
MASTER_SITES=	http://www.wanlink.com/spamilter/download/
MASTER_SITE_SUBDIR=	dinoex
EXTRACT_SUFX=	.tgz

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A Sendmail LibMilter filter to block spam

.if !defined(SENDMAIL_MILTER_IN_BASE)
.if defined(SENDMAIL_WITH_SHARED_MILTER)
LIB_DEPENDS+=	milter.3:${PORTSDIR}/mail/${SENDMAIL_MILTER_PORT}
.else
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmilter.a:${PORTSDIR}/mail/${SENDMAIL_MILTER_PORT}
.endif
.endif

SENDMAIL_MILTER_PORT?=	sendmail
WRKSRC=		${WRKDIR}/${PORTNAME}
HAS_CONFIGURE=	yes
CFLAGS+=	${PTHREAD_CFLAGS:S=""==}
LDFLAGS+=	${PTHREAD_LIBS}
MAKE_ENV+=	LDFLAGS="${LDFLAGS}" __MAKE_CONF=/dev/null

BINFILES=	spamilter-system-report spamilter-user-report
DOCSFILES=	Changelog INSTALL LICENSE docs/docs.html docs/docs.txt \
		conf/db.rcpt conf/db.rdnsbl conf/db.sndr \
		conf/policy.html conf/spamilter.rc

.include <bsd.port.pre.mk>

.if !defined(SENDMAIL_MILTER_IN_BASE)
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--sendmail-dir "${LOCALBASE}"
.endif

.if defined(SMTP_AFTER_POP3)
CONFIGURE_ARGS+=	--with-popauth
.endif

.if defined(WITH_PAM)
CONFIGURE_ARGS+=	--with-pam
.endif

.if ${OSVERSION} >= 700014
CONFIGURE_ARGS+=	--have-resn
BROKEN=			res_update.h: No such file or directory
.endif

PLIST_FILES+=	bin/dnsblchk bin/dnsblupd bin/ipfwmtad bin/mxlookup \
		bin/spamilter \
		bin/spamilter-system-report bin/spamilter-user-report \
		etc/rc.d/milter-spamilter.sh.sample
.if !defined(NOPORTDOCS)
PLIST_FILES+=	%%DOCSDIR%%/Changelog %%DOCSDIR%%/INSTALL %%DOCSDIR%%/LICENSE
PLIST_FILES+=	%%DOCSDIR%%/docs.html %%DOCSDIR%%/docs.txt
PLIST_FILES+=	%%DOCSDIR%%/db.rcpt %%DOCSDIR%%/db.rdnsbl %%DOCSDIR%%/db.sndr
PLIST_FILES+=	%%DOCSDIR%%/policy.html %%DOCSDIR%%/spamilter.rc
PLIST_DIRS+=	%%DOCSDIR%%
.endif

.if defined(SENDMAIL_WITHOUT_MILTER)
pre-fetch:
	@${ECHO_MSG}
	@${ECHO_MSG} You must unset variable SENDMAIL_WITHOUT_MILTER,
	@${ECHO_MSG} and rebuild sendmail in the ports
	@${FALSE}
.endif

pre-configure:
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=" ${FILESDIR}/spamilter.sh \
		> ${WRKSRC}/spamilter.sh
	${REINPLACE_CMD} \
		-e "s=/etc/spamilter.rc=${PREFIX}/etc/spamilter.rc=" \
		${WRKSRC}/spamilter.c \
		${WRKSRC}/docs/docs.html ${WRKSRC}/docs/docs.txt

xpost-configure:
.if ${OSVERSION} > 500000
	${REINPLACE_CMD} \
		-e "s| install-ipfwmtad | |" \
		${WRKSRC}/Makefile
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/spamilter.sh \
		${PREFIX}/etc/rc.d/milter-spamilter.sh.sample
.for i in ${BINFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${PREFIX}/bin/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCSFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
