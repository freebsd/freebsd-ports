PORTNAME=	krakend-ce
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.0
CATEGORIES=	net

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	High-performance, stateless, declarative, API Gateway
WWW=		https://github.com/krakend/krakend-ce/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	Build failure: math.MaxInt64 overflow

USES=		go:modules
GO_MODULE=	github.com/krakendio/krakend-ce/v2
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
