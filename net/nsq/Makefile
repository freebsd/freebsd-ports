# $FreeBSD$

PORTNAME=	nsq
PORTVERSION=	1.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Realtime distributed messaging platform

LICENSE=	MIT

ONLY_FOR_ARCHS=	amd64

USES=	go

USE_RC_SUBR=	nsqd nsqlookupd nsqadmin

USE_GITHUB=	yes
GH_ACCOUNT=	nsqio
GH_SUBDIR=	src/github.com/nsqio/nsq

GH_TUPLE=	BurntSushi:toml:2dff111:toml/vendor/github.com/BurntSushi/toml \
		bitly:go-hostpool:a3a6125:go_hostpool/vendor/github.com/bitly/go-hostpool \
		bitly:timer_metrics:afad179:timer_metrics/vendor/github.com/bitly/timer_metrics \
		blang:semver:9bf7bff:semver/vendor/github.com/blang/semver \
		bmizerany:perks:6cb9d9d:perks/vendor/github.com/bmizerany/perks \
		golang:snappy:d9eb7a3:snappy/vendor/github.com/golang/snappy \
		judwhite:go-svc:63c1240:go_svc/vendor/github.com/judwhite/go-svc \
		julienschmidt:httprouter:6aacfd5:httprouter/vendor/github.com/julienschmidt/httprouter \
		mreiferson:go-options:77551d2:go_options/vendor/github.com/mreiferson/go-options \
		nsqio:go-diskqueue:0681a1a:go_diskqueue/vendor/github.com/nsqio/go-diskqueue \
		nsqio:go-nsq:a53d495:go_nsq/vendor/github.com/nsqio/go-nsq

GO_BUILDFLAGS=	-ldflags "-X main.GitDescribe=${DISTVERSIONFULL}"
GO_TARGET=	./apps/nsqd ./apps/nsqlookupd ./apps/nsqadmin \
		./apps/nsq_to_nsq ./apps/nsq_to_file ./apps/nsq_to_http \
		./apps/nsq_tail ./apps/nsq_stat ./apps/to_nsq

.include <bsd.port.mk>
