# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	antibody
PORTVERSION=	4.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	shells

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	High-performance zsh plugin manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	git:devel/git \
		zsh:shells/zsh

USES=		go:modules

PLIST_FILES=	bin/antibody

USE_GITHUB=	yes
GH_ACCOUNT=	getantibody
# Not needed: go-spew, go-difflib
GH_TUPLE=	alecthomas:kingpin:v2.2.6:kingpin/vendor/gopkg.in/alecthomas/kingpin.v2 \
		alecthomas:template:fb15b89:tempalte/vendor/github.com/alecthomas/template \
		alecthomas:units:f65c72e:units/vendor/github.com/alecthomas/units \
		caarlos0:gohome:75f08ebc:gohome/vendor/github.com/caarlos0/gohome \
		getantibody:folder:v1.0.0:folder/vendor/github.com/getantibody/folder \
		golang:crypto:34f6963:crypto/vendor/golang.org/x/crypto \
		golang:net:d98b1b4:net/vendor/golang.org/x/net \
		golang:sync:1d60e4:sync/vendor/golang.org/x/sync \
		golang:sys:7c87d1:sys/vendor/golang.org/x/sys

.include <bsd.port.mk>
