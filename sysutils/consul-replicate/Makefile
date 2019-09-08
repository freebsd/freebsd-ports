# $FreeBSD$

PORTNAME=	consul-replicate
PORTVERSION=	0.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Consul cross-DC KV replication daemon

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		fails to build

USES=		compiler go

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

USE_RC_SUBR=	consul-replicate

PLIST_FILES=	bin/${PORTNAME}

USERS=		consul
GROUPS=		consul

post-extract:
	@${MV} ${WRKSRC}/vendor/ ${WRKSRC}/src/

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}; \
		${SETENV} CGO_ENABLED=0 ${BUILD_ENV} ${MAKE_ENV} GOPATH=${WRKSRC} \
		go build -v -x -ldflags "\
		-X github.com/${GH_ACCOUNT}/${PORTNAME}/version.Version=${PORTVERSION}  \
		-X github.com/${GH_ACCOUNT}/${PORTNAME}/version.GitCommit=675a2c2  \
		-X github.com/${GH_ACCOUNT}/${PORTNAME}/version.GitDescribe=v${PORTVERSION} \
		" -o bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} \
		${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.pre.mk>

# golang assumes that if clang is in use, it is called "clang" and not "cc". If
# it's called "cc", go fails.
.if ${COMPILER_TYPE} == clang
BUILD_ENV=	CC=clang
.endif

.include <bsd.port.post.mk>
