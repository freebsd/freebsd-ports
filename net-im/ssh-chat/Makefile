# $FreeBSD$

PORTNAME=	ssh-chat
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7-4
DISTVERSIONSUFFIX=	-gf36d7eb
CATEGORIES=	net-im

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Chat over SSH

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/LICENSE

BUILD_DEPENDS=	go:lang/go

USE_GITHUB=	nodefault # the main code is in GH_TUPLE
GH_ACCOUNT=	shazow
GH_TUPLE=	shazow:ssh-chat:${DISTVERSIONFULL}:main/src/github.com/shazow/ssh-chat \
		shazow:rateio:e8e0088:rateio/src/github.com/shazow/rateio \
		alexcesaro:log:61e6862:log/src/github.com/alexcesaro/log \
		howeyc:gopass:bf9dde6:gopass/src/github.com/howeyc/gopass \
		jessevdk:go-flags:c6ca198:flags/src/github.com/jessevdk/go-flags \
		golang:crypto:c126467:crypto/src/golang.org/x/crypto \
		golang:sys:ac767d6:sys/src/golang.org/x/sys
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME} && \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go install ./...

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
