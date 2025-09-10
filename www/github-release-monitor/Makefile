PORTNAME=	github-release-monitor
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	www
MASTER_SITES=	LOCAL/dtxdf/${PORTNAME}/

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Self-hostable application to monitor GitHub repository releases
WWW=		https://github.com/iamspido/${PORTNAME}

LICENSE=	AGPLv3

USES=		nodejs:current,run

USE_RC_SUBR=	${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	HOMEDIR=${GRM_HOMEDIR} \
		USER=${GRM_USER}

WRKSRC=		${WRKDIR}/${PORTNAME}-files

PLIST_SUB=	GROUP=${GRM_GROUP} \
		HOMEDIR=${GRM_HOMEDIR} \
		USER=${GRM_USER}

GRM_HOMEDIR=	${WWWDIR}
GRM_USER=	www
GRM_GROUP=	www

do-install:
	@${MKDIR} ${STAGEDIR}${GRM_HOMEDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${GRM_HOMEDIR}

post-install:
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.env ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.env
	@${MKDIR} ${STAGEDIR}${GRM_HOMEDIR}/data
	@${MKDIR} ${STAGEDIR}${GRM_HOMEDIR}/.next/cache

.include <bsd.port.mk>
