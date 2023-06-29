PORTNAME=	kig
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	math education kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE interactive geometry application
WWW=		https://www.kde.org/applications/education/kig

LIB_DEPENDS=	${PY_BOOST}

USES=		cmake gettext compiler:c++11-lib desktop-file-utils kde:5 \
		python:run qt:5 shebangfix tar:xz xorg
USE_KDE=	archive auth codecs completion config configwidgets coreaddons \
		crash doctools emoticons i18n iconthemes init itemmodels \
		jobwidgets kdelibs4support kio parts service solid sonnet syntaxhighlighting \
		texteditor textwidgets widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus gui network printsupport svg widgets xml xmlpatterns \
		buildtools:build qmake:build
USE_XORG=	x11
SHEBANG_FILES=	pykig/pykig.py

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} '/Python_ADDITIONAL_VERSIONS/s|2.7|${PYTHON_VER};2.7|' \
		${WRKSRC}/cmake/modules/FindBoostPython.cmake

.include <bsd.port.mk>
