PORTNAME=	qtpass
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.0
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

PLIST_FILES=	bin/qtpass \
		share/applications/qtpass.desktop \
		share/pixmaps/qtpass.png

post-patch:
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|g' \
			${WRKSRC}/qtpass.desktop

# Install the icon and desktop file of the port.
post-install:
	${INSTALL_DATA} ${WRKSRC}/artwork/icon.png \
			${STAGEDIR}${PREFIX}/share/pixmaps/qtpass.png
	${INSTALL_DATA} ${WRKSRC}/qtpass.desktop \
			${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
