PORTNAME=	omacut
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
CATEGORIES=	multimedia

MAINTAINER=	jkh@FreeBSD.org
COMMENT=	Dead-simple video length trimmer built with Qt Quick and FFmpeg
WWW=		https://github.com/omacom-io/omacut

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ffmpeg:multimedia/ffmpeg \
		xdg-desktop-portal>0:deskutils/xdg-desktop-portal

USES=		compiler:c++17-lang desktop-file-utils gl qmake qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	omacom-io
USE_GL=		opengl
USE_QT=		base declarative multimedia

PLIST_FILES=	bin/omacut \
		share/applications/omacut.desktop \
		share/icons/hicolor/scalable/apps/omacut.svg

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/omacut ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/pkgbuild/omacut.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/pkgbuild/omacut.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps

do-test:
	@${MKDIR} ${WRKDIR}/tests
	cd ${WRKDIR}/tests && \
		${SETENVI} ${WRK_ENV} ${QMAKE_ENV} ${QMAKE} ${QMAKE_ARGS} \
			${WRKSRC}/tests/backend_tests.pro && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE_CMD} && \
		${SETENV} QT_QPA_PLATFORM=offscreen ./backend_tests

.include <bsd.port.mk>
