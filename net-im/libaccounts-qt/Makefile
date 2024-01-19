PORTNAME=	libaccounts-qt
DISTVERSION=	1.16
PORTREVISION=	5
CATEGORIES=	net-im
DIST_SUBDIR=	KDE/${GL_ACCOUNT}
PKGNAMESUFFIX=	${FLAVOR:S/qt//}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt5 wrapper for SSO framework
WWW=		https://gitlab.com/accounts-sso

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

LIB_DEPENDS=	libaccounts-glib.so:net-im/libaccounts-glib

USES=		compiler:c++17-lang gettext-runtime gnome qmake \
		pathfix pkgconfig python qt:${FLAVOR:S/qt//} tar:bz2
USE_GNOME=	glib20
_USE_QT_qt5=	buildtools:build core qmake:build testlib xml
_USE_QT_qt6=	base
USE_QT=		${_USE_QT_${FLAVOR}}

# gitlab variables
USE_GITLAB=	yes
GL_ACCOUNT=	nicolasfella
GL_PROJECT=	libaccounts-qt
GL_TAGNAME=	18557f7def9af8f4a9e0e93e9f575ae11e5066aa

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
DOCS_QMAKE_ON=		CONFIG+=docs

PLIST_SUB=	QT_VER=${FLAVOR:S/qt//}

pre-configure:
	${REINPLACE_CMD} -e 's,$$$${INSTALL_LIBDIR},${LOCALBASE}/libdata,' \
		${WRKSRC}/common-pkgconfig.pri

.include <bsd.port.mk>
