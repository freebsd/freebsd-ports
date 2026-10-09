PORTNAME=	filepizza
DISTVERSION=	2.0.20260131
CATEGORIES=	www
MASTER_SITES=	LOCAL/dtxdf/${PORTNAME}/
# For instructions on how to create assets:
#   https://github.com/DtxdF/port-assets-makejails/tree/main/filepizza
DISTFILES=	${PORTNAME}-${GITID}${EXTRACT_SUFX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Peer-to-peer file transfers in your browser
WWW=		https://file.pizza

LICENSE=	BSD3CLAUSE OFL11
LICENSE_COMB=	multi

USES=		nodejs:lts,run

USE_RC_SUBR=	${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes
SUB_LIST=	HOMEDIR=${FILEPIZZA_HOMEDIR} \
		USER=${FILEPIZZA_USER}

WRKSRC=		${WRKDIR}/${PORTNAME}-files

PLIST_SUB=	HOMEDIR=${FILEPIZZA_HOMEDIR}

GITID=		3258673e790145ba86637114a35388165a651ff3

FILEPIZZA_HOMEDIR=	${WWWDIR}
FILEPIZZA_USER=		www

do-install:
	@${MKDIR} ${STAGEDIR}${FILEPIZZA_HOMEDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${FILEPIZZA_HOMEDIR}

post-install:
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.env ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.env

.include <bsd.port.mk>
