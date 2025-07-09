PORTNAME=	krakend-ce
DISTVERSIONPREFIX=	v
DISTVERSION=	2.10.0
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	alster@vinterdalen.se
COMMENT=	High-performance, stateless, declarative, API Gateway
WWW=		https://www.krakend.io/ \
		https://github.com/krakend/krakend-ce/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armv7 i386
NOT_FOR_ARCHS_REASON=	Build failure: vendor/github.com/krakendio/krakend-amqp/v2/consumer.go:47:20: cannot use math.MaxInt64 (untyped int constant 9223372036854775807) as int value in assignment (overflows)

USES=		cpe go:modules
CPE_VENDOR=	krakend
CPE_PRODUCT=	krakend
CPE_SW_EDITION=	community

GO_MODULE=	github.com/krakendio/krakend-ce/v2
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X github.com/luraproject/lura/v2/core.KrakendVersion=${DISTVERSION} \
		-X github.com/luraproject/lura/v2/core.GoVersion=${GO_VERSION}"

TEST_TARGET=	test

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
