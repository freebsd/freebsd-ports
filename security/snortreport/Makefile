# Created by: Andrea Venturoli <freebsd@netfence.it>
# $FreeBSD$

PORTNAME=	snortreport
PORTVERSION=	1.3.4
CATEGORIES=	security www
MASTER_SITES=	http://symmetrixtech.com/download/

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Add-on module for snort to generate real-time web reports

LICENSE=	GPLv2

OPTIONS_DEFINE=		BARNYARD JPGRAPH MYSQL PGSQL DOCS

BARNYARD_DESC=		Depend on Barnyard2
JPGRAPH_DESC=		Graphical charting

BARNYARD_RUN_DEPENDS=	barnyard2:security/barnyard2
JPGRAPH_RUN_DEPENDS=	${LOCALBASE}/share/jpgraph/jpgraph.php:graphics/jpgraph2
.include <bsd.port.options.mk>

NO_BUILD=	yes
SUB_FILES=	pkg-message
PORTDOCS=	INSTALL Performance.txt create_indexes.sql
FTYPES=		css html js php phps png sample

USE_PHP=	yes
WANT_PHP_WEB=	yes

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
.endif

pre-everything::
	@${ECHO} ""
	@${ECHO} "You have to configure PHP either with MySQL or PostgreSQL"
	@${ECHO} "support in order to let snortreport collect its data."
	@${ECHO} ""

post-patch:
	${MV} ${WRKSRC}/srconf.php ${WRKSRC}/srconf.php.sample

do-install:
# srconf.conf contains snort database login credentials
	${INSTALL} -o ${WWWOWN} -g ${WWWGRP} -m 750 -d ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${FTYPES:S|^|${WRKSRC}/*|} ${STAGEDIR}${WWWDIR}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
