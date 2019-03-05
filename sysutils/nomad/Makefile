# $FreeBSD$

PORTNAME=	nomad
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.7
CATEGORIES=	sysutils

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Cluster manager and scheduler

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		fails to build

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	On i386: go compiler crashes: https://github.com/golang/go/issues/23763

BUILD_DEPENDS=	go:lang/go

USES=		compiler
USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp golang:sys
GH_PROJECT=	sys:sys
GH_TAGNAME=	fa43e7bc11b:sys
GH_SUBDIR=	src/github.com/hashicorp/nomad
USE_RC_SUBR=	nomad

USERS=		nomad
GROUPS=		nomad

post-patch:
	${MV} ${WRKSRC_sys}/cpu ${WRKSRC}/vendor/golang.org/x/sys

do-build:
	@cd ${WRKSRC}/src/github.com/hashicorp/nomad && \
		${SETENV} ${MAKE_ENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -v -x \
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
