# $FreeBSD$

PORTNAME=	nomad
PORTVERSION=	0.6.3
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	jhixson@gmail.com
COMMENT=	Cluster manager and scheduler

LICENSE=	MPL20

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	go>=1.8:lang/go

USES=		compiler

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
GH_SUBDIR=	src/github.com/hashicorp/nomad

USE_RC_SUBR=	nomad

USERS=		nomad
GROUPS=		nomad

STRIP=

do-build:
	@cd ${WRKSRC}/src/github.com/hashicorp/nomad; \
	${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -v -x \
		-ldflags "-X main.GitDescribe=${DISTVERSIONFULL}" -o bin/nomad

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/hashicorp/nomad/bin/nomad ${STAGEDIR}${PREFIX}/bin/nomad
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/nomad
	${INSTALL_DATA} ${WRKSRC}/src/github.com/hashicorp/nomad/dist/client.hcl \
		${STAGEDIR}${PREFIX}/etc/nomad/client.hcl.sample
	${INSTALL_DATA} ${WRKSRC}/src/github.com/hashicorp/nomad/dist/server.hcl \
		${STAGEDIR}${PREFIX}/etc/nomad/server.hcl.sample

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
BUILD_ENV=	CC=clang
.endif

.include <bsd.port.post.mk>
