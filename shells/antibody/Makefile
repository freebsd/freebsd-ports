PORTNAME=	antibody
PORTVERSION=	6.1.1
DISTVERSIONPREFIX=	v
PORTREVISION=	28
CATEGORIES=	shells

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-performance zsh plugin manager
WWW=		https://getantibody.github.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	git:devel/git \
		zsh:shells/zsh

USES=		go:modules

PLIST_FILES=	bin/antibody

USE_GITHUB=	yes
GH_ACCOUNT=	getantibody
GH_TUPLE=	alecthomas:kingpin:v2.2.6:kingpin/vendor/gopkg.in/alecthomas/kingpin.v2 \
		alecthomas:template:fb15b89:tempalte/vendor/github.com/alecthomas/template \
		alecthomas:units:f65c72e:units/vendor/github.com/alecthomas/units \
		getantibody:folder:v1.0.0:folder/vendor/github.com/getantibody/folder \
		golang:crypto:948cd5:crypto/vendor/golang.org/x/crypto \
		golang:sync:6e8e73:sync/vendor/golang.org/x/sync \
		golang:sys:v0.5.0:sys/vendor/golang.org/x/sys

.include <bsd.port.mk>
