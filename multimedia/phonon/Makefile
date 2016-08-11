# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phonon
PORTVERSION=	4.8.3
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE multimedia framework

LICENSE=	LGPL21

LIB_DEPENDS=	libqzeitgeist.so:sysutils/qzeitgeist

USE_KDE4=	automoc4
USE_QT4=	corelib dbus gui \
		qmake_build moc_build rcc_build uic_build
USES=		cmake tar:xz
CMAKE_ARGS=	-DPHONON_INSTALL_QT_EXTENSIONS_INTO_SYSTEM_QT:BOOL=TRUE \
		-DPHONON_NO_PLATFORMPLUGIN:BOOL=TRUE \
		-DPHONON_BUILD_DESIGNER_PLUGIN:BOOL=OFF
USE_LDCONFIG=	yes

PLIST_SUB=	SHLIB_VER=${PORTVERSION}

OPTIONS_DEFINE=	PULSEAUDIO

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_USE=		GNOME=glib20
PULSEAUDIO_CMAKE_ON=	-DWITH_PulseAudio:BOOL=ON
PULSEAUDIO_CMAKE_OFF=	-DWITH_PulseAudio:BOOL=OFF

post-install:
	${MKDIR} ${STAGEDIR}${QT_INCDIR}
	${MKDIR} ${STAGEDIR}${QT_LIBDIR}
	${LN} -sf ${PREFIX}/include/phonon ${STAGEDIR}${QT_INCDIR}/phonon
	${LN} -sf ${PREFIX}/include/phonon ${STAGEDIR}${QT_INCDIR}/Phonon
	${LN} -sf ${PREFIX}/include/KDE/Phonon ${STAGEDIR}${PREFIX}/include/phonon/Phonon
.for lib in phonon phononexperimental
	${LN} -sf ${PREFIX}/lib/lib${lib}.so.${PORTVERSION} ${STAGEDIR}${QT_LIBDIR}/lib${lib}.so
	${LN} -sf ${PREFIX}/lib/lib${lib}.so.${PORTVERSION} ${STAGEDIR}${QT_LIBDIR}/lib${lib}.so.4
.endfor

.include <bsd.port.mk>
