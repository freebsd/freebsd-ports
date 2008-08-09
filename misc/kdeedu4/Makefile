# New ports collection Makefile for:	kdeedu
# Date created:				2008-01-31
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdeedu
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Collection of entertaining, educational programs for KDE

BUILD_DEPENDS=	${LOCALBASE}/include/eigen/util.h:${PORTSDIR}/math/eigen \
		${LOCALBASE}/lib/ocaml/facile/facile.a:${PORTSDIR}/math/facile \
		gmm++>=3.0.4:${PORTSDIR}/math/gmm++
LIB_DEPENDS=	usb-0.1:${PORTSDIR}/devel/libusb \
		boost_python:${PORTSDIR}/devel/boost-python \
		nova:${PORTSDIR}/astro/libnova \
		openbabel.3:${PORTSDIR}/science/openbabel \
		cfitsio.0:${PORTSDIR}/astro/cfitsio \
		qalculate.4:${PORTSDIR}/math/libqalculate \
		gsl.12:${PORTSDIR}/math/gsl

LATEST_LINK=	${PORTNAME}4

USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=    yes
USE_BZIP2=	yes
USE_QT_VER=	4
USE_KDE4=	kdelibs workspace kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
QT_COMPONENTS=	qmake gui moc rcc uic svg

#fix checking boost_python
CMAKE_ARGS+=	-DCMAKE_REQUIRED_INCLUDES:STRING="${LOCALBASE}/include"

post-extract:
	${MKDIR} ${WRKSRC}

post-patch:
	#fix checking libnova
	${REINPLACE_CMD} -e 's|\(CMAKE_REQUIRED_INCLUDES $${NOVA_INCLUDE_DIR}\)|\1 ${LOCALBASE}/include|' \
		 ${WRKSRC}/../cmake/modules/FindNova.cmake
	#fix checking boost_python
	${REINPLACE_CMD} -e 's|\(CMAKE_REQUIRED_INCLUDES $${_pydir}\)|\1 ${LOCALBASE}/include|' \
		 ${WRKSRC}/../cmake/modules/FindBoostPython.cmake

post-configure:
	${REINPLACE_CMD} -e "s,-ldl,,g" ${WRKSRC}/kalzium/src/CMakeFiles/kalzium.dir/build.make
	${REINPLACE_CMD} -e "s,-ldl,,g" ${WRKSRC}/kalzium/src/CMakeFiles/kalzium.dir/link.txt

.include <bsd.port.mk>
