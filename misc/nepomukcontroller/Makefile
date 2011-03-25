# New ports collection makefile for:	nepomukcontroller
# Date created:		2011-01-06
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nepomukcontroller
PORTVERSION=	0.2
CATEGORIES=	misc kde
MASTER_SITES=	http://kde-apps.org/CONTENT/content-files/
DISTNAME=	137088-${PORTNAME}-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Nepomuk systray applet

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	kdeprefix kdehier automoc4 kdelibs runtime
USE_QT_VER=	4
QT_COMPONENTS=	moc_build qmake_build rcc_build uic_build

MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/nepomukcontroller \
		share/applications/kde4/nepomukcontroller.desktop

.include <bsd.port.mk>
