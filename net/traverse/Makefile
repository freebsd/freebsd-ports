PORTNAME=	traverse
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
CATEGORIES=	net

MAINTAINER=	hayzam@alchemilla.io
COMMENT=	STUN and TURN server probe with text, JSON, and XML output
WWW=		https://github.com/AlchemillaHQ/traverse

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.26+,modules

GO_MODULE=	github.com/AlchemillaHQ/traverse
GO_BUILDFLAGS=	-ldflags="-X ${GO_MODULE}/internal/version.Version=${DISTVERSION} ${STRIP}"
CGO_ENABLED=	0

PLIST_FILES=	bin/traverse

.include <bsd.port.mk>
