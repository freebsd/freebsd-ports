PORTNAME=	spamilter
PORTVERSION=	0.60
PORTREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	http://www.wanlink.com/spamilter/download/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Sendmail LibMilter filter to block spam
WWW=		https://www.wanlink.com/spamilter/

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		tar:tgz shebangfix fakeroot
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--have-resn
USE_RC_SUBR=	spamilter

LDFLAGS+=	-lpthread
MAKE_ENV+=	__MAKE_CONF=/dev/null

BINFILES=	spamilter-system-report spamilter-user-report
SHEBANG_FILES=	${BINFILES}
DOCSFILES=	Changelog INSTALL LICENSE docs/docs.html docs/docs.txt \
		conf/db.rcpt conf/db.rdnsbl conf/db.sndr \
		conf/policy.html conf/spamilter.rc

PLIST_FILES+=	bin/dnsblchk bin/dnsblupd bin/mxlookup bin/spamilter \
		bin/spamilter-system-report bin/spamilter-user-report
PORTDOCS=	Changelog INSTALL LICENSE docs.html docs.txt db.rcpt \
		db.rdnsbl db.sndr policy.html spamilter.rc

OPTIONS_DEFINE=	SMTP_AFTER_POP3 PAM LIBSPF IPFWMTAD DOCS
SMTP_AFTER_POP3_DESC=	SMTP after POP3
LIBSPF_DESC=	build with libspf
IPFWMTAD_DESC=	build ipfwmtad (requires openssl)

SMTP_AFTER_POP3_CONFIGURE_ON=	--with-popauth
PAM_CONFIGURE_ON=	--with-pam
LIBSPF_BUILD_DEPENDS=	${LOCALBASE}/lib/libspf.a:mail/libspf
LIBSPF_CONFIGURE_ON=	--with-libspf ${LOCALBASE}
LIBSPF_CFLAGS=		-I${LOCALBASE}/include
LIBSPF_LDFLAGS=		-L${LOCALBASE}/lib
IPFWMTAD_PLIST_FILES=	bin/ipfwmtad
IPFWMTAD_USES=	ssl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPFWMTAD}
BROKEN_FreeBSD_13=	option IPFWMTAD needs old openssl
.endif

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

CONFIGURE_ARGS+=	--sendmail-dir "${MILTERBASE}"

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

.if ! ${PORT_OPTIONS:MIPFWMTAD}
post-configure:
	${REINPLACE_CMD} \
		-e 's| install-ipfwmtad $$| |' \
		-e 's| ipfwmtad $$| |' \
		${WRKSRC}/Makefile
.endif

post-install:
.for i in ${BINFILES}
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin/
.endfor

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCSFILES:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
