PORTNAME=	gotop
DISTVERSIONPREFIX=	v
DISTVERSION=	4.2.0-30
DISTVERSIONSUFFIX=	-g2872dab
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Terminal based graphical activity monitor inspired by gtop and vtop
WWW=		https://github.com/xxxserxxx/gotop

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	xxxserxxx

GO_MODULE=	github.com/xxxserxxx/gotop/v4
GO_MOD_DIST=	github
GO_TARGET=	./cmd/gotop/

PLIST_FILES=	bin/${PORTNAME}

# tests as of v4.2.0-30-g2872dab: ok github.com/xxxserxxx/gotop/v4, ok colorschemes, ok layout, ok logging, ok termui, ok utils; [no test files] cmd/gotop devices termui/drawille-go widgets

.include <bsd.port.mk>
