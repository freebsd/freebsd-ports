PORTNAME=	homer
DISTVERSIONPREFIX=	v
DISTVERSION=	23.10.1
CATEGORIES=	www
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/${GH_TAGNAME}/
DISTNAME=	homer

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	Dead simple static HOMepage for your servER
WWW=		https://github.com/bastienwirtz/homer

LICENSE=	APACHE20

USES=		zip
USE_GITHUB=	nodefault
GH_ACCOUNT=	bastienwirtz

NO_ARCH=	YES
NO_BUILD=	YES

PLIST_SUB=	HOMER_USERNAME=${WWWOWN}

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${CP} -a ${WRKDIR}/*.js ${WRKDIR}/logo.png ${WRKDIR}/index.html ${STAGEDIR}${WWWDIR}
	${MKDIR} ${STAGEDIR}${WWWDIR}/assets
	cd ${WRKDIR}/assets && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/assets
	${MKDIR} ${STAGEDIR}${WWWDIR}/resources
	cd ${WRKDIR}/resources && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/resources
	${INSTALL_DATA} ${WRKDIR}/assets/config.yml.dist \
		${STAGEDIR}${WWWDIR}/assets/config.yml

.include <bsd.port.mk>
