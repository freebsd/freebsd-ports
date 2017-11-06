# $FreeBSD$

PORTNAME=		kreport
DISTVERSION=		3.0.2
CATEGORIES=		textproc kde
MASTER_SITES=		KDE/stable/${PORTNAME}/src
DIST_SUBDIR=		KDE/${PORTNAME}

MAINTAINER=		kde@FreeBSD.org
COMMENT=		Framework for creation of reports in multiple formats

LIB_DEPENDS=		libKPropertyCore3.so:x11-toolkits/kproperty

USES=			cmake:outsource gettext kde:5 python:2 tar:xz
USE_KDE=		config coreaddons ecm widgetsaddons
USE_QT5=		core gui network qml webkit widgets xml \
			buildtools_build printsupport qmake_build

CONFLICTS_INSTALL=	calligra-2*

.include <bsd.port.mk>
