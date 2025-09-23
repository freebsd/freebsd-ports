PORTNAME=	mattermost-webapp
PORTVERSION=	10.5.11
DISTVERSIONPREFIX=	v
CATEGORIES=	www
MASTER_SITES=	https://releases.mattermost.com/${PORTVERSION}/
DISTNAME=	mattermost-${PORTVERSION}-linux-amd64

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Webapp of Mattermost server
WWW=		https://mattermost.org/

LICENSE=	APACHE20

WWWDIR=		${PREFIX}/www/mattermost
NO_ARCH=	yes
NO_BUILD=	yes

MATTERMOSTD_USER=	mattermost
MATTERMOSTD_GROUP=	mattermost

USERS=		${MATTERMOSTD_USER}
GROUPS=		${MATTERMOSTD_GROUP}

PLIST_SUB=	MATTERMOSTD_USER=${MATTERMOSTD_USER} \
		MATTERMOSTD_GROUP=${MATTERMOSTD_GROUP}

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKDIR}/mattermost && ${COPYTREE_SHARE} client ${STAGEDIR}${WWWDIR}
	${MKDIR} ${STAGEDIR}${WWWDIR}/client/plugins

.include <bsd.port.mk>
