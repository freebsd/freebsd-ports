# New ports collection Makefile for:	phonon
# Date created:				2008-01-30
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	phonon
PORTVERSION=	4.3.0
CATEGORIES=	multimedia kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}/${PORTVERSION}/
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE4 phonon applications

LIB_DEPENDS=	xine.1:${PORTSDIR}/multimedia/libxine

CONFLICTS=	qt4-phonon-4* kdebase-runtime-4.1.[0-4]*

USE_BZIP2=	yes
USE_KDE4=	kdehier automoc4 kdeprefix
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib opengl dbus qt3support designer network svg qtestlib \
		qmake_build moc_build rcc_build uic_build
USE_GSTREAMER=	yes

.include <bsd.port.pre.mk>

.if exists(${QT_LIBDIR}/libphonon.so)
IGNORE=		conflicts with Qt4 phonon. Please, deinstall qt4-phonon
.endif

post-extract:
	${MKDIR} ${WRKSRC}

post-patch:
#fix finding automoc when PREFIX is not matched KDE4_PREFIX
	${REINPLACE_CMD} -e 's|NO_DEFAULT_PATH|${KDE4_PREFIX} NO_DEFAULT_PATH|' \
		${WRKSRC}/../cmake/FindAutomoc4.cmake

pre-configure:
	${REINPLACE_CMD} -e '/phonon.pc/s|pkgconfig|../libdata/pkgconfig|' \
			-e 's|{QT_INCLUDES}|{QT_INCLUDES} ${LOCALBASE}/include|'\
		${WRKSRC}/../CMakeLists.txt

.include <bsd.port.post.mk>
