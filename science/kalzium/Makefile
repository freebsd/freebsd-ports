# $FreeBSD$

PORTNAME=	kalzium
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	science kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Periodic table of elements for KDE 4

LIB_DEPENDS=	libopenbabel.so:science/openbabel \
		libavogadro.so:science/avogadro
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/eigen2.pc:math/eigen2 \
		${LOCALBASE}/libdata/pkgconfig/eigen3.pc:math/eigen3 \
		${LOCALBASE}/lib/ocaml/facile/facile.a:math/facile \
		${LOCALBASE}/libdata/pkgconfig/chemical-mime-data.pc:science/chemical-mime-data
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/chemical-mime-data.pc:science/chemical-mime-data

USE_KDE4=	kdelibs automoc4
USES=		cmake:outsource pkgconfig tar:xz
USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=	yes
USE_QT4=	corelib declarative designer opengl script xml \
		moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
