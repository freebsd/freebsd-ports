# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=		dragon
PORTVERSION=		${KDE4_VERSION}
CATEGORIES=		multimedia kde
MASTER_SITES=		${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=		KDE

MAINTAINER=		kde@FreeBSD.org
COMMENT=		A KDE multimedia player with a focus on simplicity instead of features

LICENSE=		GPLv2

CONFLICTS_INSTALL=	kdemultimedia-4.[1-8].*

MAKE_JOBS_SAFE=		yes
KDE4_BUILDENV=		yes
USE_KDE4=		automoc4 kdehier kdelibs kdeprefix
USE_QT4=		dbus phonon \
			moc_build qmake_build rcc_build uic_build
USE_XZ=			yes

MAN1=			dragon.1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
