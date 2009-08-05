# New ports collection Makefile for:	phonon
# Date created:				2008-01-30
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	phonon
PORTVERSION=	4.3.1
PORTREVISION=	3
CATEGORIES=	multimedia kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/4.2.1/src
PKGNAMESUFFIX=	-xine
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Phonon xine backend

LIB_DEPENDS=	xine.1:${PORTSDIR}/multimedia/libxine

CONFLICTS=	phonon-4.3.0*

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	kdehier automoc4 kdeprefix
USE_QT_VER=	4
QT_COMPONENTS=	gui dbus xml phonon \
		qmake_build moc_build rcc_build uic_build

post-patch:
#fix finding automoc when PREFIX is not matched KDE4_PREFIX
	${REINPLACE_CMD} -e 's|NO_DEFAULT_PATH|${KDE4_PREFIX} NO_DEFAULT_PATH|' \
		${WRKSRC}/cmake/FindAutomoc4.cmake

.include <bsd.port.mk>
