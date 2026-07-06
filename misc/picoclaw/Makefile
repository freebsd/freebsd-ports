PORTNAME=	picoclaw
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.1
CATEGORIES=	misc

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Lightweight personal AI assistant
WWW=		https://github.com/sipeed/picoclaw

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.25+,modules

BROKEN_i386=	vendored modernc.org/libc + modernc.org/sqlite broken on 386
BROKEN_armv7=	vendored modernc.org/libc + modernc.org/sqlite broken on arm

GO_MODULE=	github.com/sipeed/picoclaw
GO_TARGET=	./cmd/${PORTNAME}

_CONFIG_PKG=	${GO_MODULE}/pkg/config
GO_BUILDFLAGS=	-tags goolm,stdjson \
		-ldflags "-s -w \
			-X ${_CONFIG_PKG}.Version=${DISTVERSION}"

USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message

PLIST_FILES=	bin/${PORTNAME}

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} \
		${GO_CMD} generate ./...

.include <bsd.port.mk>
