# New ports collection Makefile for:	phonon
# Date created:				2008-01-30
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	phonon
PORTVERSION=	4.5.0
PORTREVISION=	1
CATEGORIES=	multimedia kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${PHONON_BRANCH}/${PORTNAME}/${PORTVERSION}/src/
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Multimedia framework for KDE 4

LIB_DEPENDS=	qzeitgeist.0:${PORTSDIR}/sysutils/qzeitgeist

CONFLICTS=	qt4-phonon-4*

PHONON_BRANCH=	stable

USE_KDE4=	kdehier kdeprefix automoc4
USE_QT_VER=	4
QT_COMPONENTS=	dbus gui \
		qmake_build moc_build rcc_build uic_build
USE_BZIP2=	yes
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

OPTIONS=	PULSEAUDIO	"Support playback via PulseAudio" off
#		DESIGNER	"Install Qt Designer plugin" off \

.include <bsd.port.options.mk>

# FIXME: Enable this option with Qt 4.8 (qt4-webkit does not depend on
# phonon anymore).
# qt4-designer depends on qt4-webkit, hence on phonon. Disable this
# option to avoid a circular dependency.
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
	${REINPLACE_CMD} -e '/add_subdirectory(tests)/ d' \
		${PATCH_WRKSRC}/${PORTNAME}/experimental/CMakeLists.txt

# FIXME: We need to pass -DPHONON_INSTALL_QT_EXTENSIONS_INTO_SYSTEM_QT=1
# to install the designer plugin and the Qt .pri file into the
# system-wide Qt directory in the next release.
# Reference: http://commits.kde.org/phonon/664035456f0c9dc85b65c893f431b82118c281c0
post-install:
	${LN} -sf ${PREFIX}/include/phonon ${QT_INCDIR}/phonon
	${LN} -sf ${PREFIX}/include/phonon ${QT_INCDIR}/Phonon
	${LN} -sf ${PREFIX}/include/KDE/Phonon ${PREFIX}/include/phonon/Phonon
.for lib in phonon phononexperimental
	${LN} -sf ${PREFIX}/lib/lib${lib}.so.4.5.0 ${QT_LIBDIR}/lib${lib}.so
	${LN} -sf ${PREFIX}/lib/lib${lib}.so.4.5.0 ${QT_LIBDIR}/lib${lib}.so.4
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
