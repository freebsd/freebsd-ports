# $FreeBSD$

PORTNAME=	gobuster
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.1-15
DISTVERSIONSUFFIX=	-g0e209e5
CATEGORIES=	misc dns

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Directory/file & DNS busting tool written in Go

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	OJ
GH_TUPLE=	google:uuid:c2e93f3:uuid/vendor/github.com/google/uuid \
		hashicorp:errwrap:8a6fb52:errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:886a7fb:gomultierror/vendor/github.com/hashicorp/go-multierror \
		golang:crypto:0e37d00:crypto/vendor/golang.org/x/crypto \
		golang:sys:d8f5ea2:sys/vendor/golang.org/x/sys
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
