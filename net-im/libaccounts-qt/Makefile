PORTNAME=	libaccounts-qt
DISTVERSION=	1.17
PORTREVISION=	1
CATEGORIES=	net-im
PKGNAMESUFFIX=	6
DIST_SUBDIR=	KDE/${GL_ACCOUNT}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 6 wrapper for SSO framework
WWW=		https://gitlab.com/accounts-sso

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libaccounts-glib.so:net-im/libaccounts-glib

USES=		compiler:c++17-lang gettext-runtime gnome qmake \
		pathfix pkgconfig python qt:6 tar:bz2
USE_GITLAB=	yes
GL_ACCOUNT=	accounts-sso
GL_TAGNAME=	c8fdd05f1a1ff5886f4649d24f2ba8c5f61cfa3a
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_QT=		base

PLIST_SUB=	QT_VER=6

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen \
			dot:graphics/graphviz
DOCS_USE=		QT=tools:build
DOCS_QMAKE_ON=		CONFIG+=docs
DOCS_BINARY_ALIAS=	qhelpgenerator=${QHELPGENERATOR}

pre-configure:
	${REINPLACE_CMD} -e 's,$$$${INSTALL_LIBDIR},${LOCALBASE}/libdata,' \
		${WRKSRC}/common-pkgconfig.pri

.include <bsd.port.mk>
