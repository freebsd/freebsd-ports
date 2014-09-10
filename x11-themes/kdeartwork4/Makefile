# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdeartwork
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	x11-themes kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Artworks Themes

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/eigen2.pc:${PORTSDIR}/math/eigen2

USE_KDE4=	kdehier kdelibs kdeprefix libkexiv2 workspace automoc4
USES=		cmake:outsource tar:xz
USE_QT4=	corelib gui opengl \
		moc_build qmake_build rcc_build uic_build
USE_XORG=	x11 xt

OPTIONS_DEFINE=	GNOME
GNOME_DESC=	Use Gnome screensavers

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNOME}
BUILD_DEPENDS+=	${LOCALBASE}/share/applications/xscreensaver-properties.desktop:${PORTSDIR}/x11/xscreensaver-gnome
RUN_DEPENDS+=	${LOCALBASE}/share/applications/xscreensaver-properties.desktop:${PORTSDIR}/x11/xscreensaver-gnome
.else
BUILD_DEPENDS+=	xscreensaver:${PORTSDIR}/x11/xscreensaver
RUN_DEPENDS+=	xscreensaver:${PORTSDIR}/x11/xscreensaver
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local/|${LOCALBASE}|g' \
			-e 's|/usr/share|${LOCALBASE}/share|g' \
		${PATCH_WRKSRC}/cmake/modules/FindXscreensaver.cmake

.include <bsd.port.mk>
