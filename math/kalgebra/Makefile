# $FreeBSD$

PORTNAME=	kalgebra
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	math kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE graph calculator

LIB_DEPENDS=	analitza.5:${PORTSDIR}/math/analitza

CONFLICTS=	kdeedu-4.[0-6].*

CMAKE_ARGS=	-DBUILD_mobile:BOOL=FALSE
USE_GL=		glu
USE_KDE4=	kdehier kdelibs kdeprefix libkdeedu automoc4
KDE4_BUILDENV=	yes
USE_QT4=	gui opengl script scripttools xml \
		moc_build qmake_build rcc_build uic_build
USE_XZ=		yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
