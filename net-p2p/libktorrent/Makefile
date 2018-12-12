# $FreeBSD$

PORTNAME=	libktorrent
DISTVERSION=	2.1.0
PORTREVISION=	5
CATEGORIES=	net-p2p kde
DIST_SUBDIR=	KDE/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Torrent library from KTorrent project

BUILD_DEPENDS=	${LOCALBASE}/include/boost/concept_check.hpp:devel/boost-libs

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgmp.so:math/gmp \
		libqca-qt5.so:devel/qca@qt5

USES=		cmake:outsource compiler:c++11-lang gettext kde:5 qt:5
USE_KDE=	archive completion config coreaddons crash ecm i18n \
		jobwidgets kio service solid widgetsaddons
USE_QT=		core gui network testlib xml \
		buildtools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	KDE
GH_TAGNAME=	eb79ad2

.include <bsd.port.mk>
