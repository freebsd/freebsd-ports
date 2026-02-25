PORTNAME=	termshot
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.1
CATEGORIES=	textproc graphics

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Creates screenshots based on terminal command output
WWW=		https://github.com/homeport/termshot

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/homeport/termshot
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X ${GO_MODULE}/internal/cmd.version=${DISTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
