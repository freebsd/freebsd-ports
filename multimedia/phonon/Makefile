# New ports collection Makefile for:	phonon
# Date created:				2008-01-30
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	phonon
PORTVERSION=	4.6.0
CATEGORIES=	multimedia kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${PHONON_BRANCH}/${PORTNAME}/${PORTVERSION}/src/
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE multimedia framework

LIB_DEPENDS=	qzeitgeist.1:${PORTSDIR}/sysutils/qzeitgeist

CONFLICTS=	qt4-phonon-4*

PHONON_BRANCH=	stable

USE_KDE4=	kdehier kdeprefix automoc4
USE_QT_VER=	4
QT_COMPONENTS=	dbus gui \
		qmake_build moc_build rcc_build uic_build
USE_XZ=		yes
USE_CMAKE=	yes
CMAKE_ARGS=	-DPHONON_INSTALL_QT_EXTENSIONS_INTO_SYSTEM_QT:BOOL=TRUE \
		-DPHONON_NO_PLATFORMPLUGIN:BOOL=TRUE
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

OPTIONS=	PULSEAUDIO	"Support playback via PulseAudio" off
#		DESIGNER	"Install Qt Designer plugin" off \

.include <bsd.port.options.mk>

# qt4-designer depends on phonon. Disable this option to avoid a
# circular dependency.
.undef WITH_DESIGNER
.ifdef(WITH_DESIGNER)
QT_COMPONENTS+=	designer
CMAKE_ARGS+=	-DPHONON_BUILD_DESIGNER_PLUGIN:BOOL=ON
PLIST_SUB+=	DESIGNER=""
.else
CMAKE_ARGS+=	-DPHONON_BUILD_DESIGNER_PLUGIN:BOOL=OFF
PLIST_SUB+=	DESIGNER="@comment "
.endif

.ifdef(WITH_PULSEAUDIO)
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
USE_GNOME+=	glib20
CMAKE_ARGS+=	-DWITH_PulseAudio:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_PulseAudio:BOOL=OFF
.endif

PLIST_SUB+=	QT_PREFIX=${QT_PREFIX}

.ifdef(WITH_QT_PHONON)
IGNORE=		conflicts with Qt 4 phonon. Please, deinstall qt4-phonon and unset WITH_QT_PHONON to continue
.endif

pre-configure:
	${REINPLACE_CMD} -e '/phonon.pc/s|pkgconfig|../libdata/pkgconfig|' \
		-e 's|{QT_INCLUDES}|{QT_INCLUDES} ${LOCALBASE}/include|'\
		${PATCH_WRKSRC}/CMakeLists.txt

post-install:
	${LN} -sf ${PREFIX}/include/phonon ${QT_INCDIR}/phonon
	${LN} -sf ${PREFIX}/include/phonon ${QT_INCDIR}/Phonon
	${LN} -sf ${PREFIX}/include/KDE/Phonon ${PREFIX}/include/phonon/Phonon
.for lib in phonon phononexperimental
	${LN} -sf ${PREFIX}/lib/lib${lib}.so.${PORTVERSION} ${QT_LIBDIR}/lib${lib}.so
	${LN} -sf ${PREFIX}/lib/lib${lib}.so.${PORTVERSION} ${QT_LIBDIR}/lib${lib}.so.4
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
