# Created by: Alberto Villa <avilla@FreeBSD.org>
# $FreeBSD$

PORTNAME=	telepathy-qt
PORTVERSION=	0.9.7
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	https://telepathy.freedesktop.org/releases/${PORTNAME}/
PKGNAMESUFFIX?=	4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	High-level Qt binding for Telepathy

LICENSE=	LGPL21

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_dbus_bindings.so:devel/py-dbus@${PY_FLAVOR}
LIB_DEPENDS=	libtelepathy-farstream.so:net-im/telepathy-farstream \
		libtelepathy-glib.so:net-im/telepathy-glib
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_dbus_bindings.so:devel/py-dbus@${PY_FLAVOR}

OPTIONS_DEFINE=	DOCS

USE_GNOME=	glib20 libxslt:build
USE_GSTREAMER=	yes
USES=		cmake:outsource gettext pathfix pkgconfig python:2.7,build
CMAKE_ARGS=	-DENABLE_EXAMPLES:BOOL=False \
		-DENABLE_FARSIGHT:BOOL=False \
		-DENABLE_FARSTREAM:BOOL=True \
		-DENABLE_TESTS:BOOL=False \
		-DDESIRED_QT_VERSION:STRING=${PKGNAMESUFFIX} \
		-DQT_QMAKE_EXECUTABLE:FILEPATH=${QMAKE}
. if ${PKGNAMESUFFIX:M4}
USE_QT4=	corelib dbus gui network qtestlib_build xml \
		moc_build qmake_build rcc_build uic_build
SHLIB_SUFFIX=	2
. else
USE_QT5=	core dbus gui network xml \
		buildtools_build qmake_build testlib_build widgets_build
SHLIB_SUFFIX=	0
. endif

USE_LDCONFIG=	yes

# Required because FindGObject.cmake is too old and uses the pkg-config values
# directly (-lgobject-2.0 instead of /path/to/libgobject-2.0.so).
CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

# We do not need Doxygen because the tarball already ships with prebuilt
# documentation.
CMAKE_ARGS+=	-DDOXYGEN_EXECUTABLE:FILEPATH=""

PLIST_SUB=	PORTVERSION="${PORTVERSION}" \
		QTVER_SUFFIX="${PKGNAMESUFFIX}" \
		SHLIB_SUFFIX="${SHLIB_SUFFIX}"

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
