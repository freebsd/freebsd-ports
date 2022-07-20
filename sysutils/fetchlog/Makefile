PORTNAME=	fetchlog
PORTVERSION=	1.4
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	alexander.haderer@loescap.de
COMMENT=	Fetch and convert new messages of a logfile

LICENSE=	GPLv2

PORTDOCS=	CHANGES README README.Nagios README.SNMP
PORTEXAMPLES=	fetchlog.cfg fetchlog_service.cfg notify.cfg.example

PLIST_FILES=	bin/fetchlog man/man1/fetchlog.1.gz

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fetchlog ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_MAN} ${PORTNAME}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTEXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
