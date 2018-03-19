# $FreeBSD$

PORTNAME=	mattermost-webapp
PORTVERSION=	4.8.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www
MASTER_SITES=	https://releases.mattermost.com/${PORTVERSION}/
DISTNAME=	mattermost-${PORTVERSION}-linux-amd64

MAINTAINER=	loic.blot@unix-experience.fr
COMMENT=	Webapp of Mattermost server

LICENSE=	APACHE20

NO_BUILD=	yes

WWWDIR=		${PREFIX}/www/mattermost

MATTERMOSTD_USER=	mattermost
MATTERMOSTD_GROUP=	mattermost

USERS=		${MATTERMOSTD_USER}
GROUPS=		${MATTERMOSTD_GROUP}

PLIST_SUB=	MATTERMOSTD_USER=${MATTERMOSTD_USER} \
			MATTERMOSTD_GROUP=${MATTERMOSTD_GROUP}

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${CP} -R ${WRKDIR}/mattermost/client ${STAGEDIR}${WWWDIR}
	${MKDIR} ${STAGEDIR}${WWWDIR}/client/plugins

.include <bsd.port.post.mk>
