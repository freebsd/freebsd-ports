# $FreeBSD$

PORTNAME=	geekclock
PORTVERSION=	1.0
PORTREVISION=	11
CATEGORIES=	x11-clocks deskutils kde
MASTER_SITES=	http://w2f2.com/projects/${PORTNAME}/
PKGNAMEPREFIX=	plasma-applet-
DISTNAME=	geek-clock-plasmoid-${PORTVERSION}-src

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	KDE4 geeky analog clock plasma applet

USES=		cmake
USE_KDE4=	automoc4 kdelibs workspace
USE_QT4=	gui dbus network opengl svg webkit xml \
		qmake_build moc_build rcc_build uic_build

PLIST_FILES=	lib/kde4/plasma_applet_geekclock.so \
		share/apps/desktoptheme/default/widgets/geekclock.svgz \
		share/kde4/services/plasma-applet-geekclock.desktop

.include <bsd.port.mk>
