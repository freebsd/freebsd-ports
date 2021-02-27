# $FreeBSD$

PORTNAME=	vault
PORTVERSION=	1.6.3
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Tool for securely accessing secrets

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_TUPLE=	hashicorp:${PORTNAME}:${VAULTTAG}:DEFAULT \
		swills:vaultui:${VAULTUITAG}:vaultui

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
COMMIT_ID=	b540be4b7ec48d0dd7512c8d8df9399d6bf84d76
GO_BUILDFLAGS=	-tags=ui \
		-ldflags="\
		-X github.com/hashicorp/vault/sdk/version.Version=${PORTVERSION} \
		-X github.com/hashicorp/vault/sdk/version.VersionPrerelease= \
		-X github.com/hashicorp/vault/sdk/version.VersionMetadata= \
		-X github.com/hashicorp/vault/sdk/version.GitCommit='${COMMIT_ID}'"

VAULTTAG=	${DISTVERSIONPREFIX}${PORTVERSION}
VAULTUITAG=	${DISTVERSIONPREFIX}${PORTVERSION}

USE_RC_SUBR=	vault

USERS=		vault
GROUPS=		vault

PLIST_FILES=	bin/${PORTNAME}
SUB_FILES=	pkg-message

PORTSCOUT=	limit:^(v?)[0-9]+\.[0-9]+\.[0-9]+$

post-patch:
	@${CP} ${WRKDIR}/vaultui-${PORTVERSION}/http/bindata_assetfs.go ${WRKDIR}/vault-${PORTVERSION}/http/bindata_assetfs.go

.include <bsd.port.mk>
