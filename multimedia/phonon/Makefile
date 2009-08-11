# New ports collection Makefile for:	phonon
# Date created:				2008-01-30
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	phonon
PORTVERSION=	4.3.1
PORTREVISION=	1
CATEGORIES=	multimedia kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/4.2.1/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Multimedia framework for KDE4

CONFLICTS=	qt4-phonon-4* kdebase-runtime-4.1.[0-4]*

USE_BZIP2=	yes
USE_KDE4=	kdehier automoc4 kdeprefix
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui dbus xml qtestlib \
		qmake_build moc_build rcc_build uic_build

IGNORE=		superseded by multimedia/qt4-phonon
EXPIRATION_DATE=	2009-09-06
DEPRECATED=	${IGNORE}

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

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
