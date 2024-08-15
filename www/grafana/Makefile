PORTNAME=	grafana
DISTVERSIONPREFIX=	v
DISTVERSION=	10.4.5
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://dl.grafana.com/oss/release/:public \
		https://raw.githubusercontent.com/${GH_ACCOUNT}/${GH_PROJECT}/${DISTVERSIONFULL}/:gomod
DISTFILES=	grafana-${DISTVERSION}.linux-amd64${EXTRACT_SUFX}:public \
		go.mod:gomod \
		pkg/util/xorm/go.mod:gomod

MAINTAINER=	drtr0jan@yandex.ru
COMMENT=	Dashboard and graph editor for multiple data stores
WWW=		https://grafana.com/grafana/ \
		https://github.com/grafana/grafana

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 i386 riscv64

BUILD_DEPENDS=	wire:devel/go-wire
RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		cpe go:1.21,modules

USE_GITHUB=	yes

USE_RC_SUBR=	grafana
TAG=		17cbd42

GO_MODULE=	github.com/grafana/grafana
GO_TARGET=	./pkg/cmd/grafana \
		./pkg/cmd/grafana-server \
		./pkg/cmd/grafana-cli
GO_BUILDFLAGS=	-ldflags="-w -X main.version=${PORTVERSION} -X main.commit=${TAG}"

CONFLICTS_INSTALL=	grafana*

SUB_LIST=	GRAFANA_USER=${GRAFANA_USER} \
		GRAFANA_GROUP=${GRAFANA_GROUP} \
		GRAFANA_DATADIR=${GRAFANA_DATADIR} \
		GRAFANA_HOMEDIR=${GRAFANA_HOMEDIR} \
		GRAFANA_LOGDIR=${GRAFANA_LOGDIR} \
		GRAFANA_PLUGINDIR=${GRAFANA_PLUGINDIR} \
		GRAFANA_PROVISIONINGDIR=${GRAFANA_PROVISIONINGDIR}

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
	${SETENV} ${MAKE_ENV} ${GO_ENV} wire gen -tags "oss" ./pkg/server )

post-install:
	${MKDIR} ${STAGEDIR}${GRAFANA_HOMEDIR}
	${MKDIR} ${STAGEDIR}${GRAFANA_HOMEDIR}/conf
	${MKDIR} ${STAGEDIR}${GRAFANA_DATADIR}
	${MKDIR} ${STAGEDIR}${GRAFANA_PLUGINDIR}
.for dir in access-control alerting dashboards datasources notifiers plugins
	${MKDIR} ${STAGEDIR}${GRAFANA_PROVISIONINGDIR}/${dir}
.endfor
	${MKDIR} ${STAGEDIR}${GRAFANA_LOGDIR}
	( cd ${WRKDIR}/${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX} && ${COPYTREE_SHARE} public ${STAGEDIR}${GRAFANA_HOMEDIR} )
.for dir in input-datasource
	${MKDIR} ${STAGEDIR}${GRAFANA_HOMEDIR}/plugins-bundled/internal/${dir}
	( cd ${WRKDIR}/${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}/plugins-bundled/internal/${dir}/dist && ${COPYTREE_SHARE} . ${STAGEDIR}${GRAFANA_HOMEDIR}/plugins-bundled/internal/${dir} )
.endfor
	${INSTALL_DATA} ${WRKSRC}/conf/defaults.ini ${STAGEDIR}${GRAFANA_HOMEDIR}/conf/defaults.ini
	${INSTALL_DATA} ${WRKSRC}/conf/sample.ini ${STAGEDIR}${ETCDIR}/grafana.ini.sample
	${INSTALL_DATA} ${WRKSRC}/conf/ldap.toml ${STAGEDIR}${ETCDIR}/ldap.toml.sample
	${FIND} ${STAGEDIR}${DATADIR}/public -type f | ${SED} "s,^${STAGEDIR}${DATADIR},${DATADIR}," >> ${TMPPLIST}

.include <bsd.port.mk>
