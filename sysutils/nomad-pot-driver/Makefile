# $FreeBSD$

PORTNAME=	nomad-pot-driver
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2
DISTVERSIONSUFFIX=	-11-g412dbeb
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Nomad driver to support pot jails

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	pot:sysutils/pot \
		nomad:sysutils/nomad

USES=		compiler go
USE_GITHUB=	yes
GH_ACCOUNT=	trivago
GH_SUBDIR=	src/github.com/trivago/nomad-pot-driver

PLIST_FILES=	libexec/nomad/plugins/nomad-pot-driver
SUB_FILES=	pkg-message

do-build:
	@cd ${WRKSRC}/src/github.com/trivago/nomad-pot-driver && \
		${SETENV} ${MAKE_ENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build -v -x \
		-o bin/nomad-pot-driver

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nomad/plugins
	${INSTALL_SCRIPT} ${WRKSRC}/src/github.com/trivago/nomad-pot-driver/bin/nomad-pot-driver ${STAGEDIR}${PREFIX}/libexec/nomad/plugins

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
BUILD_ENV=	CC=clang
.endif

.include <bsd.port.post.mk>
