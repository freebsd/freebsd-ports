PORTNAME=	gobuster
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.0
PORTREVISION=	4
CATEGORIES=	misc dns

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Directory/file & DNS busting tool written in Go

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	OJ
GH_TUPLE=	\
		golang:crypto:123391ffb6de:golang_crypto/vendor/golang.org/x/crypto \
		golang:sys:1b9f1253b3ed:golang_sys/vendor/golang.org/x/sys \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		spf13:cobra:v1.0.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
