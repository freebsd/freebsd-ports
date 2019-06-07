# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	antibody
PORTVERSION=	4.1.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	shells

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	High-performance zsh plugin manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	git:devel/git \
		zsh:shells/zsh

USES=		go

PLIST_FILES=	bin/antibody

USE_GITHUB=	yes
GH_ACCOUNT=	getantibody
GH_SUBDIR=	src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}
# Not needed: go-spew, go-difflib
GH_TUPLE=	alecthomas:kingpin:a39589:kingpin/src/github.com/alecthomas/kingpin \
		alecthomas:template:a0175e:tempalte/src/github.com/alecthomas/template \
		alecthomas:units:2efee8:units/src/github.com/alecthomas/units \
		caarlos0:gohome:75f08ebc:gohome/src/github.com/caarlos0/gohome \
		getantibody:folder:v1.0.0:folder/src/github.com/getantibody/folder \
		golang:crypto:1a580b:crypto/src/golang.org/x/crypto \
		golang:net:2491c5:net/src/golang.org/x/net \
		golang:sync:1d60e4:sync/src/golang.org/x/sync \
		golang:sys:7c87d1:sys/src/golang.org/x/sys

do-build:
	${RM} ${WRKSRC}/go.mod
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/antibody-${PORTVERSION} ${STAGEDIR}${PREFIX}/bin/antibody

.include <bsd.port.mk>
