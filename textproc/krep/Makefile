PORTNAME=	krep
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.0
CATEGORIES=	textproc

MAINTAINER=	alven@FreeBSD.org
COMMENT=	High-performance string search utility
WWW=		https://github.com/davidesantangelo/krep/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	davidesantangelo

TEST_TARGET=	test

PLIST_FILES=	bin/krep

OPTIONS_DEFINE=	SIMD

SIMD_MAKE_ARGS=	SIMD=1

.include <bsd.port.mk>
