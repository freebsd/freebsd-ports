# Created by: Carsten Larsen <cs@innolan.dk>
# $FreeBSD$

PORTNAME=	ntpa
PORTVERSION=	0.8.2
CATEGORIES=	net
MASTER_SITES=	http://dist1.innolan.net/ \
		http://dist2.innolan.net/

MAINTAINER=	cs@innolan.net
COMMENT=	NTP data collection and charting

LICENSE=	MIT BSD3CLAUSE PostgreSQL GPLv2
LICENSE_COMB=	multi

BUILD_DEPENDS=	newtonsoft-json>=0:devel/newtonsoft-json
RUN_DEPENDS=	newtonsoft-json>=0:devel/newtonsoft-json

USES=		mono pkgconfig autoreconf gmake
GNU_CONFIGURE=	yes
NO_ARCH=	yes
OPTIONS_SUB=	yes
USE_RC_SUBR=	ntpa

USERS=		ntpa
GROUPS=		ntpa

SUB_FILES=	ntpad ntpav ntpac ntpag

OPTIONS_DEFINE=	WEBFILES GRAPH
WEBFILES_DESC=	Install web files
GRAPH_DESC=	Graph generation (requires Cairo)

GRAPH_BUILD_DEPENDS=	nplot>=0:graphics/nplot
GRAPH_RUN_DEPENDS=	nplot>=0:graphics/nplot

CONFIGURE_ARGS+=	--libdir=${LOCALBASE}/libexec --bindir=${LOCALBASE}/libexec/ntpa

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MGRAPH}
CONFIGURE_ENV+=	NPLOT_CFLAGS=" " NPLOT_LIBS="-r:../packages/NPlot.0.9.10.0/lib/net20/NPlot.dll"
.endif

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
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/ntpa/
	${INSTALL_DATA} ${WRKSRC}/examples/ntpa.conf ${STAGEDIR}${PREFIX}/etc/ntpa/ntpa.conf.sample
	${INSTALL_MAN} ${WRKSRC}/docs/ntpa.1 ${STAGEDIR}${PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/CHANGES ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/DATABASE ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}/var/log/ntpa
	${MKDIR} ${STAGEDIR}/var/run/ntpa
	${INSTALL_DATA} ${FILESDIR}/newsyslog ${STAGEDIR}${ETCDIR}/ntpa.newsyslog

.include <bsd.port.mk>
