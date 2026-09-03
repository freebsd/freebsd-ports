PORTNAME=	reqlog
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Search, trace, and stream logs across files, Docker, and SSH
WWW=		https://github.com/SagarMaheshwary/reqlog

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/sagarmaheshwary/reqlog
GO_TARGET=	./cmd/reqlog
GO_LDFLAGS=	-X main.version=${DISTVERSION}

PLIST_FILES=	bin/reqlog

.include <bsd.port.mk>
