# Created by: Alberto Villa <avilla@FreeBSD.org>
# $FreeBSD$

PORTNAME=	telepathy-qt4
PORTVERSION=	0.9.6.1
CATEGORIES=	net-im
MASTER_SITES=	https://telepathy.freedesktop.org/releases/${PORTNAME:C/4//}/
DISTNAME=	${PORTNAME:C/4//}-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	High-level Qt binding for Telepathy

LICENSE=	LGPL21

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_dbus_bindings.so:devel/py-dbus
LIB_DEPENDS=	libtelepathy-farstream.so:net-im/telepathy-farstream \
		libtelepathy-glib.so:net-im/telepathy-glib
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_dbus_bindings.so:devel/py-dbus

OPTIONS_DEFINE=	DOCS

USE_GNOME=	libxslt:build
USE_GSTREAMER=	yes
USE_QT4=	corelib dbus gui network qtestlib_build xml \
		moc_build qmake_build rcc_build uic_build
USES=		cmake:outsource pathfix pkgconfig python:build
CMAKE_ARGS=	-DENABLE_EXAMPLES:BOOL=False \
		-DENABLE_FARSIGHT:BOOL=False \
		-DENABLE_FARSTREAM:BOOL=True \
		-DENABLE_TESTS:BOOL=False \
		-DDESIRED_QT_VERSION:STRING=4 \
		-DQT_QMAKE_EXECUTABLE:FILEPATH=${QMAKE}
USE_LDCONFIG=	yes

# Required because FindGObject.cmake is too old and uses the pkg-config values
# directly (-lgobject-2.0 instead of /path/to/libgobject-2.0.so).
CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

# We do not need Doxygen because the tarball already ships with prebuilt
# documentation.
CMAKE_ARGS+=	-DDOXYGEN_EXECUTABLE:FILEPATH=""

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

PORTDOCS=	AUTHORS ChangeLog HACKING NEWS README html

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${CP} -R doc/html .
. for f in ${PORTDOCS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${f} ${STAGEDIR}${DOCSDIR}
. endfor

.include <bsd.port.mk>
