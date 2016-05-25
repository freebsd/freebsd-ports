# $FreeBSD$

PORTNAME=	phonon
PORTVERSION=	0.8.2
PORTREVISION=	1
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTNAME}-backend${PKGNAMESUFFIX}/${PORTVERSION}/src
PKGNAMESUFFIX=	-vlc
DISTNAME=	${PORTNAME}-backend${PKGNAMESUFFIX}-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	VLC backend for Phonon

LIB_DEPENDS=	libvlc.so:multimedia/vlc-qt4

USE_KDE4=	automoc4
USE_QT4=	corelib gui phonon \
		qmake_build moc_build rcc_build uic_build
USES=		cmake pkgconfig tar:xz

post-install:
	${MKDIR} ${STAGEDIR}${QT_PLUGINDIR}/phonon_backend
	${LN} -sf ${PREFIX}/lib/kde4/plugins/phonon_backend/phonon_vlc.so \
		${STAGEDIR}${QT_PLUGINDIR}/phonon_backend/libphonon_vlc.so

.include <bsd.port.mk>
