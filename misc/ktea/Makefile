PORTNAME=	ktea
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Kafka TUI client
WWW=		https://github.com/jonas-grgt/ktea

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.25+,modules

GO_MODULE=	github.com/jonas-grgt/ktea
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
