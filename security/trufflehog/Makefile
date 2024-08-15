PORTNAME=	trufflehog
DISTVERSIONPREFIX=	v
DISTVERSION=	3.63.11
PORTREVISION=	5
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Find and verify credentials
WWW=		https://trufflesecurity.com/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	compilation fails see details here: https://github.com/golang/go/issues/65187
BROKEN_i386=	compilation fails see details here: https://github.com/golang/go/issues/65187

USES=		go:1.21,modules

GO_MODULE=	github.com/trufflesecurity/trufflehog/v3
#GO_TARGET=	./${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
