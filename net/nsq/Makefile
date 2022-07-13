PORTNAME=	nsq
PORTVERSION=	1.2.1
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	net

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Realtime distributed messaging platform

LICENSE=	MIT

ONLY_FOR_ARCHS=	aarch64 amd64 armv7

USES=	go:modules

USE_RC_SUBR=	nsqd nsqlookupd nsqadmin

USE_GITHUB=	yes
GH_ACCOUNT=	nsqio
GH_SUBDIR=	src/github.com/nsqio/nsq
GH_TUPLE=	\
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		bitly:go-hostpool:v0.1.0:bitly_go_hostpool/vendor/github.com/bitly/go-hostpool \
		bitly:timer_metrics:v1.0.0:bitly_timer_metrics/vendor/github.com/bitly/timer_metrics \
		blang:semver:v3.5.1:blang_semver/vendor/github.com/blang/semver \
		bmizerany:perks:d9a9656a3a4b:bmizerany_perks/vendor/github.com/bmizerany/perks \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:22da62e12c0c:golang_sys/vendor/golang.org/x/sys \
		julienschmidt:httprouter:v1.3.0:julienschmidt_httprouter/vendor/github.com/julienschmidt/httprouter \
		mreiferson:go-options:v1.0.0:mreiferson_go_options/vendor/github.com/mreiferson/go-options \
		mreiferson:go-svc:7a96e00010f6:mreiferson_go_svc/vendor/github.com/judwhite/go-svc \
		nsqio:go-diskqueue:v1.0.0:nsqio_go_diskqueue/vendor/github.com/nsqio/go-diskqueue \
		nsqio:go-nsq:v1.0.8:nsqio_go_nsq/vendor/github.com/nsqio/go-nsq

GO_BUILDFLAGS=	-ldflags "-X main.GitDescribe=${DISTVERSIONFULL}"
GO_TARGET=	./apps/nsqd ./apps/nsqlookupd ./apps/nsqadmin \
		./apps/nsq_to_nsq ./apps/nsq_to_file ./apps/nsq_to_http \
		./apps/nsq_tail ./apps/nsq_stat ./apps/to_nsq

.include <bsd.port.mk>
