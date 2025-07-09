PORTNAME=	grafana
DISTVERSIONPREFIX=	v
DISTVERSION=	12.0.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://dl.grafana.com/oss/release/ \
		https://raw.githubusercontent.com/${GH_ACCOUNT}/${GH_PROJECT}/${DISTVERSIONFULL}/:gomod
DISTFILES=	grafana-${DISTVERSION}.linux-amd64${EXTRACT_SUFX} \
		go.mod:gomod \
		go.work:gomod \
		.citools/bra/go.mod:gomod \
		.citools/cog/go.mod:gomod \
		.citools/cue/go.mod:gomod \
		.citools/golangci-lint/go.mod:gomod \
		.citools/jb/go.mod:gomod \
		.citools/lefthook/go.mod:gomod \
		.citools/swagger/go.mod:gomod \
		apps/advisor/go.mod:gomod \
		apps/alerting/notifications/go.mod:gomod \
		apps/dashboard/go.mod:gomod \
		apps/folder/go.mod:gomod \
		apps/investigations/go.mod:gomod \
		apps/playlist/go.mod:gomod \
		pkg/aggregator/go.mod:gomod \
		pkg/apimachinery/go.mod:gomod \
		pkg/apis/secret/go.mod:gomod \
		pkg/apiserver/go.mod:gomod \
		pkg/build/go.mod:gomod \
		pkg/build/wire/go.mod:gomod \
		pkg/codegen/go.mod:gomod \
		pkg/plugins/codegen/go.mod:gomod \
		pkg/promlib/go.mod:gomod \
		pkg/semconv/go.mod:gomod \
		pkg/storage/unified/apistore/go.mod:gomod \
		pkg/storage/unified/resource/go.mod:gomod \
		pkg/util/xorm/go.mod:gomod
EXTRACT_ONLY=	${DISTFILES:N*.mod\:*:N*.mod:C/:.*//:Ngo.work}

MAINTAINER=	drtr0jan@yandex.ru
COMMENT=	Dashboard and graph editor for multiple data stores
WWW=		https://grafana.com/grafana/ \
		https://github.com/grafana/grafana

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 riscv64

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		cpe go:modules

USE_GITHUB=	yes

USE_RC_SUBR=	grafana
TAG=		5bda17e

GO_MOD_DIST=	github
GO_MODULE=	github.com/grafana/grafana
GO_TARGET=	./pkg/cmd/grafana \
		./pkg/cmd/grafana-server \
		./pkg/cmd/grafana-cli
GO_BUILDFLAGS=	-ldflags="-w -X main.version=${DISTVERSION} -X main.commit=${TAG} \
		-X main.buildstamp=$$(${STAT} -f %Sm -t %s ${WRKSRC}/.gitignore)"

CONFLICTS_INSTALL=	grafana*

SUB_LIST=	GRAFANA_USER=${GRAFANA_USER} \
		GRAFANA_GROUP=${GRAFANA_GROUP} \
		GRAFANA_DATADIR=${GRAFANA_DATADIR} \
		GRAFANA_HOMEDIR=${GRAFANA_HOMEDIR} \
		GRAFANA_LOGDIR=${GRAFANA_LOGDIR} \
		GRAFANA_PLUGINDIR=${GRAFANA_PLUGINDIR} \
		GRAFANA_PROVISIONINGDIR=${GRAFANA_PROVISIONINGDIR}
# Disable some master port targets
TARGET_ORDER_OVERRIDE=	-1:go-post-extract

GRAFANA_USER?=	grafana
GRAFANA_GROUP?=	grafana

USERS=		${GRAFANA_USER}
GROUPS=		${GRAFANA_GROUP}

PLIST_SUB=	${SUB_LIST}

GRAFANA_DATADIR?=		/var/db/${PORTNAME}
GRAFANA_HOMEDIR?=		${DATADIR}
GRAFANA_LOGDIR?=		/var/log/${PORTNAME}
GRAFANA_PLUGINDIR?=		${GRAFANA_DATADIR}/plugins
GRAFANA_PROVISIONINGDIR?=	${ETCDIR}/provisioning

post-extract:
	@${ECHO_MSG} "===> Tidying ${GO_MODNAME} dependencies";
	@(cd ${GO_WRKSRC}; ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} \
		GOPROXY=${GO_MODCACHE} ${GO_CMD} mod tidy -e)
	@${ECHO_MSG} "===> Vendoring ${GO_MODNAME} dependencies";
	@(cd ${GO_WRKSRC}; ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} \
		GOPROXY=${GO_MODCACHE} ${GO_CMD} work vendor -e)

post-patch:
	@${REINPLACE_CMD} \
		-e 's|;data = /var/lib/grafana|data = ${GRAFANA_DATADIR}|g' \
		-e 's|;logs = /var/log/grafana|logs = ${GRAFANA_LOGDIR}|g' \
		-e 's|;plugins = /var/lib/grafana/plugins|plugins = ${GRAFANA_PLUGINDIR}|g' \
		-e 's|;provisioning = conf/provisioning|provisioning = ${GRAFANA_PROVISIONINGDIR}|g' \
		 ${WRKSRC}/conf/sample.ini

pre-build:
	@(cd ${GO_WRKSRC}; \
	${ECHO_MSG} "===>  Generating wire_gen.go"; \
	${SETENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=off ${GO_CMD} run \
		./pkg/build/wire/cmd/wire/main.go gen -tags "oss" ./pkg/server)

post-install:
	${MKDIR} ${STAGEDIR}${GRAFANA_HOMEDIR}
	${MKDIR} ${STAGEDIR}${GRAFANA_HOMEDIR}/conf
	${MKDIR} ${STAGEDIR}${GRAFANA_DATADIR}
	${MKDIR} ${STAGEDIR}${GRAFANA_PLUGINDIR}
.for dir in access-control alerting dashboards datasources plugins
	${MKDIR} ${STAGEDIR}${GRAFANA_PROVISIONINGDIR}/${dir}
.endfor
	${MKDIR} ${STAGEDIR}${GRAFANA_LOGDIR}
	(cd ${WRKDIR}/${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX} \
		&& ${COPYTREE_SHARE} public ${STAGEDIR}${GRAFANA_HOMEDIR})
	${INSTALL_DATA} ${WRKSRC}/conf/defaults.ini \
		${STAGEDIR}${GRAFANA_HOMEDIR}/conf/defaults.ini
	${INSTALL_DATA} ${WRKSRC}/conf/sample.ini \
		${STAGEDIR}${ETCDIR}/grafana.ini.sample
	${INSTALL_DATA} ${WRKSRC}/conf/ldap.toml \
		${STAGEDIR}${ETCDIR}/ldap.toml.sample
	${FIND} ${STAGEDIR}${DATADIR}/public -type f | \
		${SED} "s,^${STAGEDIR}${DATADIR},${DATADIR}," >> ${TMPPLIST}

.include <bsd.port.mk>
