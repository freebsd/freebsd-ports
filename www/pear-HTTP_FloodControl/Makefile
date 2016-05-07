# Created by: Ditesh Shashikant Gathani <ditesh@gathani.org>
# $FreeBSD$

PORTNAME=	HTTP_FloodControl
PORTVERSION=	0.1.1
CATEGORIES=	www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR classes to detect and protect from attempts to flood a site

BUILD_DEPENDS=	${PEARDIR}/HTTP.php:www/pear-HTTP
RUN_DEPENDS=	${PEARDIR}/HTTP.php:www/pear-HTTP

DOCS=		README LICENSE
OPTIONS_DEFINE=	PEAR_DB PEAR_MDB PEAR_MDB2
PEAR_DB_DESC=	PEAR::DB support
PEAR_MDB_DESC=	PEAR::MDB support
PEAR_MDB2_DESC=	PEAR::MDB2 support

USES=	pear

PEAR_DB_RUN_DEPENDS=	${PEARDIR}/DB.php:databases/pear-DB
PEAR_MDB_RUN_DEPENDS=	${PEARDIR}/MDB.php:databases/pear-MDB
PEAR_MDB2_RUN_DEPENDS=	${PEARDIR}/MDB2.php:databases/pear-MDB2

post-extract:
	${MKDIR} ${WRKSRC}/docs
	${MV} ${WRKSRC}/README ${WRKSRC}/LICENSE ${WRKSRC}/docs
	${MV} ${WRKDIR}/package2.xml ${WRKDIR}/package.xml

.include <bsd.port.mk>
