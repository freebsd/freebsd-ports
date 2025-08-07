PORTNAME=	consul-replicate
PORTVERSION=	0.4.0
DISTVERSIONPREFIX=	v
PORTREVISION=	28
CATEGORIES=	sysutils

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Consul cross-DC KV replication daemon
WWW=		https://github.com/hashicorp/consul-replicate

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="\
		-X github.com/${GH_ACCOUNT}/${PORTNAME}/version.Version=${PORTVERSION} \
		-X github.com/${GH_ACCOUNT}/${PORTNAME}/version.GitCommit=675a2c2 \
		-X github.com/${GH_ACCOUNT}/${PORTNAME}/version.GitDescribe=v${PORTVERSION} \
		"

USE_RC_SUBR=	consul-replicate

PLIST_FILES=	bin/${PORTNAME}

USERS=		consul
GROUPS=		consul

.include <bsd.port.mk>
