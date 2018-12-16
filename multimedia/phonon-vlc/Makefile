# $FreeBSD$

PORTNAME=	phonon
DISTVERSION=	0.10.1
PORTREVISION=	3
CATEGORIES=	multimedia kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTNAME}-backend-${PHONON_PLUGIN}/${DISTVERSION}
PKGNAMESUFFIX=	-${PHONON_PLUGIN}-${FLAVOR}
DISTNAME=	${PORTNAME}-backend-${PHONON_PLUGIN}-${DISTVERSION}
DIST_SUBDIR=	KDE/phonon

MAINTAINER=	kde@FreeBSD.org
COMMENT=	VLC backend for Phonon

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

FLAVORS=	qt5 qt4
FLAVOR?=	${FLAVORS:[1]}

qt4_LIB_DEPENDS=	libvlc.so:multimedia/vlc-qt4
qt5_LIB_DEPENDS=	libvlc.so:multimedia/vlc3

USES=		cmake:outsource pkgconfig tar:xz

.  if ${FLAVOR} == qt4
DEPRECATED=	Qt4 has been EOL since december 2015
EXPIRATION_DATE=2019-03-15
USES+=		kde:4 qt:4
USE_KDE=	automoc4
USE_QT=		corelib gui phonon \
		qmake_build moc_build rcc_build uic_build
PLIST_FILES=	lib/kde4/plugins/phonon_backend/phonon_vlc.so \
		share/kde4/services/phononbackends/vlc.desktop \
		${QT_PLUGINDIR}/phonon_backend/libphonon_vlc.so
.  else
USES+=		kde:5 qt:5
USE_KDE=	ecm
USE_QT=		core gui widgets phonon4 \
		buildtools_build qmake_build
CMAKE_ON=	PHONON_BUILD_PHONON4QT5
PLIST_FILES=	${QT_PLUGINDIR_REL}/phonon4qt5_backend/phonon_vlc.so
.  endif

PHONON_PLUGIN=	vlc
WRKSRC=		${WRKDIR}/${PORTNAME}-${PHONON_PLUGIN}-${DISTVERSION}

.  if ${FLAVOR} == qt4
post-install:
	${MKDIR} ${STAGEDIR}${QT_PLUGINDIR}/phonon_backend
	${RLN} ${STAGEDIR}${PREFIX}/lib/kde4/plugins/phonon_backend/phonon_vlc.so \
		${STAGEDIR}${QT_PLUGINDIR}/phonon_backend/libphonon_vlc.so
.  endif

.include <bsd.port.mk>
