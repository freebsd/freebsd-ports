# Created by: Carsten Larsen <cs@innolan.dk>
# $FreeBSD$

PORTNAME=	ntpa
PORTVERSION=	0.6.2
CATEGORIES=	net
MASTER_SITES=	http://suyai.innolan.net/

MAINTAINER=	cs@innolan.dk
COMMENT=	NTP data collection and charting

LICENSE=	MIT

OPTIONS_DEFINE=	WEBFILES GRAPH
OPTIONS_DEFAULT=	PGSQL
OPTIONS_MULTI=		DATABASE
OPTIONS_MULTI_DATABASE=	PGSQL MYSQL
WEBFILES_IMPLIES=	GRAPH
WEBFILES_DESC=	Install web files
GRAPH_DESC=	Graph generation (requires Cairo)
PGSQL_DESC=	PostgreSQL Connector
MYSQL_DESC=	MySQL Connector (GPL)

GRAPH_LIB_DEPENDS=	libgdiplus.so:x11-toolkits/libgdiplus \
			libcairo.so:graphics/cairo \
			libpng.so:graphics/png
GRAPH_RUN_DEPENDS=	${LOCALBASE}/share/fonts/webfonts/arial.ttf:x11-fonts/webfonts
GRAPH_CONFIGURE_ON=	GRAPH
MYSQL_CONFIGURE_ON=	MYSQL
PGSQL_CONFIGURE_ON=	PGSQL

USES=		mono
NO_ARCH=	yes
HAS_CONFIGURE=	yes
OPTIONS_SUB=	yes
USE_RC_SUBR=	ntpa

USERS=		ntpa
GROUPS=		ntpa

SUB_FILES=	ntpad ntpav ntpac
WRKSRC=		${WRKDIR}/anguist-ntpa-9204e1e36b8d

.include <bsd.port.options.mk>

pre-install:
	@${MKDIR} ${WRKSRC}/script
	${MV} ${WRKDIR}/ntpad ${WRKSRC}/script/ntpa
	${MV} ${WRKDIR}/ntpav ${WRKSRC}/script/ntpav
	${MV} ${WRKDIR}/ntpac ${WRKSRC}/script/ntpac

post-install-WEBFILES-on:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/html && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	${INSTALL_MAN} ${WRKSRC}/docs/ntpa.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
	${MKDIR} ${STAGEDIR}/var/log/ntpa
	${MKDIR} ${STAGEDIR}/var/run/ntpa

.include <bsd.port.mk>
