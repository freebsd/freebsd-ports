# $FreeBSD$

PORTNAME=	kcalc
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	math kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Scientific calculator for KDE

LIB_DEPENDS=    gmp.10:${PORTSDIR}/math/gmp \
                mpfr:${PORTSDIR}/math/mpfr

CONFLICTS_INSTALL=	kdeutils-4.[0-7].*

USE_XZ=		yes
USE_KDE4=	kdeprefix kdehier automoc4 kdelibs
USES=		cmake:outsource
USE_QT4=	xml qmake_build moc_build rcc_build uic_build

.include <bsd.port.mk>
