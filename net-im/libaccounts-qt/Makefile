PORTNAME=	libaccounts-qt
DISTVERSION=	1.17
CATEGORIES=	net-im
PKGNAMESUFFIX=	${FLAVOR:S/qt//}
DIST_SUBDIR=	KDE/${GL_ACCOUNT}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt5 wrapper for SSO framework
WWW=		https://gitlab.com/accounts-sso

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libaccounts-glib.so:net-im/libaccounts-glib

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

USES=		compiler:c++17-lang gettext-runtime gnome qmake \
		pathfix pkgconfig python qt:${FLAVOR:S/qt//} tar:bz2
USE_GITLAB=	yes
GL_ACCOUNT=	accounts-sso
GL_TAGNAME=	c8fdd05f1a1ff5886f4649d24f2ba8c5f61cfa3a
USE_GNOME=	glib20
USE_LDCONFIG=	yes
_USE_QT_qt5=	buildtools:build core qmake:build testlib:build xml
_USE_QT_qt6=	base
USE_QT=		${_USE_QT_${FLAVOR}}

PLIST_SUB=	QT_VER=${FLAVOR:S/qt//}

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \
			dot:graphics/graphviz
_DOCS_USE_qt5=		QT=help:build
_DOCS_USE_qt6=		QT=tools:build
DOCS_USE=		${_DOCS_USE_${FLAVOR}}
DOCS_QMAKE_ON=		CONFIG+=docs
DOCS_BINARY_ALIAS=	qhelpgenerator=${QHELPGENERATOR}

pre-configure:
	${REINPLACE_CMD} -e 's,$$$${INSTALL_LIBDIR},${LOCALBASE}/libdata,' \
		${WRKSRC}/common-pkgconfig.pri

.include <bsd.port.mk>
