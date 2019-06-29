# $FreeBSD$

PORTNAME=	consul_exporter
PORTVERSION=	0.3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	t.tom@succont.de
COMMENT=	Exporter for Consul metrics

LICENSE=	APACHE20

USES=		compiler go

USE_GITHUB=	yes
GH_ACCOUNT=	prometheus
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/consul_exporter

USE_RC_SUBR=	consul_exporter

PLIST_FILES=	bin/consul_exporter

post-extract:
	@${MV} ${WRKSRC}/vendor/ ${WRKSRC}/src/

do-build:
	@cd ${WRKSRC}/src/github.com/prometheus/consul_exporter; ${SETENV} ${MAKE_ENV} CGO_ENABLED=0 ${BUILD_ENV} GOPATH=${WRKSRC} go build \
		-ldflags "\
		-X github.com/prometheus/consul_exporter/version.Version=${PORTVERSION}  \
		-X github.com/prometheus/consul_exporter/version.VersionPrerelease=  \
		-X github.com/prometheus/consul_exporter/version.GitDescribe=v${PORTVERSION} \
		" \
		-o bin/consul_exporter

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/prometheus/consul_exporter/bin/consul_exporter ${STAGEDIR}${PREFIX}/bin/consul_exporter

.include <bsd.port.pre.mk>

# golang assumes that if clang is in use, it is called "clang" and not "cc". If
# it's called "cc", go fails.
.if ${COMPILER_TYPE} == clang
BUILD_ENV=	CC=clang
.endif

.include <bsd.port.post.mk>
