PORTNAME=	sysinfo
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://codeberg.org/BSDforge/${PORTNAME}/archive/${DISTVERSION}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Utility used to report on the system and it's configuration
WWW=		https://codeberg.org/BSDforge/sysinfo

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DMIDECODE

DMIDECODE_DESC=		Include information from the dmidecode tool
DMIDECODE_RUN_DEPENDS=	dmidecode:sysutils/dmidecode

# nuke this nonsense in next ver
post-patch:
	@${REINPLACE_CMD} -e 's|common.subr|${DATADIR}/common.subr|g' ${WRKSRC}/sysinfo
	@${REINPLACE_CMD} -e 's|sysinfo.conf|${PREFIX}/etc/sysinfo.conf|g' \
		${WRKSRC}/sysinfo ${WRKSRC}/doc/sysinfo.conf.5
	@${REINPLACE_CMD} -e 's|APPDIR=.|APPDIR=${DATADIR}|g' \
		${WRKSRC}/sysinfo.conf ${WRKSRC}/doc/sysinfo.conf.5

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sysinfo ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/sysinfo.conf ${STAGEDIR}${PREFIX}/etc/sysinfo.conf.sample
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/common.subr ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_BIN} modules ${STAGEDIR}${DATADIR})
	${INSTALL_MAN} ${WRKSRC}/doc/sysinfo.conf.5 ${STAGEDIR}${PREFIX}/share/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/sysinfo.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
