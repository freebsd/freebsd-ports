# $FreeBSD$

PORTNAME=	sid-milter
PORTVERSION=	1.0.0
PORTREVISION=	7
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/SenderID%20Milter/${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Milter module for sid and spf

RESTRICTED=	May incorporate intellectual property, possible patent issues

USES=		groff
# on FreeBSD 11 optimized code fails with 'MalformedDomain'
CFLAGS:=	${CFLAGS:S/-O2//g}
WCONF=		${WRKSRC}/devtools/Site
DOCSFILES=	FEATURES INSTALL KNOWNBUGS LICENSE README README-SenderID \
		RELEASE_NOTES rfc4406.txt rfc4407.txt rfc4408.txt
INSTALL_WRKSRC=	${WRKSRC}/sid-filter
PLIST_FILES=	libexec/sid-filter man/man8/sid-filter.8.gz
USE_RC_SUBR=	milter-sid
PORTDOCS=	${DOCSFILES}

SITE+=		${FILESDIR}/site.config.m4

.if !defined(BUILDING_INDEX)
IPCCHECK!=	ipcrm -q 0 2>&1 || true
.if ${IPCCHECK:Mimplemented}
IGNORE=		your system does not support sysvipc
.endif
.endif

OPTIONS_DEFINE=	LIBAR NH_MFROM DOCS
LIBAR_DESC=	build and install libar
NH_MFROM_DESC=	use NH_MFROM

LIBAR_PLIST_FILES=	include/libar.h lib/libar.a man/man3/ar.3.gz

.include <bsd.port.options.mk>

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

.if defined(WITH_MILTER_PORT)
SITE+=		${FILESDIR}/site.config.m4.milter
.endif

pre-configure:
	${REINPLACE_CMD} -e "s|\`-O'|\`${CFLAGS}'|g" \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/devtools/OS/FreeBSD
	${SED} -e "s|%%PREFIX%%|${PREFIX}|g" \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${SITE} > ${WCONF}/site.config.m4

pre-configure-NH_MFROM-on:
	${ECHO_CMD} \
		'APPENDDEF(`confENVDEF'\'', `-D_FFR_NH_MFROM'\'')' \
		>> ${WCONF}/site.config.m4

post-install:
	${INSTALL_MAN} ${WRKSRC}/*/sid-filter.8 ${STAGEDIR}${PREFIX}/man/man8/

post-install-LIBAR-on:
	${INSTALL_DATA} ${WRKSRC}/*/libar/libar.a ${STAGEDIR}${PREFIX}/lib/libar.a
	${INSTALL_DATA} ${WRKSRC}/libar/ar.h ${STAGEDIR}${PREFIX}/include/libar.h
	${INSTALL_MAN} ${WRKSRC}/*/ar.3 ${STAGEDIR}${PREFIX}/man/man3/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCSFILES:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
