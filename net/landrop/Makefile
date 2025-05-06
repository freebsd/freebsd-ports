PORTNAME=	landrop
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Drop any files to any devices on your LAN
WWW=		https://landrop.app

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Unmaintained version and the newer version turned to close source
EXPIRATION_DATE=2025-06-13

LIB_DEPENDS=	libsodium.so:security/libsodium

USES=	gl qmake:outsource qt:5

USE_GITHUB=	yes

GH_ACCOUNT=	LANDrop
GH_PROJECT=	LANDrop

USE_GL=	gl
USE_QT=	buildtools:build core gui network widgets

QMAKE_SOURCE_PATH=	${WRKSRC}/LANDrop/LANDrop.pro

PLIST_FILES=	bin/landrop \
		share/applications/landrop.desktop \
		share/icons/hicolor/scalable/apps/landrop.svg

.include <bsd.port.mk>
