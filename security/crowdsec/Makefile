PORTNAME=	crowdsec
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.11
CATEGORIES=	security

MAINTAINER=	marco@crowdsec.net
COMMENT=	CrowdSec lightweight and collaborative security engine
WWW=		https://github.com/crowdsecurity/crowdsec

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libre2.so:devel/re2

USES=		go:modules pkgconfig
_COMMIT=	d64ee2ae
_BUILD_DATE=	$$(date -u "+%F_%T")
USE_RC_SUBR=	crowdsec

GO_MODULE=	github.com/crowdsecurity/crowdsec
GO_TARGET=	./cmd/crowdsec \
		./cmd/crowdsec-cli \
		./cmd/notification-email \
		./cmd/notification-http \
		./cmd/notification-sentinel \
		./cmd/notification-slack \
		./cmd/notification-splunk

GO_BUILDFLAGS=	-v -trimpath -tags netgo,osusergo,sqlite_omit_load_extension,re2_cgo \
		-ldflags="\
		-a -s \
		-X github.com/crowdsecurity/go-cs-lib/version.Version=${DISTVERSIONPREFIX}${PKGVERSION} \
		-X github.com/crowdsecurity/go-cs-lib/version.BuildDate=${_BUILD_DATE} \
		-X github.com/crowdsecurity/go-cs-lib/version.Tag=${_COMMIT} \
		-X ${GO_MODULE}/pkg/cwversion.Codename=alphaga \
		-X ${GO_MODULE}/pkg/csconfig.defaultConfigDir=${PREFIX}/etc/crowdsec \
		-X ${GO_MODULE}/pkg/csconfig.defaultDataDir=/var/db/crowdsec/data \
		-X ${GO_MODULE}/pkg/cwversion.Libre2=C++"

SUB_FILES=	pkg-deinstall pkg-install pkg-message crowdsec.cron upgrade-hub

OPTIONS_DEFINE=	FIREWALL_BOUNCER
OPTIONS_DEFAULT=

FIREWALL_BOUNCER_DESC=	Depend on security/crowdsec-firewall-bouncer
FIREWALL_BOUNCER_RUN_DEPENDS=	crowdsec-firewall-bouncer>=0.0.27:security/crowdsec-firewall-bouncer

PLUGIN_DIR=	${PREFIX}/lib/crowdsec/plugins
STAGE_PLUGINS=	${STAGEDIR}${PLUGIN_DIR}
STAGE_BIN=	${STAGEDIR}${PREFIX}/bin

post-patch:
	@${REINPLACE_CMD} 's,/etc/crowdsec/,${ETCDIR}/,g' \
		${WRKSRC}/config/config.yaml

	@${REINPLACE_CMD} 's,/var/lib/,/var/db/,g' \
		${WRKSRC}/config/config.yaml

do-install:
	#
	# Binaries
	#

	${INSTALL_PROGRAM} ${WRKDIR}/bin/crowdsec ${STAGE_BIN}/
	${INSTALL_PROGRAM} ${WRKDIR}/bin/crowdsec-cli ${STAGE_BIN}/cscli

	# keep this around for compatibility
	${LN} -s cscli ${STAGE_BIN}/crowdsec-cli

	@${MKDIR} ${STAGE_PLUGINS}
	${INSTALL_PROGRAM} ${WRKDIR}/bin/notification-email ${STAGE_PLUGINS}/
	${INSTALL_PROGRAM} ${WRKDIR}/bin/notification-http ${STAGE_PLUGINS}/
	${INSTALL_PROGRAM} ${WRKDIR}/bin/notification-sentinel ${STAGE_PLUGINS}/
	${INSTALL_PROGRAM} ${WRKDIR}/bin/notification-slack ${STAGE_PLUGINS}/
	${INSTALL_PROGRAM} ${WRKDIR}/bin/notification-splunk ${STAGE_PLUGINS}/

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
	@${MV} ${WRKSRC}/cmd/notification-email/email.yaml \
		${STAGEDIR}${ETCDIR}/notifications/email.yaml.sample

	@${MKDIR} ${STAGEDIR}${ETCDIR}/notifications/http
	@${MV} ${WRKSRC}/cmd/notification-http/http.yaml \
		${STAGEDIR}${ETCDIR}/notifications/http.yaml.sample

	@${MKDIR} ${STAGEDIR}${ETCDIR}/notifications/sentinel
	@${MV} ${WRKSRC}/cmd/notification-sentinel/sentinel.yaml \
		${STAGEDIR}${ETCDIR}/notifications/sentinel.yaml.sample

	@${MKDIR} ${STAGEDIR}${ETCDIR}/notifications/slack
	@${MV} ${WRKSRC}/cmd/notification-slack/slack.yaml \
		${STAGEDIR}${ETCDIR}/notifications/slack.yaml.sample

	@${MKDIR} ${STAGEDIR}${ETCDIR}/notifications/splunk
	@${MV} ${WRKSRC}/cmd/notification-splunk/splunk.yaml \
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
	@${MKDIR} ${STAGEDIR}${ETCDIR}/acquis.d
	@${MKDIR} ${STAGEDIR}/var/db/crowdsec/data
	@${MKDIR} ${STAGEDIR}/var/db/crowdsec/data/trace

	#
	# Cron
	#

	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/crowdsec
	${INSTALL_DATA} ${WRKDIR}/upgrade-hub \
		${STAGEDIR}${PREFIX}/libexec/crowdsec/upgrade-hub

	#
	# Cleanup
	#

	@${RM} ${STAGEDIR}${ETCDIR}/acquis_win.yaml
	@${RM} ${STAGEDIR}${ETCDIR}/config_win_no_lapi.yaml
	@${RM} ${STAGEDIR}${ETCDIR}/config_win.yaml
	@${RM} ${STAGEDIR}${ETCDIR}/crowdsec.cron.daily
	@${RM} ${STAGEDIR}${ETCDIR}/crowdsec.service
	@${RM} ${STAGEDIR}${ETCDIR}/context.yaml
	@${RM} ${STAGEDIR}${ETCDIR}/detect.yaml
	@${RM} ${STAGEDIR}${ETCDIR}/dev.yaml
	@${RM} ${STAGEDIR}${ETCDIR}/user.yaml
	@${RMDIR} ${STAGEDIR}${ETCDIR}/notifications/email
	@${RMDIR} ${STAGEDIR}${ETCDIR}/notifications/http
	@${RMDIR} ${STAGEDIR}${ETCDIR}/notifications/sentinel
	@${RMDIR} ${STAGEDIR}${ETCDIR}/notifications/slack
	@${RMDIR} ${STAGEDIR}${ETCDIR}/notifications/splunk

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/cron.d
	${INSTALL_DATA} ${WRKDIR}/crowdsec.cron ${STAGEDIR}${PREFIX}/etc/cron.d/crowdsec

.include <bsd.port.mk>
