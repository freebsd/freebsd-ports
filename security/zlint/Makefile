PORTNAME=	zlint
DISTVERSIONPREFIX=	v
DISTVERSION=	3.6.6
PORTREVISION=	1
CATEGORIES=	security www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	X.509 certificate linter
WWW=		https://github.com/zmap/zlint

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.23,modules

GO_MODULE=	github.com/zmap/zlint/v3
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
