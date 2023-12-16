PORTNAME=	trufflehog
DISTVERSIONPREFIX=	v
DISTVERSION=	3.60.3
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Find and verify credentials
WWW=		https://trufflesecurity.com/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.21,modules

GO_MODULE=	github.com/trufflesecurity/trufflehog/v3
#GO_TARGET=	./${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
