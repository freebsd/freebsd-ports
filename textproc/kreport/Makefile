# $FreeBSD$

PORTNAME=		kreport
DISTVERSION=		3.1.0
PORTREVISION=	1
CATEGORIES=		textproc kde
MASTER_SITES=		KDE/stable/${PORTNAME}/src
DIST_SUBDIR=		KDE/${PORTNAME}

MAINTAINER=		kde@FreeBSD.org
COMMENT=		Framework for creation of reports in multiple formats

LIB_DEPENDS=		libKPropertyCore3.so:x11-toolkits/kproperty

USES=			cmake:outsource compiler:c++11-lang gettext kde:5 \
			python:2.7 qt:5 tar:xz
USE_KDE=		config coreaddons ecm marble widgetsaddons
USE_QT=			core declarative gui network webkit widgets xml \
			buildtools_build printsupport qmake_build

CONFLICTS_INSTALL=	calligra-2*

.include <bsd.port.mk>
