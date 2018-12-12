# $FreeBSD$

PORTNAME=	libkvkontakte
DISTVERSION=	5.0.0
PORTREVISION=	2
CATEGORIES=	net kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/digikam

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE library for accessing vk.com

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USES=		cmake:outsource compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	config coreaddons ecm i18n kdewebkit kio service widgetsaddons
USE_QT=		core gui network webkit widgets \
		buildtools_build qmake_build

.include <bsd.port.mk>
