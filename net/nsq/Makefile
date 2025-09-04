PORTNAME=	nsq
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
PORTREVISION=	14
CATEGORIES=	net

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Realtime distributed messaging platform
WWW=		https://nsq.io

LICENSE=	MIT

ONLY_FOR_ARCHS=	aarch64 amd64 armv7 i386 riscv64

USES=		go:modules

GO_MODULE=	github.com/nsqio/nsq
GO_TARGET=	./apps/nsqd ./apps/nsqlookupd ./apps/nsqadmin \
		./apps/nsq_to_nsq ./apps/nsq_to_file ./apps/nsq_to_http \
		./apps/nsq_tail ./apps/nsq_stat ./apps/to_nsq

USE_RC_SUBR=	nsqd nsqlookupd nsqadmin

.include <bsd.port.mk>
