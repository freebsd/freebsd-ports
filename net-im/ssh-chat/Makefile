# $FreeBSD$

PORTNAME=	ssh-chat
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.2
PORTREVISION=	1
CATEGORIES=	net-im

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Chat over SSH

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	shazow
GH_TUPLE=	\
		alexcesaro:log:61e686294e58:alexcesaro_log/vendor/github.com/alexcesaro/log \
		golang:crypto:b7391e95e576:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:f7bb7a8bee54:golang_sys/vendor/golang.org/x/sys \
		howeyc:gopass:bf9dde6d0d2c:howeyc_gopass/vendor/github.com/howeyc/gopass \
		jessevdk:go-flags:v1.4.0:jessevdk_go_flags/vendor/github.com/jessevdk/go-flags \
		shazow:rateio:e8e00881e5c1:shazow_rateio/vendor/github.com/shazow/rateio
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
