# New ports collection Makefile for:	phonon
# Date created:				2008-01-30
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	phonon
PORTVERSION=	4.4.1
PORTREVISION=	0
CATEGORIES=	multimedia kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE} \
		http://ns.ael.ru/~fluffy.khv/distfiles/
MASTER_SITE_SUBDIR=	${PHONON_BRANCH}/${PORTNAME}/${PORTVERSION}/
PKGNAMESUFFIX=	-gstreamer
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Phonon gstreamer backend

CONFLICTS=	qt4-phonon-gst-4*

PHONON_BRANCH=	stable
USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	kdehier automoc4 kdeprefix
USE_QT_VER=	4
QT_COMPONENTS=	gui dbus xml opengl phonon \
		qmake_build moc_build rcc_build uic_build
USE_GSTREAMER=	yes

PLIST_SUB+=	QT_PREFIX=${QT_PREFIX}

# Explicitly disable alsa, see for details:
# http://mail.kde.org/pipermail/kde-freebsd/2010-March/008015.html
CMAKE_ARGS+=	-DWITH_Alsa:BOOL=OFF

.if defined(WITH_QT_PHONON)
IGNORE=		conflicts with Qt4 phonon. Please, deinstall qt4-phonon-gst and set WITH_KDE_PHONON to continue
.endif

post-patch:
#fix finding automoc when PREFIX is not matched KDE4_PREFIX
	${REINPLACE_CMD} -e 's|NO_DEFAULT_PATH|${KDE4_PREFIX} NO_DEFAULT_PATH|' \
		${PATCH_WRKSRC}/cmake/FindAutomoc4.cmake

pre-configure:
	${REINPLACE_CMD} -e '/phonon.pc/s|pkgconfig|../libdata/pkgconfig|' \
			-e 's|{QT_INCLUDES}|{QT_INCLUDES} ${LOCALBASE}/include|'\
		${PATCH_WRKSRC}/CMakeLists.txt

pre-install:
	${MKDIR} ${QT_PLUGINDIR}/phonon_backend

post-install:
	${LN} -sf ${PREFIX}/lib/kde4/plugins/phonon_backend/phonon_gstreamer.so ${QT_PLUGINDIR}/phonon_backend/libphonon_gstreamer.so

.include <bsd.port.mk>
