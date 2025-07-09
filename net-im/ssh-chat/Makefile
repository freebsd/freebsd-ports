PORTNAME=	ssh-chat
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.1
PORTREVISION=	28
CATEGORIES=	net-im

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Chat over SSH
WWW=		https://github.com/shazow/ssh-chat

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	shazow
GH_TUPLE=	\
		alexcesaro:log:61e686294e58:alexcesaro_log/vendor/github.com/alexcesaro/log \
		golang:crypto:9e8e0b390897:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.4:golang_text/vendor/golang.org/x/text \
		howeyc:gopass:7cb4b85ec19c:howeyc_gopass/vendor/github.com/howeyc/gopass \
		jessevdk:go-flags:v1.4.0:jessevdk_go_flags/vendor/github.com/jessevdk/go-flags \
		shazow:rateio:4461efc8bdc4:shazow_rateio/vendor/github.com/shazow/rateio
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
