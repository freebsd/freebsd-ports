PORTNAME=	vault
PORTVERSION=	1.14.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security
MASTER_SITES=	https://raw.githubusercontent.com/hashicorp/vault/${DISTVERSIONFULL}/
DISTFILES=	go.mod \
		api/go.mod \
		api/auth/approle/go.mod \
		api/auth/kubernetes/go.mod \
		api/auth/userpass/go.mod \
		sdk/go.mod

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tool for securely accessing secrets
WWW=		https://vaultproject.io/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
CPE_VENDOR=	hashicorp
USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
USE_RC_SUBR=	vault

GO_MODULE=	github.com/hashicorp/vault
GO_BUILDFLAGS=	-ldflags="-s \
		-X github.com/hashicorp/vault/version.GitCommit=${GITID} \
		-X github.com/hashicorp/vault/version.BuildDate=${SOURCE_DATE_EPOCH:U${SOURCE_DATE_EPOCH_CMD:sh}} \
		"

SUB_FILES=	pkg-message

USERS=		vault
GROUPS=		vault

PLIST_FILES=	bin/${PORTNAME}

GITID=	13a649f860186dffe3f3a4459814d87191efc321

.include <bsd.port.pre.mk>

# Bring DISTINFO_FILE into scope so we can get the timestamp.
SOURCE_DATE_EPOCH_CMD=	date -ur \
			$$(${GREP} -m1 TIMESTAMP ${DISTINFO_FILE} | ${SED} -e 's/[^0-9]//g') \
			'+%Y-%m-%dT%H:%M:%SZ'

.include <bsd.port.post.mk>
