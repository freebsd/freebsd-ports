# $FreeBSD$

PORTNAME=	kalgebra
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	math kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE graph calculator

LIB_DEPENDS=	libanalitza.so:math/analitza

CMAKE_ARGS=	-DBUILD_mobile:BOOL=FALSE
USE_GL=		glu
USE_KDE4=	kdelibs kdeprefix libkdeedu automoc4
USES=		cmake:outsource tar:xz
USE_QT4=	corelib declarative gui opengl \
		moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
