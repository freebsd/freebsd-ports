# $FreeBSD$

PORTNAME=	ssh-chat
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7-4
DISTVERSIONSUFFIX=	-gf36d7eb
CATEGORIES=	net-im

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Chat over SSH

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	shazow
GH_TUPLE=	shazow:rateio:e8e0088:rateio/vendor/github.com/shazow/rateio \
		alexcesaro:log:61e6862:log/vendor/github.com/alexcesaro/log \
		howeyc:gopass:bf9dde6:gopass/vendor/github.com/howeyc/gopass \
		jessevdk:go-flags:c6ca198:flags/vendor/github.com/jessevdk/go-flags \
		golang:crypto:c126467:crypto/vendor/golang.org/x/crypto \
		golang:sys:ac767d6:sys/vendor/golang.org/x/sys

GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
