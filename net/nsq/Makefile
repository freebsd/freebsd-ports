# $FreeBSD$

PORTNAME=	nsq
PORTVERSION=	0.3.8
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	jhixson@gmail.com
COMMENT=	Realtime distributed messaging platform

LICENSE=	MIT

BUILD_DEPENDS=	go>=1.7:lang/go

ONLY_FOR_ARCHS=	amd64

USE_RC_SUBR=	nsqd nsqlookupd nsqadmin

USES=	compiler go

USE_GITHUB=	yes
GH_ACCOUNT=	nsqio
GH_SUBDIR=	src/github.com/nsqio/nsq
GH_TUPLE=	BurntSushi:toml:v0.2.0:toml/src/github.com/BurntSushi/toml \
	judwhite:go-svc:v1.0.0:go_svc/src/github.com/judwhite/go-svc \
	mreiferson:go-options:77551d2:go_options/src/github.com/mreiferson/go-options \
	mreiferson:go-snappystream:v0.2.3:go_snappystream/src/github.com/mreiferson/go-snappystream\
	bitly:go-hostpool:d0e59c2:go_hostpool/src/github.com/bitly/go-hostpool \
	bitly:go-simplejson:v0.5.0:go_simplejson/src/github.com/bitly/go-simplejson\
	bitly:timer_metrics:afad179:timer_metrics/src/github.com/bitly/timer_metrics \
	blang:semver:v3.3.0:semver/src/github.com/blang/semver \
	bmizerany:perks:d9a9656:perks/src/github.com/bmizerany/perks \
	julienschmidt:httprouter:8a45e95:httprouter/src/github.com/julienschmidt/httprouter \
	nsqio:go-nsq:v1.0.6:go_nsq/src/github.com/nsqio/go-nsq

TARGETS=	nsqd nsqlookupd nsqadmin nsq_pubsub nsq_to_nsq nsq_to_file \
	nsq_to_http nsq_tail nsq_stat to_nsq

STRIP=

.for _t in ${TARGETS}
build-${_t}:
	cd ${GO_WRKSRC}/apps/${_t}; \
		${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build \
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
