PORTNAME=	mattermost
DISTVERSION=	10.11.12
CATEGORIES=	www
MASTER_SITES=	https://releases.mattermost.com/${DISTVERSION}/
PKGNAMESUFFIX=	-webapp
DISTNAME=	mattermost-${PORTVERSION}-linux-amd64

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Webapp of Mattermost server
WWW=		https://mattermost.org/

LICENSE=	APACHE20

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

MATTERMOSTD_USER=	mattermost
MATTERMOSTD_GROUP=	mattermost

USERS=		${MATTERMOSTD_USER}
GROUPS=		${MATTERMOSTD_GROUP}

PLIST_SUB=	MATTERMOSTD_USER=${MATTERMOSTD_USER} \
		MATTERMOSTD_GROUP=${MATTERMOSTD_GROUP}

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} client ${STAGEDIR}${WWWDIR}
	${MKDIR} ${STAGEDIR}${WWWDIR}/client/plugins

.include <bsd.port.mk>
