# $FreeBSD$

PORTNAME=	sid-milter
PORTVERSION=	1.0.0
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/SenderID%20Milter/${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	An sid and spf milter for Sendmail

RESTRICTED=	May incorporate intellectual property, possible patent issues

WCONF=		${WRKSRC}/devtools/Site
MAN8=		sid-filter.8
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

OPTIONS_DEFINE=	LIBAR NH_MFROM
LIBAR_DESC=	build and install libar
NH_MFROM_DESC=	use NH_MFROM

.include <bsd.port.options.mk>

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

.if defined(WITH_SENDMAIL_PORT)
SITE+=		${FILESDIR}/site.config.m4.milter
.endif

.if ${PORT_OPTIONS:MLIBAR}
MAN3=		ar.3
PLIST_FILES+=	include/libar.h lib/libar.a man/man3/ar.3.gz
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|' \
		-e 's|-D_THREAD_SAFE|${PTHREAD_CFLAGS}|' \
		-e "s|\`-O'|\`${CFLAGS}'|g" \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/devtools/OS/FreeBSD
	${SED} -e "s|%%PREFIX%%|${PREFIX}|g" \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${SITE} > ${WCONF}/site.config.m4
.if ${PORT_OPTIONS:MNH_MFROM}
	${ECHO_CMD} \
		'APPENDDEF(`confENVDEF'\'', `-D_FFR_NH_MFROM'\'')' \
		>> ${WCONF}/site.config.m4
.endif

post-install:
.for i in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/*/${i} ${STAGEDIR}${PREFIX}/man/man8/
.endfor
.if ${PORT_OPTIONS:MLIBAR}
	${INSTALL_LIB} ${WRKSRC}/*/libar/libar.a ${STAGEDIR}${PREFIX}/lib/libar.a
	${INSTALL_DATA} ${WRKSRC}/libar/ar.h ${STAGEDIR}${PREFIX}/include/libar.h
.for i in ${MAN3}
	${INSTALL_MAN} ${WRKSRC}/*/${i} ${STAGEDIR}${PREFIX}/man/man3/
.endfor
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCSFILES:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
