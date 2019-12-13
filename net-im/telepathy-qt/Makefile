# Created by: Alberto Villa <avilla@FreeBSD.org>
# $FreeBSD$

PORTNAME=	telepathy-qt
DISTVERSION=	0.9.8
CATEGORIES=	net-im
MASTER_SITES=	https://telepathy.freedesktop.org/releases/${PORTNAME}/
PKGNAMESUFFIX=	5

MAINTAINER=	kde@FreeBSD.org
COMMENT=	High-level Qt binding for Telepathy

LICENSE=	LGPL21

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_dbus_bindings.so:devel/py-dbus@${PY_FLAVOR}
LIB_DEPENDS=	libtelepathy-farstream.so:net-im/telepathy-farstream \
		libtelepathy-glib.so:net-im/telepathy-glib
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_dbus_bindings.so:devel/py-dbus@${PY_FLAVOR}

USES=		cmake compiler:c++11-lang gettext gnome localbase:ldflags pathfix \
		pkgconfig python:2.7,build qt:5
USE_GNOME=	glib20 libxslt:build
USE_GSTREAMER=	yes
USE_LDCONFIG=	yes
USE_QT=		core dbus gui network xml \
		buildtools_build qmake_build testlib_build widgets_build

CMAKE_ON=	ENABLE_FARSTREAM CMAKE_DISABLE_FIND_PACKAGE_Doxygen
CMAKE_OFF=	ENABLE_EXAMPLES ENABLE_FARSIGHT ENABLE_TESTS
CMAKE_ARGS=	-DDESIRED_QT_VERSION:STRING=${PKGNAMESUFFIX} \
		-DQT_QMAKE_EXECUTABLE:FILEPATH=${QMAKE}

OPTIONS_DEFINE=	DOCS

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

PORTDOCS=	AUTHORS ChangeLog HACKING NEWS README html
# Manually set DOCSDIR, to handle the version suffix
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${CP} -R doc/html .
. for f in ${PORTDOCS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} ${STAGEDIR}${DOCSDIR}
. endfor

.include <bsd.port.mk>
