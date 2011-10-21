# New ports collection makefile for:	qt-gstreamer
# Date created:		Sat 15 Jan 2011, 23:39:37
# Whom:			Dima Panov <fluffy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gstreamer
PORTVERSION=	0.10.1
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/qt-${PORTNAME}/
PKGNAMESUFFIX=	-qt4
DISTNAME=	qt-${PORTNAME}-${PORTVERSION}

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Qt4 bindings for GStreamer multimedia library

LIB_DEPENDS=	boost_thread:${PORTSDIR}/devel/boost-libs

USE_BISON=	build
USE_BZIP2=	yes
USE_CMAKE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GSTREAMER=	yes
USE_GNOME=	glib20
USE_KDE4=	automoc4
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui qtestlib \
		qmake_build moc_build rcc_build uic_build

PLIST_SUB=	VERSION="${GST_VERSION}"

GST_VERSION=${PORTVERSION:C/..$//}

CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH:STRING="${LOCALBASE}/include"
LDFLAGS+=	-L${LOCALBASE}/lib

post-extract:
	${REINPLACE_CMD} -e 's|$${LIB_INSTALL_DIR}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/src/CMakeLists.txt

.include <bsd.port.mk>
