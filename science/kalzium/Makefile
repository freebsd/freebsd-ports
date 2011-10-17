# New ports collection Makefile for:	kalzium
# Date created:				6 September 2011
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kalzium
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	science kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Periodic table of elements for KDE 4

LIB_DEPENDS=	openbabel.3:${PORTSDIR}/science/openbabel \
		avogadro.1:${PORTSDIR}/science/avogadro

BUILD_DEPENDS=	eigen>=2.0.b3:${PORTSDIR}/math/eigen2 \
		${LOCALBASE}/lib/ocaml/facile/facile.a:${PORTSDIR}/math/facile

CONFLICTS=	kdeedu-4.[0-6].*

# Keep USE_GCC in sync with science/avogadro.
USE_GCC=	4.4+
USE_KDE4=	kdehier kdelibs kdeprefix automoc4
KDE4_BUILDENV=	yes
USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=	yes
USE_QT_VER=	4
QT_COMPONENTS=	dbus designer opengl script xml \
		moc_build qmake_build rcc_build uic_build
USE_BZIP2=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		kalzium.1

.include <bsd.port.mk>
