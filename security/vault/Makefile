# $FreeBSD$

PORTNAME=	vault
PORTVERSION=	0.9.6
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Tool for securely accessing secrets

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go>=1.9:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}
COMMIT_ID=	7e1fbde40afee241f81ef08700e7987d86fc7242

USE_RC_SUBR=	vault

USERS=		vault
GROUPS=		vault

PLIST_FILES=	bin/${PORTNAME}

do-build:
	@cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${BUILD_ENV} CGO_ENABLED=0 GOPATH=${WRKSRC} \
		go build \
		-ldflags "\
		-X github.com/hashicorp/vault/version.Version=${PORTVERSION} \
		-X github.com/hashicorp/vault/version.VersionPrerelease= \
		-X github.com/hashicorp/vault/version.VersionMetadata= \
		-X github.com/hashicorp/vault/version.GitCommit='${COMMIT_ID}'" \
		-o bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
