PORTNAME=	trufflehog
DISTVERSIONPREFIX=	v
DISTVERSION=	3.91.1
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Find and verify credentials
WWW=		https://trufflesecurity.com \
		https://github.com/trufflesecurity/trufflehog

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	compilation fails see details here: https://github.com/trufflesecurity/trufflehog/issues/3791
BROKEN_i386=	compilation fails see details here: https://github.com/trufflesecurity/trufflehog/issues/3791

USES=		go:1.24+,modules

GO_MODULE=	github.com/trufflesecurity/trufflehog/v3
#GO_TARGET=	./${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
