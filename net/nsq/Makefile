# $FreeBSD$

PORTNAME=	nsq
PORTVERSION=	1.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Realtime distributed messaging platform

LICENSE=	MIT

ONLY_FOR_ARCHS=	amd64

USES=	go:modules

USE_RC_SUBR=	nsqd nsqlookupd nsqadmin

USE_GITHUB=	yes
GH_ACCOUNT=	nsqio
GH_SUBDIR=	src/github.com/nsqio/nsq

GH_TUPLE=	BurntSushi:toml:v0.3.1:toml/vendor/github.com/BurntSushi/toml \
		bitly:go-hostpool:a3a6125de932:go_hostpool/vendor/github.com/bitly/go-hostpool \
		bitly:timer_metrics:b1c65ca7ae62:timer_metrics/vendor/github.com/bitly/timer_metrics \
		blang:semver:v3.5.1:semver/vendor/github.com/blang/semver \
		bmizerany:perks:d9a9656a3a4b:perks/vendor/github.com/bmizerany/perks \
		golang:snappy:2e65f85255db:snappy/vendor/github.com/golang/snappy \
		judwhite:go-svc:v1.0.0:go_svc/vendor/github.com/judwhite/go-svc \
		julienschmidt:httprouter:v1.2.0:httprouter/vendor/github.com/julienschmidt/httprouter \
		mreiferson:go-options:0c63f026bcd6:go_options/vendor/github.com/mreiferson/go-options \
		nsqio:go-diskqueue:74cfbc9de839:go_diskqueue/vendor/github.com/nsqio/go-diskqueue \
		nsqio:go-nsq:v1.0.7:go_nsq/vendor/github.com/nsqio/go-nsq

GO_BUILDFLAGS=	-ldflags "-X main.GitDescribe=${DISTVERSIONFULL}"
GO_TARGET=	./apps/nsqd ./apps/nsqlookupd ./apps/nsqadmin \
		./apps/nsq_to_nsq ./apps/nsq_to_file ./apps/nsq_to_http \
		./apps/nsq_tail ./apps/nsq_stat ./apps/to_nsq

.include <bsd.port.mk>
