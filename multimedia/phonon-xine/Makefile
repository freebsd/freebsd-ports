# New ports collection Makefile for:	phonon
# Date created:				2008-01-30
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	phonon
PORTVERSION=	4.4.2
CATEGORIES=	multimedia kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
PKGNAMESUFFIX=	-xine
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Phonon xine backend

LIB_DEPENDS=	xine.1:${PORTSDIR}/multimedia/libxine

CONFLICTS=	phonon-4.3.0*

PHONON_BRANCH=	stable
USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	kdehier automoc4 kdeprefix
USE_QT_VER=	4
QT_COMPONENTS=	gui dbus xml phonon \
		qmake_build moc_build rcc_build uic_build

PLIST_SUB+=	QT_PREFIX=${QT_PREFIX}

post-patch:
#fix finding automoc when PREFIX is not matched KDE4_PREFIX
	${REINPLACE_CMD} -e 's|NO_DEFAULT_PATH|${KDE4_PREFIX} NO_DEFAULT_PATH|' \
		${WRKSRC}/cmake/FindAutomoc4.cmake

pre-install:
	${MKDIR} ${QT_PLUGINDIR}/phonon_backend

post-install:
	${LN} -sf ${PREFIX}/lib/kde4/plugins/phonon_backend/phonon_xine.so ${QT_PLUGINDIR}/phonon_backend/libphonon_xine.so

.include <bsd.port.mk>
