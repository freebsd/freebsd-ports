PORTNAME=	omacalc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2
CATEGORIES=	math

MAINTAINER=	jkh@FreeBSD.org
COMMENT=	Dead-simple calculator built with Qt Quick
WWW=		https://github.com/omacom-io/omacalc

LICENSE=	MIT OFL11
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE
LICENSE_FILE_OFL11=	${WRKSRC}/fonts/OFL.txt

RUN_DEPENDS=	xdg-desktop-portal>0:deskutils/xdg-desktop-portal

USES=		compiler:c++17-lang gl qmake qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	omacom-io
USE_GL=		opengl
USE_QT=		base declarative

PLIST_FILES=	bin/omacalc \
		share/applications/omacalc.desktop \
		share/icons/hicolor/scalable/apps/omacalc.svg

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/omacalc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/omacalc.desktop \
		${STAGEDIR}${DESKTOPDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${FILESDIR}/omacalc.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps

do-test:
	@${MKDIR} ${WRKDIR}/tests
	cd ${WRKDIR}/tests && \
		${SETENVI} ${WRK_ENV} ${QMAKE_ENV} ${QMAKE} ${QMAKE_ARGS} \
			${WRKSRC}/tests/tests.pro && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE_CMD} && \
		${SETENV} QT_QPA_PLATFORM=offscreen ./tst_omacalc

.include <bsd.port.mk>
