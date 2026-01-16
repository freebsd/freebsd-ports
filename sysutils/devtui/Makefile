PORTNAME=	devtui
DISTVERSIONPREFIX=	v
DISTVERSION=	0.33.2
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	vidar@karlsen.tech
COMMENT=	Swiss-army app for developers
WWW=		https://devtui.com

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.25+,modules

USE_GITHUB=	yes
GH_ACCOUNT=	skatkov

GO_MOD_DIST=	github
GO_MODULE=	github.com/skatkov/${PORTNAME}

PLIST_FILES=	bin/devtui

.include <bsd.port.mk>
