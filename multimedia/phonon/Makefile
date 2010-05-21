# New ports collection Makefile for:	phonon
# Date created:				2008-01-30
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	phonon
PORTVERSION=	4.4.1
CATEGORIES=	multimedia kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE} \
		http://ns.ael.ru/~fluffy.khv/distfiles/
MASTER_SITE_SUBDIR=	${PHONON_BRANCH}/${PORTNAME}/${PORTVERSION}/
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Multimedia framework for KDE4

CONFLICTS=	qt4-phonon-4* kdebase-runtime-4.1.[0-4]*

PHONON_BRANCH=	stable
USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	kdehier automoc4 kdeprefix
USE_QT_VER=	4
QT_COMPONENTS=	gui dbus xml qtestlib \
		qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes

OPTIONS=	PULSEAUDIO "Phonon support for PulseAudio" off

.include <bsd.port.options.mk>

.if defined(WITH_PULSEAUDIO)
CMAKE_ARGS+=	-DWITH_PulseAudio:BOOL=ON
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
USE_GNOME+=	glib20
.else
CMAKE_ARGS+=	-DWITH_PulseAudio:BOOL=OFF
.endif

PLIST_SUB+=	QT_PREFIX=${QT_PREFIX}

.if defined(WITH_QT_PHONON)
IGNORE=		conflicts with Qt4 phonon. Please, deinstall qt4-phonon and set WITH_KDE_PHONON to continue
.endif

post-patch:
#fix finding automoc when PREFIX is not matched KDE4_PREFIX
	${REINPLACE_CMD} -e 's|NO_DEFAULT_PATH|${KDE4_PREFIX} NO_DEFAULT_PATH|' \
		${PATCH_WRKSRC}/cmake/FindAutomoc4.cmake

pre-configure:
	${REINPLACE_CMD} -e '/phonon.pc/s|pkgconfig|../libdata/pkgconfig|' \
			-e 's|{QT_INCLUDES}|{QT_INCLUDES} ${LOCALBASE}/include|'\
		${PATCH_WRKSRC}/CMakeLists.txt

post-install:
	${LN} -sf ${PREFIX}/include/phonon ${QT_INCDIR}/phonon
	${LN} -sf ${PREFIX}/include/phonon ${QT_INCDIR}/Phonon
	${LN} -sf ${PREFIX}/include/KDE/Phonon ${PREFIX}/include/phonon/Phonon
	${LN} -sf ${PREFIX}/lib/libphonon.so.4.4.0 ${QT_LIBDIR}/libphonon.so
	${LN} -sf ${PREFIX}/lib/libphonon.so.4.4.0 ${QT_LIBDIR}/libphonon.so.4
	${LN} -sf ${PREFIX}/lib/libphononexperimental.so.4.4.0 ${QT_LIBDIR}/libphononexperimental.so
	${LN} -sf ${PREFIX}/lib/libphononexperimental.so.4.4.0 ${QT_LIBDIR}/libphononexperimental.so.4
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
