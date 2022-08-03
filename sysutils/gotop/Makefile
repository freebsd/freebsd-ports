PORTNAME=	gotop
DISTVERSIONPREFIX=	v
DISTVERSION=	4.1.4
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Terminal based graphical activity monitor inspired by gtop and vtop

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/xxxserxxx/gotop/v4
GO_TARGET=	./cmd/gotop/

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
