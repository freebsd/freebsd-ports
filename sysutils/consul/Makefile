# $FreeBSD$

PORTNAME=	consul
PORTVERSION=	0.9.2
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Service discovery and configuration made easy

LICENSE=	MPL

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USES=		compiler

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

USE_RC_SUBR=	consul

PLIST_FILES=	bin/consul

USERS=		consul
GROUPS=		consul

post-extract:
	@${MV} ${WRKSRC}/vendor/ ${WRKSRC}/src/

do-build:
	@cd ${WRKSRC}/src/github.com/hashicorp/consul; ${SETENV} CGO_ENABLED=0 ${BUILD_ENV} GOPATH=${WRKSRC} go build \
		-ldflags "\
		-X github.com/hashicorp/consul/version.Version=${PORTVERSION}  \
		-X github.com/hashicorp/consul/version.VersionPrerelease=  \
		-X github.com/hashicorp/consul/version.GitDescribe=v${PORTVERSION} \
		" \
		-o bin/consul

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/hashicorp/consul/bin/consul ${STAGEDIR}${PREFIX}/bin/consul

.include <bsd.port.pre.mk>

# golang assumes that if clang is in use, it is called "clang" and not "cc". If
# it's called "cc", go fails.
.if ${COMPILER_TYPE} == clang
BUILD_ENV=	CC=clang
.endif

.include <bsd.port.post.mk>
