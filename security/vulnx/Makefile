PORTNAME=	vulnx
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.2
CATEGORIES=	security

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	CLI for exploring vulnerability data
WWW=		https://github.com/projectdiscovery/vulnx

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/projectdiscovery/${PORTNAME}/v2

GO_TARGET=	./cmd/${PORTNAME}
GO_LDFLAGS=	-X ${GO_MODULE}/cmd/${PORTNAME}/clis.Version=${DISTVERSION}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
