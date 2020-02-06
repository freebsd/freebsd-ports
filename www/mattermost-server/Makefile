# $FreeBSD$

PORTNAME=	mattermost-server
PORTVERSION=	5.19.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	loic.blot@unix-experience.fr
COMMENT=	Open source Slack-alternative in Golang and React

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	amd64 armv6 armv7 i386

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss \
		mattermost-webapp>=${PORTVERSION}:www/mattermost-webapp

USES=		go:modules

GO_TARGET=	./cmd/mattermost ./config/config_generator
GO_BUILDFLAGS=	-ldflags="-X github.com/mattermost/mattermost-server/model.BuildNumber=${PORTVERSION}"

USE_RC_SUBR=	mattermostd

USE_GITHUB=	yes
GH_ACCOUNT=	mattermost

WWWDIR=		${PREFIX}/www/mattermost

MATTERMOSTD_USER=	mattermost
MATTERMOSTD_GROUP=	mattermost

USERS=		${MATTERMOSTD_USER}
GROUPS=		${MATTERMOSTD_GROUP}

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/mattermost ${STAGEDIR}${PREFIX}/bin/mattermostd
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/mattermost
	${SETENV} OUTPUT_CONFIG=${WRKSRC}/config/default.json ${WRKDIR}/bin/config_generator
	${INSTALL_DATA} ${WRKSRC}/config/default.json ${STAGEDIR}${PREFIX}/etc/mattermost/config.json.sample
	${RM} ${STAGEDIR}${PREFIX}/bin/config_generator
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${GO_WRKSRC} && ${COPYTREE_SHARE} 'fonts i18n templates' ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
