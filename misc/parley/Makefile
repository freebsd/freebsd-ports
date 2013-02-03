# $FreeBSD$

PORTNAME=	parley
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Vocabulary trainer for KDE 4

CONFLICTS=	kdeedu-4.[0-6].*

USE_GNOME=	libxml2 libxslt
USE_KDE4=	kdehier kdelibs kdeprefix libkdeedu attica automoc4
KDE4_BUILDENV=	yes
USE_QT4=	corelib moc_build qmake_build rcc_build uic_build
USE_XORG=	x11 xrender
USE_XZ=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
