PORTNAME=	surge
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.1
PORTREVISION=	6
CATEGORIES=	www

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	High-performance download manager with TUI and CLI
WWW=		https://github.com/surge-downloader/surge

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	module modernc.org/sqlite only supported on aarch64 and amd64

USES=		go:modules

GO_MODULE=	github.com/surge-downloader/surge

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
