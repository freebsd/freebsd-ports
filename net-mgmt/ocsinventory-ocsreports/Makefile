# $FreeBSD$

PORTNAME=	ocsinventory-ocsreports
PORTVERSION=	2.6
CATEGORIES=	net-mgmt

MAINTAINER=	dgeo@centrale-marseille.fr
COMMENT=	Webconsole for OCS Inventory NG

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:web
USE_PHP=	mysqli pcre zlib session xml gd zip openssl mbstring soap
NO_ARCH=	yes
NO_BUILD=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	OCSInventory-NG
GH_PROJECT=	OCSInventory-ocsreports
SUB_FILES=	apache.conf pkg-message

ETCDIR=		${PREFIX}/etc/ocsinventory-server

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR} ${STAGEDIR}${ETCDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR} "! -name dbconfig.inc.php ! -name cas.config.php")
	${INSTALL_DATA} ${WRKSRC}/dbconfig.inc.php ${STAGEDIR}${WWWDIR}/dbconfig.inc.php.sample
	${INSTALL_DATA} ${WRKSRC}/backend/require/cas.config.php ${STAGEDIR}${WWWDIR}/backend/require/cas.config.php.sample
	${INSTALL_DATA} ${WRKDIR}/apache.conf ${STAGEDIR}${ETCDIR}/ocsreports.inc.sample
	${MKDIR} ${STAGEDIR}${DATADIR}/packages
	${MKDIR} ${STAGEDIR}${DATADIR}/snmp

.include <bsd.port.mk>
