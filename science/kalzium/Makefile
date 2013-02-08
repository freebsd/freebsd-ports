# $FreeBSD$

PORTNAME=	kalzium
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	science kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Periodic table of elements for KDE 4

LIB_DEPENDS=	openbabel:${PORTSDIR}/science/openbabel \
		avogadro:${PORTSDIR}/science/avogadro

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/eigen2.pc:${PORTSDIR}/math/eigen2 \
		${LOCALBASE}/lib/ocaml/facile/facile.a:${PORTSDIR}/math/facile

CONFLICTS=	kdeedu-4.[0-6].*

# Keep USE_GCC in sync with science/avogadro.
USE_GCC=	4.4+
USE_KDE4=	kdehier kdelibs kdeprefix automoc4
KDE4_BUILDENV=	yes
USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=	yes
USE_QT4=	dbus designer opengl script xml \
		moc_build qmake_build rcc_build uic_build
USE_XZ=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		kalzium.1

.include <bsd.port.mk>
