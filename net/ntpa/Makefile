# Created by: Carsten Larsen <cs@innolan.dk>
# $FreeBSD$

PORTNAME=	ntpa
PORTVERSION=	0.7.1
CATEGORIES=	net
MASTER_SITES=	http://dist.innolan.net/

MAINTAINER=	cs@innolan.dk
COMMENT=	NTP data collection and charting

LICENSE=	MIT

USES=		mono
NO_ARCH=	yes
OPTIONS_SUB=	yes
USE_RC_SUBR=	ntpa

USERS=		ntpa
GROUPS=		ntpa

SUB_FILES=	ntpad ntpav ntpac ntpag

OPTIONS_DEFINE=	WEBFILES GRAPH
WEBFILES_DESC=	Install web files
GRAPH_DESC=	Graph generation (requires Cairo)

GRAPH_RUN_DEPENDS=	nplot>=0:graphics/nplot

do-patch:
	@${REINPLACE_CMD} 's|NPlot.0.9.10.0\\lib\\net20|NPlot.0.9.10.1|' \
	${WRKSRC}/Ntp.Analyzer/Ntp.Analyzer.csproj
	@${REINPLACE_CMD} '/Mono.Posix.4.0.0.0/d' \
	${WRKSRC}/Ntp.Common/Ntp.Common.csproj

post-install-WEBFILES-on:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/html && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/ntpad ${STAGEDIR}${PREFIX}/sbin/ntpa
	${INSTALL_SCRIPT} ${WRKDIR}/ntpav ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKDIR}/ntpag ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKDIR}/ntpac ${STAGEDIR}${PREFIX}/sbin
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/graph.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/ntpd.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/openntp.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/small.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/bin/MySql.Data.dll ${STAGEDIR}${PREFIX}/libexec/ntpa
	${INSTALL_DATA} ${WRKSRC}/bin/Npgsql.dll ${STAGEDIR}${PREFIX}/libexec/ntpa
	${INSTALL_MAN} ${WRKSRC}/docs/ntpa.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}/var/log/ntpa
	${MKDIR} ${STAGEDIR}/var/run/ntpa

.include <bsd.port.mk>
