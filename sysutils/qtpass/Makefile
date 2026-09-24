PORTNAME=	qtpass
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.2
CATEGORIES=	sysutils

MAINTAINER=	brouwer@annejan.com
COMMENT=	Qt GUI for pass, the standard unix password manager
WWW=		https://qtpass.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	pass:sysutils/password-store

USES=		compiler:c++17-lang cpe gl qmake:outsource qt:6
CPE_VENDOR=	ijhack
USE_GITHUB=	yes
GH_ACCOUNT=	IJHack
GH_PROJECT=	QtPass
USE_GL=		opengl
USE_QT=		base tools:build svg:run translations:run

# 1.8.1 installs the desktop file, the AppStream metainfo and the hicolor
# icons itself (main/main.pro INSTALLS).
PLIST_FILES=	bin/qtpass \
		share/applications/qtpass.desktop \
		share/icons/hicolor/512x512/apps/qtpass-icon.png \
		share/icons/hicolor/scalable/apps/qtpass-icon.svg \
		share/metainfo/org.qtpass.QtPass.metainfo.xml

.include <bsd.port.mk>
