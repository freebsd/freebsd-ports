PORTNAME=	ocsinventory-ocsreports
PORTVERSION=	2.8
CATEGORIES=	net-mgmt
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/${PORTVERSION}/
DISTNAME=	OCSNG_UNIX_SERVER_${PORTVERSION}

MAINTAINER=	dgeo@centrale-marseille.fr
COMMENT=	Webconsole for OCS Inventory NG

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:web
USE_PHP=	curl gd mbstring mysqli openssl pcre session simplexml soap xml zip zlib
NO_ARCH=	yes
NO_BUILD=	yes
GH_ACCOUNT=	OCSInventory-NG
GH_PROJECT=	OCSInventory-ocsreports
SUB_FILES=	apache.conf pkg-message

ETCDIR=		${PREFIX}/etc/ocsinventory-server

WRKSRC=		${WRKDIR}/${PORTNAME}

do-extract:
	${TAR} xf ${DISTDIR}/${DISTFILES} -C ${WRKDIR}/ --strip-components=1 \
		--exclude ".git*" ${DISTNAME}/ocsreports
	${MV} ${WRKDIR}/ocsreports ${WRKDIR}/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR} ${STAGEDIR}${ETCDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR} "! -name dbconfig.inc.php ! -name cas.config.php")
	${INSTALL_DATA} ${FILESDIR}/dbconfig.inc.php.sample ${STAGEDIR}${WWWDIR}/dbconfig.inc.php.sample
	${INSTALL_DATA} ${WRKSRC}/backend/require/cas.config.php ${STAGEDIR}${WWWDIR}/backend/require/cas.config.php.sample
	${INSTALL_DATA} ${WRKDIR}/apache.conf ${STAGEDIR}${ETCDIR}/ocsreports.inc.sample
	${MKDIR} ${STAGEDIR}${DATADIR}/packages
	${MKDIR} ${STAGEDIR}${DATADIR}/snmp

.include <bsd.port.mk>
