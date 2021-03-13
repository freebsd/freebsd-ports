# $FreeBSD$

PORTNAME=	mattermost-webapp
PORTVERSION=	5.32.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www
MASTER_SITES=	https://releases.mattermost.com/${PORTVERSION}/
DISTNAME=	mattermost-${PORTVERSION}-linux-amd64

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Webapp of Mattermost server

LICENSE=	APACHE20

NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR=		${PREFIX}/www/mattermost

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

post-install:
	(cd ${STAGEDIR}${PREFIX} && \
		${FIND} -E -s ${WWWDIR_REL}/client -type f -regex '.*[0-9a-f]{20,}.*\.(apng|css|eot|gif|jpg|js|json|map|mp3|png|svg|ttf|woff|woff2)$$' >> ${TMPPLIST})

.include <bsd.port.mk>
