# $FreeBSD$

PORTNAME=	kcalc
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	math kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Scientific calculator for KDE

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr

USE_KDE4=	kdeprefix automoc4 kdelibs
USES=		cmake:outsource tar:xz
USE_QT4=	xml qmake_build moc_build rcc_build uic_build

.include <bsd.port.mk>
