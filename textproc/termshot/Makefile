PORTNAME=	termshot
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	textproc graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Creates screenshots based on terminal command output
WWW=		https://github.com/homeport/termshot

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24+,modules
GO_MODULE=	github.com/homeport/termshot
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-tags noupdater \
		-ldflags "\
		-s -w \
		-X ${GO_MODULE}/internal/cmd.version=${DISTVERSION}"

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
