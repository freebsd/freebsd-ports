PORTNAME=	eightctl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.8
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Control your sleep from the terminal
WWW=		https://github.com/steipete/eightctl

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_PKGNAME=	github.com/steipete/eightctl

USE_GITHUB=	yes
GH_ACCOUNT=	steipete

GO_MODULE=	github.com/steipete/eightctl
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
