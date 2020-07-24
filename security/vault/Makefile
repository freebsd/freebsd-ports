# $FreeBSD$

PORTNAME=	vault
PORTVERSION=	1.5.0
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
GO_BUILDFLAGS=	-tags=ui \
		-ldflags="\
		-X github.com/hashicorp/vault/version.Version=${PORTVERSION} \
		-X github.com/hashicorp/vault/version.VersionPrerelease= \
		-X github.com/hashicorp/vault/version.VersionMetadata= \
		-X github.com/hashicorp/vault/version.GitCommit='${COMMIT_ID}'"

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
