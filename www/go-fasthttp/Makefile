# $FreeBSD$

PORTNAME=	fasthttp
PORTVERSION=	20160617
DISTVERSIONPREFIX=	v
CATEGORIES=	www net
PKGNAMEPREFIX=	go-

MAINTAINER=	guy.tabrar@me.com
COMMENT=	Fast HTTP package for Go, tuned for high performance

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=		Go libraries should not be packaged
EXPIRATION_DATE=	2019-03-31

BUILD_DEPENDS=	go-compress>=0:archivers/go-compress \
		go-cpuid>=0:devel/go-cpuid \
		go-crc32>=0:devel/go-crc32
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	valyala
USES=		go
GO_PKGNAME=	github.com/valyala/fasthttp

.include <bsd.port.mk>
