PORTNAME=	nebula
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.1
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scalable overlay networking tool
WWW=		https://github.com/slackhq/nebula

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/slackhq/nebula
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
