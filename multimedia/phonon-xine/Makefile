# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phonon
PORTVERSION=	4.4.4
PORTREVISION=	5
CATEGORIES=	multimedia kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${PHONON_BRANCH}/${PORTNAME}/${PORTNAME}-backend${PKGNAMESUFFIX}/${PORTVERSION}/src
PKGNAMESUFFIX=	-xine
DISTNAME=	${PORTNAME}-backend${PKGNAMESUFFIX}-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	The xine backend for Phonon

LIB_DEPENDS=	xine.2:${PORTSDIR}/multimedia/libxine

CONFLICTS=	phonon-4.3.0*

PHONON_BRANCH=	stable
USE_BZIP2=	yes
USES=		cmake pkgconfig
USE_KDE4=	kdehier automoc4 kdeprefix
USE_QT4=	gui dbus xml phonon \
		qmake_build moc_build rcc_build uic_build

PLIST_SUB+=	QT_PREFIX=${QT_PREFIX}

NO_STAGE=	yes
pre-su-install:
	${MKDIR} ${QT_PLUGINDIR}/phonon_backend

post-install:
	${LN} -sf ${PREFIX}/lib/kde4/plugins/phonon_backend/phonon_xine.so ${QT_PLUGINDIR}/phonon_backend/libphonon_xine.so

.include <bsd.port.mk>
