PORTNAME=	crowdsec
PORTVERSION=	1.3.2	# NOTE: change BUILD_VERSION and BUILD_TAG as well
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
ALL_TARGET=	build

USE_GITHUB=	yes
GH_ACCOUNT=	crowdsecurity
GH_PROJECT=	crowdsec
GH_TAGNAME=	v1.3.2-freebsd-wip
#GH_TAGNAME is automatically set from DISTVERSION

OPTIONS_DEFINE=	FIREWALL_BOUNCER
OPTIONS_DEFAULT=

FIREWALL_BOUNCER_DESC=	Depend on security/crowdsec-firewall-bouncer
FIREWALL_BOUNCER_RUN_DEPENDS=	crowdsec-firewall-bouncer>=0.0.23.r2:security/crowdsec-firewall-bouncer

USE_RC_SUBR=	crowdsec

SUB_FILES=	pkg-deinstall pkg-install pkg-message

MAKE_ENV=	BUILD_VERSION="v1.3.2" \
		BUILD_TAG="716251323da59f1ce04fb1fc38af0a72629b5d78" \
		DEFAULT_CONFIGDIR="${PREFIX}/etc/crowdsec" \
		DEFAULT_DATADIR="/var/db/crowdsec/data"

PLUGIN_DIR=	${PREFIX}/lib/crowdsec/plugins
STAGE_PLUGINS=	${STAGEDIR}${PLUGIN_DIR}
STAGE_BIN=	${STAGEDIR}${PREFIX}/bin

post-patch:
	@${REINPLACE_CMD} 's,/etc/crowdsec/,${ETCDIR}/,g' \
		${WRKSRC}/config/config.yaml \
		${WRKSRC}/config/profiles.yaml

	@${REINPLACE_CMD} 's,/var/lib/,/var/db/,g' \
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

	@${MV} ${STAGEDIR}${ETCDIR}/console.yaml \
		${STAGEDIR}${ETCDIR}/console.yaml.sample

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
		${STAGEDIR}${ETCDIR}/notifications/email.yaml.sample

	@${MKDIR} ${STAGEDIR}${ETCDIR}/notifications/http
	@${MV} ${WRKSRC}/plugins/notifications/http/http.yaml \
		${STAGEDIR}${ETCDIR}/notifications/http.yaml.sample

	@${MKDIR} ${STAGEDIR}${ETCDIR}/notifications/slack
	@${MV} ${WRKSRC}/plugins/notifications/slack/slack.yaml \
		${STAGEDIR}${ETCDIR}/notifications/slack.yaml.sample

	@${MKDIR} ${STAGEDIR}${ETCDIR}/notifications/splunk
	@${MV} ${WRKSRC}/plugins/notifications/splunk/splunk.yaml \
		${STAGEDIR}${ETCDIR}/notifications/splunk.yaml.sample

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
	# Cleanup
	#

	@${RM} ${STAGEDIR}${ETCDIR}/crowdsec.service
	@${RM} ${STAGEDIR}${ETCDIR}/dev.yaml
	@${RM} ${STAGEDIR}${ETCDIR}/user.yaml
	@${RMDIR} ${STAGEDIR}${ETCDIR}/notifications/email
	@${RMDIR} ${STAGEDIR}${ETCDIR}/notifications/http
	@${RMDIR} ${STAGEDIR}${ETCDIR}/notifications/slack
	@${RMDIR} ${STAGEDIR}${ETCDIR}/notifications/splunk

.include <bsd.port.mk>
