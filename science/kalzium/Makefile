# $FreeBSD$

PORTNAME=	kalzium
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	science kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Periodic table of elements for KDE 4

LIB_DEPENDS=	openbabel:${PORTSDIR}/science/openbabel \
		avogadro:${PORTSDIR}/science/avogadro

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/eigen2.pc:${PORTSDIR}/math/eigen2 \
		${LOCALBASE}/lib/ocaml/facile/facile.a:${PORTSDIR}/math/facile

CONFLICTS=	kdeedu-4.[0-6].*

USE_GCC=	yes
USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USES=		cmake:outsource pkgconfig
USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=	yes
USE_QT4=	corelib declarative designer opengl script xml \
		moc_build qmake_build rcc_build uic_build
USE_XZ=		yes
USE_LDCONFIG=	yes

MAN1=		kalzium.1

NO_STAGE=	yes
.include <bsd.port.mk>
