PORTNAME=	loki
DISTVERSIONPREFIX=	v
DISTVERSION=	2.9.2
PORTREVISION=	28
CATEGORIES=	sysutils
PKGNAMEPREFIX=	grafana-

MAINTAINER=	freebsd@funzi.org
COMMENT=	Scalable, highly-available, multi-tenant log aggregation system
WWW=		https://github.com/grafana/loki

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules cpe
CPE_VENDOR=	grafana
USE_GITHUB=	yes

GH_ACCOUNT=	grafana
GH_PROJECT=	loki

USE_RC_SUBR=	loki promtail

GO_TARGET=	./cmd/loki ./cmd/loki-canary ./cmd/logcli ./clients/cmd/promtail
GO_BUILDFLAGS=	-v -ldflags "${LD_FLAG_STRING}"

LD_FLAG_STRING=	-s \
		${LD_FLAG_X_PREFIX}.Version=${PORTVERSION} \
		${LD_FLAG_X_PREFIX}.Revision=${PORTREVISION} \
		${LD_FLAG_X_PREFIX}.Branch=HEAD \
		${LD_FLAG_X_PREFIX}.BuildUser=${BUILD_USER} \
		${LD_FLAG_X_PREFIX}.BuildDate=$$(date -u +"%Y-%m-%dT%H:%M:%SZ")
LD_FLAG_X_PREFIX=	-X github.com/grafana/loki/pkg/util/build
BUILD_USER?=	${USER}

LOKI_USER?=	loki
LOKI_GROUP?=	loki
LOKI_DATADIR?=	/var/db/${PORTNAME}

PROMTAIL_USER?=	promtail
PROMTAIL_GROUP?=	promtail
PROMTAIL_DATADIR?=	/var/db/promtail

SUB_LIST=	LOKI_USER=${LOKI_USER} \
		LOKI_GROUP=${LOKI_GROUP} \
		LOKI_DATADIR=${LOKI_DATADIR} \
		PROMTAIL_USER=${PROMTAIL_USER} \
		PROMTAIL_GROUP=${PROMTAIL_GROUP} \
		PROMTAIL_DATADIR=${PROMTAIL_DATADIR}

USERS=		${LOKI_USER} ${PROMTAIL_USER}
GROUPS=		${LOKI_GROUP} ${PROMTAIL_GROUP}

PLIST_SUB=	${SUB_LIST}

post-install:
	@${CP} ${WRKSRC}/cmd/loki/loki-local-config.yaml ${STAGEDIR}${PREFIX}/etc/loki.yaml.sample
	@${CP} ${WRKSRC}/clients/cmd/promtail/promtail-local-config.yaml ${STAGEDIR}${PREFIX}/etc/promtail.yaml.sample
	@${MKDIR} ${STAGEDIR}${LOKI_DATADIR}
	@${MKDIR} ${STAGEDIR}${LOKI_DATADIR}/rules-temp
	@${MKDIR} ${STAGEDIR}${PROMTAIL_DATADIR}

.include <bsd.port.mk>
