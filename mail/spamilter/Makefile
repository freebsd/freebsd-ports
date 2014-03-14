# $FreeBSD$

PORTNAME=	spamilter
PORTVERSION=	0.60
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.wanlink.com/spamilter/download/
MASTER_SITE_SUBDIR=	dinoex
EXTRACT_SUFX=	.tgz

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A Sendmail LibMilter filter to block spam

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

NEED_ROOT=	yes

USES=		shebangfix
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--have-resn
USE_RC_SUBR=	spamilter

CFLAGS+=	${PTHREAD_CFLAGS:S=""==}
LDFLAGS+=	${PTHREAD_LIBS}
MAKE_ENV+=	__MAKE_CONF=/dev/null

BINFILES=	spamilter-system-report spamilter-user-report
SHEBANG_FILES=	${BINFILES}
DOCSFILES=	Changelog INSTALL LICENSE docs/docs.html docs/docs.txt \
		conf/db.rcpt conf/db.rdnsbl conf/db.sndr \
		conf/policy.html conf/spamilter.rc

PLIST_FILES+=	bin/dnsblchk bin/dnsblupd bin/ipfwmtad bin/mxlookup \
		bin/spamilter \
		bin/spamilter-system-report bin/spamilter-user-report
PORTDOCS=	Changelog INSTALL LICENSE docs.html docs.txt db.rcpt \
		db.rdnsbl db.sndr policy.html spamilter.rc

OPTIONS_DEFINE=	SMTP_AFTER_POP3 PAM LIBSPF
SMTP_AFTER_POP3_DESC=	SMTP after POP3
LIBSPF_DESC=	build with libspf

SMTP_AFTER_POP3_CONFIGURE_ON=	--with-popauth
PAM_CONFIGURE_ON=	--with-pam
LIBSPF_BUILD_DEPENDS=	${LOCALBASE}/lib/libspf.a:${PORTSDIR}/mail/libspf
LIBSPF_CONFIGURE_ON=	--with-libspf ${LOCALBASE}
LIBSPF_CFLAGS=		-I${LOCALBASE}/include
LIBSPF_LDFLAGS=		-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

.if defined(WITH_SENDMAIL_PORT)
CONFIGURE_ARGS+=	--sendmail-dir "${LOCALBASE}"
.else
CONFIGURE_ARGS+=	--sendmail-dir "/usr"
.endif

post-extract:
	${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

pre-configure:
	${REINPLACE_CMD} \
		-e "s=/etc/spamilter.rc=${PREFIX}/etc/spamilter.rc=" \
		${WRKSRC}/spamilter.c \
		${WRKSRC}/docs/docs.html ${WRKSRC}/docs/docs.txt
	${REINPLACE_CMD} \
		-e "s=/usr/local/=${PREFIX}/=" \
		${WRKSRC}/Makefile.tmpl

post-install:
.for i in ${BINFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin/
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCSFILES:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
