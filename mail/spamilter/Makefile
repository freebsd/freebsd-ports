# New ports collection makefile for:	spamilter
# Date created:				21. Apr 2004
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	spamilter
PORTVERSION=	0.59
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.wanlink.com/spamilter/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A Sendmail LibMilter filter to block spam

.if !defined(SENDMAIL_MILTER_IN_BASE)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmilter.a:${PORTSDIR}/mail/${SENDMAIL_PORT}
.endif

SENDMAIL_PORT?=	sendmail
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
CFLAGS+=	${PTHREAD_CFLAGS:S=""==}
LDFLAGS+=	${PTHREAD_LIBS}
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"

BINFILES=	spamilter-system-report spamilter-user-report
DOCSFILES=	Changelog INSTALL LICENSE docs/docs.html docs/docs.txt \
		conf/db.rcpt conf/db.rdnsbl conf/db.sndr \
		conf/policy.html conf/spamilter.rc

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
ALL_TARGET=	spamilter dnsblchk mxlookup iflookup
.else
PLIST_FILES+=	bin/ipfwmtad
.endif
.if ${OSVERSION} > 501000
IGNORE=		is unusable because of resource starvation in threads
.endif

.if !defined(SENDMAIL_MILTER_IN_BASE)
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--sendmail_dir ${LOCALBASE}
.endif
#CFLAGS+=	-DDEBUG_TIMESTAMP

PLIST_FILES+=	bin/dnsblchk bin/mxlookup bin/spamilter \
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

post-configure:
	${REINPLACE_CMD} \
		-e "s|^CFLAGS=|#CFLAGS=|" \
		-e "s|^LDFLAGS=|#LDFLAGS=|" \
		-e "s|^LIBDIRS=|#LIBDIRS=|" \
		-e "s|/usr/local/bind|${LOCALBASE}/bind|" \
		-e "s|/usr/local/|${PREFIX}/|" \
		${WRKSRC}/Makefile
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
