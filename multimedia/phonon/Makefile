# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phonon
PORTVERSION=	4.7.0
CATEGORIES=	multimedia kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${PHONON_BRANCH}/${PORTNAME}/${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE multimedia framework

LIB_DEPENDS=	qzeitgeist:${PORTSDIR}/sysutils/qzeitgeist

CONFLICTS=	qt4-phonon-4*

PHONON_BRANCH=	stable

USE_KDE4=	kdehier kdeprefix automoc4
USE_QT4=	corelib dbus gui \
		qmake_build moc_build rcc_build uic_build
USE_XZ=		yes
USES=		cmake
CMAKE_ARGS=	-DPHONON_INSTALL_QT_EXTENSIONS_INTO_SYSTEM_QT:BOOL=TRUE \
		-DPHONON_NO_PLATFORMPLUGIN:BOOL=TRUE \
		-DPHONON_BUILD_DESIGNER_PLUGIN:BOOL=OFF
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	PULSEAUDIO

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	pulse:${PORTSDIR}/audio/pulseaudio
USE_GNOME+=	glib20
CMAKE_ARGS+=	-DWITH_PulseAudio:BOOL=ON
.else
CMAKE_ARGS+=	-DWITH_PulseAudio:BOOL=OFF
.endif

PLIST_SUB+=	QT_PREFIX=${QT_PREFIX}

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
