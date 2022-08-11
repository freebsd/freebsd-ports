PORTNAME=	portsentry
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/sentrytools/${PORTNAME}%201.x/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Port scan detection and active defense

SUB_FILES=	portsentry.sh
ALL_TARGET=	freebsd
CFLAGS+=	-DPREFIX=\"${PREFIX}\"
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
WRKSRC=		${WRKDIR}/portsentry_beta

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local/psionic/portsentry,${PREFIX}/etc,g' \
		${WRKSRC}/portsentry.conf ${WRKSRC}/portsentry_config.h

do-install:
	${INSTALL_DATA} ${WRKSRC}/portsentry.conf \
		${STAGEDIR}${PREFIX}/etc/portsentry.conf.sample
	${INSTALL_DATA} ${WRKSRC}/portsentry.ignore \
		${STAGEDIR}${PREFIX}/etc/portsentry.ignore.sample
	${INSTALL_PROGRAM} ${WRKSRC}/portsentry \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/portsentry.sh ${STAGEDIR}${PREFIX}/etc/rc.d/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.install ${WRKSRC}/README.methods \
		${WRKSRC}/README.stealth ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
