PORTNAME=	tempo
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.2
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES+=	https://raw.githubusercontent.com/${GH_ACCOUNT}/${PORTNAME}/${DISTVERSIONFULL}/
PKGNAMEPREFIX=	grafana-
DISTFILES=	go.mod

MAINTAINER=	daniel@morante.net
COMMENT=	High volume, minimal dependency distributed tracing backend
WWW=		https://github.com/grafana/tempo

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	grafana
GH_PROJECT=	tempo

USE_RC_SUBR=	tempo

GO_MODULE=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=	./cmd/tempo ./cmd/tempo-query ./cmd/tempo-cli ./cmd/tempo-vulture
GO_BUILDFLAGS=	-v -ldflags "${LD_FLAG_STRING}"

LD_FLAG_STRING=	-s \
		${LD_FLAG_X_PREFIX}.Version=${DISTVERSION} \
		${LD_FLAG_X_PREFIX}.Revision=${PORTREVISION} \
		${LD_FLAG_X_PREFIX}.Branch=HEAD \
		${LD_FLAG_X_PREFIX}.BuildUser=${BUILD_USER} \
		${LD_FLAG_X_PREFIX}.BuildDate=$$(date -u +"%Y-%m-%dT%H:%M:%SZ")
LD_FLAG_X_PREFIX=	-X github.com/grafana/tempo/pkg/util/build
BUILD_USER?=	${USER}

TEMPO_USER?=	tempo
TEMPO_GROUP?=	tempo
TEMPO_DATADIR?=	/var/db/${PORTNAME}

SUB_LIST=	TEMPO_USER=${TEMPO_USER} \
		TEMPO_GROUP=${TEMPO_GROUP} \
		TEMPO_DATADIR=${TEMPO_DATADIR} \

USERS=		${TEMPO_USER}
GROUPS=		${TEMPO_GROUP}

PLIST_SUB=	${SUB_LIST}

post-install:
	@${CP} ${WRKSRC}/example/docker-compose/shared/tempo.yaml ${STAGEDIR}${PREFIX}/etc/tempo.yaml.sample
	@${MKDIR} ${STAGEDIR}${TEMPO_DATADIR}

.include <bsd.port.mk>
