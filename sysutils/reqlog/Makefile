PORTNAME=	reqlog
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.1
CATEGORIES=	sysutils

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Search, trace, and stream logs across files, Docker, and SSH
WWW=		https://github.com/SagarMaheshwary/reqlog

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/sagarmaheshwary/reqlog
GO_TARGET=	./cmd/reqlog

PLIST_FILES=	bin/reqlog

.include <bsd.port.mk>
