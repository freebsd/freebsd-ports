PORTNAME=	pageedit
DISTVERSION=	1.9.20
CATEGORIES=	textproc
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	WYSIWYG visual XHTML editor
WWW=		https://github.com/Sigil-Ebook/PageEdit

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

FLAVORS=	qt6 qt5
FLAVOR?=	qt6
qt5_CONFLICTS_INSTALL=	pageedit-qt6
qt6_CONFLICTS_INSTALL=	pageedit-qt5

USES=		cmake qt:${FLAVOR:S/qt//} ${_USES_${FLAVOR}} desktop-file-utils
USE_GITHUB=	yes
GH_ACCOUNT=	Sigil-Ebook
GH_PROJECT=	PageEdit
USE_LOCALE=	${_USE_LOCALE_${FLAVOR}}
USE_QT=		${_USE_QT_${FLAVOR}}
USE_GL=		${_USE_GL_${FLAVOR}}
CMAKE_ARGS=	${_CMAKE_ARGS_${FLAVOR}}

_CMAKE_ARGS_qt6=	-DUSE_QT6:BOOL=TRUE
_USE_LOCALE_qt6=	en_US.UTF-8
_USES_qt6=	gl
_USE_GL_qt6=	gl opengl
_USE_QT_qt6=		5compat base webengine translations declarative webchannel positioning
_USE_QT_qt5=		concurrent core declarative gui location network \
			printsupport webchannel webengine widgets xml \
			buildtools:build linguisttools:build qmake:build
_PLIST_QT5_qt5=
_PLIST_QT5_qt6=	"@comment "
PLIST_SUB=	QT5_ONLY=${_PLIST_QT5_${FLAVOR}}

.include <bsd.port.mk>
