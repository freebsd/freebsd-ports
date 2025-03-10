PORTNAME=	fetchlog
DISTVERSION=	1.6
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	alexander.haderer@loescap.de
COMMENT=	Fetch and convert new messages of a logfile
WWW=		https://fetchlog.sourceforge.net/

LICENSE=	GPLv2

PLIST_FILES=	bin/fetchlog share/man/man1/fetchlog.1.gz
PORTDOCS=	CHANGES README README.Nagios README.SNMP
PORTEXAMPLES=	fetchlog.cfg fetchlog_service.cfg notify.cfg.example \
		check_snmp_fetchlog_b2n check_snmp_fetchlog_bb2b \
		check_snmp_fetchlog_bb2n

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fetchlog ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_MAN} ${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTEXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
