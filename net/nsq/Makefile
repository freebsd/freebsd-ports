# $FreeBSD$

PORTNAME=	nsq
PORTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Realtime distributed messaging platform

LICENSE=	MIT

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	go>=1.7:lang/go

USES=	compiler go

USE_RC_SUBR=	nsqd nsqlookupd nsqadmin

USE_GITHUB=	yes
GH_ACCOUNT=	nsqio
GH_SUBDIR=	src/github.com/nsqio/nsq

GH_TUPLE=	BurntSushi:toml:2dff111:toml/src/github.com/BurntSushi/toml \
	bitly:go-hostpool:a3a6125:go_hostpool/src/github.com/bitly/go-hostpool \
	bitly:timer_metrics:afad179:timer_metrics/src/github.com/bitly/timer_metrics \
	blang:semver:9bf7bff:semver/src/github.com/blang/semver \
	bmizerany:perks:6cb9d9d:perks/src/github.com/bmizerany/perks \
	golang:snappy:d9eb7a3:snappy/src/github.com/golang/snappy \
	judwhite:go-svc:63c1240:go_svc/src/github.com/judwhite/go-svc \
	julienschmidt:httprouter:6aacfd5:httprouter/src/github.com/julienschmidt/httprouter \
	mreiferson:go-options:77551d2:go_options/src/github.com/mreiferson/go-options \
	nsqio:go-diskqueue:0681a1a:go_diskqueue/src/github.com/nsqio/go-diskqueue \
	nsqio:go-nsq:a53d495:go_nsq/src/github.com/nsqio/go-nsq

TARGETS=	nsqd nsqlookupd nsqadmin nsq_to_nsq nsq_to_file \
	nsq_to_http nsq_tail nsq_stat to_nsq

.for _t in ${TARGETS}
build-${_t}:
	cd ${GO_WRKSRC}/apps/${_t}; \
		${SETENV} ${MAKE_ENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build \
			-ldflags "-X main.GitDescribe=${DISTVERSIONFULL}" -o bin/${_t}
install-${_t}:
	${INSTALL_PROGRAM} ${GO_WRKSRC}/apps/${_t}/bin/${_t} \
		${STAGEDIR}${PREFIX}/bin/${_t}

build_targets+=	build-${_t}
install_targets+=	install-${_t}
.endfor

do-build: ${build_targets}
do-install: ${install_targets}

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
BUILD_ENV=	CC=clang
.endif

.include <bsd.port.post.mk>
