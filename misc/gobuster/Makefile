# $FreeBSD$

PORTNAME=	gobuster
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.1
PORTREVISION=	1
CATEGORIES=	misc dns

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Directory/file & DNS busting tool written in Go

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	OJ
GH_TUPLE=	google:uuid:c2e93f3:uuid/vendor/github.com/google/uuid \
		hashicorp:errwrap:8a6fb52:errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:886a7fb:gomultierror/vendor/github.com/hashicorp/go-multierror \
		golang:crypto:0e37d00:crypto/vendor/golang.org/x/crypto \
		spf13:cobra:0.0.5:cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.3:pflag/vendor/github.com/spf13/pflag \
		golang:sys:d8f5ea2:sys/vendor/golang.org/x/sys

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
