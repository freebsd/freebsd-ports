# $FreeBSD$

PORTNAME=	ntpa
PORTVERSION=	0.6.1
CATEGORIES=	net
MASTER_SITES=	http://suyai.innolan.net/

MAINTAINER=	cs@innolan.dk
COMMENT=	NTP data collection and charting

LICENSE=	MIT

OPTIONS_DEFINE=	GRAPH PGSQL MYSQL
OPTION_MULTI=	PGSQL MYSQL
GRAPH_DESC=	Graphs and HTML generation (requires Cairo)
PGSQL_DESC=	PostgreSQL Connector
MYSQL_DESC=	MySQL Connector (GPL)

OPTIONS_DEFAULT=	GRAPH PGSQL

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

post-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/html && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	${INSTALL_MAN} ${WRKSRC}/docs/ntpa.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
	${MKDIR} ${STAGEDIR}/var/log/ntpa
	${MKDIR} ${STAGEDIR}/var/run/ntpa

.include <bsd.port.mk>
