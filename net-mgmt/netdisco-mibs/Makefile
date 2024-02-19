PORTNAME=	netdisco-mibs
DISTVERSION=	4.034
CATEGORIES=	net-mgmt
MASTER_SITES=	https://github.com/netdisco/${PORTNAME}/releases/download/${DISTVERSION}/
DISTNAME=	${PORTNAME}

MAINTAINER=	dgeo@centrale-med.fr
COMMENT=	MIBs for use with ports-mgmt/netdisco (and SNMP)

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

post-extract:
	${RM} -rf ${WRKSRC}/.github
	${RM} -f ${WRKSRC}/robots.txt

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/netdisco/mibs|${LOCALBASE}/share/netdisko-mibs|g' ${WRKSRC}/EXTRAS/contrib/snmp.conf
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${LOCALBASE}/bin/perl|' ${WRKSRC}/EXTRAS/scripts/*/*

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${RM} ${STAGEDIR}${DATADIR}/robots.txt

.include <bsd.port.mk>
