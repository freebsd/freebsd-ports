PORTNAME=	Zonemaster-GUI
DISTVERSION=	5.0.0
CATEGORIES=	www dns perl5
MASTER_SITES=	https://github.com/zonemaster/zonemaster-gui/releases/download/v${DISTVERSION}/
PKGNAMEPREFIX=	p5-
DISTFILES=	zonemaster_web_gui_v${DISTVERSION}.zip

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Perl Web Front End for Zonemaster DNS testing
WWW=		https://zonemaster.net/en

LICENSE=	CC-BY-4.0
LICENSE_FILE=	${WRKDIR}/LICENSE

RUN_DEPENDS=	p5-Zonemaster-Backend>0:dns/p5-Zonemaster-Backend \
		p5-Zonemaster-Engine>0:dns/p5-Zonemaster-Engine

USES=		apache:run localbase
WWWDIR=		${PREFIX}/www/zonemaster-web-gui
NO_ARCH=	yes
NO_BUILD=	yes

USERS=		zonemaster
GROUPS=		zonemaster

post-extract:
	${MV} ${WRKDIR}/dist/config.json ${WRKDIR}/config.json.sample

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR} \
		${STAGEDIR}${PREFIX}/${APACHEETCDIR}/Includes
	${SED} -i '' -e 's|/var/www/html/zonemaster-web-gui/dist|${WWWDIR}|g' \
		${WRKDIR}/zonemaster.conf-example
	${INSTALL_DATA} ${WRKDIR}/zonemaster.conf-example \
		${STAGEDIR}/${PREFIX}/${APACHEETCDIR}/Includes/zonemaster.conf.sample
	${INSTALL_DATA} ${WRKDIR}/config.json.sample \
		${STAGEDIR}${WWWDIR}/config.json.sample
	(cd ${WRKDIR}/dist && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
