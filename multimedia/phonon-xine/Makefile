# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phonon
PORTVERSION=	4.4.4
PORTREVISION=	12
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTNAME}-backend${PKGNAMESUFFIX}/${PORTVERSION}/src
PKGNAMESUFFIX=	-xine
DISTNAME=	${PORTNAME}-backend${PKGNAMESUFFIX}-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	The xine backend for Phonon

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

BUILD_DEPENDS=	automoc4:devel/automoc4
LIB_DEPENDS=	libxine.so:multimedia/libxine

USES=		cmake pkgconfig qt:4 tar:bzip2
USE_QT=		corelib dbus gui phonon \
		qmake_build moc_build rcc_build uic_build
USE_XORG=	xcb

post-install:
	${MKDIR} ${STAGEDIR}${QT_PLUGINDIR}/phonon_backend
	${LN} -sf ${PREFIX}/lib/kde4/plugins/phonon_backend/phonon_xine.so \
		${STAGEDIR}${QT_PLUGINDIR}/phonon_backend/libphonon_xine.so

.include <bsd.port.mk>
