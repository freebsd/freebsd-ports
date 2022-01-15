PORTNAME=	crowdsec
PORTVERSION=	1.2.3	# NOTE: change BUILD_VERSION and BUILD_TAG as well
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	marco@crowdsec.net
COMMENT=	CrowdSec lightweight and collaborative security engine

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	git:devel/git@lite \
		go:lang/go \
		jq:textproc/jq

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	crowdsecurity
GH_PROJECT=	crowdsec
GH_TAGNAME=	v1.2.3-freebsd
#GH_TAGNAME is automatically set from DISTVERSION

USE_RC_SUBR=	crowdsec

SUB_FILES=	pkg-message \
		pkg-deinstall

# BUILD_VERSION=$(git describe --tags $(git rev-list --tags --max-count=1))
# BUILD_TAG=$(git rev-parse HEAD)
MAKE_ENV=	BUILD_VERSION="v1.2.3" \
		BUILD_TAG="fc4be1e0ffc5888f2824358464cb2426cd4472e1"

PLUGIN_DIR=	${PREFIX}/lib/crowdsec/plugins
STAGE_PLUGINS=	${STAGEDIR}${PLUGIN_DIR}
STAGE_BIN=	${STAGEDIR}${PREFIX}/bin

post-patch:
	@${REINPLACE_CMD} 's,/etc/crowdsec/,${ETCDIR}/,g' \
		${WRKSRC}/pkg/csconfig/config.go \
		${WRKSRC}/pkg/cstest/hubtest_item.go \
		${WRKSRC}/cmd/crowdsec-cli/machines.go \
		${WRKSRC}/cmd/crowdsec-cli/main.go \
		${WRKSRC}/cmd/crowdsec/main.go \
		${WRKSRC}/config/config.yaml \
		${WRKSRC}/config/profiles.yaml

	@${REINPLACE_CMD} 's,/var/lib/,/var/db/,g' \
		${WRKSRC}/pkg/csconfig/config.go \
		${WRKSRC}/pkg/metabase/database.go \
		${WRKSRC}/config/config.yaml \
		${WRKSRC}/config/profiles.yaml

do-install:
	#
	# Binaries
	#

	${INSTALL_PROGRAM} ${WRKSRC}/cmd/crowdsec/crowdsec ${STAGE_BIN}/
	${INSTALL_PROGRAM} ${WRKSRC}/cmd/crowdsec-cli/cscli ${STAGE_BIN}/
	${LN} -s cscli ${STAGE_BIN}/crowdsec-cli

	@${MKDIR} ${STAGE_PLUGINS}
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/notifications/email/notification-email ${STAGE_PLUGINS}/
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/notifications/http/notification-http ${STAGE_PLUGINS}/
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/notifications/slack/notification-slack ${STAGE_PLUGINS}/
	${INSTALL_PROGRAM} ${WRKSRC}/plugins/notifications/splunk/notification-splunk ${STAGE_PLUGINS}/

	#
	# Configuration
	#

	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@(cd ${WRKSRC}/config && ${COPYTREE_SHARE} . ${STAGEDIR}${ETCDIR})

	@${MV} ${STAGEDIR}${ETCDIR}/acquis.yaml \
		${STAGEDIR}${ETCDIR}/acquis.yaml.sample

	@${MV} ${STAGEDIR}${ETCDIR}/config.yaml \
		${STAGEDIR}${ETCDIR}/config.yaml.sample

	@${MV} ${STAGEDIR}${ETCDIR}/profiles.yaml \
		${STAGEDIR}${ETCDIR}/profiles.yaml.sample

	# managed by "cscli simulation"
	@${MV} ${STAGEDIR}${ETCDIR}/simulation.yaml \
		${STAGEDIR}${ETCDIR}/simulation.yaml.sample

	#
	# Plugin configuration
	#

	@${MKDIR} ${STAGEDIR}${ETCDIR}/notifications

	@${MKDIR} ${STAGEDIR}${ETCDIR}/notifications/email
	@${MV} ${WRKSRC}/plugins/notifications/email/email.yaml \
		${STAGEDIR}${ETCDIR}/notifications/email/email.yaml.sample

	@${MKDIR} ${STAGEDIR}${ETCDIR}/notifications/http
	@${MV} ${WRKSRC}/plugins/notifications/http/http.yaml \
		${STAGEDIR}${ETCDIR}/notifications/http/http.yaml.sample

	@${MKDIR} ${STAGEDIR}${ETCDIR}/notifications/slack
	@${MV} ${WRKSRC}/plugins/notifications/slack/slack.yaml \
		${STAGEDIR}${ETCDIR}/notifications/slack/slack.yaml.sample

	@${MKDIR} ${STAGEDIR}${ETCDIR}/notifications/splunk
	@${MV} ${WRKSRC}/plugins/notifications/splunk/splunk.yaml \
		${STAGEDIR}${ETCDIR}/notifications/splunk/splunk.yaml.sample

	# updated by "cscli machines" at first service start
	@${MV} ${STAGEDIR}${ETCDIR}/local_api_credentials.yaml \
		${STAGEDIR}${ETCDIR}/local_api_credentials.yaml.sample

	# updated by "cscli capi" at first service start
	@${MV} ${STAGEDIR}${ETCDIR}/online_api_credentials.yaml \
		${STAGEDIR}${ETCDIR}/online_api_credentials.yaml.sample

	#
	# Data
	#

	@${MKDIR} ${STAGEDIR}${ETCDIR}/hub
	@${MKDIR} ${STAGEDIR}/var/db/crowdsec/data

	#
	# Log rotation
	#

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/crowdsec.conf-newsyslog ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/crowdsec.conf.sample

.include <bsd.port.mk>
