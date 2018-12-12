# Created by: Dima Panov <fluffy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gstreamer
PORTVERSION=	0.10.3
PORTREVISION=	13
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/qt-${PORTNAME}/
PKGNAMESUFFIX=	-qt4
DISTNAME=	qt-${PORTNAME}-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt4 bindings for GStreamer multimedia library

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		bison cmake:noninja gmake kde:4 pathfix pkgconfig qt:4 tar:bzip2
USE_LDCONFIG=	yes
USE_GSTREAMER=	yes
USE_GNOME=	glib20
USE_KDE=	automoc4
USE_QT=		corelib gui opengl declarative \
		qmake_build moc_build rcc_build uic_build qtestlib_build

PLIST_SUB=	VERSION="${PORTVERSION}" GST_VERSION="${GST_VERSION}"

GST_VERSION=	${PORTVERSION:C/..$//}

CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH:STRING="${LOCALBASE}/include"
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
