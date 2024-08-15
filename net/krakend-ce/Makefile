PORTNAME=	krakend-ce
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.3
PORTREVISION=	3
CATEGORIES=	net

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	High-performance, stateless, declarative, API Gateway
WWW=		https://github.com/krakend/krakend-ce/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	Build failure: math.MaxInt64 overflow

USES=		go:1.22,modules
GO_MODULE=	github.com/krakendio/krakend-ce/v2
GO_TARGET=	./cmd/${PORTNAME}

GO_BUILDFLAGS=	-ldflags="-X github.com/luraproject/lura/v2/core.KrakendVersion=${DISTVERSION} \
	-X github.com/luraproject/lura/v2/core.GoVersion=${GO_VERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
