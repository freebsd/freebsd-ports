PORTNAME=		apg
DISTVERSIONPREFIX=	v
DISTVERSION=		1.2.0
PORTREVISION=	5
PORTEPOCH=		1
CATEGORIES=		security sysutils

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Automated Password Generator written in Go
WWW=		https://github.com/wneessen/apg-go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.22,modules
USE_GITHUB=	yes
GH_ACCOUNT=	wneessen
GH_PROJECT=	apg-go
GH_TUPLE=	wneessen:go-hibp:v1.0.6:wneessen_go_hibp/vendor/github.com/wneessen/go-hibp

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
