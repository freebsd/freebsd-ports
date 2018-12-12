# Created by: Alberto Villa <avilla@FreeBSD.org>
# $FreeBSD$

PORTNAME=	telepathy-qt
PORTVERSION=	0.9.7
PORTREVISION=	4
CATEGORIES=	net-im
MASTER_SITES=	https://telepathy.freedesktop.org/releases/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	High-level Qt binding for Telepathy

LICENSE=	LGPL21

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/_dbus_bindings.so:devel/py-dbus@${PY_FLAVOR}
LIB_DEPENDS=	libtelepathy-farstream.so:net-im/telepathy-farstream \
		libtelepathy-glib.so:net-im/telepathy-glib
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_dbus_bindings.so:devel/py-dbus@${PY_FLAVOR}

FLAVORS=	qt5 qt4
FLAVOR?=	${FLAVORS:[1]}
qt4_PKGNAMESUFFIX=	4
qt5_PKGNAMESUFFIX=	5

qt4_DEPRECATED=		Qt4 has been EOL since december 2015
qt4_EXPIRATION_DATE=	2019-03-15

USES=		cmake:outsource gettext gnome localbase:ldflags pathfix pkgconfig python:2.7,build
USE_GNOME=	glib20 libxslt:build
USE_GSTREAMER=	yes
USE_LDCONFIG=	yes

CMAKE_ON=	ENABLE_FARSTREAM CMAKE_DISABLE_FIND_PACKAGE_Doxygen
CMAKE_OFF=	ENABLE_EXAMPLES ENABLE_FARSIGHT ENABLE_TESTS
CMAKE_ARGS=	-DDESIRED_QT_VERSION:STRING=${PKGNAMESUFFIX} \
		-DQT_QMAKE_EXECUTABLE:FILEPATH=${QMAKE}

. if ${FLAVOR} == qt4
USES+=		qt:4
USE_QT=		corelib dbus gui network xml \
		moc_build qmake_build qtestlib_build rcc_build uic_build
SHLIB_SUFFIX=	2
. else
USES+=		compiler:c++11-lang qt:5
USE_QT=		core dbus gui network xml \
		buildtools_build qmake_build testlib_build widgets_build
SHLIB_SUFFIX=	0
. endif

OPTIONS_DEFINE=	DOCS

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
