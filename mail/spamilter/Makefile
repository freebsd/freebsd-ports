# New ports collection makefile for:	spamilter
# Date created:				21. Apr 2004
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	spamilter
PORTVERSION=	0.60
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.wanlink.com/spamilter/download/
MASTER_SITE_SUBDIR=	dinoex
EXTRACT_SUFX=	.tgz

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A Sendmail LibMilter filter to block spam

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--have-resn
USE_RC_SUBR=	spamilter

CFLAGS+=	${PTHREAD_CFLAGS:S=""==}
LDFLAGS+=	${PTHREAD_LIBS}
MAKE_ENV+=	__MAKE_CONF=/dev/null

BINFILES=	spamilter-system-report spamilter-user-report
DOCSFILES=	Changelog INSTALL LICENSE docs/docs.html docs/docs.txt \
		conf/db.rcpt conf/db.rdnsbl conf/db.sndr \
		conf/policy.html conf/spamilter.rc

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

.if defined(WITH_SENDMAIL_PORT)
CONFIGURE_ARGS+=	--sendmail-dir "${LOCALBASE}"
.else
CONFIGURE_ARGS+=	--sendmail-dir "/usr"
.endif

.if defined(SMTP_AFTER_POP3)
CONFIGURE_ARGS+=	--with-popauth
.endif

.if defined(WITH_PAM)
CONFIGURE_ARGS+=	--with-pam
.endif

.if defined(WITH_LIBSPF)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libspf.a:${PORTSDIR}/mail/libspf
CONFIGURE_ARGS+=	--with-libspf ${LOCALBASE}
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

PLIST_FILES+=	bin/dnsblchk bin/dnsblupd bin/ipfwmtad bin/mxlookup \
		bin/spamilter \
		bin/spamilter-system-report bin/spamilter-user-report
PORTDOCS=	Changelog INSTALL LICENSE docs.html docs.txt db.rcpt \
		db.rdnsbl db.sndr policy.html spamilter.rc

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

pre-configure:
	${REINPLACE_CMD} \
		-e "s=/etc/spamilter.rc=${PREFIX}/etc/spamilter.rc=" \
		${WRKSRC}/spamilter.c \
		${WRKSRC}/docs/docs.html ${WRKSRC}/docs/docs.txt
	${REINPLACE_CMD} \
		-e "s=/usr/local/=${PREFIX}/=" \
		${WRKSRC}/Makefile.tmpl

xpost-configure:
	${REINPLACE_CMD} \
		-e "s| install-ipfwmtad | |" \
		${WRKSRC}/Makefile

post-install:
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
