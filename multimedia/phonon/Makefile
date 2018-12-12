# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phonon
DISTVERSION=	4.10.1
PORTREVISION=	2
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}
DIST_SUBDIR=	KDE/phonon

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE multimedia framework

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

FLAVORS=	qt5 qt4
FLAVOR?=	${FLAVORS:[1]}

qt4_LIB_DEPENDS=	libqzeitgeist.so:sysutils/qzeitgeist
qt4_PKGNAMESUFFIX=	-qt4
qt5_PKGNAMESUFFIX=	-qt5
qt4_PLIST=	${.CURDIR}/pkg-plist.qt4
qt5_PLIST=	${.CURDIR}/pkg-plist.qt5

qt4_DEPRECATED=		Qt4 has been EOL since december 2015
qt4_EXPIRATION_DATE=	2019-03-15

USES=		cmake compiler:c++11-lang pathfix tar:xz
CMAKE_ON=	PHONON_INSTALL_QT_EXTENSIONS_INTO_SYSTEM_QT \
		PHONON_NO_PLATFORMPLUGIN
CMAKE_OFF=	PHONON_BUILD_DESIGNER_PLUGIN:BOOL=OFF
USE_LDCONFIG=	yes

.  if ${FLAVOR} == qt4
USES+=		kde:4 qt:4
USE_KDE=	automoc4
USE_QT=		corelib dbus declarative gui testlib \
		qmake_build moc_build rcc_build uic_build
.  else
USES+=		kde:5 qt:5
USE_KDE=	ecm
USE_QT=		core dbus gui opengl widgets \
		buildtools_build qmake_build
CMAKE_OFF+=	PHONON_BUILD_DECLARATIVE_PLUGIN
CMAKE_ON+=	PHONON_BUILD_PHONON4QT5
.  endif

PLIST_SUB=	SHLIB_VER=${DISTVERSION}

OPTIONS_DEFINE=	PULSEAUDIO

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_USE=		GNOME=glib20
PULSEAUDIO_CMAKE_BOOL=	WITH_PulseAudio

.  if ${FLAVOR} == qt4
post-install:
	${MKDIR} ${STAGEDIR}${QT_INCDIR}
	${MKDIR} ${STAGEDIR}${QT_LIBDIR}
	${RLN} ${STAGEDIR}${PREFIX}/include/phonon ${STAGEDIR}${QT_INCDIR}/phonon
	${RLN} ${STAGEDIR}${PREFIX}/include/phonon ${STAGEDIR}${QT_INCDIR}/Phonon
	${RLN} ${STAGEDIR}${PREFIX}/include/KDE/Phonon ${STAGEDIR}${PREFIX}/include/phonon/Phonon
.    for lib in phonon phononexperimental
	${RLN} ${STAGEDIR}${PREFIX}/lib/lib${lib}.so.${DISTVERSION} ${STAGEDIR}${QT_LIBDIR}/lib${lib}.so
	${RLN} ${STAGEDIR}${PREFIX}/lib/lib${lib}.so.${DISTVERSION} ${STAGEDIR}${QT_LIBDIR}/lib${lib}.so.4
.    endfor
.  endif

.include <bsd.port.mk>
