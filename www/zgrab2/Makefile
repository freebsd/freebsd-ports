PORTNAME=	zgrab2
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.7
PORTREVISION=	10
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast Go application scanner
WWW=		https://github.com/zmap/zgrab2

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	compilation fails: ztypes_freebsd_arm64.go:400:12: undefined: uint128

USES=		go:modules

GO_MODULE=	github.com/zmap/zgrab2
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
