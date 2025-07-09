PORTNAME=	mattermost
PORTVERSION=	10.5.8
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	LOCAL/decke
PKGNAMESUFFIX=	-server

# implicit-approval+ for decke
MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Open source Slack-alternative in Golang and React
WWW=		https://mattermost.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE.txt

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss \
		mattermost-webapp>=${PORTVERSION}:www/mattermost-webapp

USES=		go:modules tar:xz
USE_RC_SUBR=	mattermostd

GO_TARGET=	./cmd/mattermost ./cmd/mmctl ./scripts/config_generator
GO_BUILDFLAGS=	-ldflags=" \
		-X github.com/mattermost/mattermost/server/public/model.BuildNumber=${PORTVERSION} \
		-X github.com/mattermost/mattermost/server/public/model.BuildHashEnterprise=none \
		-X github.com/mattermost/mattermost/server/public/model.BuildEnterpriseReady=false"

WRKSRC_SUBDIR=	server
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
	${MKDIR} ${STAGEDIR}${WWWDIR}/templates
	cd ${GO_WRKSRC} && ${COPYTREE_SHARE} 'fonts i18n' ${STAGEDIR}${WWWDIR}
	cd ${GO_WRKSRC}/templates && ${CP} *.html *.js ${STAGEDIR}${WWWDIR}/templates

.include <bsd.port.mk>
