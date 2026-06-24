PORTNAME=	loki
DISTVERSIONPREFIX=	v
DISTVERSION=	3.7.2
PORTREVISION=	1
CATEGORIES=	sysutils
PKGNAMEPREFIX=	grafana-
PKGNAMESUFFIX=	3

MAINTAINER=	daniel@morante.net
COMMENT=	Scalable, highly-available, multi-tenant log aggregation system
WWW=		https://github.com/grafana/loki

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	module modernc.org/sqlite only supported on aarch64 and amd64

USES=		go:modules cpe
CPE_VENDOR=	grafana
USE_GITHUB=	yes

GH_ACCOUNT=	grafana
GH_PROJECT=	loki

USE_RC_SUBR=	loki

GO_MOD_DIST=	github
GO_MODULE=	github.com/${GH_ACCOUNT}/${GH_PROJECT}/v3
GO_TARGET=	./cmd/loki ./cmd/loki-canary ./cmd/logcli ./cmd/lokitool
GO_BUILDFLAGS=	-v -ldflags "${LD_FLAG_STRING}"

LD_FLAG_STRING=	-s \
		${LD_FLAG_X_PREFIX}.Version=${DISTVERSION} \
		${LD_FLAG_X_PREFIX}.Revision=${PORTREVISION} \
		${LD_FLAG_X_PREFIX}.Branch=HEAD \
		${LD_FLAG_X_PREFIX}.BuildUser=${BUILD_USER} \
		${LD_FLAG_X_PREFIX}.BuildDate=$$(date -u +"%Y-%m-%dT%H:%M:%SZ")
LD_FLAG_X_PREFIX=	-X github.com/grafana/loki/v3/pkg/util/build
BUILD_USER?=	${USER}

LOKI_USER?=	loki
LOKI_GROUP?=	loki
LOKI_DATADIR?=	/var/db/${PORTNAME}

CONFLICTS_INSTALL=	grafana-loki

SUB_LIST=	LOKI_USER=${LOKI_USER} \
		LOKI_GROUP=${LOKI_GROUP} \
		LOKI_DATADIR=${LOKI_DATADIR}

USERS=		${LOKI_USER}
GROUPS=		${LOKI_GROUP}

PLIST_SUB=	${SUB_LIST}

# The main go.mod has "replace ./pkg/push => ./pkg/push".  go-post-fetch (800)
# runs go mod download from DIST_SUBDIR and needs pkg/push/go.mod present.
# post-fetch runs at priority 700, after do-fetch (500) downloads the tarball.
post-fetch:
	@(cd ${DISTDIR}/${DIST_SUBDIR}; [ -e pkg/push/go.mod ] || (\
		${MKDIR} pkg/push; \
		${TAR} -xzf ${DISTNAME}${EXTRACT_SUFX} \
			${PORTNAME}-${DISTVERSION}/pkg/push/go.mod \
			${PORTNAME}-${DISTVERSION}/pkg/push/go.sum; \
		${CP} ${PORTNAME}-${DISTVERSION}/pkg/push/go.mod pkg/push/go.mod; \
		${CP} ${PORTNAME}-${DISTVERSION}/pkg/push/go.sum pkg/push/go.sum; \
		${RM} -r ${PORTNAME}-${DISTVERSION}))

post-install:
	@${CP} ${WRKSRC}/cmd/loki/loki-local-config.yaml ${STAGEDIR}${PREFIX}/etc/loki.yaml.sample
	@${MKDIR} ${STAGEDIR}${LOKI_DATADIR}
	@${MKDIR} ${STAGEDIR}${LOKI_DATADIR}/rules-temp

.include <bsd.port.mk>
