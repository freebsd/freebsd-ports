# $FreeBSD$

PORTNAME=	mattermost-server
PORTVERSION=	5.10.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	loic.blot@unix-experience.fr
COMMENT=	Open source Slack-alternative in Golang and React

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	amd64 armv6 armv7 i386

BUILD_DEPENDS=	go>=1.8.1:lang/go
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss \
		mattermost-webapp>=${PORTVERSION}:www/mattermost-webapp

GO_LDFLAGS=	-X github.com/mattermost/mattermost-server/model.BuildNumber=${PORTVERSION}

USE_RC_SUBR=	mattermostd

USE_GITHUB=	yes
GH_ACCOUNT=	mattermost

WWWDIR=		${PREFIX}/www/mattermost

MATTERMOSTD_USER=	mattermost
MATTERMOSTD_GROUP=	mattermost

USERS=		${MATTERMOSTD_USER}
GROUPS=		${MATTERMOSTD_GROUP}

pre-build:
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}
	@cd ${WRKSRC} && \
		${MV} api4 app cmd config doc einterfaces imports jobs manualtesting \
		mlog migrations model plugin services store testlib utils web wsapi vendor \
		${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${GH_PROJECT} && \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go install -ldflags="${GO_LDFLAGS}" ./...

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/mattermost ${STAGEDIR}${PREFIX}/bin/mattermostd
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/mattermost
	${INSTALL_DATA} ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}/config/default.json ${STAGEDIR}${PREFIX}/etc/mattermost/config.json.sample
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} 'fonts i18n templates' ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
