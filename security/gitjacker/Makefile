PORTNAME=	gitjacker
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
PORTREVISION=	3
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Leak git repositories from misconfigured websites

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
CPE_VENDOR=	${PORTNAME}_project

GO_MODULE=	github.com/liamg/gitjacker
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
