PORTNAME=	terraform
DISTVERSIONPREFIX=	v
DISTVERSION=	1.12.2
CATEGORIES=	sysutils
MASTER_SITES=	https://raw.githubusercontent.com/${GH_ACCOUNT}/${GH_PROJECT}/${DISTVERSIONFULL}/:gomod
DISTFILES=	${DISTVERSIONFULL}${EXTRACT_SUFX} \
		go.mod:gomod \
		internal/backend/remote-state/azure/go.mod:gomod \
		internal/backend/remote-state/consul/go.mod:gomod \
		internal/backend/remote-state/cos/go.mod:gomod \
		internal/backend/remote-state/gcs/go.mod:gomod \
		internal/backend/remote-state/kubernetes/go.mod:gomod \
		internal/backend/remote-state/oci/go.mod:gomod \
		internal/backend/remote-state/oss/go.mod:gomod \
		internal/backend/remote-state/pg/go.mod:gomod \
		internal/backend/remote-state/s3/go.mod:gomod \
		internal/legacy/go.mod:gomod
EXTRACT_ONLY=	${DISTFILES:N*.mod\:*:N*.mod:C/:.*//:Ngo.work}

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Provides a common configuration to launch infrastructure
WWW=		https://terraform.io/

USES=		cpe go:1.24,modules
USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
GH_PROJECT=	terraform

LICENSE_NAME=	Business Source License 1.1
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror pkg-sell auto-accept

CPE_VENDOR=	hashicorp
GO_MODULE=	github.com/hashicorp/terraform
GO_BUILDFLAGS=	-ldflags="-X github.com/hashicorp/terraform/version.dev=no"

# Disable some master port targets
TARGET_ORDER_OVERRIDE=	-1:go-post-extract

post-extract:
	@${ECHO_MSG} "===> Tidying ${GO_MODNAME} dependencies";
	@(cd ${GO_WRKSRC}; ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=${GO_MODCACHE} ${GO_CMD} mod tidy)
	@${ECHO_MSG} "===> Vendoring ${GO_MODNAME} dependencies";
	@(cd ${GO_WRKSRC}; ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GO_ENV} GOPROXY=${GO_MODCACHE} ${GO_CMD} mod vendor)

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
