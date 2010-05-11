# New ports collection Makefile for:	kdeedu
# Date created:				2008-01-31
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdeedu
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Collection of entertaining, educational programs for KDE

BUILD_DEPENDS=	${LOCALBASE}/lib/ocaml/facile/facile.a:${PORTSDIR}/math/facile \
		eigen>=2.0.b3:${PORTSDIR}/math/eigen2 \
		gmm++>=3.0.4:${PORTSDIR}/math/gmm++ \
		xplanet:${PORTSDIR}/astro/xplanet
LIB_DEPENDS=	boost_python:${PORTSDIR}/devel/boost-python-libs \
		nova:${PORTSDIR}/astro/libnova \
		openbabel.3:${PORTSDIR}/science/openbabel \
		cfitsio.0:${PORTSDIR}/astro/cfitsio \
		qalculate.5:${PORTSDIR}/math/libqalculate \
		gsl.15:${PORTSDIR}/math/gsl \
		spectre.1:${PORTSDIR}/print/libspectre
#		gps.19:${PORTSDIR}/astro/gpsd
RUN_DEPENDS=	xplanet:${PORTSDIR}/astro/xplanet

LATEST_LINK=	${PORTNAME}4

USE_BZIP2=	yes
USE_KDE4=	kdelibs kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui svg qmake_build moc_build rcc_build uic_build
USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=	yes
USE_PYTHON=	yes
MAKE_JOBS_UNSAFE=	yes

MAN1=		kalzium.1 \
		kbruch.1 \
		kig.1 \
		kmplot.1 \
		ktouch.1
MAN6=		khangman.6

#fix checking boost_python
CMAKE_ARGS+=	-DCMAKE_REQUIRED_INCLUDES:STRING="${LOCALBASE}/include" \
		-DBOOST_PYTHON_INCLUDES="${LOCALBASE}/include;${PYTHON_INCLUDEDIR}" \
		-DBOOST_PYTHON_LIBS="-L${LOCALBASE}/lib -lboost_python -l${PYTHON_VERSION}" \
		-DWITH_R:BOOL=OFF

#Disable gpsd support, new version is required
post-patch:
	${REINPLACE_CMD} -e "/find_package/d" \
		${WRKSRC}/marble/src/plugins/positionprovider/CMakeLists.txt

.include <bsd.port.mk>
